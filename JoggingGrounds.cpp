#include<bits/stdc++.h>
#include "cmath" 
#include <stdio.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define eb emplace_back
#define deb(x) cout<<"dBUG->"<<x<<endl
#define eps 1e-6
#define vll vector<long long int>
#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()
#define bye exit(0)
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
typedef long long int ll;


ll M=1e9+7;
double distance1_2(double r,double d0,double d1,double a1,double a2,double v1,double v2,double c1,double c2,double n)
{

  double move1=v1*n;
  double move2=v2*n;
  int check1=(int)(move1+a1);
  int check2=(int)(move2+a2);
  move1=(double)(check1%360);
  move2=(double)(check2%360);
double m=360;
  if(c1==1)
  {
   
   move1=m-move1;
  }
  if(c2==1)
  {
    move2=m-move2;
  }
  //deb(move1);
  double k=180;
  double pi=M_PI;
  move1=(pi*move1)/k;
  move2=(pi*move2)/k;
  //deb(move1);
  
//  deb(move1);
  double x1=d0+r*(cos(move1));
  //deb(x1);
  double y1=r*(sin(move1));
  double x2=d1+r*(cos(move2));
  double y2=r*(sin(move2));
  double p=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
  return p;
}
void solve()
  {
   double r,d1,d2,d3;
   cin>>r>>d1>>d2>>d3;
   double a1,a2,a3,a4;
   cin>>a1>>a2>>a3>>a4;
   double v1,v2,v3,v4;
   cin>>v1>>v2>>v3>>v4;
   double c1,c2,c3,c4;
   cin>>c1>>c2>>c3>>c4;
   double n;
   cin>>n;
   double d0=0;
   double p1=distance1_2(r,d0,d1,a1,a2,v1,v2,c1,c2,n);
    double p2=distance1_2(r,d1,d2,a2,a3,v2,v3,c2,c3,n);
    double p3=distance1_2(r,d2,d3,a3,a4,v3,v4,c3,c4,n);
   
    double p=p1+p2+p3;
    
    cout<<round(p);
  }


int main(){
    // Your code here!
  FAST;
     #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
   //here number of test case
  //  ll t;
    //  cin>>t;
    //while(t--)
        solve();
  

}
