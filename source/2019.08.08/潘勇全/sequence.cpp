#include <bits/stdc++.h>
typedef long long ll ;

const int maxn = 500002 , maxm = 2000 ;

int L[ maxm ] , R[ maxm ] , Belong[ maxn ] , tmp , Block , n , m , lll , rrr ;
ll s , e , A[ maxn ] , Lazy[ maxn ] ;

void Build()
{
	Block = ( int ) sqrt( n ) ;
	int num = n / Block ; if( n % Block ) num ++ ;
	for( int i = 1 ; i <= n ; ++i ) Belong[ i ] = ( i - 1 ) / Block + 1 ;
	for( int i = 1 ; i <= num ; ++i )
	{
		L[ i ] = ( i - 1 ) * Block + 1 ; R[ i ] = i * Block ;
	}
	R[ num ] = n ;
}

void Update( int lll , int rrr , ll d )
{
	if( Belong[ lll ] == Belong[ rrr ] )
	{
		for( int i = lll ; i <= rrr ; ++i ) A[ i ] += d ;
	}
	else
	{
		for( int i = lll ; i <= R[ Belong[ lll ] ] ; ++i ) A[ i ] += d ;
		for( int i = Belong[ lll ] + 1 ; i < Belong[ rrr ] ; ++i ) Lazy[ i ] += d ;
		for( int i = L[ Belong[ rrr ] ] ; i <= rrr ; ++i ) A[ i ] += d ;
	}
}

int main()
{
	freopen( "sequence.in" , "r" , stdin ) ;
	freopen( "sequence.out" , "w" , stdout ) ;
	scanf( "%d%d" , &n , &m ) ; Build() ;
	for( int i = 1 ; i <= m ; ++i )
	{
		scanf( "%d%d%lld%lld" , &lll , &rrr , &s , &e ) ;
		if( s == e ) Update( lll , rrr , s ) ;
		else
		{
			tmp = ( e - s ) / ( rrr - lll ) ;
			for( int j = lll ; j <= rrr ; ++j )
			{
				A[ j ] += s ; s += tmp ;
			}
		}
	}
	for( int i = 1 ; i <= n ; ++i ) A[ i ] += Lazy[ Belong[ i ] ] ;
	ll ans = A[ 1 ] ;
	for( int i = 2 ; i <= n ; ++i ) ans ^= A[ i ] ;
	printf( "%lld" , ans ) ;
	return 0 ;
}
