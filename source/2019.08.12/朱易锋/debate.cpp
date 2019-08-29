#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
	R int f=1,num=0;
	R char ch=getchar();
	while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(0!=isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num*f;
}
const int N=400000+107;
struct node
{
	int val;
};
I bool operator<(node a,node b)
{
	return a.val>b.val;
}
multiset<node>s[7];
multiset<node>::iterator it,it1,it2;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	R int n=read();
	R char cho[100];
	R int sum1=0,sum2=0,ans=0;
	for(R int i=1;i<=n;i++)
	{
		R int opt=0;
		scanf("%s",&cho);R int val=read();
		if(cho[0]==cho[1])
		{
			if(cho[0]=='0')opt=1;
			else 
			{
				opt=4;ans+=val;
				sum1++;sum2++;
			}
		}
		else
		{
			if(cho[0]=='0')opt=2;
			else opt=3;
		}
		s[opt].insert((node){val});
	}
	while((s[2].size()!=0)&&(s[3].size()!=0))
	{
		it=s[2].begin();
		node now2=*it;s[2].erase(it);
		it=s[3].begin();
		node now3=*it;s[3].erase(it);
		ans+=(now2.val+now3.val);
	}
	R int pos=0;
	if(s[2].size()!=0)pos=2;
	else if(s[3].size()!=0)pos=3;
	else pos=0;
	R int ret=0;
	if(pos==2)ret=sum1;
	else if(pos==3)ret=sum2;
	else ret=max(sum1,sum2);
	while(ret!=0)
	{
		if((s[1].size()==0)&&(s[pos].size()==0))break;
		R int now1=0,now2=0;
		node t;
		if(s[1].size())
		{
			it1=s[1].begin();
			if(it1!=s[1].end())t=*it1,now1=t.val;
		}
		if(s[pos].size())
		{
			it2=s[pos].begin();
			if(it2!=s[pos].end())t=*it2,now2=t.val;
		}

		if(now1>now2&&now1!=0)
		{
			ans+=now1,ret--;s[1].erase(it1);
		}
		else if(now2>now1&&now2!=0)
		{
			ans+=now2,ret--;s[pos].erase(it2);
		}
	}
	printf("%d",ans);
	return 0;
}
