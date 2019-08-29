#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int a[305];
int b[305];
int main()
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
	int Q;
	read(Q);
	while(Q--)
		{
			int n,p;
			read(n);
			read(p);
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++) a[i]=i,b[i]=i;
			int w=0;
			while(next_permutation(a+1,a+n+1))
				{
					for(int i=1;i<=n;i++) if(a[i]!=b[i]) w++;
					w%=p;
					for(int i=1;i<=n;i++) b[i]=a[i];
				}
			cout<<w<<endl;
		}
	return 0;
}


