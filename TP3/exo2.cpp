// #include "tp3.h"
// #include <QApplication>
// #include <time.h>

// MainWindow* w = nullptr;
// using std::size_t;

// /**
//  * @brief define indexMin and indexMax as the first and the last index of toSearch
//  * @param array array of int to process
//  * @param toSearch value to find
//  * @param indexMin first index of the value to find
//  * @param indexMax last index of the value to find
//  */
// void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
// {
// 	// do not use increments, use two different binary search loop
//     indexMin = indexMax = -1;
// }

// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	MainWindow::instruction_duration = 500;
// 	w = new BinarySearchAllWindow(binarySearchAll);
// 	w->show();

// 	return a.exec();
// }


#include <iostream>
#include <vector>

using namespace std; 

int binarySearchMin(vector<int>& vecteur, int toSearch){
    int start = 0; 
    int end = vecteur.size(); 
    int mid; 
    int res; 

    while (start < end)
    {
        mid = (start+end)/2; 
        if (toSearch > vecteur[mid]){
            start = mid+1; 
        }
        else if (toSearch < vecteur[mid]){
            end = mid; 
        }
        else {
            while(vecteur[mid-1] == toSearch){
                mid = mid-1; 
            }
            return mid; 
        }
    }	
	return -1;
}


int binarySearchMax(vector<int>& vecteur, int toSearch, int indexMin){
    int res = indexMin; 
    while(indexMin + 1 < vecteur.size() && vecteur[indexMin+1] == toSearch){
        res = res+1;
        indexMin++; 
    }
    return res; 
}



void binarySearchAll(vector<int>& vecteur, int toSearch, int& indexMax, int& indexMin){
    if (vecteur.size() <= 0){
        indexMax = -1; 
        indexMin = -1;
    }
    indexMin = binarySearchMin(vecteur, toSearch);   
    if (indexMin == -1){
        indexMax = -1; 
    }else{
        indexMax =  binarySearchMax(vecteur, toSearch,  indexMin); 
    }
}


void draw(vector<int>& vecteur){
    cout << endl;
    cout << "--------------" << endl;
    for (size_t i = 0; i < vecteur.size(); i++)
    {
        cout << vecteur[i] << " ";
    }
}


int main(){
    vector<int> vecteur;
    for (size_t i = 1; i <= 10; i++)
    {
        if (i > 2 && i < 8){
            vecteur.push_back(5);
        }
        else {
            vecteur.push_back(i);
        }
    }
    int indexMax = vecteur.size(); 
    int indexMin = 0; 

	draw(vecteur); 

	int n =  5;	
	cout << endl << "nombre à trouver : " << n << endl;   

    binarySearchAll(vecteur, n, indexMax, indexMin); 

    cout << "index Min : " << indexMin << endl; 
    cout << "index Max : " << indexMax << endl; 



    return 0; 
}

