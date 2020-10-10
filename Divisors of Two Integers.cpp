#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<long int > arr(n);
    for(int i=0;i< n ;i++)
        cin>>arr[i];
    unsigned long x = *max_element(arr.begin(),arr.end());
    vector<int> divx;

    for(unsigned long int i =1 ; i*i <= x ; i++)
    {
        if(x%i ==0)
        {
            if(i*i == x)
                divx.push_back(i);
            else
            {
                divx.push_back(i);
                divx.push_back((x/i));
            }
        }
    }
    for(int i =0 ;i<n ;i++)
    {
        for(unsigned long int j = 0 ; j< divx.size() ;j++)
        {
            if(arr[i] == divx[j])
            {
                arr[i] = -1;
                divx[j] = -1;
                break;
            }
        }
    }
    unsigned long int y = *max_element(arr.begin(),arr.end());
    cout<<x<<" "<<y;



    return 0;
}
