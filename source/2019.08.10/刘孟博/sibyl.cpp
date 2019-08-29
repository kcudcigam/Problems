#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int MAXN=3e5+10,INF=0x3f3f3f3f;
int n,m,Q,fir[MAXN],to[MAXN<<1],cnt,nxt[MAXN<<1],a[MAXN],tmp[MAXN],mx=-INF,tag[MAXN],add[MAXN];
inline void ins(int x,int y){nxt[++cnt]=fir[x],to[cnt]=y;fir[x]=cnt;}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read(),m=read(),Q=read();
	for(int i=1,x,y;i<=m;i++){
		x=read(),y=read();
		ins(x,y),ins(y,x);++tmp[x],++tmp[y];
		if(x!=1)mx=max(mx,tmp[x]);
		if(y!=1)mx=max(mx,tmp[y]);
		if(x==1)tag[y]=1;if(y==1)tag[x]=1;
	}
	if(n<=3000&&m<=3000&&Q<=3000){
		while(Q--){
			int opt=read(),x=read();
			if(opt==0)printf("%d\n",a[x]);
			else{
				int y=read();a[x]+=y;
				for(int i=fir[x];i;i=nxt[i])a[to[i]]+=y;
			}
		}
	}else if(mx<=10){
		while(Q--){
			int opt=read(),x=read();
			if(opt==0)printf("%d\n",a[x]+add[1]*tag[x]);
			else{
				int y=read();a[x]+=y;
				if(x==1)add[1]+=y;
				else for(int i=fir[x];i;i=nxt[i])a[to[i]]+=y;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++)tag[i]=-1;
		for(int i=1;i<=n;i++)if(tmp[i]>=2){
			for(int j=fir[i];j;j=nxt[j])tag[to[j]]=i;
			tag[i]=0;
		}
		for(int i=1;i<=n;i++)if(tag[i]==-1){
			for(int j=fir[i];j;j=nxt[j])tag[to[j]]=i;
			tag[i]=0;
		}
		while(Q--){
			int opt=read(),x=read();
			if(opt==0)printf("%d\n",a[x]+add[tag[x]]);
			else{
				int y=read();a[x]+=y;
				if(!tag[x])add[x]+=y;
				else for(int i=fir[x];i;i=nxt[i])a[to[i]]+=y;
			}
		}
	}
	return 0;
}
