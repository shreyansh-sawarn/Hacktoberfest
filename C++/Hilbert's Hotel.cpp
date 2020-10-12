#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t;
    cin>>t;
	while(t--)
	{
		long int n;
		cin >> n;
		long int arr[n];
		vector<long int>vis(n, 0);

		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			long int x = (arr[i] % n + n) % n;
			x = (x + i) % n;
			vis[x]++;
		}

		string ans = "YES";

		for (long int i = 0; i < n; ++i)
		{
			if (vis[i] == 0)
				ans = "NO";
		}

		cout << ans << '\n';
	}
	return 0;
}
