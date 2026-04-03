#include<bits/stdc++.h>
using namespace std;
const int Maxn=1000000,Maxw=60;
int T,x,n;
int ans[Maxn+10];
long long k;
long long pw[Maxw+5];
int main(int argc,char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<Maxw;i++)
        pw[i]=(1ll<<i);
    cin>>T;
    while(T--)
    {
        cin>>x>>k;
        n=1,ans[1]=0;
        while(x>0)
        {
            ans[n]++;
            if(k==1)
            {
                n++,ans[n]=0;
                break;
            }
            if(x>Maxw||k<=pw[x-1]) n++,ans[n]=0,k--;
            else k-=pw[x-1];
            x--;
        }
        for(int i=1;i<n;i++)
        {
            cout<<ans[i];
            if(i+1<n) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}