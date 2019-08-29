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
priority_queue<pair<int,int> > pqf;
priority_queue<pair<int,int> > pqs;
struct node{
	int a,bh;
};
node d[400005];
inline bool cmp(node a,node b)
{
	return a.a>b.a;
}
bool cho[400005];
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++)
		{
			int p=read();
			int a=read();
			if(p&1) pqf.push(make_pair(a,i));
			if(p&2) pqs.push(make_pair(a,i));
			d[i].a=a;
			d[i].bh=i;
		}
	int df=min(pqf.size(),pqs.size());
	int ans=0;
	int ha=0;
	for(int i=1;i<=df;i++)
		{
			pair<int,int>pa=pqf.top();
			cho[pa.second]=1;
			ans+=pa.first;
			pqf.pop();
			ha++;
		}
	for(int i=1;i<=df;i++)
		{
			pair<int,int>pa=pqs.top();
			if(!cho[pa.second])
			{
				cho[pa.second]=1;
				ans+=pa.first;
				ha++;
			}
			pqs.pop();
		}
	int mx=min(df*2,n);
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n;i++)
		{
			if(ha==mx) break;
			if(cho[d[i].bh]) continue;
			cho[d[i].bh]=1;
			ans+=d[i].a;
			ha++;
		}
	cout<<ans<<endl;
	return 0;
}
/*
6
11 19
10 22
00 18
00 29
11 29
10 28
*/

