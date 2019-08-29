#include <bits/stdc++.h>

int n , u , v , Dep[ 2002 ] , Vis[ 2002 ] , cnt , Pos ;
std :: vector < int > G[ 2002 ] ; std :: queue < int > q ;

void BFS( int u )
{
	for( int i = 0 ; i < ( int ) G[ u ].size() ; ++i )
	{
		v = G[ u ][ i ] ;
		if( Vis[ v ] ) continue ;
		Vis[ v ] = 1 ;
		Dep[ v ] = Dep[ u ] + 1 ;
		ans = std :: max ( )
		DFS( v ) ;
	}
}

int main()
{
	//freopen( "town.in" , "r" , stdin ) ;
	//freopen( "town.out" , "w" , stdout ) ;
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i < n ; ++i )
	{
		memset( Dep , 0 , sizeof( Dep ) ) ; memset( Vis , 0 , sizeof( Vis ) ) ;
		scanf( "%d%d" , &u , &v ) ; G[ u ].push_back( v ) ; G[ v ].push_back( u ) ;
		BFS( u ) ;
	}
	return 0 ;
}


