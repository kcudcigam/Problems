#include <bits/stdc++.h>
typedef long long LL ;

int n , a , b , c , d , A[ 200005 ] , tmp ;
bool Flag ; LL ans ;

template < typename T > void read( T &x )
{
	int f = 1 ; x = 0 ; char c = getchar() ;
	for( ; !isdigit( c ) ; c = getchar() ) if( c == '-' ) f = -f ;
	for ( ; isdigit( c ) ; c = getchar() ) x = x * 10 + c - '0' ;
	x *= f ;
}


LL Cal( int x )
{
	return a * x * x * x + b * x * x + c * x + d ;
}

namespace dllxl
{
	void SolveA()
	{
		ans = 0 ;
		for( int i = 1 ; i <= n ; ++i )
		{
			if( A[ i ] >= 0 )
			{
				ans += Cal( A[ i ] ) ;
				if( Flag )
				{
					ans += Cal( tmp ) ; Flag = tmp = 0 ;
				}
			}
			if( A[ i ] < 0 )
			{
				tmp = std :: min( tmp , A[ i ] ) ; Flag = 1 ;
			}
		}
		printf( "%lld\n" , ans ) ;
	}
}

namespace dlccz
{
	void SolveB()
	{
		ans = 0 ;
		for( int i = 1 ; i <= n ; ++i )
		{
			if( A[ i ] >= 0 ) continue ;
			if( A[ i ] <= 0 ) ans += Cal( A[ i ] ) ;
		}
		printf( "%lld\n" , ans ) ;
	}
}

int main()
{
	freopen( "min.in" , "r" , stdin ) ;
	freopen( "min.out" , "w" , stdout ) ;
	read( n ) ; read( a ) ; read( b ) ; read( c ) ; read( d ) ;
	for( int i = 1 ; i <= n ; ++i ) read( A[ i ] ) ;
	if( a >= 0 && b >= 0 && c >= 0 ) dllxl :: SolveA() ;
	else if( a >= 0 && b >= 0 && c <= 0 ) dllxl :: SolveA() ;
	else if( a >= 0 && b <= 0 && c >= 0 ) dllxl :: SolveA() ;
	else dlccz :: SolveB() ;
	return 0 ;
}
