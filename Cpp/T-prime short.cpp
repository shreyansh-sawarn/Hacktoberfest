#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
vector<long long >isprime(MAX_SIZE , true);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long int N = 1000000;
    isprime[0] = false;
    isprime[1] = false;
	for (unsigned long long int p=2; p*p<=N; p++)
    {
        if (isprime[p] == true)
        {
            for (unsigned long long int i=p*p; i<=N; i += p)
                isprime[i] = false;
        }
    }

    unsigned long int t;
    cin>>t;
    while(t!=0)
    {
        unsigned long long int n;
        cin>>n;
        unsigned long long int sqrtn;
        sqrtn = sqrt(n);
        if(sqrtn*sqrtn == n && isprime[sqrtn]==true)
            cout<<"YES\n";
        else
            cout<<"NO\n";

        t--;
    }
    return 0;

}
