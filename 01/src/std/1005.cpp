#include <bits/stdc++.h>
#define ll long long
using namespace std;
void Solve()
{
	ll N,K;
	cin>>N>>K;
	for(ll i=2;;i++)
	{
		bool flag=false;
		ll ans=1;
		for(int j=1;j<=K;j++)
		{
			ans*=i;
			if(ans>N)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			cout<<i-1<<endl;
			return;
		}
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		Solve();
	}
}
