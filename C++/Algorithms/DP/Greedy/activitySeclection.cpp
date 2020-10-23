#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int>p2){
    return p1.second<p2.second;
}

int max_activities(vector<pair<int,int>>v,int n)
{
    sort(v.begin(),v.end(),compare);
    int ans=1;
    pair<int,int> prev=v[0];
    for(int i=1;i<n;i++){
        if(v[i].first>=prev.second){
            ans++;
            prev=v[i];
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }
    cout<<max_activities(v,n);
}