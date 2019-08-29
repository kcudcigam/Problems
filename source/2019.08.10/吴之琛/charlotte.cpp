#include<bits/stdc++.h>
#define N 100010
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int q,n;
struct node{
	int t,x,y;
};
node a[N];
bool cmp(node x,node y){
	return x.t<y.t;
}
bool check(){
	for (int i=1;i<=n;i++){
		int dis=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y),w=a[i].t-a[i-1].t;
		if (dis>w||(dis&1)!=(w&1)) return false;
	}
	return true;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(q);
	while (q--){
		read(n);
		for (int i=1;i<=n;i++){
			read(a[i].t);
			read(a[i].x);
			read(a[i].y);
		}
		sort(a+1,a+n+1,cmp);
		if (check()) puts("Yes");
		else puts("No");
	}
	return 0;
}

