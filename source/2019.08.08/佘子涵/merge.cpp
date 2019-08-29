#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=500001;
long long n,q,f[N],s[N],pd,a,b;
long long get(int x){
	if(f[x]==x) return x;
	int ol=f[x];
	int nw=get(f[x]);
	if(ol==nw) return f[x];
	if(ol==x) s[x]=s[ol]-s[nw];
	else s[x]+=s[ol];
	f[x]=nw;
	return f[x];
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;i++) f[i]=i;
	while(q--){
		read(pd);read(a);read(b);
		if(pd==1){
			int fa=get(b);
			int fa1=get(a);
			f[fa]=fa1;
			s[fa]=s[fa]-s[fa1];
			if(fa!=b) s[b]+=s[fa];
		}
		if(pd==2){
			s[get(a)]+=b;
		}
	}
	for(int i=1;i<=n;i++){
		get(i);
		printf("%lld ",(i==f[i])?s[i]:s[i]+s[f[i]]);
	}
	return 0;
} 
