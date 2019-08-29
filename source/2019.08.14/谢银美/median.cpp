#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100005],b[100005];
int c[200005];
int q,x,y,z;
int l1,r1,l2,r2,tot;
int read() {
	char c = getchar(); 
	int x = 0; 
	for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) 
		x = x * 10 - '0' + c; 
	return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read();
	m=read();
	for (int i = 1; i <= n; ++ i)
		a[i]=read();
	for (int i = 1; i <= n; ++ i)
		b[i]=read();
	for (int i = 1; i <= m; ++ i){
		q=read();
		if (q == 1){
			x=read();
			y=read();
			z=read();
			if (x == 0)
				a[y] = z;
			else
				b[y] = z;
		}
		else{
			l1=read();
			r1=read();
			l2=read();
			r2=read();
			for (int j = 1; j <= (r1-l1+1); ++ j)
				c[j] = a[l1+j-1];
			tot = r1-l1+1;
			for (int j = 1; j <= (r2-l2+1); ++ j)
				c[tot+j] = b[l2+j-1];
			tot += r2-l2+1;
			sort(c+1,c+1+tot);
			int mid = (tot+1)/2;
			printf("%d\n",c[mid]);
			
		}
	}
	return 0;
}

