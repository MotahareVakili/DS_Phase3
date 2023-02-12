#ifndef TNODE_H
#define TNODE_H
#include"QString"

class Node
{
    friend class Binary_Tree;
    QString data;
    Node * parent;
    Node * left;
    Node * right;
public:
    Node(QString d,Node * p,Node * l,Node* r);
    QString get_data();
    Node * get_parent();
    Node * get_left();
    Node * get_right();
    void set_data(QString d);
    void set_parent(Node * p);
    void set_left(Node * l);
    void set_right(Node * r);
};

#endif // TNODE_H
