#include<bits/stdc++.h>
using namespace std;
int n,k,m,tot;
int Pow[60],a[60],l[60];
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	scanf("%d%d",&n,&k);
	Pow[0]=1;
	for(int i=1;i<=30;i++)
	Pow[i]=Pow[i-1]<<1;
	while(n)
	{
		if(n&1)
		a[++m]=tot,l[m]=Pow[tot]+l[m-1];
		n>>=1;
		tot++;
	}
	if(m<=k)
	{
		puts("0");
		return 0;
	}
	int s=a[m-k+1];
	printf("%d\n",Pow[s+1]-l[m-k+1]);                                                      
	return 0;
}
