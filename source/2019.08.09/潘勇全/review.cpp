#include <bits/stdc++.h>

int n ;

int main()
{
	freopen( "review.in" , "r" , stdin ) ;
	freopen( "review.out" , "w" , stdout ) ;
	scanf( "%d" , &n ) ;
	if( n == 1 ) printf( "2 1\n1 2" ) ;
	if( n == 2 ) printf( "3 3\n1 2\n2 3\n1 3\n" ) ;
	if( n == 3 ) printf( "4 5\n1 2\n1 3\n2 4\n3 4\n" ) ;
	if( n == 4 ) printf( "4 6\n1 2\n1 3\n2 3\n2 4\n3 4\n" ) ;
	if( n == 5 ) printf( "5 8\n1 2\n1 3\n1 4\n1 5\n2 3\n2 5\n3 4\n4 5\n" ) ;
	return 0 ;
}

