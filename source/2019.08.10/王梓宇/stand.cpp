#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10];
int bl[300],br[300];
struct node{
	int x,y;
};
node c[10000009];
bool cmpp(node x,node y){
	return x.x>y.x;
}
long long ans;
inline int read(){int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch<='9'&&ch>='0'){x*=10;x+=(ch-'0');ch=getchar();}
	return x*f;
}
long long f(int x){
	long long ans=0;
	long long y=x;
	for(int i=1;i<=5;++i){
		ans+=y*a[i];
		y*=x;
	}
	return ans;
}
void work(int x){
	for(int i=1;i<=n;++i){
		if(bl[i]<=x&&br[i]>=x){
			for(int j=bl[i];j<=br[i];++j){
			for(int k=1;k<=m;++k){
				if(c[k].y==j){
					c[k].x--;
				}
				break;
			}
			}
		}
	}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	bool fg_1=true;
	n=read(),m=read();
	for(int i=1;i<=5;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		c[i].y=i;
	}
	for(int i=1;i<=n;++i){
		bl[i]=read();
		br[i]=read();
		if(bl[i]!=1||br[i]!=m){
			fg_1=false;
		}
		c[bl[i]].x++;
		c[br[i]+1].x--;
	}
	if(fg_1){
		ans=f(n);
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=m;++i){
		c[i].x+=c[i-1].x;
	}
	sort(c+1,c+1+m,cmpp);
	while(n){
		if(n<c[1].x){
			ans+=f(n);
			n=0;
		}
		if(n>=c[1].x){
			n-=c[1].x;
			ans+=f(c[1].x);
			work(c[1].y);
		}
		sort(c+1,c+1+m,cmpp);
	}
	printf("%lld",ans);
	return 0;
}


