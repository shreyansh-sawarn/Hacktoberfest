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
    long long int ans=0;
    int temp =1;
    for(long long int len=1;len<=n;len++)
    {

        for(long long int i=0;i<(n-len + 1);i++)
        {
            temp = 1;

            for(long long int j=i;j<=(i+len-1);j++)
            {
                    if(counts[j] == false)
                    {
                        temp =0;
                        i = j;
                        break;
                    }

            }

            if(temp==1)
                ans++;
        }

    }
    cout<<ans;




    return 0;
}

