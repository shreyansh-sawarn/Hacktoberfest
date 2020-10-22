#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<int> &s1,int n){
       if(n==1){
           return;
       }
       stack<int>s2;

       int t=s1.top();
       s1.pop();
       for(int i=1;i<n;i++){
           s2.push(s1.top());
           s1.pop();
       }
       s1.push(t);
       while(!s2.empty()){
           s1.push(s2.top());
           s2.pop();
       }
       return reverse(s1,n-1);
}
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

void insertatbottom(stack<int> &s,int top){
     //base case
     if(s.empty()){
         s.push(top);
         return;
     }
     //rec case
     int x=s.top();
     s.pop();
     insertatbottom(s,top);
     s.push(x);
     return;

}

void reverseRec(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    int top=s.top();
    s.pop();
    reverseRec(s);
    insertatbottom(s,top);
}

int main(){
   stack<int> s1;
   for(int i=0;i<6;i++){
       int d;
       cin>>d;
       s1.push(d);
   }
   reverse(s1,s1.size());
   showstack(s1);


}