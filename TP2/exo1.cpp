// #include <QApplication>
// #include <time.h>

// #include "tp2.h"

// MainWindow* w = nullptr;

// void selectionSort(Array& toSort){
// 	// selectionSort
// }

// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
//     uint elementCount=15; // number of elements to sort
//     MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
//     w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
//     w->show();

// 	return a.exec();
// }

#include <iostream>
#include <vector>

using namespace std; 

 int triSelection(vector<int>& vecteur){
	for (size_t i = 0; i < vecteur.size(); i++)
	{
		for (size_t j = 0; j< vecteur.size(); j++)
		{
			if (vecteur[i] < vecteur[j]){
				swap(vecteur[i], vecteur[j]); 
			}
		}
		
	}
    return 0; 
 }


 void draw(vector<int> vecteur){
    cout << endl; 
    cout << "--------------" << endl; 
    for (size_t i = 0; i < vecteur.size(); i++)
    {
        cout << vecteur[i] << " " ; 
    }
    
 }



int main(){
	vector<int> vecteur;
	for (size_t i = 10; i > 0; i--)
	{
		 vecteur.push_back(i);
	}
    draw(vecteur); 
	triSelection(vecteur); 
    draw(vecteur); 

	return 0; 
}
