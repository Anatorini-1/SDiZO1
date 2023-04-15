

#include "RBTree.h"
#include <iostream>
#include <iomanip>
void RBTree::add(int elem) {
    /*Step 1: Create a new Node, color it RED(true)*/
    Node* newNode = new Node;
    newNode->value = elem;
    newNode->left = nil;
    newNode->right = nil;
    newNode->parent = nil;
    newNode->color = true;

    /*Step 2:Perform regular BST insertion*/
    if (root == 0){
        root = newNode;
        root->color = 0;
        root->parent = nil;
        len++;
        return;
    }
    Node* currentNode = root;
    while (true){
        if (elem < currentNode->value){
            if (currentNode->left == nil){
                currentNode->left = newNode;
                newNode->parent = currentNode;
                break;
            }
            currentNode = currentNode->left;
        } else {
            if (currentNode->right == nil){
                currentNode->right = newNode;
                newNode->parent = currentNode;
                break;
            }
            currentNode = currentNode->right;
        }
    }
    this->len++;
    /*Step 3 : Validate the RBTree properties and fix if necessary*/
    repairInsert(newNode);


}

void RBTree::del(int val) {
    /*Step 1: Regular BST deletion*/
    Node* toDel = find(val);
    del(toDel);
}
void RBTree::del(Node *toDel) {
    bool orgColor = toDel->color;
    //Case 0: value not found in the tree -> do nothing
    if (toDel == nil){
        return;
    }
        //Case 1: toDel has no children -> delete it and set parent's child to nil
    else if (toDel->left == nil && toDel->right == nil){
        if (toDel->parent->left == toDel){
            toDel->parent->left = nil;
        } else {
            toDel->parent->right = nil;
        }
        if(toDel == root){
            root = nil;
            return;
        }

        delete toDel;
    }
        //Case 2: toDel has one child -> swap the toDel's value with the child's value -> delete the child
    else if(toDel->left == nil && toDel->right != nil){
        auto* tmp = toDel->right;
        toDel->value = toDel->right->value;
        toDel->right = toDel->right->right;
        toDel->right->parent = toDel;
        delete tmp;
    }
    else if (toDel->left != nil && toDel->right == nil){
        auto* tmp = toDel->left;
        toDel->value = toDel->left->value;
        toDel->left = toDel->left->left;
        toDel->left->parent = toDel;
        delete tmp;
    }
        //Case 3: toDel has two children -> swap the toDel's value with the predecessor's value -> delete the predecessor
    else {
        Node* predecessor = this->predecessor(toDel);
        toDel->value = predecessor->value;
        if (predecessor->parent->left == predecessor){
            predecessor->parent->left = nil;
        } else {
            predecessor->parent->right = nil;
        }
        del(predecessor);
    }


    /*Step 2: Validate the RBTree properties and fix if necessary*/
    if(orgColor == RED) return;
    repairDelete(toDel);

}


