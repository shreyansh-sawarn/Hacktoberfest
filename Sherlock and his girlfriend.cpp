#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long int n;
    cin>>n;
    bool is_prime[n+101];
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(unsigned long int i=2;i*i<=n+100;i++)
    {
        if(is_prime[i] == true)
        {
            for(unsigned long int j = i*i;j<=n+100;j+=i)
            {
                is_prime[j] = false;
            }
        }

    }
    unsigned long int counts=0;
    unsigned long int npr=0,pr =0;
    for(unsigned long int i=2;i<=n+1;i++)
    {
        if(is_prime[i]== false)
            npr++;
        else
            pr++;
    }
    if(npr == 0)
    {
        cout<<"1\n";
    }
    else
        cout<<"2\n";

    for(unsigned long int i=2;i<=n+1;i++)
    {
        if(is_prime[i]==true)
            cout<<"1 ";
        else
            cout<<"2 ";
    }



    return 0;
}

