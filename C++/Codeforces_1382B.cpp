#include<bits/stdc++.h>
using namespace std;
 int main()
 {int t;long long i;
   cin>>t;
   while(t--)
    {long long n;long long countt=0;
      cin>>n;
        long long a[n];
        for(i=0;i<n;i++)
            {cin>>a[i];}
          for(i=0;i<n;i++)
          {
              countt++;
              if(a[i]>1)
              {
                  break;
              }
          }
if(countt%2==0)
    cout<<"Second"<<endl;
else
    cout<<"First"<<endl;}}
