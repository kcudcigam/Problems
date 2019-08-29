#include <bits/stdc++.h>

template < typename T > void read( T &x )
{
	int f = 1 ; x = 0 ; char c = getchar() ;
	for( ; !isdigit( c ) ; c = getchar() ) if( c == '-' ) f = -f ;
	for ( ; isdigit( c ) ; c = getchar() ) x = x * 10 + c - '0' ;
	x *= f ;
}

int main()
{
	//freopen( "max.in" , "r" , stdin ) ;
	//freopen( "max.out" , "w" , stdout ) ;
	
	return 0;
}
