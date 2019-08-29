#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
for (; isdigit(c);c=getchar()) x=x*10+c -'0';
x*=f;
}
int n,m,a[500005],l,r,s,e,b[500005];
long long ans;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int i,j;
	read(n);
	read(m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&l,&r,&s,&e);
		if(s==e)
		{
			for(j=l;j<=r;j++)
			{
				a[j]+=s;
			}	
		}
		else 
		{
			int v=0;
			for(j=l;j<=r;j++)
			{
				b[j]=s;
				v=e%(r-l);
				s+=v;
			}
			for(j=l;j<=r;j++)
			{
				a[j]+=b[j];
			}
		}
	}
	for(i=1;i<=n;i+=2)
	{
		ans^=a[i]^a[i+1];
	}
	printf("%lld",ans);
	return 0;
}

