#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while(t--){
    	int n,k;cin>>n>>k;
    	if(n>=k){
    		cout<<"-1\n";
    		continue;
		}
		int now=1,sum=0;
		map<int,int>mp;
		mp[0]=1;
		for(int i=1;i<=n;i++){
			while(mp.count((sum+now)%k))now++;
			cout<<now<<" ";
			sum=(sum+now)%k;
			mp[sum]=1;
			now++;
		}
		cout<<endl;
	}
}
