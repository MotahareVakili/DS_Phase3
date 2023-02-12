#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "tnode.h"
#include "QQueue"
#include "Stck.h"

class Binary_Tree
{

 Node * root=nullptr;
public:
    QString preorder="";
    QString postorder="";
    QString inorder="";
    QString level_order="";

    void pre(Node* tmp);
    void post(Node* tmp);
    void in(Node* tmp);
    void level();
    void post_to_tree(QString * postfix);

};

#endif // BINARY_TREE_H
