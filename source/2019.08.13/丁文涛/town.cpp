#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =2147483647;
const int SIZ =1e5;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int w=1,c,ret=0;
	while((c=readc())>'9'||c<'0');
	ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0'; 
	return ret*w;
}
const int MAXN =3e5+3,MAXM=MAXN;
int n,edg[MAXN][2];
int tot,head[MAXN],nxt[MAXM],ver[MAXM];
void add(int u,int v){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
}
int dis[MAXN];
int calc(int t){
	queue<int> q; q.push(t); int lst=0;
	memset(dis,0,sizeof(dis)),dis[t]=1;
	while(!q.empty()){
		int u=q.front(); lst=u; q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=ver[i];
			if(!dis[v]) dis[v]=dis[u]+1,q.push(v);
		}
	}
	q.push(lst);
	memset(dis,0,sizeof(dis)),dis[lst]=1;
	while(!q.empty()){
		int u=q.front(); lst=u; q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=ver[i];
			if(!dis[v]) dis[v]=dis[u]+1,q.push(v);
		}
	}
	return dis[lst]-1;
}
bool sub;
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=qread();
	up(1,n-1,i){
		edg[i][0]=qread(),edg[i][1]=qread();
		if(edg[i][0]>i||edg[i][1]!=i+1) sub=false;
	}
	if(sub){
		up(1,n-1,i) printf("%d\n",i); exit(0);
	}
	up(1,n-1,i){
		int u=edg[i][0],v=edg[i][1];
		add(u,v),add(v,u);
		printf("%d\n",calc(u));
	}
	return 0;
} 
/*
5
3 5
3 4
1 2
1 3
*/
