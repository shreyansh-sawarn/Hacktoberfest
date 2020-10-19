#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define mod 1000000007
#define inf 1e18
const int N = 300005;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
void cs(int &x)
{
    cout << "Case #" << x << ": ";
}
bool cmp(string a, string b)
{
    return a + b < b + a;
}
int32_t main()
{
    fastIO;
    int t; cin >> t;
    int x = 1;
    while (t--)
    {
        int n, k; cin >> n >> k;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int r = -1, val = INT_MAX;
        for (auto i : v)
        {
            if (i <= k && (k - i) % i == 0 && (k - i) / i < val)
            {
                r = i;
                val = (k - i) / i;
            }
        }
        cout << r << endl;
    }
    return 0;
}
