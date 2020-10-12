#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int test, num, t = 1, choose;

    cin>>test;

    while (test--)
    {

        cin>>num;

        vector <long long int> vc1(num), vc2;

        for(long long int i = 0; i < num; i++)
        {
            cin>>vc1[i];
        }

        sort(vc1.begin(), vc1.end());

        long long int ans = vc1[0] * vc1[num - 1];

        for(long long int i = 2; i * i <= ans; i++)
        {
            if(ans % i == 0)
            {
                vc2.push_back(i);
                if(i != ans / i)
                {
                    vc2.push_back(ans / i);
                }
            }
        }

        sort(vc2.begin(), vc2.end());

        if(vc1 == vc2)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << "-1" << "\n";
        }
    }

    return 0;
}
