#include<bits/stdc++.h>
#define N 300010
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n,m,q;
struct side{
	int v,last;
};
int head[N];
side c[N<<1];
int len;
struct node{
	int type,x,y;
};
node que[N];
int sum[N];
int du[N];
bool vis[N];
int fa[N];
int tag[N];
bool connect[N];
void put(int x,int y){
	c[++len].v=y;
	c[len].last=head[x];
	head[x]=len;
	return;
}
void bl(){
	for (int i=1;i<=q;i++){
		if (!que[i].type) printf("%d\n",sum[que[i].x]);
		else for (int j=head[que[i].x];j;j=c[j].last) sum[c[j].v]+=que[i].y;
	}
	return;
}
bool checktask1(){
	for (int i=1;i<=m;i++) if (du[c[i*2].v]>1&&du[c[i*2-1].v]>1) return false;
	return true;
}
void subtask1(){
	for (int i=1;i<=n;i++)
		if (du[i]>1){
			for (int j=head[i];j;j=c[j].last) fa[c[j].v]=i;
		}
	for (int i=1;i<=q;i++){
		if (!que[i].type) printf("%d\n",du[que[i].x]>1?sum[que[i].x]:(sum[que[i].x]+tag[fa[que[i].x]]));
		else 
			if (du[que[i].x]>1){
				sum[que[i].x]+=que[i].y;
				tag[que[i].x]+=que[i].y;
			}
			else{
				sum[que[i].x]+=que[i].y;
				sum[fa[que[i].x]]+=que[i].y;
			}
	}
	return;
}
bool checktask2(){
	for (int i=2;i<=n;i++) if (du[i]>10) return false;
	return true;
}
void subtask2(){
	memset(connect,false,sizeof(connect));
	int extra=0;
	for (int i=head[1];i;i=c[i].last) connect[c[i].v]=true;
	for (int i=1;i<=q;i++){
		if (!que[i].type){
			if (que[i].x==1) printf("%d\n",sum[1]+extra);
			else{
				int res=0;
				for (int j=head[que[i].x];j;j=c[j].last) res+=sum[c[j].v];
				printf("%d\n",res);
			}
		}
		else{
			sum[que[i].x]+=que[i].y;
			if (connect[que[i].x]) extra+=que[i].y;
		}
	}
	return;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n);read(m);read(q);
	for (int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		put(x,y);
		put(y,x);
		du[x]++;
		du[y]++;
	}
	for (int i=1;i<=q;i++){
		read(que[i].type);
		read(que[i].x);
		if (que[i].type) read(que[i].y);
	}
	if (n<=3000&&m<=3000){
		bl();
		return 0;
	}
	if (checktask1()){
		subtask1();
		return 0;
	}
	if (checktask2()){
		subtask2();
		return 0;
	}
	return 0;
}

