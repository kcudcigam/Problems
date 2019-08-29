#include<bits/stdc++.h>
using namespace std;
int n,ans,w[400005],f=1,t,s,a[400005];
priority_queue<int> q,p,v,d;
char ch;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		f=0;
		ch=getchar();
		ch=getchar();
		if(ch=='1')
		f+=1;
		ch=getchar();
		if(ch=='1')
		f+=2;
		scanf("%d",&w[i]);
		if(f==1)
		q.push(w[i]);
		if(f==2)
		p.push(w[i]);
		if(f==3)
		v.push(w[i]);
		if(f==0)
		d.push(w[i]);
	}
	while(!v.empty())
	{
		s++;
		ans+=v.top();
		v.pop();
	}
	t=min(q.size(),p.size());
	for (int i=1;i<=t;i++)
	{
		ans=ans+q.top()+p.top();
		q.pop();
		p.pop();
	}
	while(!q.empty())
	{
		d.push(q.top());
		q.pop();
	}
	while(!p.empty())
	{
		d.push((p.top()));
		p.pop();
	}
	for (int i=1;i<=s;i++)
	{
		if(d.empty())
		break;
		ans+=d.top();
		d.pop();
	}
	cout<<ans<<endl;
	return 0;
}
