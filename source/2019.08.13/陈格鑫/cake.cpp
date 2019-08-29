#include <bits/stdc++.h>
using namespace std;

const unsigned long long Mod = 1000000007;
const unsigned long long N = 301;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit(c=getchar()) ) if( c=='-' ) f=-1;
	while( isdigit(c) ) num=(num<<1)+(num<<3)+(c&15), c=getchar();
	return num*f;
}

unsigned long long n, m, ans;
unsigned long long f[N][N];

int main ()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
    scanf("%lld%lld", &n,&m);
    f[1][1]=1, f[1][2]=1, f[2][1]=1, f[2][2]=2;
    if( n==1 )
    {
    	for(register unsigned long long i=3; i<=m; ++i)
    	  for(register unsigned long long j=1; j<i; ++j)
    	    f[1][i] += f[1][j] * f[1][i-j];
    	printf("%lld", f[1][m]%Mod);
	}
	else if( n==2 )
	{
		for(register unsigned long long i=3; i<=m; ++i)
    	  for(register unsigned long long j=1; j<i; ++j)
    	    f[1][i] += f[1][j] * f[1][i-j];
    	for(register long long i=3; i<=m; ++i)
    	f[2][i]= f[1][i] * f[1][i] ;
    	for(register unsigned long long i=3; i<=m; ++i)
    	  for(register unsigned long long j=1; j<i; ++j)
    	  	f[2][i] += f[2][j] * f[2][i-j];
    	printf("%lld", f[2][m]%Mod);
	}
//	else
//	{
//		for(register unsigned long long i=3; i<=m; ++i)
//		{
//    	    for(register unsigned long long j=1; j<i; ++j)
//    	      f[1][i] += f[1][j] * f[1][i-j];
//    	    f[i][1]=f[1][i];
//    	}
//		for(register unsigned long long k=2; k<=n; ++k)
//		  for(register unsigned long long i=3; i<=m; ++i)
//    	    for(register unsigned long long j=1; j<i; ++j)
//    	      f[k][i] += f[k][j] * f[k][i-j];
//    	for(register unsigned long long i=1; i<=n; ++i)
//    	  for(register unsigned long long op=1; op<=m; ++op)
//    	    for(register unsigned long long j=1; j<m; ++j)
//    	      for(register unsigned long long k=1; k<n; ++k)
//    	        f[i][m]
//    	for(register unsigned long long i=1; i<m; ++i)
//    	  f[n][m]+= f[n][i] * f[n][m-i];
//    	for(register unsigned long long i=1; i<n; ++i)
//    	  f[n][m]+= f[i][m] * f[n-i][m];
//	}
	return 0;
}
