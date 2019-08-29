#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F(i,j,k) for(int i=j;i<=k;i++)
#define DF(i,j,k) for(int i=j;i>=k;i--)
#define M make_pair
#define P pair
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inline void write(T x){
	T l=0;
	ull y=0;
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
ll n,tot,nxt[401000],to[401000],val[401000],h[2][401000],head[401000],dis[401000],ans[401000],l1[401000],l2[401000];
const ll INF=1e15+2000;
inline void add(int x,int y,int len,int num,int num2){
	nxt[++tot]=head[x];
	to[tot]=y;
	val[tot]=len;
	h[num2][num]=tot;
	head[x]=tot;
}
inline void SPFA(){
	queue<int>q;
	q.push(1);
	F(i,1,n)dis[i]=INF;
	dis[1]=0;
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(int i=head[x];i;i=nxt[i])
			if(dis[to[i]]>dis[x]+val[i]){dis[to[i]]=dis[x]+val[i];q.push(to[i]);}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num;read(num);
	int m;read(n);read(m);
	F(i,1,m){
		int x,y,len;read(x);read(y);read(len);
		add(x,y,len,i,0);
		add(y,x,len,i,1);
		l1[i]=x;
		l2[i]=y;
	}
	F(i,1,m){
		cout<<i<<endl;
		ll t=val[h[0][i]];
		val[h[0][i]]=val[h[1][i]]=INF;
		SPFA();
		val[h[0][i]]=val[h[1][i]]=t;
		checkmax(ans[l1[i]],dis[l1[i]]);
		checkmax(ans[l2[i]],dis[l2[i]]);
	}
	F(i,1,n)if(ans[i]==INF)ans[i]=-1;
	F(j,1,n-1)writes(ans[j]);
	writeln(ans[n]);
	return 0;
}

