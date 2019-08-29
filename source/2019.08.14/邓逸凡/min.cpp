#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar(); int x=0,f=1; for(;c < '0' || c > '9'; c = getchar())  if  (c=='-')  f=-f;
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x*f;
}
long long F[200005][2][3];
int a[200005];
long long sq(long long x)
{
	return x*x;
}
long long cb(long long x)
{
	return x*x*x;
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int N=read(),A=read(),B=read(),C=read(),D=read();
	for  (int i=1;i<=N;i++)
		a[i]=read();
	F[1][0][2]=F[1][1][2]=a[1];
	F[1][1][1]=F[1][0][1]=A*cb(a[1])+B*sq(a[1])+C*a[1]+D;
	F[1][1][0]=F[1][0][0]=F[1][1][1];
	for  (int i=2;i<=N;i++)
		{
			F[i][1][2]=a[i];
			F[i][1][1]=A*cb(a[i])+B*sq(a[i])+C*a[i]+D;
			F[i][1][0]=max(F[i-1][1][0],F[i-1][0][0])+F[i][1][1];
				
			F[i][0][0]=F[i-1][0][0];
			if  (a[i]<F[i-1][0][2])
				{
					F[i][0][2]=a[i];
					F[i][0][1]=F[i][1][1];
					F[i][0][0]=F[i][0][0]-F[i-1][0][1]+F[i][0][1];
				}
			else
				{
					F[i][0][2]=F[i-1][0][2];
					F[i][0][1]=F[i-1][0][1];
				}
			long long xx=F[i-1][1][0];
			int yy,zz;
			if  (a[i]<F[i-1][1][2])
				{
					yy=a[i];
					zz=F[i][1][1];
					xx=xx-F[i-1][1][1]+F[i][1][1];
				}
			else
				{
					yy=F[i-1][1][2];
					zz=F[i-1][0][1];
				}
			if  (xx>F[i][0][0])
				{
					F[i][0][0]=xx;
					F[i][0][1]=yy;
					F[i][0][2]=zz;
				}
		}
	long long Ans=max(F[N][0][0],F[N][1][0]);
	cout<<Ans<<endl;
	return 0;
}

