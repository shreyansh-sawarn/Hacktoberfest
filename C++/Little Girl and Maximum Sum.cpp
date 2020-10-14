#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    long long int q;
    cin>>n>>q;
    vector<long long int>arr(n);
    for(long long int i =0;i<n;i++)
        cin>>arr[i];
    vector<pair<long long int, long long int >>query(q);
    for(long long int i=0;i<q;i++)
        cin>>query[i].first>>query[i].second;
    vector<long long int>countsarr(n);
    fill(countsarr.begin(), countsarr.end(), 0);
    for(long long int j =0;j<q;j++)
    {
        countsarr[query[j].first -1]++;
        if(query[j].second < n)
            countsarr[query[j].second]--;
    }
    vector<long long int>counts(n);
    counts[0] = countsarr[0];
    for(long long int i =1;i<n;i++)
        counts[i] = counts[i-1] + countsarr[i];

    sort(counts.begin(),counts.end());
    sort(arr.begin(),arr.end());
    long long int sum =0;
    for(long long int i=0;i<n;i++)
        sum += arr[i] * counts[i];
    cout<<sum;
    return 0;
}
