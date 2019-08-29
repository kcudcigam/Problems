#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int ans[300010];bool in[300010];int deg[300010];
struct wzy{
	int nxt,vertice;
}edge[600010];
int head[300010];int len=0;
inline void add_edge(int x,int y){
	edge[++len].nxt=head[x];edge[len].vertice=y;
	head[x]=len;return;
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);

	int n,m,Q,x,y;read(n);read(m);read(Q);
	int opt=1;
	rep(i,1,m){
		read(x);read(y);add_edge(x,y);add_edge(y,x);
		deg[x]++;deg[y]++;
	}
	rep(i,2,n){opt&=(deg[i]<10);}

	if(!opt||n<=3000){
		rep(i,1,Q){
			int tmp;read(tmp);
			if(!tmp){read(x);write(ans[x]);}
			else{
				read(x);read(y);ans[x]+=y;
				for(int i=head[x];i;i=edge[i].nxt){
					ans[edge[i].vertice]+=y;
				}
			}
		}
	}else{
		for(int i=head[1];i;i=edge[i].nxt){in[edge[i].vertice]=1;}
		in[1]=1;int nop=0;
		rep(i,1,Q){
			int tmp;read(tmp);
			if(!tmp){
				read(x);write(ans[x]+(in[x]==1)*nop);
			}else{
				read(x);read(y);
				if(x==1){nop+=y;}
				else{
					ans[x]+=y;
					for(int i=head[x];i;i=edge[i].nxt){
						ans[edge[i].vertice]+=y;
					}
				}
			}
		}
	}
	return 0;
}
