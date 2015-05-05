#ifndef PQUEUE_H
#define PQUEUE_H
#include <string>

struct node
{
    node *n;
    std::string name;

};

struct delivery
{
    int priority;
    std::string *otherdlvr;
    std::string name;
};

class pqueue
{
    public:
        pqueue(int qsize);
        ~pqueue();
        void enqueue(delivery a);
        delivery dequeue();
        void printQueue();
        void sortLowestPriority();
        void sortHighestPriority();
        void addDeliveryLocation(std::string str);
        delivery * getQueue();
        delivery searchQueue(std::string name);
        node *headOfDelivery;
    private:
        //node *head;
        //node *tail;
        int qHead;
        int qTail;
        int qSize;
        delivery * arrayQ;
        delivery nil;



};

#endif // PQUEUE_H
