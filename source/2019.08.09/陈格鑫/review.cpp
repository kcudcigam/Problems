#include <bits/stdc++.h>
using namespace std;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) +(c&15), c=getchar();
	return num*f;
}

int y;

int main ()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%d", &y);
	if( y <= 63 )
	{
		printf("%d %d\n1 %d", y+1,(y<<1)-1,y+1);
		for(register int i=2; i<y+1; ++i)
		  printf("\n1 %d\n%d %d", i,i,y+1);
	}
	else if( y<=124 )
	{
		int num=0, op=0;
		printf("64 %d\n1 64", y+62);
		for(register int i=2; i<64; ++i)
		  printf("\n1 %d\n%d 64", i,i);
		for(register int i=2; i<63; ++i){
		  for(register int j=i+1; j<64; ++j)
		  {
		  	++num;
		  	printf("\n%d %d", i,j);
		  	if( num == y-63 )
		  	{
		  		op=1;
		  		break;
			}
		  }
		  if( op ) break;
	    }
	}
	else{
		printf("%d %d\n1 %d", y+1,(y<<1)-1,y+1);
		for(register int i=2; i<y+1; ++i)
		  printf("\n1 %d\n%d %d", i,i,y+1);
	}
	return 0;
}
