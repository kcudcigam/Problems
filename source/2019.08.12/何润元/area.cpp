#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F(i,j,k) for(int i=j;i<=k;i++)
#define DF(i,j,k) for(int i=j;i>=k;i--)
#define P pair
#define M make_pair
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inline void write(T x){
	ull y=0;
	T l=0;
	if(!x){putchar(48);return;}
	if(x<0){x=-x;putchar('-');}
	while(x){y=y*10+x%10;x/=10;l++;}
	while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void checkmax(T &a,T b){a=max(a,b);}
template<typename T>inline void checkmin(T &a,T b){a=min(a,b);}
map<ull,int> f;
const int dx[5]{0,1,0,-1,0},dy[5]={0,0,1,0,-1};
int ff[110][110];
int cha(ll x,ll y){
	int an=1;
	while(x!=1||y!=1){
		ll nk=1;
		while(nk*2<x||nk*2<y)nk*=2;
		if(x>nk&&y>nk)an*=-1;
		if(x>nk)x-=nk;
		if(y>nk)y-=nk;
	}
	return an;
}
ll ans=0;
ll k=1e10;
queue <P<ll,ll> >q;
inline void bfs(ll x,ll y){
	q.push(M(x,y));
	f[x*k+y]=1;
	int p=cha(x,y);
	while(!q.empty()){
		ll bx=q.front().first,by=q.front().second;q.pop();
		f[bx*k+by]=1;
		if(bx==1||by==1){ans=-1;break;}
		ff[bx][by]=1;
		F(i,1,4)
			if(!f[(bx+dx[i])*k+by+dy[i]]&&cha(bx+dx[i],by+dy[i])==p)q.push(M(bx+dx[i],by+dy[i]));
	}
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int x,y;read(x);read(y);x++;y++;
	bfs(x,y);
	if(ans==-1){puts("infinity");return 0;}
	F(i,1,100){
		F(j,1,100)
			ans+=ff[i][j];
	}
	writeln(ans);
	return 0;
}
