// #include "tp3.h"
// #include <QApplication>
// #include <time.h>

// MainWindow* w = nullptr;
// using std::size_t;

// int binarySearch(Array& array, int toSearch)
// {
// 	return -1;
// }

// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	MainWindow::instruction_duration = 500;
// 	w = new BinarySearchWindow(binarySearch);
// 	w->show();

// 	return a.exec();
// }


#include <iostream>
#include <vector>

using namespace std; 



int binarySearch(vector<int>& vecteur, int toSearch){
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
            return mid; 
        }
    }
		
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

    cout << "position : " << binarySearch(vecteur,  n) << endl;  
    
    return 0; 
}

