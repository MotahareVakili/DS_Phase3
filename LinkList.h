#ifndef LINKLIST_H
#define LINKLIST_H

#endif // LINKLIST_H
template<typename T>
class  node
{
    template<typename Z>
    friend class link_list;
   T data;
    node<T> * next;


public:
    node(T d,node* next)
    {
        this->data=d;
        this->next=next;
    }

};
template<typename Z>
class link_list
{
    node<Z> * head;
    node<Z> *tail;
    int sz=0;


public:

    link_list()
    {
        head=nullptr;
    }

    Z first()
    {
         if(is_empty())
             return nullptr;
        return head->data;
    }

    Z remove_first()
    {
        if(is_empty())
            return nullptr;
        Z answer=head->data;
        node<Z> * tmp=head;
        head=head->next;
        delete tmp;
        sz--;

        return answer;
    }

    void push_front(Z d)
    {
        node<Z> * tmp=new node<Z>(d,head);
        head=tmp;
       sz++;

    }

    ~link_list()
    {
        node<Z>* tmp=head;
        while(tmp!=nullptr)
        {
            node<Z> * tp=tmp;
            tmp=tmp->next;
            delete tp;

        }
        head=nullptr;
    }

    int size()
    {
        return sz;
    }

    bool is_empty()
    {
        return sz==0;
    }

};
