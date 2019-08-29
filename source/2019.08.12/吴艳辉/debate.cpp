#include<bits/stdc++.h>
using namespace std;
struct wyh
{
	int ans1,ans2;
	int H;
}A[400005];
int  ren,n,Maxx,sum1,sum2,MAX;
char s[5];
int max(int x,int y)
{
	return x>=y?x:y;
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s %d",s,&A[i].H);
		if(s[0]=='1')
		{
			A[i].ans1=1;
		}
		if(s[1]=='1')
		{
			A[i].ans2=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		ren=0;
		sum1=0;
		sum2=0;
		for(int j=i;j<=n;j++)
		{
			ren++;
			sum1+=A[j].ans1;
			sum2+=A[j].ans2;
			Maxx+=A[j].H;
			if(sum1 >= ren/2 && sum2 >=	ren/2)
			{
				MAX=max(Maxx,MAX);
			}
		}
		Maxx=0;
	}
	printf("%d",MAX);
	return 0;
}
