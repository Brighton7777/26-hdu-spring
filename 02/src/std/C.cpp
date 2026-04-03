#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+5;
int a[N];

#define ls (k<<1)
#define rs ((k<<1)|1)
#define mid ((l+r)>>1)
int mx[N<<2],id[N<<2];

void pushup(int l,int r,int k) {
    if (mx[ls]>mx[rs]) id[k]=id[ls],mx[k]=mx[ls];
    else id[k]=id[rs],mx[k]=mx[rs];
}
void build(int l,int r,int k) {
    if (l==r) {
        mx[k]=a[l];
        id[k]=l;
        return ;
    }
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushup(l,r,k);
}
void update(int l,int r,int k,int x,int v) {
    if (l==r) {
        mx[k]=v;
        return ;
    }
    if (x<=mid) update(l,mid,ls,x,v);
    else update(mid+1,r,rs,x,v);
    pushup(l,r,k);
}
pair<int,int> query(int l,int r,int k,int L,int R) {
    if (L<=l&&r<=R) return {mx[k],id[k]};
    if (r<L||R<l) return {0,0};
    return max(query(l,mid,ls,L,R),query(mid+1,r,rs,L,R));
}

void solve() {
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    for (int i=2;i<=n;i++) {
        int l=n/i*i;
        int ans=0;
        vector<int> upd;
        if (l!=n) {
            auto [v,id]=query(1,n,1,l+1,n);
            ans+=v;
            update(1,n,1,id,0);
            upd.push_back(id);
        }
        for (int j=l;j>=i;j-=i) {
            auto [v,id]=query(1,n,1,j-i+1,n);
            ans+=v;
            update(1,n,1,id,0);
            upd.push_back(id);
        }
        for (auto j:upd) update(1,n,1,j,a[j]);
        cout<<ans<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T; while (T--) solve();
}