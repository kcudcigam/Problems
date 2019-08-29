#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int w,num;
}Money[100010];
int chos[100010];
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		Money[i].w=a;
		Money[i].num=b+c;
		x+=a*c;
	}
	
	chos[0]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=Money[i].num;j++)
		{
			for(int k=x;k>=1;k--)
			{
				if(chos[k-Money[i].w])
				{
					chos[k]++;
					break;
				}
			}
		}
	}
	
	cout<<chos[x]<<endl;
	return 0;
}


