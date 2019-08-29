#include <bits/stdc++.h>
using namespace std;
long long Y;
int a[100],x[200100],y[200100],tot,n,qi;

/*template <typename _Tp> _Tp read (){
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
}*/

int main (){
	//freopen("review.in","r",stdin);
	//freopen("review.out","w",stdout);
	scanf("%lld", &Y);
	if(Y == 1)
		printf("2 1\n1 2\n");
	else 
		if(Y == 2)
			printf("3 3\n1 2\n2 3\n1 3\n");
		else 
		 	if(Y == 3)
		 		printf("4 5\n1 2\n1 3\n1 4\n2 3\n3 4\n");
			else 
				if(Y == 4)
					printf("4 6\n1 2\n1 3\n1 4\n2 3\n2 4\n3 4\n");
				else
					if(Y == 5)
						printf("5 8\n1 2\n1 3\n1 4\n1 5\n2 3\n2 4\n3 4\n4 5");
					else 
						if(Y <= 63){
							for(int i = 3; i <= Y + 1; ++i){
								x[++tot] = 1;
								y[tot] = i; 
							}
							printf("64 %d\n", tot+64);
							for(int i = 1; i <= tot; ++i)
								printf("%d %d\n", x[i], y[i]);
							for(int i = 1; i <= 63; ++i)
								printf("%d %d\n", i, i+1);
						} else {
							for(int i = 1; i <= 63; ++i){
								x[++tot] = i;
								y[tot] = i+1;
							}
							for(int i = 3; i <= 64; ++i){
								x[++tot] = 1;
								y[tot] = i; 
							}
							a[1] = 1;
							for(int i = 2; i <= 64; ++i)
								a[i] = i - 1;
							n = 62;
							while(1){
								while(a[64] + a[n] > Y) 
									--n;
								if(a[64] + a[n] == Y){
									x[++tot] = n;
									y[tot] = 64;
									break;
								}
								for(int i = 64-n-1; i >= 1; --i)
									if(i * a[n] + a[64] < Y){
										qi = i;
										break;
									}
								for(int i = n+2; i <= n + qi + 1; ++i){
									x[++tot] = n;
									y[tot] = i;
									for(int j = i; j <= 64; ++j)
										a[j] += a[n];
								}
								if(a[64] == Y)
									break;
								--n;
							}
							printf("64 %d\n", tot);
							for(int i = 1; i <= tot; ++i)
								printf("%d %d\n", x[i], y[i]);
						}
	return 0;
}

