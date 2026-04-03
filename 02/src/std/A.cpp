#include<bits/stdc++.h>
using namespace std;
const int Maxn=1000000,mod=998244353;
int k,lens,lent;
char s[Maxn+100],t[Maxn+100];
unsigned sum,p2[Maxn+100],p3[Maxn+100],fs[Maxn+100],ft[Maxn+100],tmp,ms,mt,ns,nt;
int main()
{
	scanf("%d",&k);
	p2[0]=1;
	p3[0]=1;
	for(int i=1;i<=Maxn;i++)
	{
		p2[i]=p2[i-1]<<1;
		p2[i]%=mod;
		p3[i]=(p3[i-1]<<1)+p3[i-1];
		p3[i]%=mod;
	}
	while(k--)
	{
		scanf("%s %s",t,s);
		lens=strlen(s);
		lent=strlen(t);
		sum=0;
		fs[0]=1;
		tmp=1;
		ns=0;
		for(int i=0;i<lens;i++)
		{
			if(s[lens-i-1]-'0')
			{
				ns+=p2[i];
				tmp<<=1;
				tmp%=mod;
				tmp+=p3[i];
				tmp%=mod;
			}
			ns%=mod;
			fs[i+1]=tmp;			
		}
		ft[0]=1;
		tmp=1;
		nt=0;
		for(int i=0;i<lent;i++)
		{
			if(!(t[lent-i-1]-'0'))
			{
				tmp<<=1;
				tmp%=mod;
				tmp+=p3[i];
				tmp%=mod;
			}
			else nt+=p2[i];
			nt%=mod;
			ft[i+1]=tmp;
		}
		for(int i=lent;i<lens;i++)
		{
			tmp<<=1;
			tmp%=mod;
			tmp+=p3[i];
			tmp%=mod;
			ft[i+1]=tmp;
		}
		if(lent==1&&t[0]=='0')
		{
			sum=fs[lens];
			sum<<=1;
			sum%=mod;
			sum=(sum-ns+nt-1+mod)%mod;
			printf("%u\n",sum);
			continue;
		}
		ms=lens;
		mt=lent;
		while(lens>lent)
		{
			if(s[ms-lens]-'0')
			{
				sum+=fs[lens-1];
				sum%=mod;
				sum+=ft[lens-1];
				sum%=mod;
			}
			lens--;
		}
		while(lens>0)
		{
			if(!(s[ms-lens]-'0')&&t[mt-lent]-'0') break;
			if(s[ms-lens]-'0'&&!(t[mt-lent]-'0'))
			{
				sum+=fs[lens-1];
				sum%=mod;
				sum+=ft[lens-1];
				sum%=mod;
			}
			lens--;
			lent--;
		}
		if(lens==0&&lent==0)
		{
			sum++;
			sum%=mod;
		}
		sum<<=1;
		sum%=mod;
		sum=(sum-ns+nt-1+mod)%mod;
		printf("%u\n",sum);
	}
	return 0;
}