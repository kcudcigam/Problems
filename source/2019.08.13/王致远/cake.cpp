#include<bits/stdc++.h>
using namespace std;
long long f[310][310];
int a,b;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void wrk(int x,int y)
{
	for (int i=1;i<x;i++) 
	{
		if (f[x-i][y]==0) wrk(x-i,y);
		if (f[i][y]==0) wrk(i,y);
		f[x][y]=(f[x][y]+f[x-i][y]*f[i][y])%1000000007;
	}
	for (int i=1;i<y;i++)
	{
		if (f[x][y-i]==0) wrk(x,y-i);
		if (f[x][i]==0) wrk(x,i);
		f[x][y]=(f[x][y]+f[x][y-i]*f[x][i])%1000000007;		
	}
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);f[1][1]=1;
	wrk(a,b);
	cout<<f[a][b]<<endl;
	return 0;
}


