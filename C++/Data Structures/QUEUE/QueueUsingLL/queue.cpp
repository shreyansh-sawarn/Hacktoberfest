// Perform linear queues using Linked List implementation.
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

//class Node
class Node
{
    public:
        int data;
        Node *nextNode;
        //constructor
        Node(int data, Node* nextNode)
        {
            this->data = data;
            this->nextNode = nextNode;
        }
        //destructor
        ~Node()
        {
            cout<<"Destroyed "<<this->data<<"\n";
        }
};

class queueLL
{
    private:
        Node *head, *tail, *temp;
        int totalNodes;
    public:
        //constructor
        queueLL()
        {
           head = tail = temp = 0;
           totalNodes = 0; 
        }
        //destructor
        ~queueLL()
        {
            temp = head;
            Node* nextPtr = 0;
            while (temp != 0) 
            {
                nextPtr = temp->nextNode;
                delete temp;
                temp = nextPtr;
            }
            temp = nextPtr = 0;
            cout<<"Done\n";          
        }
        //member functions
        void enqueue(int x);
        void dequeue();
        void clear();
        void firstEle();
        int isEmpty();
        void display();
};

int queueLL :: isEmpty()
{
    if(totalNodes == 0)
        return 1;
    return 0;
}


void queueLL :: enqueue(int x)
{
    temp = new Node(x,0);
    if(tail == 0)
    {
        head = tail = temp;
    }
    else
    {
        tail->nextNode = temp;
        tail = temp;
    }
    temp = 0;
    totalNodes++;
    
}

void queueLL :: dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is Empty\n";
        getch();
    }
    else
    {
        if(head == tail)
        {
            temp = head;
            head = tail = 0;
        }
        else
        {
            temp = head;
            head = head->nextNode;
        }
        cout<<temp->data;
        delete temp;
        temp = 0;
        totalNodes--;
    }
}

void queueLL :: clear()
{
    if(!isEmpty())
    {
        temp = head;
        Node* nextPtr = 0;
        while(temp != 0)
        {
            nextPtr = temp->nextNode;
            delete temp;
            temp = nextPtr;
        }
        temp = nextPtr = head = tail = 0; 
        totalNodes = 0;
        cout<<"Queue Cleared\n";
        getch();
    }
}

void queueLL :: firstEle()
{
    if(!isEmpty())
    {
        cout<<head->data<<"\n";
        getch();
    }
}

void queueLL :: display()
{
    if(!isEmpty())
    {
        temp = head;
        while (temp != 0)
        {
            cout<<temp->data<<" ";
            temp = temp->nextNode;
        }
        cout<<"\n";
        temp = 0;
    }
    else
    {
        cout<<"EMPTY\n";
    }
    
}

int main()
{
    queueLL *Q = new queueLL();
    int choice;
    int flag = 1;
    do
    {
        cout<<"--------------------\n";
        cout<<"Queue -> ";Q->display();
        cout<<"--------------------\n"
            <<"Operations :\n"
            <<"1. enqueue(x)\n"
            <<"2. dequeue()\n"
            <<"3. clear()\n"
            <<"4. firstEle()\n"
            <<"5. Exit\n"
            <<"--------------------\n"
            <<"What do you want to do : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int temp;
            cout<<"Element : ";  cin>>temp;
            Q->enqueue(temp);
            break;
        case 2:
            Q->dequeue();
            break;
        case 3:
            Q->clear();
            break;
        case 4:
            Q->firstEle();
            break;
        case 5:
        default:
            flag = 0;
            break;
        }
        system("CLS");
    } while (flag);
    delete Q;
    return 0;
}