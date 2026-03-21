/**
 * 题目：炼金术士的配方
 * 数据范围：N <= 2e5, Val <= 1e6
 * 算法：筛法预处理 + 异或哈希 + 前缀和计数
 */
#include <iostream>
#include <vector>
#include <random>
#include <unordered_map> 
#include <map> 
using namespace std;
typedef unsigned long long ull;
const int M=1000005;//值域
ull hsh[M];
bool vis[M];
mt19937_64 rg(random_device{}());
void init_sieve(){
    for(int i=2;i<M;i++){
		if(!vis[i]){
			hsh[i]=rg();
			for(int j=i+i;j<M;j+=i){
				hsh[j]=hsh[j/i]^hsh[i];
				vis[j]=1;
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init_sieve();
    int N,X;cin>>N>>X;
    ull tar=hsh[X];
    unordered_map<ull, int> mp;
    mp.reserve(N);
    mp[0]=1;
    ull cur=0;
    long long ans=0;
    for (int i=0,val;i<N;++i){
        cin>>val;
        cur^=hsh[val];
        ull need=cur^tar;
        if(mp.count(need)) ans+=mp[need];
        mp[cur]++;
    }
    cout<<ans<<endl;
    return 0;
}
