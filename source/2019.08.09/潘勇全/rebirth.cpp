#include <bits/stdc++.h>

const int maxn = 500002 ;

int V[ maxn << 1 ] , W[ maxn << 1 ] , Next[ maxn ] , Head[ maxn ] , Dis[ maxn ] , Vis[ maxn ] , n , m , u , v , w , rua ;
std :: vector < std :: pair < int , int > > G[ maxn ] ;
struct HeapNode
{
	int u , d ;
} ;

std :: priority_queue < HeapNode > q ;
bool operator < ( HeapNode kkk , HeapNode yyy )
{
	return kkk.d > yyy.d ;
}

inline void Add( int u , int v , int w )
{
	V[ ++tot ] = v ; W[ tot ] = w ; Next[ tot ] = Head[ u ] ; Head[ u ] = tot ;
}

void Dijkstra( int d )
{
	memset( Dis , 0x3f , sizeof( Dis ) ) ; Dis[ d ] = 0 ;
	
}

int main() 
{
	freopen( "rebirth.in" , "r" , stdin ) ;
	freopen( "rebirth.out" , "w" , stdout ) ;
	scanf( "%d%d%d" , &rua , &n , &m ) ;
	for( int i = 1 ; i <= m ; ++i )
	{
		scanf( "%d%d%d" , &u , &v , &w ) ; Add( u , v , w ) ; Add( v , u , w ) ;
	}
	
	return 0 ;
}

