#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long int n;
    cin>>n;
    vector< int > arr(n);
    unsigned long int no_of_ones =0 , no_of_twos =0;
    for(unsigned long int i=0;i<n;i++ )
    {
        int x;
        cin>> x;
        arr[i] =x;
        if(x==1)
            no_of_ones++;
        if(x==2)
            no_of_twos++;
    }
    vector<int> ans(n);
    if(no_of_twos == 0 || no_of_ones == 0)
    {
        for(unsigned int i=0;i<n;i++)
            ans[i] = arr[i];
    }


    else
    {
        ans[0] = 2;
        ans[1] = 1;
        no_of_twos--;
        no_of_ones--;
        unsigned int w=2;
        while(no_of_twos >0)
        {
            ans[w] = 2;
            w++;
            no_of_twos--;
        }
        while(no_of_ones > 0)
        {
            ans[w] = 1;
            w++;
            no_of_ones--;
        }

    }
    for(unsigned int i =0 ;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;
}

