#include<bits/stdc++.h>
using namespace std;
long long y,bs,n,tot=0,t,cnt=0,a[200001];
template <typename T> void read(T & x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar())  x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
 /*   read(y);
    if(y==1) 
    {puts("2 1");	puts("1 2");}
	else
	if(y==2)
	{puts("3 3");puts("1 2");puts("2 3");puts("1 3");}
	if(y==3)
	{puts("4 5");puts("1 2");puts("2 4");puts("1 3");puts("3 4");puts("1 4");};
	if(y==4)
	{puts("4 6");puts("1 2");puts("2 3");puts("3 4");puts("1 3");puts("2 4");puts("1 4");};
	if(y==5)
	{puts("5 8");puts("1 2");puts("2 5");puts("1 3");puts("3 5");puts("3 4");puts("4 5");puts("1 4");puts("1 5");}
	*/
		read(y);
			t=y-1;
			while(t!=0)
			{
				tot++;
				if(t%2==1)
				{	a[tot]=1;cnt++;}	
				t>>=1;
			}
			n=tot+2;
			
			
			///cout<<n<<' '<<n*(n-1)/2-tot+cnt;
			int qwe=n*(n-1)/2-tot+cnt;
			
			cout<<n<<' '<<qwe<<endl;
			int ttt=1;
			printf("%d %d\n",ttt,n);
		
		for(register int i=1;i<n;i++)
		{
			int poi=i+1;
			for(register int k=poi;k<n;k++)
		printf("%d %d\n",i,k);
		}
		
		
		for(register int i=1;i<n-1;i++)
		if(a[i]==1)
		printf("%d %d\n",i+1,n);
	
    return 0;
 } 
