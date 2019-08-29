#include<bits/stdc++.h>
#define LL long long 
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
struct node{
	int t,x,y;
}a[M];
int n;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T=read();
	while (T--){
		n=read();
		int dis=0,del=0;
		bool flag=0;
		a[0].t=a[0].x=a[0].y=0;
		F(i,1,n){
			a[i]=(node){read(),read(),read()};
			if (flag) continue;
			del=a[i].t-a[i-1].t;
			dis=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
			if (del<dis || (del-dis)&1){
				flag=1;
				puts("No");
//				break;
			}
		}
		if (!flag) puts("Yes"); 
	}
	return 0; 
}
