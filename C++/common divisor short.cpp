#include<bits/stdc++.h>
using namespace std;

long long divisor(long long n){
    long long i,c=0;
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            c+=2;
        }
        if(i*i==n) c--;
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long gcd=a[0];
    for(int i=1;i<n;i++){
        gcd=__gcd(gcd,a[i]);
    }
    cout<<divisor(gcd)<<endl;
}
