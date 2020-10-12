#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
vector<long long >isprime(MAX_SIZE , true);
vector<unsigned long long >prime;
vector<unsigned long long >triplet;
int binarySearch(int l, int r, int x)
{

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (triplet[m] == x)
            return m;
        if (triplet[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long int N = 1000000;
    isprime[0] = false;
    isprime[1] = false;
	for (long long int i=2; i<N ; i++)
	{
		if (isprime[i])
		{
			prime.push_back(i);
		}
		for (long long int j=0; j < (int)prime.size() && i*prime[j] < N; j++)
		{
			isprime[i*prime[j]]=false;
		}
	}

    for(unsigned long long int i=0 ;i< prime.size();i++)
    {
        {
            triplet.push_back((prime[i])*(prime[i]));
        }
    }
    sort(triplet.begin(),triplet.end());

    unsigned long int t;
    cin>>t;
    while(t!=0)
    {
        unsigned long long int n;
        cin>>n;
        int result = binarySearch(0 , (triplet.size() - 1) , n);
        (result == -1) ? cout << "NO\n" : cout << "YES\n";
        t--;
    }
    return 0;

}
