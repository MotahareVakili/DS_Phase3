#ifndef STACK_H
#define STACK_H
#endif // STACK_H
#include "LinkList.h"


template <typename T>
class linked_stack
{

public:

    link_list<T> ll;


int size()
{
     return ll.size();
}

bool is_empty()
{
    return ll.is_empty();
}

void push(T data)
{
    ll.push_front(data);
}

T top()
{
    return ll.first();
}

T pop()
{
    return ll.remove_first();
}

};
