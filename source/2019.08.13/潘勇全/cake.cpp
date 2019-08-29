#include <bits/stdc++.h>
const unsigned long long MOD = 1e9 + 7 ;

int n , m ;
unsigned long long DP[ 302 ][ 302 ] ;

int main()
{
	freopen( "cake.in" , "r" , stdin ) ;
	freopen( "cake.out" , "w" , stdout ) ;
	DP[ 1 ][ 1 ] = 1 ;
	for( int i = 1 ; i <= 300 ; ++i )
		for( int j = 1 ; j <= 300 ; ++j )
		{
			for( int k = 1 ; k < j ; ++k )
			{
				DP[ i ][ j ] = ( DP[ i ][ j ] + ( DP[ i ][ k ] * DP[ i ][ j - k ] ) % MOD ) % MOD ;
			}
			for( int k = 1 ; k < i ; ++k )
			{
				DP[ i ][ j ] = ( DP[ i ][ j ] + ( DP[ i - k ][ j ] * DP[ k ][ j ] ) % MOD ) % MOD ;
			}
		}
	DP[ 1 ][ 1 ] = 0 ;
	scanf( "%d%d" , &n , &m ) ; printf( "%llu" , DP[ n ][ m ] ) ;
	return 0 ;
}


