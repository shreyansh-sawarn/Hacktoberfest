#include<bits/stdc++.h>
using namespace std;
void fun();
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    fun();
    return 0;
}
void fun()
{
    ll n,k;
    cin>>n>>k;
    if(n%k==0)
    {
    ll first,second;
    first=n/k;
    ll tmp;
    tmp=first;
    if(tmp%k==0)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
    }
}