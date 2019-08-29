#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int q,n,p,a[10000005];
signed main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	while(q--)
	{
		read(n);
		read(p);
		int x=1;
		a[1]=0;
		for(int i=2;i<=n;i++)
		{
			int add;
			if (i%2==0) add=1;
			else add=i-1;
			a[i]=(a[i-1]+i-1)*i-(i-1)+add;
			a[i]%=p;
		}
		cout<<a[n]<<endl;
	}
	return 0;
}

