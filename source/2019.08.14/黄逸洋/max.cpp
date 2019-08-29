#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
long long P=1e9+7;
long long n,m,q;
long long x[200010],y[200010],p[200010];
long long l[200010],r[200010];
long long acti[200010],fina[200010],ans=0;

long long cbcx[200010];
vector<long long>a[200010];

long long fan(long long poss){
	return 1000000008-poss;
}
long long Maxx(long long l,long long r){
	long long res=-1e15;
	for(long long i=l;i<=r;i++){
		res=max(res,fina[i]);
	}
	return res;
}
void doit(long long poss){
	for(long long i=1;i<=n;i++)fina[i]=1e15;
	for(long long i=1;i<=m;i++){
		if(acti[i])fina[x[i]]=min(fina[x[i]],y[i]);
	}
	for(long long i=1;i<=n;i++){
		if(fina[i]==1e15)fina[i]=0;
	}
	
	for(long long i=1;i<=q;i++){
		long long res=Maxx(l[i],r[i]);
		ans=(ans+res*poss%P)%P;
	}
}
void dfs(long long dep,long long poss){
	if(poss==0)return;
	if(dep>m){
		doit(poss);
	}else{
		dfs(dep+1,poss*fan(p[dep])%P);
		acti[dep]=1;
		dfs(dep+1,poss*p[dep]%P);
		acti[dep]=0;
	}
}
void baoli(){
	ans=0;
	dfs(1,1);
	writeln(ans);
}
void xuanxue(){
	for(long long i=1;i<=m;i++){
		a[x[i]].push_back(i);
	}
	ans=0;
	for(long long i=1;i<=m;i++){
		cbcx[i]=p[i];
		for(long long j=0;j<a[i].size();j++){
			long long tmp=a[i][j];
			if(y[tmp]<y[i])cbcx[i]=cbcx[i]*fan(p[tmp])%P;
		}
		ans=(ans+cbcx[i]*y[i]%P)%P;
	}
	writeln(ans);
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);

	read(n);read(m);read(q);
	for(long long i=1;i<=m;i++){
		read(x[i]);read(y[i]);read(p[i]);
	}
	for(long long i=1;i<=q;i++){
		read(l[i]);read(r[i]);
	}
	
	if(n<=20)baoli();
	else if(q==n)xuanxue();
	return 0;
}
/*
3 3 2
1 1 500000004
2 2 333333336
3 3 1
1 2
2 3

3 3 3
1 1 500000004
2 2 333333336
3 3 1
1 1
2 2
3 3

3 3 3
1 1 1
2 2 1
3 3 1
1 1
2 2
3 3

*/


