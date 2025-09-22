#ifndef NODE_H
#define NODE_H

class Node
{
    private:
        int x;
        Node *nextNode;

    public:
        Node(Node*, int);
        void setx(int);
        void setptr(Node*);
        int getx();
        Node* getptr();
        ~Node();
};


#endif
