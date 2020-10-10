#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int n,k,m=0;
    cin>>n>>k;
    long long int a[n],d[n-1];
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==k)
    {
        cout<<0<<"\n";
        return 0;
    }
    for(long int i=0;i<n;i++)
    {
        d[i-1]=(a[i]-a[i-1]);
    }
    sort(d,d+n-1);

    long long int sum=0;

    for(long int i=n-k-1;i>=0;i--)
    {
        sum+=d[i];
    }
    cout<<sum<<"\n";
    return 0;
}

