#include<bits/stdc++.h>
using namespace std;
const int N=4e5+11;
bool usd[N];
pair< int, int > x[N];
int t1=0,t2=0,t3=0;
int x1[N],x2[N],x3[N];
int cmp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
template <typename T> void read(T &x){
	T f=1;
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
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n;
	read(n);
	
	for (int i=1;i<=n;i++){
		read(x[i].second);
		read(x[i].first);
	}
	sort(x+1,x+n+1,cmp);
	for (int i=1;i<=n;i++){
		if (x[i].second/10){
			x1[++t1]=i;
		}
		if (x[i].second%10){
			x2[++t2]=i;
		}
		if (x[i].second/10+x[i].second%10==0){
			x3[++t3]=i;
		}
	}
	if ((t1==ceil(n*1.0/2))&&(t2==floor(n*1.0/2))){
		int ans=0;
		for (int i=1;i<=n;i++){
			ans+=x[i].first;
		}
		writeln(ans);
		return 0;
	}
	if (t1>t2){
		int ans=0;
		int tot=2*t2;
		memset(usd,true,sizeof(usd));
		for (int i=1;i<=t2;i++){
			if (usd[x2[i]]){
				ans+=x[x2[i]].first;
				usd[x2[i]]=false;
				tot--;
			}
		}
		for (int i=1;i<=t2;i++){
			if (usd[x1[i]]){
				ans+=x[x1[i]].first;
				usd[x1[i]]=false;
				tot--;
			}
		}
		int kk=1;
		while (tot--){
			ans+=x[x3[kk++]].first;
		}
		writeln(ans);
		return 0;
	}
	if (t2>=t1){
		int ans=0;
		int tot=2*t1;
		memset(usd,true,sizeof(usd));
		for (int i=1;i<=t1;i++){
			if (usd[x1[i]]){
				ans+=x[x1[i]].first;
				usd[x1[i]]=false;
				tot--;
			}
		}
		for (int i=1;i<=t1;i++){
			if (usd[x2[i]]){
				ans+=x[x2[i]].first;
				usd[x2[i]]=false;
				tot--;
			}
		}
		int kk=1;
		while (tot--){
			ans+=x[x3[kk++]].first;
		}
		writeln(ans);
		return 0;
	}
	return 0;
}

