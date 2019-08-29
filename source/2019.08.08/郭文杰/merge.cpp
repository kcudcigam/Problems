#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int x,pre;
} f[5000005];

int n,q,ai;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

inline int find(int x)
{
	return f[x].pre==x?x:find(f[x].pre);
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;++i)
		f[i].pre=i;
	ai=n;
	for(int i=1;i<=q;++i)
	{
		int x,a,b;
		read(x),read(a),read(b);
		if(x==1)
			f[a].pre=f[b].pre=++ai;
		else
			f[f[a].pre].x+=b;
	}
	for(int i=1;i<=n;++i)
	{
		int ans=0,pre=i;
		do
		{
			ans+=f[pre].x;
			pre=f[pre].pre;
		} while(pre&&pre!=i);
		printf("%d ",ans);
	}
	return 0;
}

