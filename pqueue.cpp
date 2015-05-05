#include "pqueue.h"
#include <iostream>
#include <string>
using namespace std;

inline pqueue::pqueue(int qsize)
{
    qSize = qsize;
    qHead = 0;
    qTail = 0;
    arrayQ = new delivery[qSize];
    for (int i = 0; i < qSize; i++)
        arrayQ[i] = nil;
}

inline pqueue::~pqueue()
{
    arrayQ = NULL;
    delete arrayQ;
}

inline void pqueue::enqueue(delivery a)
{
    if (qTail == qSize)
    {
        cout<<"Queue full"<<endl;
        return;
    }
    arrayQ[qTail] = a;
    qTail++;
}

inline delivery * pqueue::getQueue()
{
    return arrayQ;
}

inline delivery pqueue::searchQueue(string name)
{
    for (int i = 0; i < qSize; i++)
    {
        if (arrayQ[qSize].name == name)
            return arrayQ[qSize];
    }
}

inline delivery pqueue::dequeue()
{
    int countr = 0;
    for (int i = 0; i < qSize; i++)
    {
        if (arrayQ[i].name == "")
            countr++;
    }
    if (countr == qSize)
    {
        cout<<"Array empty"<<endl;
        return nil;
    }

    delivery dequeued = arrayQ[qHead];

    delivery *copyarr = arrayQ;
    qHead++;
    for (int i = qHead; i < qSize; i++)
    {
        copyarr[i] = arrayQ[i];
    }
    arrayQ = copyarr;

    return dequeued;
}

inline void pqueue::printQueue()
{
    for (int i = 0; i < qSize; i++)
    {
        cout<<"City to be delivered to: "<<arrayQ[i].name<<", Priority:"<<arrayQ[i].priority<<" "<<endl;
    }
}

inline void pqueue::sortHighestPriority()
{
    delivery temp;

    for (int i = 0; i < qHead-1; i++)
    {
        for (int j = 0; j < qHead-i-1; j++)
        {
            if (arrayQ[j].priority > arrayQ[j+1].priority)
            {
                temp = arrayQ[j];
                arrayQ[j] = arrayQ[j+1];
                arrayQ[j+1] = temp;
            }
        }
    }
}

inline void pqueue::sortLowestPriority()
{
    delivery temp;

    for (int i = 0; i < qHead-1; i++)
    {
        for (int j = 0; j < qHead-i-1; j++)
        {
            if (arrayQ[j].priority < arrayQ[j+1].priority)
            {
                temp = arrayQ[j];
                arrayQ[j] = arrayQ[j+1];
                arrayQ[j+1] = temp;
            }
        }
    }
}


inline void pqueue::addDeliveryLocation(string string_locToADD)
{
    node *placeToADD = new node;
    placeToADD->name = string_locToADD;
    placeToADD->n = NULL;
    placeToADD->n = headOfDelivery;
    headOfDelivery = placeToADD;
}
