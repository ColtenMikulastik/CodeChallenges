
#include "Node.h"

Node::Node(Node *t_nextNode = nullptr, int t_x = 10)
{
    this->x = t_x;
    this->nextNode = t_nextNode;
}

void Node::setx(int t_x)
{
    this->x = t_x;
}

void Node::setptr(Node *t_nextNode)
{
    this->nextNode = t_nextNode;
}

int Node::getx()
{
    return this->x;
}

Node *Node::getptr()
{
    return this->nextNode;
}

Node::~Node()
{}
