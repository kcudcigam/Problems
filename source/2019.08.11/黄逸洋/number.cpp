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
long long a[2000];
long long T,maxx=-1;
long long h[20];
long long tmax(long long x,long long y){
	if(x>y)return x;
	return y;
}
bool liked(long long x){
	memset(h,0,sizeof(h));
	while(x){
		h[x%10]++;
		x/=10;
	}
	long long t=0;
	for(long long i=0;i<=9;i++){
		if(h[i])t++;
	}
	return t<=2;
}
void pianfen(){
	for(long long i=1;i<=T;i++){
		if(liked(a[i])){
			writeln(1);
		}else{
			writeln(2);
		}
	}
	
}
void xiagao(){
	for(long long i=1;i<=T;i++){
		long long x=a[i];
		memset(h,0,sizeof(h));
		while(x){
			h[x%10]++;
			x/=10;
		}
		long long t=0;
		for(long long i=0;i<=9;i++){
			if(h[i])t++;
		}
		writeln((t+1)/2);
	}
	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	read(T);
	for(long long i=1;i<=T;i++){
		read(a[i]);
		maxx=tmax(maxx,a[i]);
	}
	
	if(maxx<=300000){
		pianfen();
	}else if(maxx<=1e13){
		xiagao();
	}
	return 0;
}



