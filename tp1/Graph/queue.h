#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/* class Queue for BFS (Breadth-First-Search) */
template<class T>
class Queue
{
	/* structure for class Queue */
    struct Cell
    {
        T info; /* using int for vertex's number or can use other type*/
        Cell *next;
    };

    Cell *front, *rear;

public:

    Queue();
    ~Queue();
    bool IsEmpty();
    void Enqueue(T);
    T Dequeue();
};

template<class T>
Queue<T>::Queue()
{
    front = NULL;
    rear = NULL;
}

template<class T>
Queue<T>::~Queue()
{
    delete front;
}

template<class T>
bool Queue<T>::IsEmpty()
{
    return (front == NULL);
}


template<class T>
void Queue<T>::Enqueue(T info)
{
    Cell *temp = new Cell();
    temp->info = info;
    temp->next = NULL;

    if (front == NULL) /* Empty queue*/
    {
        front = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}

template<class T>
T Queue<T>::Dequeue()
{
    Cell *temp = new Cell();
    T value;

    if (front == NULL)
    {
        cout << "Queue is Emtpty" << endl;
    }
    else
    {
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
}

#endif