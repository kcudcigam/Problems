#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=6010;
int n,q,bj[N],a[N],b[N],num[6010][N],h[N],top[N],ans[N];
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
void init()
{
	read(n);read(q);
	for(int i=1;i<=n;i++)
	{
		num[i][1]=i;
		h[i]=i;
		top[i]=1;
	}
	for(int i=1;i<=q;i++)
	{
		read(bj[i]);
		read(a[i]);
		read(b[i]);
	}
	for(int i=1;i<=q;i++)
	{
		if(bj[i]==1)
		{
			int t=h[b[i]];
			while(top[t]>0)
			{
				top[h[a[i]]]++;
				num[h[a[i]]][top[h[a[i]]]]=num[t][top[t]];
				h[num[t][top[t]]]=h[a[i]];
				top[t]--;
			}
		}else if(bj[i]==2)
		{
			for(int j=1;j<=top[h[a[i]]];j++)
			{
				ans[num[h[a[i]]][j]]+=b[i];
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	init();
	return 0;
}

