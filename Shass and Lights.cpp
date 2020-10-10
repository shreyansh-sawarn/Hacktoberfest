#include <bits/stdc++.h>
using namespace std;



#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long



template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, long long m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = (ans * a) % m; b /= 2; a = (a * a) % m; } return ans % m; }



const int N = 2005;
const int MOD = 1e9 + 7;



int n, m;
int a[N], fact[N], invfact[N];



int modinv(int k)
{
    return pow(k, MOD - 2, MOD);
}



void precompute()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    invfact[N - 1] = modinv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= MOD;
    }
}



int32_t main()
{
    IOS;
    precompute();
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    a[0] = 0;
    a[m + 1] = n + 1;
    for (int i = 1; i <= m + 1; i++)
    {
        if (a[i] - a[i - 1] - 1 > 0)
            v.push_back(a[i] - a[i - 1] - 1);
    }
    int ans = fact[n - m];
    for (auto it : v)
    {
        ans *= invfact[it];
        ans %= MOD;
    }
    if (a[m] != n && v.size())
        v.pop_back();
    int idx = 0;
    if (a[1] != 1)
        idx++;
    for (; idx < v.size(); idx++)
    {
        ans *= pow(2LL, v[idx] - 1, MOD);
        ans %= MOD;
    }
    cout << ans;
}