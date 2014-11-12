#ifndef STACK_H
#define STACK_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/* class Stack for DFS (Depth-First-Search) */
template<typename T>
class Stack
{
    /* structure for class Stack */
    struct Cell
    {
        T info; /* info of something (char, int, double) inside a Cell*/
        Cell *next;
    };

    Cell *top, *bottom;

public:

    Stack();
    ~Stack();
    bool IsEmpty();
    void Push(T);
    T Pop();
};

template<typename T>
Stack<T>::Stack()
{
    top = new Cell();
    bottom = top;
    top->next = NULL;
}

template<typename T>
Stack<T>::~Stack()
{
    delete top;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
    return (top == bottom);
}

template<typename T>
void Stack<T>::Push(T info)
{
    Cell *temp = new Cell();
    temp->info = info;
    temp->next = top;
    top = temp;
}

template<class T>
T Stack<T>::Pop()
{
    Cell *temp;
    T value;

    if (IsEmpty())
    {
        cout << "Stack is Emtpty" << endl;
    }
    else
    {
        temp = top;
        top = temp->next;
        value = temp->next->info; /* Recieve the new value of top*/
        delete temp;
    }

    return value;
}

#endif