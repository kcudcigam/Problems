#include<bits/stdc++.h>
using namespace std;
priority_queue<int> a0,a1,a2;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,op,val,ans=0,sum=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d",&op,&val);
		if(op==0)  a0.push(val);
		if(op==01)  a1.push(val);
		if(op==10)  a2.push(val);
		if(op==11)
		{
			ans+=val;
			sum++;
		}
	}
	while((!a1.empty()) && (!a2.empty()))
	{
		ans=ans+a1.top()+a2.top();
		a1.pop();
		a2.pop();
	}
	while(!a1.empty())
	{
		a0.push(a1.top());
		a1.pop();
	}
	while(!a2.empty())
	{
		a0.push(a2.top());
		a2.pop();
	}
	while(sum-- && !a0.empty())
	{
		ans+=a0.top();
		a0.pop();
	}
	printf("%d\n",ans);
	return 0;
}
