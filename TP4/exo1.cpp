#include <iostream>
#include <vector>
using namespace std;

void exchange(vector<int>& heap, int i, int j) {
    int temp = heap[j];
    heap[j] = heap[i];
    heap[i] = temp;
}

int leftChild(vector<int>& heap, int nodeIndex)
{
    return heap[2*nodeIndex+1];
}

int rightChild(vector<int>& heap, int nodeIndex)
{
    return heap[2*nodeIndex+2];
}

void insertHeapNode(vector<int>& heap, int& heapSize, int value)
{
    int i = heapSize;
    heap.push_back(value);
    while (i>0 && heap[i] > heap[(i-1)/2]) {
        exchange(heap,i,(i-1)/2);
        i = (i-1)/2;
    }
    heapSize++;
}

void heapify(vector<int>& heap, int heapSize, int nodeIndex)
{
    int i_max = nodeIndex;
    for (int i=nodeIndex ; i<2*nodeIndex+1 && i<heapSize ; i++) {
        if (heap[i] > heap[i_max]) {
            i_max = i;
        }
    }

    if (i_max != nodeIndex) {
        exchange(heap,nodeIndex,i_max);
        heapify(heap,heapSize,i_max);
    }
}

void buildHeap(vector<int>& heap, int& heapSize, vector<int>& numbers, int size)
{
    for (int i=0 ; i<size ; i++) {
        insertHeapNode(heap,heapSize,numbers[i]);
    }
}

void heapSort(vector<int>& heap, int heapSize)
{
    for (int i=heapSize-1 ; i>=0 ; i--) {
        exchange(heap,i,0);
        heapify(heap,heapSize,i);
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

int main(int argc, char *argv[])
{
    vector<int> heap;
    int heapSize = 0;
    vector<int> numbers; 

    for (size_t i = 0; i < 10; i++)
    {
        numbers.push_back(rand() % 10 );
    }

    draw(numbers);
    buildHeap(heap,heapSize,numbers,10);
    draw(heap);
    heapSort(heap,heapSize);
    draw(heap);

    return 0;
}
