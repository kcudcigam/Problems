#include<bits/stdc++.h>
using namespace std;
int a,b,c,maxi,f[1000010],n[1000010],nn[1000010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') x=-x;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	read(a);read(b);memset(n,0,sizeof(n));
	if (b>1000000) b=1000000;
	for (int i=1;i<=a;i++)
	{
		read(c);memset(nn,0,sizeof(nn));
		for (int j=0;j<=b-c;j++)
		if ((n[j+c]==0)&&(f[j+c]+1>f[j]))
		{
			f[j]=f[j+c]+1;
			nn[j]=1;
		}
		memset(n,0,sizeof(n));
		for (int j=0;j<=b-c+1;j++)
		n[j]=nn[j];
	}
	maxi=0;
	for (int i=0;i<=b;i++)
	if (f[i]>maxi) maxi=f[i];
	cout<<maxi<<endl;
	return 0;
}

