#include <cstdio>

#define filein "hexodoku"

void prepare( )
{
	freopen( filein ".in", "r", stdin );
	freopen( filein ".out", "w", stdout );
}

#include <cmath>
#include <cassert>
#include <memory.h>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <functional>

using namespace std;

#define fo(a,b,c) for(a=(b);a<(c);++a)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
#define fk(a) fr(k,(a))
#define _(a,b) memset((a),(b),sizeof(a))
#define __(a) _((a),0)

const int dx[] = { 1, 0, -1, -1, 0, 1, 0 };
const int dy[] = { 0, 1, 1, 0, -1, -1, 0 };

const int MAXN = 7;
const int MAXF = 32;

char f[MAXN][MAXN + 1];
char m[MAXF];
char ansm[MAXF];
int ans;
vector<pair< int, int> > v[MAXN][MAXN];
vector<pair< int, int> > coord;
int p[MAXF][MAXF];
int pn[MAXF];
int need;
int MAXID;
int K, N;

bool test( )
{
	if ( ++ ans < N )
		return false;
	memcpy( ansm, m, sizeof( m ) );
	return true;
}

int makemask( const int &id )
{
	int i;
	int res = 0;
	int *pp = p[id];	
	int ppn = pn[id];
	fi( ppn )
	{
		int cv = m[pp[i]];
		if ( cv >= 0 )
			res |= 1 << cv;
	}
	return res;
}

bool brute( int id )
{
	if ( id == MAXID )
		return test( );
	if ( m[id] >= 0 )
		return brute( id + 1 );
	int mask = makemask( id );
	int i;
	fi( K )
	{
		if ( mask & ( 1 << i ) )
			continue;
		m[id] = i;
		if ( brute( id + 1 ) )
			return true;
		m[id] = -1;
	}
	return false;
}

void buildgraph( )
{
	_( f, -1 );
//	fprintf( stderr, "Build started\n" );
	int i, j, k;	
	fi( 7 ) if ( i <= 7 )
	{
		int y = 3;
		int x = 3;
		if ( i < 6 )
		{
			y += dy[i] * 2 + dy[( i + 4 ) % 6];
			x += dx[i] * 2 + dx[( i + 4 ) % 6];
		}
		fj( 7 )
		{
			int cx = x + dx[j];
			int cy = y + dy[j];
			f[cy][cx] = 0;
			fk( 7 ) if ( k != j )
			{
				v[cy][cx].push_back( make_pair( y + dy[k], x + dx[k] ) );				
			}
		}
	}
	int d;

	fi( MAXN ) fj( MAXN ) if ( !f[i][j] ) fr( d, 6 ) fo( k, 1, MAXN )
	{
		int cy = i + dy[d] * k;
		int cx = j + dx[d] * k;
		if ( cx < 0 || cy < 0 || cx >= MAXN || cy >= MAXN || f[cy][cx] )
			break;
		v[i][j].push_back( make_pair( cy, cx ) );
	}
	MAXID = 0;
	fi( MAXN ) fj( MAXN )
	{
		if ( f[i][j] == 0 )
		{
			coord.push_back( make_pair( i, j ) );
			f[i][j] = MAXID++;
		}
	}
	fi( MAXID )
	{
		vector<pair<int, int> > &tw = v[coord[i].first][coord[i].second];
		sort( tw.begin( ), tw.end( ) );
		tw.resize( unique( tw.begin( ), tw.end( ) ) - tw.begin( ) );
		fj( (int)tw.size( ) )
		{
			p[i][pn[i]++] = f[tw[j].first][tw[j].second];
		}
	}
//	fprintf( stderr, "Build finished\n" );
}

void readfield( )
{
//	fprintf( stderr, "Read started\n" );
	scanf( "%d %d", &K, &N );
	_( m, -1 );
	int i, j;
	fi( MAXID )
	{
		int temp;
		scanf( "%d", &temp );
		if ( temp == 0 )
			m[i] = -1;
		else
			m[i] = temp - 1;
	}
//	fprintf( stderr, "Read finished\n" );
}

void solve( )
{
	clock_t st = clock( );
//	fprintf( stderr, "Solve started\n" );
	if ( brute( 0 ) )
	{ 
		printf( "Found\n" );
		memcpy( m, ansm, sizeof( m ) );
		bool first = true;
		int i, j;
		fi( MAXID )
		{
			if ( first ) first = false;
			else printf( " " );
			printf( "%d", m[i] + 1 );
		}
		printf( "\n" );
/*
		fi( MAXN )
		{
			fj( i ) fprintf( stderr, " " );
			fj( MAXN )
			{
				if ( f[i][j] >= 0 )
				{
					fprintf( stderr, "%2d", m[f[i][j]] );
				}
				else
					fprintf( stderr, " -" );
			}
			fprintf( stderr, "\n" );
		}
*/	}
	else
	{
		printf( "No way\n" );
//		fprintf( stderr, "No way\nTotal ans found %d\n", ans );
	}
	st = clock( ) - st;
//	fprintf( stderr, "Solve finished %d\n", st );
}		

int main( )
{
	prepare( );
	int i, j, k;
	buildgraph( );	
	readfield( );
	solve( );

	return 0;

}

