#include<bits/stdc++.h>
using namespace std;
struct pos{int x,y,w;};
int vis[410][410];
void solve(){
    int n;cin>>n;
    vector<int> x(n+1),y(n+1);
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    memset(vis,0,sizeof(vis));
    queue<pos>q;
    q.push({0,0,0});
    int ans=-1;
    while(!q.empty()){
        auto [dx,dy,w]=q.front();
        q.pop();
        if(dx==0&&dy==0&&w!=0){
            ans=w;
            break;
        }
        for(int i=1;i<=n;i++){
            int fx=dx+x[i],fy=dy+y[i];
            if(fx>=-200&&fx<=200&&fy>=-200&&fy<=200&&vis[fx+200][fy+200]==0){
                vis[fx+200][fy+200]=1;
                q.push({fx,fy,w+1});
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--) solve();
}
