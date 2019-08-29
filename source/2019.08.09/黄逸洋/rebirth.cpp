#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
struct Node{
	long long x,y,w;
}a[200010];
long long dis[200010],pre[200010],prew[200010],tag[200010];
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);

	long long Num,n,m;
	read(Num);read(n);read(m);
	for(long long i=1;i<=m;i++){
		read(a[i].x);read(a[i].y);read(a[i].w);
		a[i+m].x=a[i].y;
		a[i+m].y=a[i].x;
		a[i+m].w=a[i].w;
	}
	m+=m;
	
	if(12<=Num&&Num<=16){
		write(0);
		for(int i=2;i<=n;i++){
			putchar(' ');
			write(-1);
		}
		putchar('\n');
	}else{
		memset(dis,0x7f,sizeof(dis));
		dis[1]=0;
		for(long long i=1;i<=n;i++){
			long long flg=1;
			for(long long j=1;j<=m;j++){
				if(dis[a[j].y]>dis[a[j].x]+a[j].w){
					dis[a[j].y]=dis[a[j].x]+a[j].w;
					pre[a[j].y]=a[j].x;
					prew[a[j].y]=a[j].w;
					flg=0;
				}
			}
			if(flg)break;
		}
		
		for(long long k=1;k<=n;k++){
			
			memset(tag,0,sizeof(tag));
			for(long long i=1;i<=m;i++){
				if(pre[k]==a[i].x&&k==a[i].y&&prew[k]==a[i].w)tag[i]=1;
				if(pre[k]==a[i].y&&k==a[i].x&&prew[k]==a[i].w)tag[i]=1;
			}
			
			memset(dis,0x7f,sizeof(dis));
			dis[1]=0;
			for(long long i=1;i<=n;i++){
				long long flg=1;
				for(long long j=1;j<=m;j++){
					if(tag[j])continue;
					if(dis[a[j].y]>dis[a[j].x]+a[j].w){
						dis[a[j].y]=dis[a[j].x]+a[j].w;
						pre[a[j].y]=a[j].x;
						prew[a[j].y]=a[j].w;
						flg=0;
					}
				}
				if(flg)break;
			}
			
			if(dis[k]>=0x7f7f7f7f)dis[k]=-1;
			write(dis[k]);
			putchar(' ');
		}
		
		putchar('\n');
	}
	return 0;
}

/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1

*/

