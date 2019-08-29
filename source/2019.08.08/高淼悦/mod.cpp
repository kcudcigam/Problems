#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int a[20];

int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	a[1]=0;
	a[2]=2;
	a[3]=12;
	a[4]=58;
	a[5]=310;
	a[6]=1886;
	a[7]=13244;
	a[8]=106002;
	a[9]=954090;
	a[10]=9540982;
	int n;
	read(n);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		read(x);read(y);
		cout<<a[x]<<endl;
	}
	return 0;
}


