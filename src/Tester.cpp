//
// Created by Marcin on 10.04.2023.
//

#include "Tester.h"
#include "Array.h"
#include "DoubleLinkedList.h"
#include "Heap.h"
#include "RBTree.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
double *** Tester::testArray(int sizes[], int sizesCount, int iterations) {
    double *** res = new double**[sizesCount];
    for(int i=0;i<sizesCount;i++){
        res[i] = new double*[7];
        for(int j=0;j<7;j++){
            res[i][j] = new double[iterations];
        }
    }
    for(int i=0;i<sizesCount;i++){
        cout << "Testing array of size " << sizes[i] << "\n";
        auto* arr = new Array();
        arr->fill(sizes[i],0);
        cout << "Array filled\n";
        double time;
        int index;

        for(int j=0;j<iterations;j++){
            startCounter();
            arr->addFirst(1);
            time = getCounter();
            res[i][0][j] = time;

            startCounter();
            arr->delFirst();
            time = getCounter();
            res[i][1][j] = time;

            startCounter();
            arr->addLast(1);
            time = getCounter();
            res[i][2][j] = time;

            startCounter();
            arr->delLast();
            time = getCounter();
            res[i][3][j] = time;

            index = rand() % sizes[i];
            startCounter();
            arr->addAtIndex(index,1);
            time = getCounter();
            res[i][4][j] = time;

            startCounter();
            arr->delIndex(index);
            time = getCounter();
            res[i][5][j] = time;

            startCounter();
            arr->find(1);
            time = getCounter();
            res[i][6][j] = time;
        }
        delete arr;
    }
    return res;
}


double *** Tester::testDoubleLinkedList(int *sizes, int sizesCount, int iterations) {
    double *** res = new double**[sizesCount];
    for(int i=0;i<sizesCount;i++){
        res[i] = new double*[7];
        for(int j=0;j<7;j++){
            res[i][j] = new double[iterations];
        }
    }
    for(int i=0;i<sizesCount;i++){
        cout << "Testing list of size " << sizes[i] << "\n";
        auto* list = new DoubleLinkedList();
        for(int j=0;j<sizes[i];j++)
            list->addLast(0);
        cout << "List filled\n";
        double time;
        int index;
        int precents = 0;
        for(int j=0;j<iterations;j++){
            if(j*100/iterations > precents){
                cout << j*100/iterations << "%\n";
                precents = j*100/iterations;
            }
            startCounter();
            list->addFirst(1);
            time = getCounter();
            res[i][0][j] = time;

            startCounter();
            list->delFirst();
            time = getCounter();
            res[i][1][j] = time;

            startCounter();
            list->addLast(1);
            time = getCounter();
            res[i][2][j] = time;

            startCounter();
            list->delLast();
            time = getCounter();
            res[i][3][j] = time;

            index = rand() % sizes[i];
            startCounter();
            list->addAtIndex(index,1);
            time = getCounter();
            res[i][4][j] = time;

            startCounter();
            list->delIndex(index);
            time = getCounter();
            res[i][5][j] = time;

            startCounter();
            list->find(1);
            time = getCounter();
            res[i][6][j] = time;
        }
        delete list;
    }
    return res;
}

double *** Tester::testBinaryHeap(int *sizes, int sizesCount, int iterations) {
    double *** res = new double**[sizesCount];
    for(int i=0;i<sizesCount;i++){
        res[i] = new double*[3];
        for(int j=0;j<3;j++){
            res[i][j] = new double[iterations];
        }
    }
    for(int i=0;i<sizesCount;i++){
        cout << "Testing list of size " << sizes[i] << "\n";
        auto* heap = new Heap();
        int percent = 0;
        for(int j=0;j<sizes[i];j++){
            if(j*100/sizes[i] > percent){
                cout <<"Filling "<<sizes[i] << " | " << j*100/sizes[i] << "%\n";
                percent = j*100/sizes[i];
            }
            heap->add(j);
        }

        cout << "Heap filled\n";
        double time;
        int index;
        int precents = 0;
        for(int j=0;j<iterations;j++){
            if(j*100/iterations > precents){
                cout << j*100/iterations << "%\n";
                precents = j*100/iterations;
            }
            startCounter();
            heap->add(1);
            time = getCounter();
            res[i][0][j] = time;

            startCounter();
            heap->del(sizes[i]-1);
            time = getCounter();
            res[i][1][j] = time;


            startCounter();
            heap->find(-1);
            time = getCounter();
            res[i][2][j] = time;
        }
        delete heap;
    }
    return res;
}

double *** Tester::testRedBlackTree(int *sizes, int sizesCount, int iterations) {
    double *** res = new double**[sizesCount];
    for(int i=0;i<sizesCount;i++){
        res[i] = new double*[3];
        for(int j=0;j<3;j++){
            res[i][j] = new double[iterations];
        }
    }
    for(int i=0;i<sizesCount;i++){
        cout << "Testing list of size " << sizes[i] << "\n";
        auto* heap = new RBTree();
        int percent = 0;
        for(int j=0;j<sizes[i];j++){
            if(j*100/sizes[i] > percent){
                cout <<"Filling "<<sizes[i] << " | " << j*100/sizes[i] << "%\n";
                percent = j*100/sizes[i];
            }
            heap->add(j);
        }

        cout << "RBTree filled\n";
        double time;
        int index;
        int precents = 0;
        for(int j=0;j<iterations;j++){
            if(j*100/iterations > precents){
                cout << j*100/iterations << "%\n";
                precents = j*100/iterations;
            }
            startCounter();
            heap->add(1);
            time = getCounter();
            res[i][0][j] = time;

            startCounter();
            heap->del(sizes[i]-1);
            time = getCounter();
            res[i][1][j] = time;


            startCounter();
            heap->find(-1);
            time = getCounter();
            res[i][2][j] = time;
        }
        delete heap;
    }
    return res;
}

void Tester::startCounter() {
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";
    PCFreq = double(li.QuadPart)/1000.0;
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double Tester::getCounter(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

Tester::Tester() {
    CounterStart = 0;
    PCFreq = 0.0;
    startCounter();
    srand(time(0));
}
