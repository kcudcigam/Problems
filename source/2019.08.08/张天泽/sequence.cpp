#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long  n,m,r,l,s,w,k,ans;
long long a[600000],f[600000];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=m;i++)
	{
		read(l);
		read(r);
		read(s);
		read(w);
		a[l]+=s;
		a[1+r]-=w;
		w-=s;
		k=w/(r-l);
		f[l+1]+=k;
		f[r+1]-=k;
	}
	int x=0;
	for (int i=1;i<=n;i++)
	{
		x+=f[i];
		a[i]=a[i-1]+a[i]+x;
		ans^=a[i];
	}
	
	cout<<ans<<endl;
	return 0;
}


