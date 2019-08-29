#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int Num, n, m1, m2, ans, x[10010][2], y[10010][2];
template <typename _Tp> _Tp read (){
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) + (c&15), c=getchar();
	return num*f;
}
template <typename _Tp> void write (_Tp x){
	if( x<0 ) putchar('-'), write<_Tp>(~x+1);
	else
	{
		if( x>9 ) write<_Tp>(x/10);
		putchar(x%10+'0');
	}
}

int main (){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&Num);
	scanf("%d%d&d", &n, &m1, &m2);
	for(int i = 1; i <= m1; ++i)
		scanf("%d %d",x[i][0], x[i][1]);
	for(int i = 1; i <= m2; ++i)
		scanf("%d %d",y[i][0], y[i][1]);
	if(n == 1)
		ans = 1;
	else 
		if (n == 2){
			if(m1 == 0 && m2 == 0)
				ans = 1;
			else 
				ans = 0;
		} else {
			
		}
	printf("%d\n", ans%MOD);
	return 0;
}


