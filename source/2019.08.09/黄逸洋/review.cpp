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
int N;
void doit1(){
	cout<<N+1<<' '<<2*N-1<<endl;
	
	for(int i=2;i<=N;i++){
		cout<<1<<' '<<i<<endl;
		cout<<i<<' '<<N+1<<endl;
	}
	cout<<1<<' '<<N+1<<endl;
}
void doit2(){
	int tmp=log2(N);
	int n=tmp+2,m=(tmp+1)*(tmp+2)/2;
	cout<<n<<' '<<m<<endl;
	
	cout<<1<<' '<<n<<endl;
	for(int i=2;i<n;i++){
		cout<<1<<' '<<i<<endl;
		cout<<i<<' '<<n<<endl;
	}
	for(int i=2;i<n-1;i++){
		for(int j=i+1;j<=n-1;j++){
			cout<<i<<' '<<j<<endl;
		}
	}
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	
	read(N);
	if(N<=50){
		doit1();
	}else if(N&(N-1)==0){
		doit2();
	}else{
		doit1();
	}
	return 0;
}



