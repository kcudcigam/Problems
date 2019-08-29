#include<bits/stdc++.h>
using namespace std;
pair< int , int > s[256];
bool usd[256];
int x1,x2,x3,x4,x5;
inline long long calcu(int a){
	long long x=(long long)a;
	return x5*x*x*x*x*x+x4*x*x*x*x+x3*x*x*x+x2*x*x+x1*x;
}
inline bool checkin(int a,int b){
	bool flag1=s[b].second<=s[a].first;
	bool flag2=s[b].first>=s[a].first;
	return (flag1&&flag2);
}
template <typename T> void read(T &x){
	int f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
}
template <typename T> void write(T x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	read(x1);
	read(x2);
	read(x3);
	read(x4);
	read(x5);
	bool flag=true;
	for (int i=1;i<=n;i++){
		read(s[i].second);
		read(s[i].first);
		if ((s[i].first!=m)||(s[i].second!=1)){
			flag=false;
		}
	}
	if (flag){
		writeln(calcu(n));
		return 0;
	}
	sort(s+1,s+n+1);
	long long ans1=0,ans2=0;
	memset(usd,false,sizeof(usd));
	for (int i=1;i<=n;i++){
		if (!usd[i]){
			usd[i]=true;
			int cnt=1;
			for (int j=1;j<=n;j++){
				if (checkin(i,j)&&(!usd[j])){
					++cnt;
					usd[j]=true;
				}
			}
			ans1+=calcu(cnt);
		}
	}
	memset(usd,false,sizeof(usd));
	for (int i=n;i>=1;i--){
		if (!usd[i]){
			usd[i]=true;
			int cnt=1;
			for (int j=1;j<=n;j++){
				if (checkin(i,j)&&(!usd[j])){
					++cnt;
					usd[j]=true;
				}
			}
			ans2+=calcu(cnt);
		}
	}
	writeln(max(ans1,ans2));
	return 0;
}
