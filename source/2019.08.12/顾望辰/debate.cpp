#include<cstdio>
#include<cctype>
#include<queue>
#include<vector>
using namespace std;
void qread(int& x)
{
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return ;
}
int n,a[400010];
bool de[400010][5];
void task56()
{
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		cnt1+=de[i][0];
		cnt2+=de[i][1];
	}
	printf("%lld\n",(long long)min(n*a[1],a[1]*min(cnt1,cnt2)<<1));
	return ;
}
void task78()
{
	long long ans=0,cnt=0;
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(de[i][0])
		{
			ans+=a[i];
			cnt++;
		}
		else q.push(a[i]);
	}
	while(cnt&&!q.empty())
	{
		ans+=q.top();
		q.pop();
		cnt--;
	}
	printf("%lld\n",ans);
	return ;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	qread(n);
	char c;
	bool tsk56=true,tsk78=true;
	for(int i=1;i<=n;i++)
	{
		c=getchar();
		for(;!isdigit(c);c=getchar());
		de[i][0]=c-48;
		de[i][1]=getchar()-48;
		qread(a[i]);
		if(i>1&&a[i]!=a[i-1]) tsk56=false;
		if(de[i][0]^de[i][1]) tsk78=false;
	}
	if(tsk56) task56();
	else if(tsk78) task78();
	return 0;
}
