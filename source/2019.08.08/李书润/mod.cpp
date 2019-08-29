#include<bits/stdc++.h>
using namespace std;
int a[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p;
		scanf("%d%d",&n,&p);
		printf("%d\n",a[n]%p);	
	}
	return 0;
}
