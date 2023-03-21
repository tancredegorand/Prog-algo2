// #include <QApplication>
// #include <time.h>

// #include "tp2.h"


// MainWindow* w=nullptr;

// void recursivQuickSort(Array& toSort, int size)
// {
// 	// stop statement = condition + return (return stop the function even if it does not return anything)
	
// 	Array& lowerArray = w->newArray(size);
// 	Array& greaterArray= w->newArray(size);
// 	int lowerSize = 0, greaterSize = 0; // effectives sizes

// 	// split
	
// 	// recursiv sort of lowerArray and greaterArray

// 	// merge
// }

// void quickSort(Array& toSort){
// 	recursivQuickSort(toSort, toSort.size());
// }


// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	uint elementCount=20;
// 	MainWindow::instruction_duration = 50;
//     w = new TestMainWindow(quickSort);
// 	w->show();

// 	return a.exec();
// }



















// #include <iostream>
// #include <vector>
// #include <cstdlib>

// using namespace std; 


// vector<int> quickSort(vector<int>& current){
// 	if (current.size() == 1){
// 		return current; 
// 	}

// 	int index = rand() % current.size();
//     int pivot = current[index]; 

// 	vector<int> lowers;  
// 	vector<int> greaters;  
// 	vector<int> res;  

// 	for (size_t i = 0; i < current.size(); i++)
// 	{
// 		if (current[i] < pivot)
// 		{
// 			lowers.push_back(current[i]); 
// 		}
// 		else
// 		{
// 			greaters.push_back(current[i]); 
// 		}
		
// 	}
// 	lowers = quickSort(lowers); 
// 	greaters = quickSort(greaters); 



// 	res = lowers;
//     res.insert(res.end(), greaters.begin(), greaters.end());

	

// 	return res; 
// }



// void draw(vector<int> vecteur){
//     cout << endl;
//     cout << "--------------" << endl;
//     for (size_t i = 0; i < vecteur.size(); i++)
//     {
//         cout << vecteur[i] << " ";
//     }
// }

// int main(){
//     vector<int> vecteur;
//     for (size_t i = 0; i < 2; i++)
//     {
//         vecteur.push_back(rand() % 10 + 1);
//     }

//     draw(vecteur);
//     vector<int> vecteur2 = quickSort(vecteur);
//     draw(vecteur2);

//     return 0; 
// }



// #include <iostream>
// #include <vector>
// #include <cstdlib>

// using namespace std; 

// vector<int> quickSort(vector<int> current){
// 	if(current.size() <= 1){
// 		return current;
// 	}

// 	int pivot = current[rand() % current.size()]; // sélectionne pivot 
// 	vector<int> lowers, greaters;

//  	//lowers et greaters
// 	for(int i=0; i<current.size(); i++){
// 		if(current[i] < pivot){
// 			lowers.push_back(current[i]);
// 		} else if(current[i] > pivot){
// 			greaters.push_back(current[i]);
// 		}
// 	}

// 	lowers = quickSort(lowers);
// 	greaters = quickSort(greaters);


// 	vector<int> res;
// 	res.insert(res.end(), lowers.begin(), lowers.end());
// 	res.push_back(pivot);
// 	res.insert(res.end(), greaters.begin(), greaters.end());

// 	return res;
// }


#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

void quickSort(vector<int>& vecteur){
    int size = vecteur.size();
    if (size > 1){
        int pivot = rand() % size; 
        int tab_pivot = vecteur[pivot];
        std::vector<int> lowers;
        std::vector<int> greaters;
        for(int i = 0 ; i < size; i++){
            if (pivot != i){
                if (vecteur[i] < vecteur[pivot]) lowers.push_back(vecteur[i]); 
                else greaters.push_back(vecteur[i]);
            }
        }
        quickSort(lowers);
        quickSort(greaters);
        vecteur.clear();
        vecteur.insert(vecteur.end(), lowers.begin(), lowers.end());
        vecteur.push_back(tab_pivot); 
        vecteur.insert(vecteur.end(), greaters.begin(), greaters.end());
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
    for (size_t i = 0; i < 10; i++)
    {
        vecteur.push_back(rand() % 11 );
    }

    draw(vecteur);
    quickSort(vecteur); 
    draw(vecteur);

    return 0; 
}

