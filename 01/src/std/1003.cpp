//  马拉车预处理+dp （dp可以换成二分+哈希多个log） 
#include<bits/stdc++.h>
#define maxn 5005
#define int long long
using namespace std;
int d[maxn*2],g[maxn],f[maxn][maxn],R,ps[maxn],pt[maxn],mid,n,N,Ans;
char S[maxn],s[maxn*2],T[maxn],t[maxn];
signed main(){
	int Test;scanf("%lld",&Test);
	while (Test--){
		scanf("%s%s",S+1,T+1),n=strlen(S+1);reverse(T+1,T+n+1);
		Ans=R=mid=0;
		for (int i=1;i<=n;i++) s[i<<1]=S[i],s[i<<1|1]='#';
		s[0]='@',s[1]='#';N=n<<1|1;
		for (int i=1;i<N;i++) g[i]=d[i]=0;
		for (int i=1;i<N;i++){
			if (i<=R) d[i]=min(d[2*mid-i],R-i+1);
			else d[i]=1;
			while (s[i+d[i]]==s[i-d[i]]) d[i]++;
			if (i+d[i]-1>R) R=i+d[i]-1,mid=i;
			if (d[i]!=1) g[((i-d[i]+1)+1)/2]++,g[i/2+1]--;
		}
		int now=0;
		for (int i=1;i<=n;i++) now+=g[i],ps[i]=now;
		for (int i=1;i<=n;i++) t[i<<1]=T[i],t[i<<1|1]='#';
		for (int i=1;i<N;i++) g[i]=d[i]=0;
		t[0]='@',t[1]='#';N=n<<1|1;R=mid=0;
		for (int i=1;i<N;i++){
			if (i<=R) d[i]=min(d[2*mid-i],R-i+1);
			else d[i]=1;
			while (t[i+d[i]]==t[i-d[i]]) d[i]++;
			if (i+d[i]-1>R) R=i+d[i]-1,mid=i;
			if (d[i]!=1) g[((i-d[i]+1)+1)/2]++,g[i/2+1]--;
		}
		now=0;
		for (int i=1;i<=n;i++) now+=g[i],pt[i]=now;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) f[i][j]=(S[i]==T[j]? f[i-1][j-1]+1:0),Ans=Ans+f[i][j]*(ps[i+1]+pt[j+1]+1);
		printf("%lld\n",Ans);
	}
	return 0;
}