RBTree::Node* RBTree::find(int val) {
    Node* currentNode = root;
    while (currentNode != nil){
        if (currentNode->value == val){
            return currentNode;
        } else if (currentNode->value > val){
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    return nil;
}

RBTree::RBTree() {
    root = 0;
    nil = new Node;
    nil->left = nil;
    nil->right = nil;
    nil->parent = nil;
    nil->color = 0;
    nil->value = -1;
    len=0;
}

RBTree::~RBTree() {

}

void RBTree::print() {
    std::cout <<'[';
    printTree(root);
    std::cout <<']';
    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void RBTree::printTree(Node* node){
    if (node == nil || node == 0){
        return;
    }
    printTree(node->left);
    std::cout << '(' <<node->value << ')';
    printTree(node->right);

}

void RBTree::leftRotate(RBTree::Node *x) {
    Node* y = x->right;
    x->right = y->left;
    if(y->left != nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil){
        root = y;
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

}

void RBTree::rightRotate(RBTree::Node *x) {
    Node* y = x->left;
    x->left = y->right;
    if(y->right != nil){
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil){
        root = y;
    } else if(x == x->parent->right){
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}


void RBTree::recolor(RBTree::Node *x) {
    x->color = !x->color;

}


RBTree::Node *RBTree::getUncle(RBTree::Node *x) {
    if(x->parent == NULL || x->parent->parent == NULL) {
        return NULL;
    }
    if(x->parent == x->parent->parent->left) {
        return x->parent->parent->right;
    } else {
        return x->parent->parent->left;
    }
}

RBTree::Node *RBTree::getGrandparent(RBTree::Node *x) {
    if(x->parent == NULL || x->parent->parent == NULL) {
        return NULL;
    }
    return x->parent->parent;
}

RBTree::Node *RBTree::getSibling(RBTree::Node *x) {
    if(x->parent == NULL) {
        return NULL;
    }
    if(x == x->parent->left) {
        return x->parent->right;
    } else {
        return x->parent->left;
    }
}

void RBTree::repairInsert(RBTree::Node *n) {
    //Case 1: n == root
    if(n == root){
        n->color = false;
        return;
    }
    //Case 2: Parent is black -> all good
    auto p = n->parent;
    auto g = getGrandparent(n);
    auto s = getSibling(n);
    auto u = getUncle(n);
    //Case 3: Parent is red -> problem
    if(p->color){
        //Case 3.1 P and U are RED
        if(u!= nil && u->color){
            recolor(p);
            recolor(u);
            recolor(g);
            repairInsert(g); //Handle the case of G being root
        }
        //Case 3.2 P is RED, U is BLACK (or NIL)
        else{
            //Case 3.2.1 P is right child of G, N is right child of P
            if(n == n->parent->right && n->parent == n->parent->parent->right){
                leftRotate(g);
                g->color = RED;
                p->color = BLACK;
            }
            //Case 3.2.2 P is right child of G and N is left child of P
            else if(p == g->right && n == p->left){
                rightRotate(p);
                repairInsert(p);
            }
            //Case 3.2.3 P is left child, N is left child
            else if(p == g->left && n == p->left){
                rightRotate(g);
                g->color = RED;
                p->color = BLACK;
            }
            //Case 4: P is left child, N is right child
            else if(p == g->left && n == p->right){
                leftRotate(p);
                repairInsert(p);
            }
        }
    }
}

void RBTree::repairDelete(RBTree::Node *x) {
    while (x != root && x->color == 0) {
        if (x == x->parent->left) {
            auto s = x->parent->right;
            if (s->color == 1) {
                // case 3->1
                s->color = 0;
                x->parent->color = 1;
                leftRotate(x->parent);
                s = x->parent->right;

            }

            if (s->left->color == 0 && s->right->color == 0) {
                // case 3->2
                s->color = 1;
                x = x->parent;
            } else {
                if (s->right->color == 0) {
                    // case 3->3
                    s->left->color = 0;
                    s->color = 1;
                    rightRotate(s);
                    s = x->parent->right;

                }

                // case 3->4
                s->color = x->parent->color;
                x->parent->color = 0;
                s->right->color = 0;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            auto s = x->parent->left;
            if (s->color == 1) {
                // case 3->1
                s->color = 0;
                x->parent->color = 1;
                rightRotate(x->parent);
                s = x->parent->left;

            }

            if (s->left->color == 0 && s->right->color == 0) {
                // case 3->2
                s->color = 1;
                x = x->parent;
            } else {
                if (s->left->color == 0) {
                    // case 3->3
                    s->right->color = 0;
                    s->color = 1;
                    leftRotate(s);
                    s = x->parent->left;

                }

                // case 3->4
                s->color = x->parent->color;
                x->parent->color = 0;
                s->left->color = 0;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

RBTree::Node *RBTree::predecessor(RBTree::Node *n) {
    if(n->left != nil){
        return findMax(n->left);
    }
    else {
        auto y = n->parent;
        while(y != nil && n == y->left){
            n = y;
            y = y->parent;
        }
        return y;
    }
}

RBTree::Node *RBTree::successor(RBTree::Node *n) {
    if(n->right != nil){
        return findMin(n->right);
    }
    else {
        auto y = n->parent;
        while(y != nil && n == y->right){
            n = y;
            y = y->parent;
        }
        return y;
    }

}

RBTree::Node *RBTree::findMin(RBTree::Node *n) {
    while(n->left != nil){
        n = n->left;
    }
    return n;
}

RBTree::Node *RBTree::findMax(RBTree::Node *n) {
    while(n->right != nil){
        n = n->right;
    }
    return n;
}


