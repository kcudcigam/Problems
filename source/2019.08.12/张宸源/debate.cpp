#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
using namespace std;
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
priority_queue<int> q1,q2,q0;
int n,a,sum,ans;
char opt[5];
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);
	rep(i,1,n)
	{
		scanf("%s",opt+1);
		read(a);
		if(opt[1]=='0')
		{
			if(opt[2]=='1')
			q2.push(a);
			else q0.push(a);
		}
		else
		{
			if(opt[2]=='1')
			ans+=a,sum++;
			else q1.push(a);
		}
	}
	while(!q1.empty()&&!q2.empty())
	{
		ans+=q1.top()+q2.top();
		q1.pop(),q2.pop();
	}
	while((!q1.empty()||!q0.empty())&&sum!=0)
	{
		if(q1.top()>q0.top())
		ans+=q1.top(),q1.pop();
		else ans+=q0.top(),q0.pop();
		sum--;
	}
	while((!q2.empty()||!q0.empty())&&sum!=0)
	{
		if(q2.top()>q0.top())
		ans+=q2.top(),q2.pop();
		else ans+=q0.top(),q0.pop();
		sum--;
	}
	printf("%d\n",ans);
	return 0;
}



