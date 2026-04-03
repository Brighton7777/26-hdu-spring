#include<bits/stdc++.h>
using namespace std;
const int Maxn=2000000,Maxm=50000,Maxr=30;
int n,m,ans[Maxm+10];
int pos[Maxn+10];
int tr[Maxn+10];
map<int,int> mp[Maxr+5];
vector<vector<int> > pts[Maxr+5];
int len;
int lowbit(int x){return x&-x;}
void modify(int x){while(x<=len) tr[x]++,x+=lowbit(x); return;}
int query(int x){int sum=0; while(x>0) sum+=tr[x],x-=lowbit(x); return sum;}
struct node
{
    int p,q,r;
}cir[Maxn+10];
struct req
{
    int xa,ya,xb,yb;
}squ[Maxm+10];
vector<int> group[Maxr+5];
int k;
struct E
{
    int type;
    int p,l,r,w;
}eve[Maxn+Maxm*2+10];
bool cmp(E x,E y){return x.p==y.p?x.type==y.type?x.l==y.l?x.r<y.r:x.l<y.l:x.type<y.type:x.p<y.p;}
void read(int &x)
{
    x=0;
    bool fl=false;
    int ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') fl=true;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
    if(fl) x=-x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    read(T);
    while(T--)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        read(n),read(m);
        for(int i=1;i<=m;i++)
            ans[i]=0;
        for(int i=1;i<=Maxr;i++)
            group[i].clear();
        for(int i=1;i<=Maxr;i++)
            mp[i].clear();
        for(int i=1;i<=Maxr;i++)
            pts[i].clear();
        for(int i=1;i<=n;i++)
        {
            read(cir[i].p),read(cir[i].q),read(cir[i].r);
            if(mp[cir[i].r].find(cir[i].q)==mp[cir[i].r].end()) pts[cir[i].r].push_back({}),mp[cir[i].r][cir[i].q]=int(mp[cir[i].r].size());
            pts[cir[i].r][mp[cir[i].r][cir[i].q]].push_back(cir[i].p);
        }
        for(int i=1;i<=m;i++)
            read(squ[i].xa),read(squ[i].ya),read(squ[i].xb),read(squ[i].yb);
        for(int i=1;i<=n;i++)
            group[cir[i].r].push_back(i);
        for(int i=1;i<=Maxr;i++)
        {
            for(int j=0;j<int(mp[i].size());j++)
                sort(pts[i][j].begin(),pts[i][j].end());
            if(group[i].empty()) continue;
            k=0;
            for(int x:group[i])
                k++,eve[k]={-2,cir[x].q,cir[x].p,cir[x].p,0},pos[k]=cir[x].p;
            sort(pos+1,pos+k+1);
            len=unique(pos+1,pos+k+1)-pos-1;
            for(int j=1;j<=len;j++)
                tr[j]=0;
            for(int j=1;j<=m;j++)
            {
                k++,eve[k]={-1,squ[j].ya-1,squ[j].xa-i,squ[j].xb+i,j};
                k++,eve[k]={1,squ[j].yb,squ[j].xa-i,squ[j].xb+i,j};
                int q=i;
                for(int d=1;d<=i;d++)
                {
                    while(q*q+d*d>i*i) q--;
                    if(mp[i].find(squ[j].yb+d)!=mp[i].end()) ans[j]+=upper_bound(pts[i][mp[i][squ[j].yb+d]].begin(),pts[i][mp[i][squ[j].yb+d]].end(),squ[j].xb+q)-lower_bound(pts[i][mp[i][squ[j].yb+d]].begin(),pts[i][mp[i][squ[j].yb+d]].end(),squ[j].xa-q);
                    if(mp[i].find(squ[j].ya-d)!=mp[i].end()) ans[j]+=upper_bound(pts[i][mp[i][squ[j].ya-d]].begin(),pts[i][mp[i][squ[j].ya-d]].end(),squ[j].xb+q)-lower_bound(pts[i][mp[i][squ[j].ya-d]].begin(),pts[i][mp[i][squ[j].ya-d]].end(),squ[j].xa-q);
                }
            }
            sort(eve+1,eve+k+1,cmp);
            int npos;
            for(int j=1;j<=k;j++)
            {
                if(eve[j].type==-2)
                {
                    npos=lower_bound(pos+1,pos+len+1,eve[j].l)-pos;
                    modify(npos);
                }
                else
                {
                    npos=lower_bound(pos+1,pos+len+1,eve[j].l)-pos;
                    if(npos>1) ans[eve[j].w]-=query(npos-1)*eve[j].type;
                    npos=upper_bound(pos+1,pos+len+1,eve[j].r)-pos-1;
                    if(npos>0) ans[eve[j].w]+=query(npos)*eve[j].type;
                }
            }
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}