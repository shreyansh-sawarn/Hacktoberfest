#include <bits/stdc++.h>
using namespace std;
const long int MAX = 2750140;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool is_prime[MAX+1];
    long int spf[MAX+1];
    for(long int i=0 ; i<= MAX ;i++)
        spf[i] = i;
    vector<long int>prime;
    prime.push_back(2);
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(long int i=2;i*i<=MAX;i++)
    {
        if(is_prime[i] == true)
        {
            for(long long int j = i*i;j<=MAX;j+=i)
            {
                is_prime[j] = false;
                if(spf[j]== j)
                    spf[j] = i;
            }
        }

    }
    for(long long int i=2;i<=MAX;i++)
    {
        if(is_prime[i]==true)
            prime.push_back(i);
    }
    set <long int ,greater <long int> >compositeset;
    set<int>primeinputset;
    vector<int>freq(MAX,0);
    vector<int>sol;
    long int n;
    cin>>n;
    for(long long int i =0 ;i< 2*n;i++)
    {
        long int x;
        cin>>x;
        freq[x]++;
        if(is_prime[x]==true)
            primeinputset.insert(x);
        else
            compositeset.insert(x);
    }
    vector<long int>primeinput(primeinputset.size());
    copy( primeinputset.begin(), primeinputset.end(),primeinput.begin());
    vector<long int>composite(compositeset.size());
    copy( compositeset.begin(), compositeset.end(),composite.begin());
    for(long int i=0 ; i<composite.size();i++)
    {
        long int t = composite[i];
        while(freq[t] > 0 && freq[t/spf[t]]>0)
        {
            freq[t]--;
            freq[t/spf[t]]--;
            sol.push_back(t);
        }
    }
    for(long int i=0 ; i<primeinput.size();i++)
    {
        long int t = primeinput[i];
        while(freq[t]>0 and freq[prime[t]]>0)
        {
            freq[t]--;
            freq[prime[t]]--;
            sol.push_back(t);
        }
    }
    for(long int i=0 ; i<sol.size();i++)
        cout<<sol[i] << " ";



    return 0;
}
