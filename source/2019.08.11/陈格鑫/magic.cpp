#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
const long long MOD = 998244353;

string sbb;
char s1[N];
long long n, op, ans, t0p, kl=1;

void dfs (int P)
{
	if( P == n+1 )
	{
		int num=0;
		for(register int i=1; i<P; ++i)
		{
			if( s1[i]!='a' )
			{
				for(register int j=P-1; j>i; --j)
				{
					if( s1[j]!='a' ) break;
					else ++num;
				}
				break;
			}
			else ++num;
		}
		if( num>=op ) ++ans;
		return;
	}
	for(int i=1; i<=26; ++i) s1[P]='`'+i, dfs(P+1);
}

void dfs0 (int P)
{
	if( P == n+1 )
	{
		int num=0;
		for(register int i=1; i<P; ++i)
		{
			if( s1[i]!=sbb[i] )
			{
				for(register int j=P-1; j>i; --j)
				{
					if( s1[j]!=sbb[op-kl] ) break;
					else ++t0p, ++kl;
				}
				break;
			}
			else ++t0p;
		}
		if( t0p>=op ) ++ans;
		return;
	}
	for(int i=1; i<=26; ++i) s1[P]='`'+i, dfs(P+1);
}

int main ()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
    int qwe=0;
	scanf("%lld", &n);
	cin>>sbb;
	op=sbb.length();
	if( n<op )
	{
		long long rtx=1;
		for(register long long i=1; i<=n; ++i)
			rtx=rtx*26%MOD;
		printf("%lld", rtx);
		exit(0);
	}
	for(register long long i=0; i<op; ++i)
	{
	    if( sbb[i]!='a' )
		{
			qwe=1;
			break;
		}
	}
	if( !qwe )
	{
		if( n<=4 )
	    {
	        dfs(1);
	        long long rtx=1;
	        for(register long long i=1; i<=n; ++i) rtx*=26;
	        printf("%lld", (rtx-ans)%MOD);
	    }
	    else if( op==n )
	    {
	    	long long rtx=1;
			for(register long long i=1; i<=n; ++i)
			  rtx=rtx*26%MOD;
			rtx-=1;
			if( rtx<0 ) printf("998244352");
			else printf("%lld", rtx);
		}
	}
	else
	{
		if( op == n )
		{
			long long rtx=1;
			for(register long long i=1; i<=n; ++i)
			  rtx=rtx*26%MOD;
			rtx-=1;
			if( rtx<0 ) printf("998244352");
			else printf("%lld", rtx);
		}
		else
		{
		    dfs0(1);
		    long long rtx=1;
	        for(register long long i=1; i<=n; ++i) rtx=rtx*26%MOD;
	        printf("%lld", (rtx-ans)%MOD);
		}
	}
	return 0;
}
