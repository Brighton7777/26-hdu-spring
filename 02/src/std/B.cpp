#include<bits/stdc++.h>
using namespace std;
const int Maxn=3000;
int n,cntx,cnty,x[Maxn+10],y[Maxn+10],f,r,q[Maxn+10],dx[Maxn+10],dy[Maxn+10];
vector<vector<int> > adj;
struct node
{
    int x,y;
    int dir,p;
}nums[Maxn+10];
bitset<Maxn+10> vis;
bool dfs_hungary(int u)
{
    for(int i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]])
        {
            vis[adj[u][i]]=true;
            if(y[adj[u][i]]==0)
            {
                y[adj[u][i]]=u;
                return true;
            }
            if(dfs_hungary(y[adj[u][i]]))
            {
                y[adj[u][i]]=u;
                return true;
            }
        }       
    }
    return false;
}
int hungary()
{
    int ans=0;
    for(int i=1;i<=cnty;i++)
        y[i]=0;
    for(int i=1;i<=cntx;i++)
    {
        vis=0;
        ans+=dfs_hungary(i);
    }
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>nums[i].x>>nums[i].y>>nums[i].dir;
        for(int i=1;i<=n;i++)
            nums[i].p=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(nums[i].x==nums[j].x&&nums[i].y<nums[j].y&&nums[i].dir==0&&nums[j].dir==0) nums[i].p=-1;
                if(nums[i].y==nums[j].y&&nums[i].x<nums[j].x&&nums[i].dir==1&&nums[j].dir==1) nums[i].p=-1;
                if(nums[i].x==nums[j].x&&nums[i].y>nums[j].y&&nums[i].dir==2&&nums[j].dir==2) nums[i].p=-1;
                if(nums[i].y==nums[j].y&&nums[i].x>nums[j].x&&nums[i].dir==3&&nums[j].dir==3) nums[i].p=-1;
            }
        cntx=cnty=0;
        for(int i=1;i<=n;i++)
        {
            if(nums[i].p==-1) continue;
            if(nums[i].dir&1)
            {
                cntx++;
                nums[i].p=cntx;
            }
            else
            {
                cnty++;
                nums[i].p=cnty;
            }
        }
        adj.clear();
        adj.resize(cntx+5);
        int e=0;
        for(int i=1;i<=n;i++)
        {
            if(nums[i].p==-1) continue;
            if(!(nums[i].dir&1)) continue;
            for(int j=1;j<=n;j++)
            {
                if(nums[j].p==-1) continue;
                if(nums[j].dir&1) continue;
                if((((nums[i].x<nums[j].x)^(nums[i].dir>>1))||(nums[i].x==nums[j].x))&&(((nums[i].y>nums[j].y)^(nums[j].dir>>1))||(nums[i].y==nums[j].y)))
                {
                    e++;
                    adj[nums[i].p].push_back(nums[j].p);
                }
            }
        }
        for(int i=1;i<=n;i++)
            vis[i]=false;
        for(int i=1;i<=cntx;i++)
            x[i]=dx[i]=0;
        for(int i=1;i<=cnty;i++)
            y[i]=dy[i]=0;
        cout<<cntx+cnty-hungary()<<endl;
    }
    return 0;
}