#include<bits/stdc++.h>
using namespace std;
int g[6];
int a[251][2];
int b[251];
int vis[251];
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
int js(int x){
	int a=x;
	int b=x*x;
	int c=x*x*x;
	int d=x*x*x*x;
	int e=x*x*x*x*x;
	return g[1]*a+g[2]*b+g[3]*c+g[4]*d+g[5]*c;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m,l,r;
	read(n);read(m) ;
	for(int i=1;i<=5;i++){
		read(g[i]);
	}
	for(int i=1;i<=n;i++){
		read(l),read(r);
		a[i][0]=min(l,r);
		a[i][1]=max(l,r);	
		for(int j=a[i][0];j<=a[i][1];j++){
			b[j]++;
		}
	}
	int maxx=-1,maxi;
	int rs=n,ans=0;
	while(rs>0){
		for(int i=1;i<=m;i++){
			if(b[i]>maxx){
				maxx=b[i];
				maxi=i;
			}
		}
		rs-=maxx;
		for(int i=1;i<=n;i++){
			if(a[i][0]<=maxi&&a[i][1]>=maxi&&vis[i]==0){
				for(int j=a[i][0];j<=a[i][1];j++){
					b[j]--;
				}
				vis[i]=1;
			}
			
		}
		ans+=js(maxx);
		maxx=-1;
}
	cout<<ans;
	return 0;
}


