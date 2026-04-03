#include<bits/stdc++.h>
using namespace std;
const int Maxn=1000000;
int T,n,sum;
bitset<Maxn+10> vis;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            vis[i]=false;
        for(int i=1,x;i<=n;i++)
        {
            cin>>x;
            if(x<=n) vis[x]=true;
        }
        for(int i=1;i<=n;i++)
            sum+=vis[i];
        cout<<sum<<"\n";
    }
    return 0;
}