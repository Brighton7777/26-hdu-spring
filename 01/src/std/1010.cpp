#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int M=1e5+5;
const int mod=998244353;

struct P
{
	int x,y;	
}b[M];
bool cmp(P a,P b)
{
	return a.x<b.x;
}

int fac[M],inv[M];
int _pow(int x,int ci)
{
	int now=x,ans=1;
	while(ci)
	{
		if(ci&1)ans=(ans*now)%mod;
		now=(now*now)%mod;
		ci>>=1;
	}
	return ans;
}
int c(int n,int m)
{
	if(n<0||m<0||m>n)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void init()
{
	fac[0]=inv[0]=1;
	for(int i=1;i<=M-5;i++)fac[i]=(fac[i-1]*i)%mod;
	inv[M-5]=_pow(fac[M-5],mod-2);
	for(int i=M-6;i>=1;i--)inv[i]=(inv[i+1]*(i+1))%mod;  
}

int t,n,m;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	init();
	cin>>t;
	while(t--)
	{
		int ans=1;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
			cin>>b[i].x>>b[i].y;
		sort(b+1,b+m+1,cmp);
		if(b[1].x!=1)ans=ans*(b[1].x-1)%mod*c(n-1-b[1].y,b[1].x-2)%mod*fac[b[1].x-2]%mod;
		else if(b[1].y!=n)ans=0;
		for(int i=2;i<=m;i++)
		{
			if(b[i].y>b[i-1].y)ans=0;
			if(b[i].y==b[i-1].y)ans=ans*c(n-1-b[i].y+1-(b[i-1].x-1),b[i].x-b[i-1].x)%mod*fac[b[i].x-b[i-1].x]%mod;
			else ans=ans*(b[i].x-b[i-1].x)%mod*c(n-1-b[i].y-(b[i-1].x-1),b[i].x-b[i-1].x-1)%mod*fac[b[i].x-b[i-1].x-1]%mod;
		}
		ans=ans*fac[(n-b[m].x+1)]%mod;
		cout<<ans<<endl;
	}
}
