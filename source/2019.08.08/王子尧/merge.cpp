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
struct wzy{
	int nxt,vertice;
}edge[12010];
int head[6010];
int len=0;
inline void add_edge(int x,int y){
	edge[++len].nxt=head[x];edge[len].vertice=y;
	head[x]=len;return;
}
int ans[6010];

bool in[6010];queue<int>v;
inline void scz(int a,int b){
	memset(in,0,sizeof(in));v.push(a);in[a]=1;ans[a]+=b;
	while(!v.empty()){
		int nop=v.front();v.pop();
		for(int i=head[nop];i;i=edge[i].nxt){
			int temp=edge[i].vertice;
			if(in[temp])continue;
			ans[temp]+=b;in[temp]=1;v.push(temp);
		}
	}
	return;
}

int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);

	int n,Q;read(n);read(Q);
	rep(i,1,Q){
		int tmp,a,b;read(tmp);read(a);read(b);
		if(tmp==1){
			add_edge(a,b);add_edge(b,a);
		}else{
			scz(a,b);
		}
	}
	rep(i,1,n){qwq(ans[i]);putchar((i==n)?'\n':' ');}
	return 0;
}
