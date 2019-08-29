#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
#define MAXN 400000+5
__gnu_pbds::priority_queue <int,less<int> >Q1,Q2,Q3;
int n,m,ans;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char c[2];
		int w;
		scanf("%s%d",c,&w);
		if(c[0]=='1'&&c[1]=='1')
			ans+=w,m++;
		if(c[0]=='1'&&c[1]=='0')
			Q1.push(w);
		if(c[0]=='0'&&c[1]=='1')
			Q2.push(w);
		if(c[0]=='0'&&c[1]=='0')
			Q3.push(w);
	}
	while((!Q1.empty())&&(!Q2.empty()))
		ans+=Q1.top()+Q2.top(),Q1.pop(),Q2.pop();
	while(!Q1.empty())
		Q3.push(Q1.top()),Q1.pop();
	while(!Q2.empty())
		Q3.push(Q2.top()),Q2.pop();
	for(int i=1;(i<=m)&&!(Q3.empty());i++)
		ans+=Q3.top(),Q3.pop();
	printf("%d",ans);
	return 0;
}
