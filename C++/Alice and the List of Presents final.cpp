#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;

long long int mod_pow(long long int x, long long int y)
{
	if (y == 0)
		return 1;
	if (y % 2)
		return ( x * mod_pow(x, y - 1) ) % mod ;
	else
		return (mod_pow(x, y / 2) * mod_pow(x, y / 2)) % mod;
}

int main()
{
	long long int m, n, i, j;
	cin >> n >> m;
	cout << mod_pow( mod_pow(2, m ) - 1, n ) % mod << "\n";
	return 0;
}

