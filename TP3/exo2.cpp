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



int binarySearchAll(vector<int>& vecteur, int toSearch, int indexMax, int indexMin){
	
	return -1;
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
        vecteur.push_back(i);
    }
	draw(vecteur); 

	int n =  rand() % vecteur.size();	
	cout << endl << "nombre à trouver : " << n << endl;     
    return 0; 
}

