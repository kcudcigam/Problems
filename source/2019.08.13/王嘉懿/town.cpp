#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,a,b,v[300001],d[300001],ans,fa[300001];
vector <int > nex[300001];
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void dp(int x)
{
	v[x]=1;
	for(int i=0;i<nex[x].size();i++)
	{
		int y=nex[x][i];
		if(v[y]) continue;
		dp(y);
		ans=max(ans,d[x]+d[y]+1);
		d[x]=max(d[x],d[y]+1);
	}
	
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
    read(n);
    for(register int i=1;i<=n;i++)
    fa[i]=i;
    int fathe;
    for(register int q=1;q<n;q++)
    {
    	memset(d,0,sizeof(d));
    	memset(v,0,sizeof(v));
    	ans=0;
    	read(a);read(b);
    	nex[a].push_back(b);
    	nex[b].push_back(a);
    	int aa=get(a),bb=get(b);
    	if(aa!=bb)
    	fa[aa]=bb;
    	
    	int t=get(a);
    	for(register int i=1;i<=n;i++)
    	{
    		if(get(i)==t)
    		dp(i);
		}
				cout<<ans<<endl;
	}
}
