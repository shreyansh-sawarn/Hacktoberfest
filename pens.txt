#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,kk;
        cin>>n>>k;
        kk=k;
        string s,p1,p2;
        cin>>s;
        vector<vector <char>> vec;
        vector <char> tmp;
        vector <string> str;
        string ok;
        while (kk--)
        {
            cin>>ok;
            str.emplace_back(ok);
        }
        char c;
        for(int i=0;i<str.size();++i)
        {
            for(int j=0;j<str[i].length();++j)
            {
                c=str[i][j];
                tmp.emplace_back(c);
            }
            vec.emplace_back(tmp);
            tmp.erase(tmp.begin(),tmp.end());
        }
        for(int i=0;i<n;++i)
        {
            c=s[i];
            for(int j=0;j<k;++j)
            {
                size_t found=str[j].find(c);
                if(found!=string::npos)
                {
                    cout<<j+1<<" ";
                    break;
                }
            }
        }
         cout<<"\n";
    }
    return 0;
}