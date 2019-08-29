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
const long long p=998244353;
long long n,m;
long long a[2000],w;
string st;
long long ksm(long long a,long long b){
	long long res=1,base=a;
	while(b){
		if(b&1)res=res*base%p;
		base=base*base%p;
		b>>=1;
	} 
	return res;
}
long long tmax(long long x,long long y){
	if(x>y)return x;
	return y;
}
bool check(){
	if(n<st.size())return 0;
	long long i=0,j=st.size()-1,l=1,r=n;
	while(i<=j){
		bool flg=0;
		if(st[i]==a[l]){
			i++;l++;
			flg=1;
		}
		if(st[j]==a[r]){
			j--;r--;
			flg=1;
		}
		if(!flg)return 0;
	}
	return 1;
}
void dfs(long long dep){
	if(dep>n){
		if(!check())w++;
	}else{
		for(long long i='a';i<='z';i++){
			a[dep]=i;
			dfs(dep+1);
		}
	}
}
void baoli(){
	w=0;
	dfs(1);
	writeln(w);
}
void xuanxue(){
	writeln((ksm(26,n)%p-(ksm(26,n-m)%p*(m+1)%p-ksm(26,tmax(n-m-1,0))%p*m%p+p)%p+p)%p);
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	read(n);
	cin>>st;
	m=st.size();
	
	if(n<=4){
		baoli();
	}else{
		xuanxue();
	}
	return 0;
}



