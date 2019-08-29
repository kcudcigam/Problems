#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;++i)
#define dn(r,l,i) for(register int i=r;i>=l;--i)
using namespace std;
typedef long long LL;
const int INF =2147483647;
const int SIZ =1e5;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
LL qread(){
	LL ret,w=1,c;
	while((c=readc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =3e5+3,MAXM=3e5+3;
map <pair<int,int>,bool> mmp;
LL tag[MAXN],tot,head[MAXN],nxt[MAXM*2],ver[MAXM*2];
LL _tot,_head[MAXN],_nxt[MAXM*2],_ver[MAXM*2];
LL x,y,t,val[MAXN],n,m,q,fa[MAXN],siz[MAXN];
void  add(int u,int v){
	 ver[++ tot]=v, nxt[ tot]= head[u], head[u]= tot;
}
void _add(int u,int v){
	_ver[++_tot]=v,_nxt[_tot]=_head[u],_head[u]=_tot;
}
bool vis[MAXN],typ[MAXN];
void upd(int u,int w){
	vector<int> tmp;
	for(int i=head[u];i;i=nxt[i])
	if(!vis[ver[i]])vis[ver[i]]=true,tmp.push_back(ver[i]);
	up(1,tmp.size(),i) vis[tmp[i-1]]=false,val[tmp[i-1]]+=w;
}
void bld(int u){
	vector<int> tmp;
	for(int i=head[u];i;i=nxt[i])
	if(typ[ver[i]]&&!vis[ver[i]])vis[ver[i]]=true,tmp.push_back(ver[i]);
	up(1,tmp.size(),i) vis[tmp[i-1]]=false,_add(u,tmp[i-1]);
}
LL calc(int u){
	LL sum=0;
	for(int i=_head[u];i;i=_nxt[i])
	sum+=tag[_ver[i]];
	return sum+val[u];
}
void qwrite(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) qwrite(x/10);
	putchar('0'+x%10);
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=qread(),m=qread(),q=qread(),t=ceil(sqrt(2*m))+1;
	up(1,m,i){
		int u=qread(),v=qread();
		if(u==v||mmp[make_pair(u,v)]) continue;
		add(u,v),add(v,u),siz[u]++,siz[v]++;
		mmp[make_pair(u,v)]=true;
	}
	up(1,n,i) typ[i]=(siz[i]>t);
	up(1,n,i) vis[i]=true,bld(i),vis[i]=false;
	up(1,q,i) switch(qread()){
		case 0:
			x=qread(),printf("%lld\n",calc(x)); break;
		case 1:
			x=qread(),y=qread();
			if(typ[x]) val[x]+=y,tag[x]+=y;	//heavy
			else val[x]+=y,vis[x]=true,upd(x,y),vis[x]=false;
	}
	return 0;
} 
