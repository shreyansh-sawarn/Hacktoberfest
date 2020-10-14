/*
4.Perform the following Stack operations using Linked List implementation.
    a)	Push
    b)	Pop
    c)	Clear
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std; 

//Node Class
class Node
{
    public:
        int data;
        Node* nextNode;
        //constructor
        Node(int data = 0, Node* nextNode = 0)
        {
            this->data = data;
            this->nextNode = nextNode;
        }
        //destructor
        ~Node()
        {
            cout<<"DESTROYING : "<<this->data<<"\n";
        }
};

//Stack Linked List Class
class StackLL
{
    private:
        Node *top,*temp;
        int totalNodes;
    public:
        //constructor
        StackLL()
        {
            top = temp = 0;
            totalNodes = 0;
        }
        //destructor
        ~StackLL()
        {
            temp = top;
            Node *nextNodePtr;
            while(temp != 0)
            {
                nextNodePtr = temp->nextNode;
                delete temp;
                temp = nextNodePtr;
            }
            cout<<"Done.\n";
        }
        //member functions
        int isEmpty();
        void clear();
        void display();
        void push(int x);
        void pop();
        void topElement();
};

//return the number of elements in the stack
int StackLL :: isEmpty()
{
    if(totalNodes)
    {
        return totalNodes;
    }
    return 0;
}

//clear the stack
void StackLL :: clear()
{
    cout<<"Clearing The Stack\n";
    temp = top;
    Node *nextNodePtr;
    while(temp != 0)
    {
        nextNodePtr = temp->nextNode;
        delete temp;
        temp = nextNodePtr;
    }
    top = temp = 0;
    totalNodes = 0;
    cout<<"Done.\n";
}

//display the stack
void StackLL :: display()
{
    if(isEmpty())
    {    
        temp = top;
        while(temp != 0)
        {
            cout<<temp->data<<" ";
            temp = temp->nextNode;
        }
        cout<<"\n";
    }
    else
    {
        cout<<"EMPTY\n";
    }
}

//push an element to the stack
void StackLL :: push(int x)
{
    temp = new Node(x,0);
    if(top == 0)
    {
        top = temp;
    }
    else
    {
        temp->nextNode = top;
        top = temp;
    }
    temp = 0;
    totalNodes++;
}

//pop and element from the Stack
void StackLL :: pop()
{
    if(top != 0)
    {
        temp = top;
        top = top->nextNode;
        delete temp;
        temp = 0;
        totalNodes--;
    }
}

//prints the top element of the Stack
void StackLL :: topElement()
{
    if(top != 0)
    {
        cout<<top->data;
    }
}


int main()
{
    StackLL *A = new StackLL();
    int choice;
    char flag;
    do
    {
        cout<<"\n";
        cout<<setw(12)<<setfill(' ')<<"STACK\n";
        cout<<setw(20)<<setfill('-')<<"\n";
        cout<<"top->";A->display();
        cout<<setw(20)<<setfill('-')<<"\n";
        cout<<"Operations : \n"
            <<"1. Push\n"
            <<"2. Pop\n"
            <<"3. Clear\n"
            <<"4. Top\n"
            <<"5. Exit\n";
        cout<<"Enter Choice : "; cin>>choice;
        switch (choice)
        {
        case 1:
            int temp;
            cout<<"Element : "; cin>>temp;
            A->push(temp);
            break;
        case 2:
            A->pop();
            break;
        case 3:
            A->clear();
            cout<<"Stack Cleared";
            getch();
            break;
        case 4:
            A->topElement();
            getch();
            break;
        case 5:
            flag = 'n';
            break;
        default:
            break;
        }
        system("CLS");
    } 
    while (flag != 'n');
    delete A;
    return 0;
}

