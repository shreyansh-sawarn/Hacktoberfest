#include <iostream>
#include <stack>
using namespace std;
class Mystack{
    private:
        stack<int> s;
    public:
        int minEle;
        void pushIn(int d){
            if(s.empty()){
                s.push(d);
                minEle=d;
            }else{
                if(d>=minEle){
                    s.push(d);
                }else{
                    s.push(2*d-minEle);
                    minEle=d;
                }
            }
        }

        void popOut(){
            if(s.empty()){
                cout<<"Empty"<<endl;
                return;
            }
            int t=s.top();
            s.pop();
            if(t<minEle){
                cout<<minEle;
                minEle=2*minEle-t;
                return;
            }
            cout<<t<<endl;

        }   
};
int main(){
   Mystack s1;
   s1.pushIn(1);
   s1.pushIn(5);
   cout<<s1.minEle<<endl;
}