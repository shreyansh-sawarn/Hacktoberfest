#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long int , long long int> a , pair<long long int , long long int> b)
{
    return (max(a.first,a.second)< max(b.first,b.second));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int x;
    cin>>x;
    long long int n1 = x;
    long long int n2 =  x;
    long long int sum = n1 + n2;
    vector<pair<long long int , long long int>> arr;

    for(long long int i=1;i*i<=x;i++)
    {
        if(x%i ==0)
        {

            if(__gcd(i,(x/i))== 1)
            {
                arr.push_back({i,(x/i)});
            }


        }

    }
    sort(arr.begin(),arr.end(),compare);
    cout<<arr[0].first<<" "<<arr[0].second;





    return 0;
}

