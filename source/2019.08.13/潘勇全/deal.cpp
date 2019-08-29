#include <bits/stdc++.h>
const unsigned long long MOD = 1e9 + 7 ;

int n , m ;
unsigned long long DP[ 1002 ][ 10002 ] ;
struct Money
{
	int Ai , Bi , Ci ;
}M[ 1002 ] ;

int main()
{
	//freopen( "deal.in" , "r" , stdin ) ;
	//freopen( "deal.out" , "w" , stdout ) ;
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= n ; ++i ) scanf( "%d%d%d" , &M[ i ].Ai , &M[ i ].Bi , &M[ i ].Ci ) ;
	
	return 0 ;
}


