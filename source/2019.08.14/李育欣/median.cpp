#include<bits/stdc++.h>
using namespace std;
int read() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
const int N=500001;
int n,m,a[N],b[N],a1[N],b1[N];
int work(int x,int y){
	if(x>y){
		for(int i=1;i<=y;i++){
			a1[i+x]=b1[i];
		}
		sort(a1+1,a1+x+y+1);
		printf("%d\n",a1[(x+y)/2+1]);
	}
	else{
		for(int i=1;i<=x;i++){
			b1[i+y]=a1[i];
		}
		sort(b1+1,b1+x+y+1);
		printf("%d\n",b1[(x+y)/2+1]);
	}
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	while(m--){
		int o=read();
		if(o==1){
			int x=read(),y=read(),z=read();
			if(x==0)a[y]=z;
			else b[y]=z;
		}
		else {
			memset(a1,0,sizeof(a));
			memset(b1,0,sizeof(b));
			int l1=read(),r1=read(),l2=read(),r2=read();
			int la=0,lb=0;
			for(int i=l1;i<=r1;++i){
				a1[++la]=a[i];
			}
			for(int i=l2;i<=r2;++i){
				b1[++lb]=b[i];
			}
			work(la,lb);
		}
	}
	return 0;
}

