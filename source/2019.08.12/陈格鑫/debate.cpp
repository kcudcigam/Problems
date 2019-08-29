#include <bits/stdc++.h>
using namespace std;

const int N = 400001;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit(c=getchar()) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num=(num<<1)+(num<<3)+(c&15), c=getchar();
	return num*f;
}

struct node
{
	int x, y, a;
}r[N];
char s[3];
int n, ans, top;
int sdf[N];
int numx, numy;

inline bool comp1 (const node &a, const node &b)
{
	if( a.y != b.y ) return a.y > b.y;
	return a.x > b.x;
}

inline bool comp2 (const node &a, const node &b)
{
	if( a.x != b.x ) return a.x > b.x;
	if( a.y != b.y ) return a.y > b.y;
	return a.a > b.a;
}

inline bool ert (int a, int b)
{
	return a > b;
}

int main ()
{
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	bool qwe1=0, qwe2=0;
	scanf("%d", &n);
	for(register int i=1; i<=n; ++i)
	{
		scanf("%s", s+1);
		r[i].x=s[1]-'0', r[i].y=s[2]-'0';
		r[i].a=read<int>();
	}
	sort(r+1, r+n+1, comp2);
	for(register int i=2; i<=n; ++i)
	{
	    if( r[i].a!=r[1].a ) { qwe1=1; break; }
	    if( r[i].x^r[i].y ) { qwe2=1; break; }
	}
	if( !qwe1 )
	{
		int asd=0, dj=n+1, kl=r[1].a;
	    for(register int i=1; i<=n; ++i)
	    {
	    	if( r[i].x==1 && r[i].y==1 ) ans+=kl;
	    	else
			{
	    		asd=i-1, dj=i;
	    		break;
			}
		}
		for(register int i=dj; i<=n; ++i)
		{
			if( !r[i].x )
			{
				dj=i;
				break;
			}
			else ++numx;
		}
		for(register int i=dj; i<=n; ++i)
		{
			if( !r[i].y )
			{
				dj=i-1;
				break;
			}
			else ++numy;
		}
		if( dj!=n+1 ) ans+=kl*min(numx, numy)+kl*min(n-dj, asd);
		printf("%d", ans);
	}
	else if( !qwe2 )
	{
	    for(register int i=1; i<=n; ++i)
	    {
		    if( r[i].x ) ans+=r[i].a;
		    else
		    {
			    for(register int j=i; j<=((i-1)<<1); ++j)
			      ans+=r[j].a;
			    break;
		    }
	    }
	    printf("%d", ans);
	}
	else
	{
	    int asd=0, asd1=0, asd2=0, dj=n+1;
	    for(register int i=1; i<=n; ++i)
	    {
	    	if( r[i].x==1 && r[i].y==1 ) ans+=r[i].a;
	    	else
			{
	    		asd=i-1, dj=i;
	    		break;
			}
		}
		for(register int i=dj; i<=n; ++i)
		{
			if( !r[i].x )
			{
				asd1=i-1, dj=i;
				break;
			}
			else ++numx;
		}
		for(register int i=dj; i<=n; ++i)
		{
			if( !r[i].y )
			{
				dj=i-1,
				asd2=i-1;
				break;
			}
			else ++numy;
		}
		int fgh=min(numx, numy), bnm1=asd+fgh, bnm2=asd1+fgh;
		for(register int i=asd+1; i<=bnm1; ++i) ans+=r[i].a;
		for(register int i=asd1+1; i<=bnm2; ++i) ans+=r[i].a;
		if( bnm1<asd1 )
		{
			for(register int i=bnm1+1; i<=asd1; ++i) sdf[++top]=r[i].a;
		}
		else if( bnm1<asd2 )
		{
			for(register int i=bnm2+1; i<=asd2; ++i) sdf[++top]=r[i].a;
		}
		sort(sdf+1,sdf+top+1, ert);
		for(register int i=1; i<=min(top, asd); ++i) ans+=sdf[i];
		printf("%d", ans);
	}
	return 0;
}
