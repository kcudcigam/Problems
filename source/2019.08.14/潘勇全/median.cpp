#include <bits/stdc++.h>
const int maxn = 500002 ;

template < typename T > void read( T &x )
{
	int f = 1 ; x = 0 ; char c = getchar() ;
	for( ; !isdigit( c ) ; c = getchar() ) if( c == '-' ) f = -f ;
	for ( ; isdigit( c ) ; c = getchar() ) x = x * 10 + c - '0' ;
	x *= f ;
}

int n , m , A[ maxn ] , B[ maxn ] , OP , x , y , z , LA , LB , RA , RB ;
std :: vector < int > Q ;

int main()
{
	freopen( "median.in" , "r" , stdin ) ;
	freopen( "median.out" , "w" , stdout ) ;
	read( n ) ; read( m ) ;
	for( int i = 1 ; i <= n ; ++i ) read( A[ i ] ) ;
	for( int i = 1 ; i <= n ; ++i ) read( B[ i ] ) ;
	for( int i = 1 ; i <= m ; ++i )
	{
		Q.clear() ; read( OP ) ;
		if( OP == 1 )
		{
			read( x ) ; read( y ) ; read( z ) ;
			if( x == 0 ) A[ y ] = z ; else B[ y ] = z ;
		}
		else
		{
			read( LA ) ; read( RA ) ; read( LB ) ; read( RB ) ;
			for( int i = LA ; i <= RA ; ++i ) Q.push_back( A[ i ] ) ;
			for( int i = LB ; i <= RB ; ++i ) Q.push_back( B[ i ] ) ;
			std :: sort ( Q.begin() , Q.end() ) ;
			printf( "%d\n" , Q[ ( ( RA - LA + 1 ) + ( RB - LB + 1 ) ) / 2 ] ) ;
		}
	}
	return 0;
}
