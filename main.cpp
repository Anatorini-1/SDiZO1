#include <iostream>
#include "headers/Array.h"
#include "headers/LinkedList.h"
using namespace std;
int main() {

    LinkedList* l = new LinkedList();
    l->add(1);
    l->add(2);
    l->add(3);
    l -> removeLast();
    l -> addLast(4);
    std::cout << l->find(2) << endl;
    l -> removeFirst();
    l ->addFirst(0);
    l -> addAt(1,5);
    std::cout << l->get(l->find(0)) << endl;
    l->print();


    return 0;
}
