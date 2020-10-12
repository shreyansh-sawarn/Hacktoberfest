#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int bin_power(long long int base , long long int power)
{
    if(power==0)
    {
        return 1;
    }
    else
    {
        long long int temp = bin_power(base,power/2);
        if(power%2 == 0)
            return temp*temp;
        else
            return temp*temp*base;
    }
}
long long int mod_exp(long long int base , long long int power)
{
    if(power==0)
    {
        return 1;
    }
    else
    {
        long long int temp = mod_exp(base,power/2);
        if(power%2 == 0)
            return ((temp%mod)*(temp%mod))%mod;
        else
            return (((temp%mod)*(temp%mod))%mod * base )%mod;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int m,n;
    cin>>n>>m;
    long long int temp1 =  bin_power(2,m) - 1;
    long long int ans = mod_exp(temp1 , n);
    cout<<ans;



    return 0;
}
