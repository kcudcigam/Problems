#include<bits/stdc++.h>
using namespace std;
int t[100001],x[100001],y[100001];
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inline void write(T x){
	T l=0;
	unsigned long long y=0;
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
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T,n;
	read(T);
	int sum,tim;
	int s=0;
	for(int i=1;i<=T;i++){
		read(n);
		for(int i=1;i<=n;i++){
			read(t[i]);
			read(x[i]);
			read(y[i]);
			sum=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
			tim=t[i]-t[i-1];
			if(tim>=sum&&sum%2==tim%2){
				
			}else{
				s=1;
			}
		}
		if(s==0)puts("Yes");
		else puts("No");
	} 
	return 0;
}


