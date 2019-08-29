#include<bits/stdc++.h>
using namespace std;
int i,f[300005],d[300005],h[300005],k[300005][22],l[300005][22],n,m,q,x,y,z,o,p;
vector<int> b[300005],c[300005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > a;
int read()
{
	int f=1,s=0;
	char c=getchar();
	while (c<'0'||c>'9') {
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9') {
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
 } 
void dg(int p,int fa)
{
	d[p]=d[fa]+1;
	h[p]=1;
	k[p][0]=fa;
	for (int i=0;i<b[p].size();i++)
	if (b[p][i]==fa) l[p][0]=c[p][i]; 
	for (int i=1;i<=20;i++)
	{
		k[p][i]=k[k[p][i-1]][i-1];
		l[p][i]=max(l[p][i-1],l[l[p][i-1]][i-1]);
	}
	for (int i=0;i<b[p].size();i++)
	if (b[p][i]!=fa) dg(b[p][i],p); 
}
int g(int n)
{
	if (f[n]==n) return n;
	return f[n]=g(f[n]);
}
int main(){
  freopen("graph.in","r",stdin);
  freopen("graph.out","w",stdout);
  n=read();m=read();q=read();
  for (i=1;i<=m;i++)
  {
  	x=read();y=read();z=read();
  	a.push(make_pair(z,make_pair(x,y)));
  }
  for (i=1;i<=n;i++)
  f[i]=i;
  for (i=1;i<=n;i++)
  {
  	if (a.size()>0) {
  	x=a.top().second.first; y=a.top().second.second;
	 z=a.top().first; a.pop();
    }
	 while (g(x)==g(y)&&a.size()>0)
	 {
	 	x=a.top().second.first; y=a.top().second.second;
	    z=a.top().first; a.pop();
	  } 
	 if (g(x)!=g(y)) {
	 	b[x].push_back(y);
	 	c[x].push_back(z);
	 	b[y].push_back(x);
	 	c[y].push_back(z);
	 	f[g(x)]=g(y);
	 }
  }
  for (i=1;i<=n;i++)
  {
  	if (h[i]==0) {
  		d[i]=0;
  		dg(i,i);
	  }
  }
  for (i=1;i<=q;i++)
  {
  	x=read(); y=read();
  	if (g(x)!=g(y)) printf("%d\n",-1);
  	else {
  		o=0; p=0;
  		if (d[x]<d[y]) swap(x,y);
  		for (int j=20;j>=0;j--)
  		if (d[k[x][j]]>d[y]) {
		  o=max(o,l[x][j]);x=k[x][j]; 
	    }
	    for (int j=20;j>=0;j--)
  		if (k[x][j]!=k[y][j]) {
		  o=max(o,l[x][j]);x=k[x][j];
		  p=max(p,l[p][j]);y=k[y][j]; 
	    }
	    o=max(o,l[x][0]); p=max(p,l[y][0]);
	    printf("%d\n",max(o,p));
	  }
  }
  return 0;
}


