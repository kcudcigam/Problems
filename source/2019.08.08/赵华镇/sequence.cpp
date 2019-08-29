#include<bits/stdc++.h>
using namespace std;
long long sum,a[1000005];
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	long long n,m,l,r,s,e,i,j,d;
	read(n);
	read(m);
	for(i=1;i<=m;i++){
		read(l);read(r);
		read(s);read(e);
		d=(e-s)/(r-l);
		if(s==e) d=0;
		for(j=l;j<=r;j++){
			a[j]+=s;
			if(s<=e) s+=d;
		}
	}
	sum=a[1];
	for(i=2;i<=n;i++){
		sum=sum^a[i];
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
