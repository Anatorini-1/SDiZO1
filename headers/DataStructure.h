//
// Created by Marcin on 07.03.2023.
//

#ifndef P1_DATASTRUCTURE_H
#define P1_DATASTRUCTURE_H


class DataStructure {
public:
    virtual bool add(int) = 0;
    virtual int get(int) =0;
    virtual int find(int) = 0;
    virtual bool remove(int) =0;
    virtual void print() =0;
};


#endif //P1_DATASTRUCTURE_H
