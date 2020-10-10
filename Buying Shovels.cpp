#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,k;
        cin>>n>>k;
        unsigned long long int ans=0;
        for(unsigned long long int i=1;i*i<=(n);i++)
        {
            if (n % i == 0 )
            {
                    if(i<=k)
                        ans = max(ans,i);
                    if(n/i<=k)
                        ans = max(ans ,(n/i));
            }
        }
        cout<<n/ans<<"\n";

    }
    return 0;
}


