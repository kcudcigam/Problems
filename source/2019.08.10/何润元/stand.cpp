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
int n,m,ff[260],l[260],r[260],s1[260];
ll ans,f[260],g1,g2,g3,g4,g5,s2[260],cm[260];
inline void dfs(int dep,ll s){
	if(dep>n)checkmax(ans,s);
	else {
		F(i,l[dep],r[dep]){
			ff[i]++;
			s+=f[ff[i]];
			dfs(dep+1,s);
			s-=f[ff[i]];
			ff[i]--;
		}
	}
}
inline void dfs2(int dep,int sum,ll an){
	if(dep==1)checkmax(ans,an+f[1]*sum*1LL);
	else {
		int ff=0;
		F(i,1,m)
			if(s1[i]==dep){
				ff=1;
				ll lp=0;
				int ss=0;
				DF(j,50,1)
					if(s2[i]-cm[j]>=0){
						F(k,l[j],r[j]){s2[k]-=cm[j];s1[k]--;lp+=cm[j];}
						ss++;
					}
				dfs2(dep,sum-ss,an+f[ss]);
				DF(j,50,1)
					if(lp-cm[j]>=0)
						F(k,l[j],r[j]){s2[k]+=cm[j];s1[k]++;lp-=cm[j];}
			}
		if(!ff)dfs2(dep-1,sum,an);
	}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);
	read(g1);read(g2);read(g3);read(g4);read(g5);
	for(ll i=1;i<=250;i++)f[i]=g1*i+g2*i*i+g3*i*i*i+g4*i*i*i*i+g5*i*i*i*i*i;
	int f1=1;
	F(i,1,n){
		read(l[i]);read(r[i]);
		if(l[i]!=1||r[i]!=m)f1=0;
	}
	if(f1){
		writeln(f[n]);
		return 0;
	}
/*	if(m<=5){
		dfs(1,0);
		writeln(ans);
		return 0;
	}*/
	cm[1]=1;
	F(i,2,50)cm[i]=cm[i-1]*2;
	int mx=0;
	F(i,1,n)
		F(j,l[i],r[i]){
			s1[j]++;
			s2[j]+=cm[i];
			checkmax(mx,s1[j]);
		}
	dfs2(mx,n,0);
	writeln(ans);
	return 0;
}

