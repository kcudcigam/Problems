#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar())if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
struct node{
	int x,y,t;
	bool operator < (const node& k1)const{
		return t<k1.t;
	}
	int dist(node k1){
		return abs(x-k1.x)+abs(y-k1.y);
	}
}a[MAXN];
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;for (read(T);T;T--){
		int n;read(n);
		for (int i=1;i<=n;i++)
			read(a[i].t),read(a[i].x),read(a[i].y);
		sort(a+1,a+n+1);
		a[0]=(node){0,0,0};
		int ret=1;
		for (int i=1;i<=n;i++){
			int tmp=a[i-1].dist(a[i]);
//			cerr<<a[i].t-a[i-1].t<<endl;
			if (a[i].t-a[i-1].t<tmp){
				ret=0;break;
			}
			if ((a[i].t-a[i-1].t-tmp)%2!=0){
				ret=0;break;
			}
		}
		puts(ret?"Yes":"No");
	}
	return 0;
}
/*
1
3
2 1 1
7 1 4
13 4 1

3
2
3 1 2
6 1 1
1
2 100 100
2
5 1 1
100 1 1
*/
