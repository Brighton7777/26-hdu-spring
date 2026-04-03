#include<bits/stdc++.h>
using namespace std;
long long a[200006], s[200006];
int main(){
    ios::sync_with_stdio(false);
    int t = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n-1;i++) s[i] = s[i-1] + a[i];
        long long mn = 0, mnpos = 0;
        for(int i=1;i<=n-1;i++){
            if(s[i] < mn){
                mn = s[i];
                mnpos = i;
            }
        }
        cout<<mnpos+1<<endl;
    }
}
