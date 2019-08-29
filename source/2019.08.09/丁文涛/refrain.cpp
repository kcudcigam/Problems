#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int SIZ= 1e4;
const int P	 =1e9+7;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int ret,w,c;
	while((c=readc())>'9'||c<'0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret;
}
const int MAXN =2e5+3,MAXM=MAXN;
int n,n1,n2,num,cnt,t,ttt[MAXN];
bool typ,val[MAXM*2],vis[MAXM*2];
int tot,head[MAXN],ver[MAXM*2],nxt[MAXM*2];
void add(int u,int v,bool w){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot,val[tot]=w;
}
int calc(int u){
	cnt++,vis[u]=true;
	if(ttt[u]==1) typ=true;
	for(int i=head[u];i;i=nxt[i]){
		if(!vis[ver[i]]) t+=val[i],vis[ver[i]]=true,calc(ver[i]);
	}
}
map <int,int> mmp[3];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	LL ans=1;
	num=qread(),n=qread(),n1=qread(),n2=qread();
	up(1,n1,i){
		int u=qread(),v=qread();
		add(u,v,0),add(v,u,0);
		ttt[u]++,ttt[v]++;
	}
	up(1,n2,i){
		int u=qread(),v=qread();
		add(u,v,1),add(v,u,1);
		ttt[u]++,ttt[v]++;
	}
	up(1,n,i){
		if(vis[i]) continue;
		cnt=t=typ=0,calc(i);
		if(typ){	//line or point
			if(!(cnt&1)) ans=(ans<<1)%P;
			mmp[t&1][cnt]++,ans=(LL)ans*mmp[t&1][cnt]%P;
		}else{		//circle
			ans=((LL)ans*cnt)%P;
			mmp[2  ][cnt]++,ans=(LL)ans*mmp[2  ][cnt]%P;
		}
	}
	LL all=1;
	up(1,n,i) all=(LL)all*i%P;
	printf("%lld\n",((LL)all-ans+(P))%P);
	return 0;
} 
/*
1
3 1 1
1 2
2 3
*/
