#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int N=1010;
const int Mod=1000000007;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int n,X;
LL f[20010],ans,tag[20010],g[20010];
struct Note{
	int a,b,c;
}p[N];
bool cmp(Note a,Note b){return a.a>b.a;}
void Ad(LL &x,LL y){x=(x+y)%Mod;}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=R();X=R();
	F(i,1,n)p[i].a=R(),p[i].b=R(),p[i].c=R();
	sort(p+1,p+1+n,cmp);
	f[0]=1;
	F(i,1,n){
		D(j,X-1,X-p[i].a){
			if(j<0)continue;
			int ma=j+p[i].a*2;
			for(int k=j;k>=0;k-=p[i].a){
				Ad(tag[k+p[i].a],f[k]);
				Ad(tag[min(k+p[i].a*(p[i].b+1),ma)],Mod-f[k]);
			}
		}
		//F(o,0,X+X)printf("%d tag:%lld\n",o,tag[o]);
		F(j,0,20000){
			if(j>=p[i].a)Ad(tag[j],tag[j-p[i].a]);
			Ad(f[j],tag[j]);
		}
		F(j,0,20000)tag[j]=0;
		//F(o,0,10)printf("f[%d] %lld\n",o,f[o]);printf("\n");
	}
	g[0]=1;
	F(i,1,n){
		D(j,20000,20000-p[i].a+1){
			if(j<0)continue;
			int ma=j;
			for(int k=j;k>=0;k-=p[i].a){
				if(k+p[i].a>20000)continue;
				Ad(tag[k+p[i].a],g[k]);
				Ad(tag[min(k+p[i].a*(p[i].c+1),ma)],Mod-g[k]);
			}
		}
		//F(o,0,X+X)printf("tag[%d] %lld\n",o,tag[o]);printf("\n");
		F(j,0,20000){
			if(j>=p[i].a)Ad(tag[j],tag[j-p[i].a]);
			Ad(g[j],tag[j]);
		}
		F(j,0,20000)tag[j]=0;
		//F(o,0,10)printf("g[%d] %lld\n",o,g[o]);printf("\n");
	}
	F(i,X,20000)Ad(ans,g[i-X]*f[i]);
	cout<<ans<<'\n';
	return 0;
}
