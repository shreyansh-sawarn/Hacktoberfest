#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;

    int find(int parent[],int x){
        //base case
        if(parent[x]==-1){
            return x;
        }
        return find(parent,parent[x]);
    }

    void union_set(int a,int b,int parent[],int s1,int s2){
            parent[s2]=s1;
    }

    public:
        Graph(int V){
            this->V=V;
        }
        
        void addEdge(int u,int v){
            l.push_back(make_pair(u,v));
        }

        bool contains_cycle(){
            int *parent=new int[V];
            for(int i=0;i<V;i++){
                parent[i]=-1;
            }

            //iterate and connect edge
            for(auto edge:l){
                int a=edge.first;
                int b=edge.second;
                int s1=find(parent,a);
                int s2=find(parent,b);
                if(s1!=s2){
                    union_set(a,b,parent,s1,s2);
                }else{
                    return true;
                }
            }
            delete []parent;
            return false;
        }

};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    //g.addEdge(3,0);
    cout<<g.contains_cycle()<<endl;
}