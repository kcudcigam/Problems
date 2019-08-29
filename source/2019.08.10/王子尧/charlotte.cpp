#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
struct wzy{
	int t,x,y;
}co[100010];

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	
	int T;read(T);
	while(T--){
		int n;read(n);
		rep(i,1,n){read(co[i].t);read(co[i].x);read(co[i].y);}
		
		bool f=true;
		int nt=0;int nx=0;int ny=0;
		rep(i,1,n){
			int tmp=co[i].t-nt-abs(nx-co[i].x)-abs(ny-co[i].y);
			if(tmp<0||tmp%2){f=false;break;}
			nx=co[i].x;ny=co[i].y;nt=co[i].t;
		}
		puts((f==false)?"No":"Yes");
	}
	return 0;
}
