#include <iostream>
#include "pqueue.h"
#include "pqueue.cpp"
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void displayMenu()
{
    cout<<"Main Menu"<<endl;
    cout<<"1: Print Message Locations"<<endl;
    cout<<"2: Enqueue Delivery"<<endl; //displays menu for program
    cout<<"3: Dequeue Delivery"<<endl;
    cout<<"4: Print Queue"<<endl;
    cout<<"5: Sort Queue By Highest Delivery"<<endl;
    cout<<"6: Sort Queue By Lowest Delivery"<<endl;
    cout<<"7: Quit"<<endl;
}

void transmit(delivery d, node *head)
{
    node *x = head;
    while (x != NULL)   //sends dequeued message through node network to show it was dequeued
    {
        cout<<x->name<<" received "<<d.name<<"."<<endl;
        x = x->n;
    }
}

node * buildNodes()
{
    string * stringarr = new string[3]; //builds a simple array of nodes to dequeue messages from
    stringarr[1] = "Boulder";
    stringarr[0] = "Louisville";
    stringarr[2] = "Lafayette";
    node *head = new node;
    head->name = stringarr[0];
    node *x = new node;
    x->name = stringarr[1];
    head->n = x;
    node *y = new node;
    y->name = stringarr[2];
    x->n = y;
    y->n = NULL;


    return head;
}

int main()
{
    pqueue *Q = new pqueue(10);


    node *head = buildNodes();

    bool flag = true;
    while(flag)
    {
        displayMenu(); //while user runs program
        int input;
        cin>>input;
        if (input == 1)
        {
            node *x = head; //run through list of nodes
            while (x != NULL)
            {
                cout<<x->name<<endl;
                x = x->n;
            }
        }
        if (input == 2)
        {
            string inputn = "";
            string inputtemp;
            int inputp = 0;
            cout<<"Enter delivery location:"<<endl;
            cin.ignore();
            getline(cin, inputn);
            cout<<"Enter delivery priority:"<<endl;
            cin.ignore();
            getline(cin, inputtemp); //takes in deliver name and priority, and puts them in delivery inputd
            inputp = atoi(inputtemp.c_str());
            delivery inputd;
            inputd.priority = inputp;
            inputd.name = inputn;
            cout<<"Do you want to add additional deliveries to this location? Y/N:"<<endl;
            string yn;
            cin >> yn;
            if (yn == "Y")
            {
                cout<<"How many additional deliveries do you want to add?"<<endl;
                int numd;
                cin >> numd; //if additional delivers wanted at location, make an array and run through it adding user inputs
                inputd.otherdlvr = new string[numd]; //for as many times as the user desires
                for (int i = 0; i < numd; i++)
                {
                    cout<<"Enter delivery location:"<<endl;
                    cin >> inputn;
                    inputd.otherdlvr[i] = inputn;
                }
            }
            Q->enqueue(inputd);
        }
        if (input == 3)
        {
            delivery d = Q->dequeue(); //dequeue and transmit deliver that was dequeued
            if (d.name != "")
            {
                transmit(d, head);
            }
        }
        if (input == 4)
            Q->printQueue();
        if (input == 5)
            Q->sortHighestPriority();
        if (input == 6)
            Q->sortLowestPriority();
        if (input == 7)
        {
            cout<<"Goodbye!"<<endl;
            flag = false;
        }

    }
        //quit program and free pqueue memory
    Q->~pqueue();
}
