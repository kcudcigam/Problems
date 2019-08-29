#include<bits/stdc++.h>
using namespace std;
int n,ans,tot,ta,tb;//tot,ta,tb当前选择的人数 ans活跃值
priority_queue<int> ab,oa,ob,oo;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,w;
		scanf("%d %d",&x,&w);
		if(x==11) ab.push(w);
		if(x==10) oa.push(w);
		if(x==1) ob.push(w);
		if(x==0) oo.push(w);
	}//把ab,oa,ob,oo四队人按活跃度放进四个大根堆
	
	while((!oa.empty())&&(!ob.empty()))
	{
		ans+=oa.top();
		ans+=ob.top();
		oa.pop();
		ob.pop();
		tot+=2;
		ta++;
		tb++;
	}//先把oa,ob两队人等量从小到大选好
	
	//现在oa,ob中只有一堆ox剩余人
	while(!ab.empty())
	{
		ans+=ab.top();
		ab.pop();
		tot++;
		ta++;
		tb++;//ab的人要全部选
		
		//现在选择带上oo或ox的人
		if( (!oa.empty()||!ob.empty()) && (oo.empty()) )
		{
			int Temp=0;
			oo.push(Temp);
		}//先特判若只有ox有人
		
		if(!oo.empty())
		{
			if((!oa.empty())&&oa.top()>oo.top())
			{
				if(ta+1>=(tot+1)/2)
				{
					ans+=oa.top();
					oa.pop();
					tot++;
					ta++;
				}//由于一个人可以同时支持AB,存在支持A或B的人数超过总人数一半的情况
			}//如果oa的人权重比oo大,且还可以放入,就选择oa
			else
			{
				if((!ob.empty())&&ob.top()>oo.top())
				{
					if(tb+1>=(tot+1)/2)
					{
						ans+=ob.top();
						ob.pop();
						tot++;
						tb++;
					}
				}//ob同理
				else
				{
					ans+=oo.top();
					oo.pop();
				}//oa,ob都没人或都不满足条件,就选择oo的人
			}
		}
	}//再选择ab的人,同时决定带哪些剩下的人
	
	printf("%d\n",ans);
	
	return 0;
}


