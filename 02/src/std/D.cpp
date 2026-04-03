#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        for(int i=1;i<=n-2;i++) cout<<1<<" ";
        cout<<2<<" "<<n+k<<endl;
    }
}
