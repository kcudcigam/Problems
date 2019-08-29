#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y,z,f[300002],ans,k,k2,rk,tr[300002];
pair<int,pair<int,int> > p[300002],duck[300002];
pair<int,int> l,xl[300002];
map <pair<int,int> ,int> mm;
int fd(int zyx)
{
	if(f[zyx]=zyx) return zyx;
	return f[zyx]=fd(f[zyx]);
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>y) swap(x,y);
		l.first=x;l.second=y;
		if(mm[l]==0) 
		{
			k++;
			mm[l]=k;
			p[k].first=z;p[k].second.first=x,p[k].second.second=y;
			tr[x]++;tr[y]++;
		}
		else
		{
			if(z<p[mm[l]].first) p[mm[l]].first=z;
		}
	}
	sort(p+1,p+k+1);
	for(int i=1;i<=n;i++) f[i]=i;rk=0;
	for(int i=1;i<=n;i++) if(tr[i]!=0) rk++;
	memset(xl,0,sizeof(xl));
	for(int i=1;i<=k;i++)
	{
		if(fd(f[p[i].second.first])!=fd(f[p[i].second.second]))
		{
			k2++;
			duck[k2]=p[i];
			if(xl[p[i].second.first].first==0)xl[p[i].second.first].first+=k2;    
			else xl[p[i].second.first].second+=k2;
			if(xl[p[i].second.second].first==0) xl[p[i].second.second].first+=k2;
			else xl[p[i].second.second].second+=k2;
		    f[fd(f[p[i].second.second])]=fd(f[p[i].second.first]);
			f[p[i].second.second]=fd(f[p[i].second.first]);
		}
		if(k2==rk-1) break;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		if(xl[x]>xl[y])
		{
			if(xl[y].first==0) printf("%d\n",-1);
			else printf("%d\n",duck[xl[x].first].first);
		}
		else
		{
			if(xl[x].first==0) printf("%d\n",-1);
			else printf("%d\n",duck[xl[y].first].first);
		}
	}
	return 0;
}


