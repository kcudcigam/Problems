#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
struct Info{
	int laozi;
	int nmz;
	int ans;
}a[500010];
void gao(int);
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int N,Q;
	read(N);read(Q);
	for(int i=1;i<=N;++i){
		a[i].laozi=a[i].nmz=0;
		a[i].ans=-INT_MAX;
	}
	
	for(int i=1;i<=Q;++i){
		int b,x,y;
		read(b);read(x);read(y);
		if(b==1){
			while(true){
				if(a[x].laozi!=0)x=a[x].laozi;
				else break;
			}
			while(true){
				if(a[y].laozi!=0)y=a[y].laozi;
				else break;
			}
			if(x!=y){
				a[y].laozi=x;
				a[y].nmz-=a[x].nmz;
			}
		}
		if(b==2){
			while(true){
				if(a[x].laozi!=0)x=a[x].laozi;
				else break;
			}
			a[x].nmz+=y;
		}
	}
	
	for(int i=1;i<=N;++i){
		if(a[i].ans==-INT_MAX)gao(i);
	}
	
	for(int i=1;i<N;++i){
		printf("%d ",a[i].ans);
	}
	printf("%d\n",a[N].ans);
	return 0;
}
void gao(int k){
	if(a[k].laozi==0){
		a[k].ans=a[k].nmz;
		return;
	}
	if(a[a[k].laozi].ans!=-INT_MAX){
		a[k].ans=a[a[k].laozi].ans+a[k].nmz;
		return;
	}
	gao(a[k].laozi);
	a[k].ans=a[a[k].laozi].ans+a[k].nmz;
	return;
}

