#include "binary_tree.h"


void Binary_Tree::pre(Node *tmp)
{
    if(tmp==nullptr)
        return;
   preorder=preorder+tmp->get_data()+" ";
    pre(tmp->get_left());
    pre(tmp->get_right());

}

void Binary_Tree::post(Node *tmp)
{
    if(tmp==nullptr)
        return;
    post(tmp->get_left());
    post(tmp->get_right());
    postorder=postorder+tmp->get_data()+" ";

}

void Binary_Tree::in(Node *tmp)
{
    if(tmp==nullptr)
        return;
    in(tmp->get_left());
   inorder=inorder+tmp->get_data()+" ";
    in(tmp->get_right());
}

void Binary_Tree::level()
{
    QQueue<Node*> q;
    q.enqueue(root);
    while (!q.empty())
    {
        Node * tmp=q.dequeue();
        level_order=level_order+tmp->get_data()+" ";
        if(tmp->get_left()!=nullptr)
            q.enqueue(tmp->get_left());
        if(tmp->get_right()!=nullptr)
            q.enqueue(tmp->get_right());
    }
}

void Binary_Tree::post_to_tree(QString *postfix)
{
    QStringList qsl=postfix->split(" ");
    linked_stack<Node*> st;
    QString oprator="+-*^/";
    QString oprator2="_stc";
    for(QString value:qsl)
    {
        if(oprator.contains(value))
        {
            Node* right=st.pop();
            Node* left=st.pop();
            Node * parent=new Node(value,nullptr,left,right);
            left->set_parent(parent);
            right->set_parent(parent);
            st.push(parent);
        }
        else if(oprator2.contains(value))
        {
            Node* right=st.pop();
            QString v;
            switch (value.at(0).toLatin1())
            {
            case '_':v="_";break;
            case  's':v="sin";break;
            case 'c':v="cos";break;
            case 't':v="tan";break;
            }
            Node* parent=new Node(v,nullptr,nullptr,right);
            right->set_parent(parent);
            st.push(parent);
        }
        else
        {
            Node * operand=new Node(value,nullptr,nullptr,nullptr);
            st.push(operand);
        }
    }
    root=st.pop();
    in(root);
    pre(root);
    post(root);
    level();

}



