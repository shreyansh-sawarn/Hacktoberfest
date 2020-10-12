#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin>>n>>s;
    vector<pair<int,int>> checker(n,{INT_MAX,INT_MAX});
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            int t=0;
            int j=i-1;
            if(j>=0)
            {
                for(j;j>=0;j--)
                {
                    if(s[j]=='-')
                    {
                        checker[j].first=min(checker[j].first,t);
                    }
                    else if(s[j]=='A'||s[j]=='B')
                    {
                        break;
                    }
                    ++t;
                }
            }
        }
        else if(s[i]=='B')
        {
            int t=0;
            int j=i+1;
            if(j<n)
            {
                for(j;j<n;j++)
                {
                    if(s[j]=='-')
                    {
                        checker[j].second = min(checker[j].second,t);
                    }
                    else if(s[j]=='B'||s[j]=='A')
                    {
                        break;
                    }
                    t++;
                }
            }
        }
    }
    int a_count=0;
    int b_count=0;
    for(int i=0;i<n;i++)
    {
        int x = checker[i].first;
        int y = checker[i].second;
        if(s[i]=='A')
        {
            a_count++;
        }
        else if(s[i]=='B')
        {
            b_count++;
        }
        if(s[i]=='-')
        {
            if(x>y)
            {
                b_count++;
            }
            else if(x<y)
            {
                a_count++;
            }
        }
    }
    if(a_count>b_count)
    {
        cout<<"A";
    }
    else if(b_count>a_count)
    {
        cout<<"B";
    }
    else
    {
        cout<<"Coalition government";
    }
}
