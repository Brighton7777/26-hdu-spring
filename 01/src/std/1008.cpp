#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=1e6+50;

int N,M,Q;
ll a[MAXN];

ll gcd(ll a,ll b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
ll LCM[MAXN];
void Solve()
{
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<=N;i++)
	{
		LCM[i]=1;
	}
	for(int i=1;i<=M;i++)
	{
		int x,y;
		ll g;
		scanf("%d%d%lld",&x,&y,&g);
		LCM[x]=LCM[x]/gcd(LCM[x],g)*g;
		LCM[y]=LCM[y]/gcd(LCM[y],g)*g;
	}
	
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",gcd(LCM[x],LCM[y]));
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Solve();
	}
	
}
