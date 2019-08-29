#include<bits/stdc++.h>
#define ll long long
using namespace std;
int num[30],tot=0;
struct Node{
	int x;
	int num;	
} cnt[30];
bool cmp(Node a,Node b)
{
	if(a.num==b.num)
		return a.x<b.x;
	return a.num>b.num;
}
bool cmp2(Node a,Node b)
{
	return a.x<b.x;
}
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		memset(num,0,sizeof(num));
		scanf("%lld",&n);
		m=n;
		for(int i=1;i<=20;i++)
		{
			cnt[i].x=i;
			cnt[i].num=0;
		}
		int nn=0;
		while(n)
		{
			num[++nn]=n%10;
			cnt[n%10].num++;
			n/=10;
		}
//		sort(cnt+1,cnt+20,cmp);
		tot=0;
		
		while(m!=0)
		{
			m=0;

			sort(cnt+1,cnt+20,cmp);
			int maxn=cnt[1].x;
			int max2n=cnt[2].x;
			sort(cnt+1,cnt+20,cmp2);
			
			
			if(cnt[3].num==0&&cnt[4].num==0)
			{
				tot++;
				break;
			}
					
			for(int i=1;i<=nn;i++)
			{
				if(num[i]!=0&&num[i]<maxn&&num[i+1]>maxn)
				{
					cnt[num[i+1]].num--;
					num[i+1]--;
					cnt[num[i+1]].num++;
					cnt[num[i]].num--;
					num[i]+=10;
					cnt[num[i]].num++;
				}
			}
			
			sort(cnt+1,cnt+20,cmp);
			maxn=cnt[1].x;
			max2n=cnt[2].x;
			sort(cnt+1,cnt+20,cmp2);
			bool f=1,ff=1;
			int tt;
			for(int i=nn;i>=1;i--)
			{
				if(num[i]==maxn||num[i]>9)
				{
					cnt[num[i]].num--;
					num[i]-=maxn;
					cnt[num[i]].num++;
				}
//				else
//				{
//					if(ff)
//					{
//						tt=num[i];
//						ff=0;
//					}
//
//					cnt[num[i]].num--;
//					num[i]-=tt;
//					cnt[num[i]].num++;
//				}
//				
				if(num[i]==0&&f) nn--;
				else f=0;
			}
			for(int i=1;i<=nn;i++)
			{
				if(num[i]<0)
				{
					cnt[num[i+1]].num--;
					num[i+1]--;
					cnt[num[i+1]].num++;
					cnt[num[i]].num--;
					num[i]+=10;
					cnt[num[i]].num++;					
				}
			}
			for(int i=nn;i>=1;i--)
				m=m*10+num[i];
			tot++;
		}

		cout<<tot<<endl;		
//		cout<<cnt[1].x<<endl;
//		for(int j=1;j<=nn;j++)
//		{
//			cout<<num[j]<<" ";
//		}
	}
	
	return 0;
}


