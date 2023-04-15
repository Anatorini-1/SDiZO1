#include <iostream>
#include <ctime>
#include "src/Array.h"
#include "src/DoubleLinkedList.h"
#include "src/Heap.h"
#include "src/RBTree.h"
#include "random"
#include "src/UI.h"
#include <windows.h>
#include "src/Tester.h"
#include <fstream>
#include <iomanip>
using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void startCounter() {
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main() {

    auto t = new Tester();
    int sizes[] = {100,500,1000,2000,5000,10000};
    int sizesCount = 6;
    int iterations = 500;
    double *** times = t->testRedBlackTree(sizes,sizesCount,iterations);
    double avg[6][7];
    ofstream file;
    file.open("rbtree.csv");
    cout << "Times calculated\n";
    for(int i=0;i<sizesCount; i++){
        for(int j=0;j<3;j++){
            double sum = 0;
            for(int k=0;k<iterations;k++){
                sum += times[i][j][k];
            }
            avg[i][j] = sum/(double)iterations;
        }
    }
    cout << "Averages calculated\n";

    file << "Size;Add;Del;Find;\n";
    file << std::fixed;
    for(int i=0;i<sizesCount;i++){
        file << sizes[i] << ";";
        for(int j=0;j<3;j++){
            file << avg[i][j] << ";";
        }
        file << "\n";
    }
    file.close();

    return 0;
}
