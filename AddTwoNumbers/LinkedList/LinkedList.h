#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../Node/Node.h"

class LinkedList
{
    private:
        // the list will just hold a pointer to the first Node
        Node *first_node;
    public:
        LinkedList(int, Node*);
        void printlist();
        void addnode(int);
        void removenode(int);
        ~LinkedList();
};



#endif
