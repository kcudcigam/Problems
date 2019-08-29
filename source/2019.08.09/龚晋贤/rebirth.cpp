#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > c;
vector<long long> a[500000],b[500000];
long long s[500000],t,n,m,i,j,x,y,z,h[500000],ans[500000],d,e;
int read()
{
  int f=1,s=0;
  char c;
  c=getchar();
  while ('9'<c||c<'0') {
  if (c=='-') f=-1;
  c=getchar();
  }
  while ('0'<=c&&c<='9') {
  s=s*10+c-'0';
  c=getchar();
  }
  return s*f;
}
void wr(int n)
{
  if (n<0) {
  	putchar('-');
  	n*=-1;
  }
  if (n>10) {
  wr(n/10);
  putchar(char(n%10+48));
  }
  else {
  	putchar(char(n%10+48));
  }
}
int main(){
    freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>t;
	cin>>n>>m;
	for (i=1;i<=n;i++)
    {
    	ans[i]=-1;
	}	
	for (i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (x!=y) {
		a[x].push_back(y); b[x].push_back(z);
		a[y].push_back(x); b[y].push_back(z);
	    }
	}
	for (d=1;d<=n;d++)
	{
		for (e=0;e<a[d].size();e++)
		{
			for (i=1;i<=n;i++)
			h[i]=0;
	    s[1]=0;
	    for (i=2;i<=n;i++)
	   {
	   s[i]=INT_MAX;
	   s[i]*=300000;
       }
       while (c.size()>0) c.pop();
	   for (i=1;i<=n;i++)
     	{
		c.push(make_pair(s[i],i));
	   }
	   for (i=1;i<=n-1;i++)
	   {
	   	if (c.size()>0)
		{
	    x=c.top().first; y=c.top().second;
	   	c.pop();
	    }
	   	while (h[y]!=0&&c.size()>0) {
	   		x=c.top().first; y=c.top().second;
	   	    c.pop();
		   }
		for (j=0;j<a[y].size();j++)
		{
			if ((y==d&&j==e)||(y==a[d][e]&&a[y][j]==d&&b[y][j]==b[d][e])) continue;
			else if (x+b[y][j]<s[a[y][j]]) {
				s[a[y][j]]=x+b[y][j];
				c.push(make_pair(x+b[y][j],a[y][j]));
			}
		}
		h[y]=1;
	   }
	   ans[d]=max(ans[d],s[d]);
       }
    }
    for (i=1;i<=n;i++)
    {
    	x=INT_MAX;
    	x*=300000;
    	if (x==ans[i]) cout<<-1<<' ';
    	else cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}


