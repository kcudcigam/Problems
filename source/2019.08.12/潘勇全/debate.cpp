#include <bits/stdc++.h>
const int maxn = 400002 ;

struct M
{
	bool AA , BB ; int ACT , pos ;
}P[ maxn ] , Q[ maxn ] ;
int n , OP , m , cnt0 , cnt1 , cnt2 , cnt3 , sum ; bool POSI[ maxn ] ;

bool Cmp1( M rua , M qwq )
{
	if( rua.AA == qwq.AA ) return rua.ACT > qwq.ACT ;
	else return rua.AA > qwq.AA ;
}

bool Cmp2( M rua , M qwq )
{
	if( rua.BB == qwq.BB ) return rua.ACT > qwq.ACT ;
	else return rua.BB > qwq.BB ;
}

bool Cmp3( M rua , M qwq )
{
	return rua.ACT > qwq.ACT ;
}

int main()
{
	freopen( "debate.in" , "r" , stdin ) ;
	freopen( "debate.out" , "w" , stdout ) ;
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; ++i )
	{
		scanf( "%d%d" , &OP , &m ) ;
		P[ i ].ACT = Q[ i ].ACT = m ; P[ i ].pos = Q[ i ].pos = i ;
		if( OP / 10 == 1 && OP % 10 == 1 )
		{
			sum += m ; cnt0 ++ ; P[ i ].ACT = Q[ i ].ACT = 0 ;
		}
		if( OP / 10 ) P[ i ].AA = Q[ i ].AA = 1 ;
		if( OP % 10 ) P[ i ].BB = Q[ i ].BB = 1 ;
		if( OP / 10 == 1 && OP % 10 == 0 ) cnt1 ++ ;
		if( OP / 10 == 0 && OP % 10 == 1 ) cnt2 ++ ;
	}
	cnt3 = std :: min ( cnt1 , cnt2 ) ;
	std :: sort ( P + 1 , P + n + 1 , Cmp1 ) ; std :: sort ( Q + 1 , Q + n + 1 , Cmp2 ) ;
	if( cnt0 * 2 >= n || cnt0 * 2 + cnt3 >= n )
	{
		for( int i = cnt0 + 1 ; i <= n ; ++i ) sum += P[ i ].ACT ;
		printf( "%d\n" , sum ) ; return 0 ;
	}
	for( int i = cnt0 + 1 ; i <= cnt0 + cnt3 ; ++i )
	{
		sum += P[ i ].ACT ; POSI[ P[ i ].pos ] = 1 ;
		sum += Q[ i ].ACT ; POSI[ Q[ i ].pos ] = 1 ;
	}
	for( int i = 1 ; i <= n ; ++i )
	{
		if( POSI[ P[ i ].pos ] ) P[ i ].ACT = 0 ;
		if( POSI[ Q[ i ].pos ] ) Q[ i ].ACT = 0 ;
	}
	std :: sort ( P + 1 , P + n + 1 , Cmp3 ) ;
	for( int i = 1 ; i <= cnt0 ; ++i ) sum += P[ i ].ACT ;
	printf( "%d\n" , sum ) ;
	return 0 ;
}

