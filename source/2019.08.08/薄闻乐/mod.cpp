#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int q,n,p,t[10000001],f[10000001];
long long ans;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	for (int i=1;i<=q;i++)
	{
		read(n);
		read(p);
		for (int j=0;j<n;j++)
		{
			f[j]=j+1;
			t[j]=j+1;
		}
		ans=0;
		while(next_permutation(f, f+n))
		{
			for (int j=0;j<n;j++)
			{
				if(t[j]!=f[j])
				{
					ans++;
				}
			}
			next_permutation(t, t+n);
		}
		cout<<ans%p<<endl;
	}
	return 0;
}
