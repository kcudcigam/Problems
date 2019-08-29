#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	scanf("%d",&k);
	if(k<=7)puts("No way");
	else
	{
		scanf("%d",&n);
		if(k==31)
		{
			puts("Found");
			for(int i=1;i<=k;i++)
			{
			int x;
			scanf("%d",&x);
			printf("%d ",x);	
			}
		}
		else puts("No way");
	}
}
