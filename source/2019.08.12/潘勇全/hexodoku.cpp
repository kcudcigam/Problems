#include <bits/stdc++.h>

const int maxn = 100002 ;

unsigned int ANS[ maxn ][ 32 ] ; int k , n , G[ 32 ] , C , cnt ;
int A1[ 3 ] = { 0 , 1 , 2 } , A2[ 6 ] = { 0 , 3 , 4 , 5 , 6 , 7 } , A3[ 7 ] = { 0 , 8 , 9 , 10 , 11 , 12 , 13 } ;
int A4[ 6 ] = { 0 , 14 , 15 , 16 , 17 , 18 } , A5[ 7 ] = { 0 , 19 , 20 , 21 , 22 , 23 , 24 } , A6[ 6 ] = { 0 , 25 , 26 , 27 , 28 , 29 } ;
int A7[ 3 ] = { 0 , 30 , 31 } ;
int B1[ 3 ] = { 0 , 3 , 8 } , B2[ 6 ] = { 0 , 1 , 4 , 9 , 14 , 19 } , B3[ 7 ] = { 0 , 2 , 5 , 10 , 15 , 20 , 25 } ;
int B4[ 6 ] = { 0 , 6 , 11 , 16 , 21 , 26 } , B5[ 7 ] = { 0 , 7 , 12 , 17 , 22 , 27 , 30 } , B6[ 6 ] = { 13 , 18 , 23 , 28 , 31 } ;
int B7[ 3 ] = { 0 , 24 , 29 } ;
int C1[ 3 ] = { 0 , 19 , 25 } ; C2[ 6 ] = { 0 , 8 , 14 , 20 , 26 , 30 } ; C3[ 7 ] = { 0 , 3 , 9 , 15 , 21 , 27 , 31 } ;
int C4[ 6 ] = { 0 , 4 , 10 , 16 , 22 , 28 } , C5[ 7 ] = { 0 , 1 , 5 , 12 , 17 , 23 , 29 } ; C6[ 6 ] = { 0 , 2 , 6 , 12 , 18 , 24 } ;
int C7[ 3 ] = { 0 , 7 , 13 } , D1[ 8 ] = { 0 , 5 , 9 , 12 , 16 , 20 , 23 , 27 } ;

void DFS( int G[] )
{
	if( cnt == n ) break ;
	for( int i = 31 ; i >= 1 ; ++i )
	{
		for( int j = i ; j <= 31 ; ++j )
		{
			for( int j = G[ i ] ; j <= k ; ++j , ++G[ i ] )
			{
				if( G[ i ] == k + 1 ) continue ;
				if( i == 1 )
				{
					if( A[ 1 ] == A[ 2 ] ) continue ;
				}
			}
		}
	}
}

int main()
{
//  freopen( "hexodoku.in" , "r" , stdin ) ;
//  freopen( "hexodoku.out" , "w" , stdout ) ;
	scanf( "%d%d" , &n , &k ) ;
	for( int i = 1 ; i <= n ; ++i )
	{
		scanf( "%d" , &C ) ; A[ i ] = C ;
	}
	
	return 0 ;
}

