// #include <QApplication>
// #include <time.h>
// #include "tp2.h"

// MainWindow* w=nullptr;

// void merge(Array& first, Array& second, Array& result);

// void splitAndMerge(Array& origin)
// {
// 	// stop statement = condition + return (return stop the function even if it does not return anything)

// 	// initialisation
// 	Array& first = w->newArray(origin.size()/2);
// 	Array& second = w->newArray(origin.size()-first.size());
	
// 	// split

// 	// recursiv splitAndMerge of lowerArray and greaterArray

// 	// merge
// }

// void merge(Array& first, Array& second, Array& result)
// {

// }

// void mergeSort(Array& toSort)
// {
//     splitAndMerge(toSort);
// }

// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	MainWindow::instruction_duration = 50;
//     w = new TestMainWindow(mergeSort);
// 	w->show();

// 	return a.exec();
// }


#include <iostream>
#include <vector>
#include <cstdlib>
	#include <algorithm> // pour std::sort

using namespace std; 

vector<int> quickSort(vector<int> current){
    vector<int> t1, t2; 

    int index = current.size()/2; 
    for(int i=0; i<current.size(); i++){
        if (i < index){
            t1.push_back(current[i]); 
        }else {
            t2.push_back(current[i]); 
        }
    }

    if (t1.size() > 1){
        t1 = quickSort(t1);
    }
    if (t2.size() > 1){
        t2 = quickSort(t2);
    }

    vector<int> res;
    int i = 0, j = 0;
    while (i < t1.size() && j < t2.size()){
        if (t1[i] < t2[j]){
            res.push_back(t1[i++]);
        }else{
            res.push_back(t2[j++]);
        }
    }
    while (i < t1.size()){
        res.push_back(t1[i++]);
    }
    while (j < t2.size()){
        res.push_back(t2[j++]);
    }

    return res;
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
    for (int i = 10; i >= 1; i--)
    {
        vecteur.push_back(i);
    }

    draw(vecteur);
    vector<int> vecteur2 = quickSort(vecteur); 
    draw(vecteur2);

    return 0; 
}
