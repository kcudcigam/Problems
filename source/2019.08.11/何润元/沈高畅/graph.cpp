#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	return f; 
}
int r;
bool vis[3001];
vector<int> vec[3003];
vector<int> qz[3003];
inline bool check(int l,int x)
{
	if(vis[x]) return 0;
	vis[x]=1;
	if(x==r) return 1;
	bool p=0;
	for(int i=0;i<vec[x].size();i++)
		{
			if(qz[x][i]>l) continue;
			p=max(p,check(l,vec[x][i]));
		}
	return p;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m,q;
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=m;i++)
		{
			int a,b,c;
			a=read();
			b=read();
			c=read();
			vec[a].push_back(b);
			vec[b].push_back(a);
			qz[a].push_back(c);
			qz[b].push_back(c);
		}
	for(int i=1;i<=q;i++)
		{
			int l;
			l=read();
			r=read();
			int ll=0,rr=1000000,ans=-1;
			while(ll<=rr)
				{
					int mid=(ll+rr)>>1;
//					cout<<mid<<endl;
					memset(vis,0,sizeof(vis));
					if(check(mid,l)) ans=mid,rr=mid-1;
					else ll=mid+1;
				}
			cout<<ans<<endl;
		}
	return 0;
}


