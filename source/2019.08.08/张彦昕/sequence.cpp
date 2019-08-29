#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
for (; isdigit(c);c=getchar()) x=x*10+c -'0';
x*=f;
}
long long n;
long long m;
int l,r,s,e;
int main(){
    freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	int a[500010]={0};
	long long sum=0;
	for (int i=1;i<=m;i++)
	{
		read(l);read(r);read(s);read(e);
		int o=0;
		int zj=(e-s)/(r-l);
		for (int j=l;j<=r;j++)
		{
			a[j]=a[j]+s+zj*o;
			o++; 
		}
	}
	for (int i=1;i<=n;i++)
	sum+=a[i]%2;
	cout<<sum<<endl;
	return 0;
}


