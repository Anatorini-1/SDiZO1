#include <iostream>
#include "headers/Array.h"
#include "headers/LinkedList.h"
using namespace std;
int main() {

    LinkedList* l = new LinkedList();
    l->add(1);
    l->add(2);
    l->add(3);
    l->print();
    return 0;
}
