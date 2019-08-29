#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define LL long long
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define SZ(x) (int)x.size()-1
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
bool OO(LL k){
	int a[10],s=0; ms(a,0);
	while (k) s+=(!a[k%10]),a[k%10]=1,k/=10;
	return s<=2;
}
int gg(LL k){
	int a[10],s=0; ms(a,0);
	while (k) s+=(!a[k%10]),a[k%10]=1,k/=10;
	return s;	
}
bool fuck(LL x){
	if (OO(x)) return 1;
	F(i,1,x-1){
		if (OO(i) && OO(x-i)) return 1;
	}
	return 0;
}
const int M=1e6+10;
tr1::unordered_map<LL,bool> mp;
LL g[M];
int N;
void dfs(int x,int y,int dep,LL now){
//	cout<<dep<<"\n";
	if (dep>1){
		g[++g[0]]=now;
	}
	if (dep==14) return ;
	dfs(x,y,dep+1,now*10+x);
	dfs(x,y,dep+1,now*10+y);
}
int ans;
int f[M];
void dd(LL x,int dep){
//	cout<<x<<"\n";
	if (x<=10000){
		ans=min(ans,dep+f[x]-1);
		return ;
	}
	if (mp[x]){
		ans=min(ans,dep);
		return ;
	}
	if (dep>2) return ;
	int p=lower_bound(g+1,g+N+1,x)-g;
	if (g[p]>x) p--;
	while (g[p]>=(x-x/(3-dep+1))){
		dd(x-g[p],dep+1);
		p--;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
//	F(i,1,13345){
//		if (!fuck(i)) cout<<i<<"\n";
//	}
//	cout<<fuck(2109)<<"\n";
	F(i,1,10000) {
		if (OO(i)) f[i]=1;
		else f[i]=2;
	}
	F(i,1,9){
		LL o=0;
		F(j,1,13){
			o=o*10+j;
			g[++g[0]]=o;
		}
	}
	F(i,0,9){
		F(j,i+1,9){
			dfs(i,j,1,0);
		}
	}
//	cout<<g[0]<<"\n";
	sort(g+1,g+g[0]+1);
	N=unique(g+1,g+g[0]+1)-g-1;
//	cout<<g[N]<<"\n";
	F(i,1,N) mp[g[i]]=1; 
//	cout<<N<<"\n";
	int T=read();
	while (T--){
		ans=100;
		LL x=read();
		dd(x,1);
		cout<<ans<<"\n";
	}
	return 0;
}

