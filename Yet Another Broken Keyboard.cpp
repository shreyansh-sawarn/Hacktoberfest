#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    int avail;
    cin>>n>>avail;
    string s;
    cin>>s;
    vector<char> available(avail);
    for(int i=0;i<avail;i++)
        cin>>available[i];
    bool counts[n];
    memset(counts,false,sizeof(counts));
    for(long long int i=0;i<n;i++)
    {
        for(int j=0;j<avail;j++)
        {
            if(s[i] == available[j])
                counts[i] = true;
        }
    }
    vector<long long int>cluster;
    long long int mini = -1;
    long long int maxi =-1;
    for(long long int i=0;i<n;i++)
    {
        if(counts[i]==true)
        {
            if(maxi == -1)
                mini = i;
            maxi = i;
        }
        else
        {
            if(maxi != -1 )
                cluster.push_back((maxi-mini+1));
            maxi =-1;
            mini = -1;
        }
    }
    if(maxi != -1 )
        cluster.push_back((maxi-mini+1));


    long long int ans=0;
    for(long long int i=0; i< cluster.size();i++)
        ans += (cluster[i]*(cluster[i]+1))/2 ;
    cout<<ans;







    return 0;
}

