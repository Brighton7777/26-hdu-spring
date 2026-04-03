#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t,n,m; cin>>t;
    while(t--) {
        cin>>n>>m;
        if(n%2||m%2) cout<<(n*m+1)/2<<"\n";
        else cout<<n*m/2-min(n,m)<<"\n";
    }
}