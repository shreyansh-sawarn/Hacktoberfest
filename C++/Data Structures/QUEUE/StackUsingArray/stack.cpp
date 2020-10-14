/*
5.Perform the following Stack operations using Array implementation using Templates:
    a)	Push
    b)	Pop
    c)	Clear
*/


#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Stack
template <typename T>
class Stack
{
    private:
        T *S;
        int size;
        int top;
    public:
        //constructor
        Stack()
        {
            size = 10;
            top = -1;
            S = new T[size];
            for(int i = 0; i < size; i++)
            {
                S[i] = i;
            }
        }
        //Destructor
        ~Stack()
        {
            delete[] S;
        }
        //member functions
        int isEmpty();
        void clear();
        void display();
        void push(T x);
        void push();
        void pop();
        void topElement();
};

//to check whether the Stack is Empty or Not
template <typename T>
int Stack<T> :: isEmpty()
{
    if(top == -1)
    {
        return 0;
    }
    return top;
}

//to clear the Stack and set top=-1
template <typename T>
void Stack<T> :: clear()
{
    top = -1;
}

//to display the stack
template <typename T>
void Stack<T> :: display()
{
    if(top != -1)
    {
        for(int i = 0; i <= top; ++i)
        {
            cout<<S[i]<<" ";
        }
    }
    else
    {
        cout<<"EMPTY";
    }
    cout<<"\n";
}

//to push an element on the Stack
template <typename T>
void Stack<T> :: push(T x)
{
    //check whether the Stack is full or not and move forward accordingly
    if(top == (size-1))
    {
        size = size * 2;
        T* tempArray = new T[size];
        for(int i = 0; i <=top; ++i)
        {
            tempArray[i] = S[i];
        }
        //deleting the original array and replacing it with the new one
        delete[] S;
        S = tempArray;
    }
    S[++top] = x;
}

//to push an element on the Stack (overloaded push)
template <typename T>
void Stack<T> :: push()
{
    cout<<"Element : ";
    T x;
    cin>>x;
    //check whether the Stack is full or not and move forward accordingly
    if(top == (size-1))
    {
        size = size * 2;
        T* tempArray = new T[size];
        for(int i = 0; i <=top; ++i)
        {
            tempArray[i] = S[i];
        }
        //deleting the original array and replacing it with the new one
        delete[] S;
        S = tempArray;
    }
    S[++top] = x;
}

//to pop an element from the array
template <typename T>
void Stack<T> :: pop()
{
    if(top != -1)
    {
        S[top--];
    }
}

//return the top most element of the Stack
template <typename T>
void Stack<T> :: topElement()
{
    if(top > -1)
    {
        cout<<S[top];
    }
}

int main()
{
    Stack<int> *A = new Stack<int>();
    int choice;
    char flag;
    do
    {
        cout<<"\n";
        cout<<setw(12)<<setfill(' ')<<"STACK\n";
        cout<<setw(20)<<setfill('-')<<"\n";
        A->display();
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
            A->push();
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