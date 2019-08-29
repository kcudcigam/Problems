#include <bits/stdc++.h>

const int maxn = 100002 ;

int n , A[ maxn ] , DL[ maxn ] , DR[ maxn ] , suml , sumr , ans ;

int main()
{
	freopen( "sum.in" , "r" , stdin ) ;
	freopen( "sum.out" , "w" , stdout ) ;
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; ++i )
	{
		scanf( "%d" , &A[ i ] ) ;
	}
	for( int i = 2 ; i < n ; ++i )
	{
		memset( DL , 0 , sizeof( DL ) ) ; memset( DR , 0 , sizeof( DR ) ) ;
		suml = sumr = -0x3f3f3f3f ;
		for( int j = 1 ; j < i ; ++j )
		{
			DL[ j ] = std :: max ( DL[ j - 1 ] + A[ j ] , A[ j ] ) ;
			suml = std :: max ( suml , DL[ j ] ) ;
		}
		for( int j = i + 1 ; j <= n ; ++j )
		{
			DR[ j ] = std :: max ( DR[ j - 1 ] + A[ j ] , A[ j ] ) ;
			sumr = std :: max ( sumr , DR[ j ] ) ;
		}
		ans = std :: max ( ans , suml + sumr ) ;
	}
	printf( "%d" , ans ) ;
	return 0 ;
}


