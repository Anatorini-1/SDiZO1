//
// Created by Marcin on 10.04.2023.
//

#ifndef SDIZO1_TESTER_H
#define SDIZO1_TESTER_H
#include <random>
#include <windows.h>
class Tester {
private:
    __int64  CounterStart;
    double PCFreq;
public:
    double *** testArray(int sizes[], int sizesCount, int iterations);
    double *** testDoubleLinkedList(int sizes[], int sizesCount, int iterations);
    double *** testBinaryHeap(int sizes[], int sizesCount, int iterations);
    double *** testRedBlackTree(int sizes[], int sizesCount, int iterations);
    void startCounter();
    double getCounter();
    Tester();
};


#endif //SDIZO1_TESTER_H
