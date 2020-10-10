#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n,m,t;
    cin>>n>>m>>t;
    long long int a[3], g =__gcd(n,m);
    a[1]=n/g;
    a[2]=m/g;
    while(t!=0)
    {
    	long long int x,y,u,v;
    	cin>>x>>y>>u>>v;
    	long long int c1=y/a[x]+(y%a[x]!= 0);
    	long long int c2=v/a[u]+(v%a[u]!= 0);
    	if(c1==c2)
            cout<<"YES\n";
    	else
            cout<<"NO\n";
        t--;
    }

    return 0;
}
