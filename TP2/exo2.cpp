// #include <QApplication>
// #include <time.h>

// #include "tp2.h"

// MainWindow* w=nullptr;

// void insertionSort(Array& toSort){
// 	Array& sorted=w->newArray(toSort.size());

// 	// insertion sort from toSort to sorted
	
// 	toSort=sorted; // update the original array
// }

// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
//     uint elementCount=15; // number of elements to sort
//     MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
//     w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
// 	w->show();

// 	return a.exec();
// }

#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int>& vecteur){
    vector<int> res;
    res.push_back(vecteur[0]);

    for (size_t i = 1; i < vecteur.size(); i++)
    {
        bool insert = false;
        for (size_t j = 0; j < res.size(); j++)
        {
            if (vecteur[i] < res[j])
            {
                res.insert(res.begin() + j, vecteur[i]);
                insert = true;
				break;
            }
        }
        if (!insert)
        {
            res.push_back(vecteur[i]);
        }
    }
    return res;
}

void draw(vector<int> vecteur){
    cout << endl;
    cout << "--------------" << endl;
    for (size_t i = 0; i < vecteur.size(); i++)
    {
        cout << vecteur[i] << " ";
    }
}

int main(){
    vector<int> vecteur;
    for (size_t i = 10; i > 0; i--)
    {
        vecteur.push_back(rand() % 10 + 1);
    }

    draw(vecteur);
    vector<int> vecteur2 = insertionSort(vecteur);
    draw(vecteur2);

    return 0;
}
