#include <iostream>
#include "pqueue.h"
#include "pqueue.cpp"

using namespace std;

void displayMenu()
{
    cout<<"Main Menu"<<endl;
    cout<<"1: Print Delivery Locations"<<endl;
    cout<<"2: Enqueue Delivery"<<endl;
    cout<<"3: Dequeue Delivery"<<endl;
    cout<<"4: Print Queue"<<endl;
    cout<<"5: Sort Queue By Highest Delivery"<<endl;
    cout<<"6: Sort Queue By Lowest Delivery"<<endl;
    cout<<"7: Quit"<<endl;
}

/*
void buildNodes(string *stringarr)
{
    node *head = new node;
    node *x = head;
    for (int i = 0; i < stringarr->size(); i++)
    {

    }
}*/

int main()
{
    pqueue *Q = new pqueue(10);

    bool flag = true;
    while(flag)
    {
        displayMenu();
        int input;
        cin>>input;
        switch(input)
        {
            case 1:

            case 2:
            {
                string inputn = "";
                int inputp = 0;
                cout<<"Enter delivery location:"<<endl;
                cin >> inputn;
                cout<<"Enter delivery priority:"<<endl;
                cin >> inputp;
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
                    cin >> numd;
                    inputd.otherdlvr = new string[numd];
                    for (int i = 0; i < numd; i++)
                    {
                        cout<<"Enter delivery location:"<<endl;
                        cin >> inputn;
                        inputd.otherdlvr[i] = inputn;
                    }

                }
                Q->enqueue(inputd);
            }
            case 3:
            {
                delivery d = Q->dequeue();
                cout<<d.name<<endl;
            }
            case 4:
                Q->printQueue();
            case 5:
                Q->sortHighestPriority();
            case 6:
                Q->sortLowestPriority();
            case 7:
                cout<<"Goodbye!"<<endl;
                flag = false;
        }
    }

    Q->~pqueue();
}
