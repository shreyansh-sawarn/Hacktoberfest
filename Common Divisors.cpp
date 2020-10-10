#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int n;
    cin>>n;
    vector<long long int>arr(n);
    for(long int i=0;i<n;i++)
        cin>>arr[i];

    long long int result= arr[0];
    for (long long int i = 1; i < n; i++)
    {
         result = gcd(arr[i], result);
    }
    long long int ans=0;
    for(long int i=1;i*i<=result;i++)
    {
        if(result%i==0)
        {
            if(i*i == result)
                ans++;
            else
                ans+=2 ;
        }
    }
    cout<<ans;



    return 0;
}

