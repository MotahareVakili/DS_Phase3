#include "tnode.h"


Node::Node(QString d, Node *p, Node *l, Node *r)
{
    data =d;
    parent =p;
    left =l;
    right =r;
}

QString Node::get_data()
{
    return data;
}

Node *Node::get_parent()
{
    return parent;
}

Node *Node::get_left()
{
    return left;
}

Node *Node::get_right()
{
    return right;
}

void Node::set_data(QString d)
{
    data=d;
}

void Node::set_parent(Node *p)
{
    parent=p;
}

void Node::set_left(Node *l)
{
    left=l;
}

void Node::set_right(Node *r)
{
    right=r;
}
