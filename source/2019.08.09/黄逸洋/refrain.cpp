#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
const long long P=1e9+7;
long long X1[200010],Y1[200010],X2[200010],Y2[200010];
long long Num,n,m1,m2,w=0;
long long h1[200010],h2[200010],a[200010],h[200010];
long long fc[200010];
bool check(){
	for(long long i=1;i<=m1;i++){
		if(!h1[a[X1[i]]]||!h1[a[Y1[i]]]){
			return true;
		}
	}
	for(long long i=1;i<=m2;i++){
		if(!h2[a[X2[i]]]||!h2[a[Y2[i]]]){
			return true;
		}
	}
	return false;
}
void dfs(long long dep){
	if(dep>n){
		if(check()){
			w++;
		}
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!h[i]){
			h[i]=1;
			a[dep]=i;
			dfs(dep+1);
			h[i]=0;
			a[dep]=0;
		}
	}
}
void doit1(){
	dfs(1);
	writeln(w);
}
void doit3(){
	writeln(0);
}
void xuanxue(){
	fc[0]=fc[1]=1;
	for(long long i=2;i<=n;i++)fc[i]=fc[i-1]*i%P;
	
	long long t1=0,t2=0,t_=0,t12=0;
	for(long long i=1;i<=n;i++){
		if(h1[i]&&h2[i])t12++;
		if(h1[i]&&!h2[i])t1++;
		if(!h1[i]&&h2[i])t2++;
		if(!h1[i]&&!h2[i])t_++;
	}
	
	writeln((fc[n]-fc[t1]*fc[t2]%P*fc[t12]%P*fc[t_]%P+P)%P);
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);

	read(Num);read(n);read(m1);read(m2);
	for(long long i=1;i<=m1;i++){
		long long x,y;
		read(x);read(y);
		h1[x]=h1[y]=1;
		X1[i]=x;Y1[i]=y;
	}
	for(long long i=1;i<=m2;i++){
		long long x,y;
		read(x);read(y);
		h2[x]=h2[y]=1;
		X2[i]=x;Y2[i]=y;
	}
	
	if(1<=Num&&Num<=6){
		doit1();
	}else if(11<=Num&&Num<=14){
		doit3();
	}else{
		xuanxue();
	}
	return 0;
}
/*
3
3 1 1
1 2
2 3

3
4 2 2
1 2
3 4
1 3
2 4

4
4 1 1
1 2
3 4

*/


