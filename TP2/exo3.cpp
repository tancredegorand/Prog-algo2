// #include <QApplication>
// #include <time.h>

// #include "tp2.h"

// MainWindow* w=nullptr;


// void bubbleSort(Array& toSort){
// 	// bubbleSort
// }


// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	uint elementCount=20;
// 	MainWindow::instruction_duration = 100;
// 	w = new TestMainWindow(bubbleSort);
// 	w->show();

// 	return a.exec();
// }



#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble(vector<int>& vecteur){
    for (size_t i = 0; i < vecteur.size() - 1; i++) {
        for (size_t j = 0; j < vecteur.size() - i - 1; j++) {
            if (vecteur[j] > vecteur[j + 1]) {
                swap(vecteur[j], vecteur[j + 1]);
            }
        }
    }
    return vecteur;
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
    for (size_t i = 0; i < 10; i++)
    {
        vecteur.push_back(rand() % 10 + 1);
    }

    draw(vecteur);
    vector<int> vecteur2 = bubble(vecteur);
    draw(vecteur2);

    return 0; 
}
