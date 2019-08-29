#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y,t;
} a[100010];
int k,n,p,lt,x,y;

void read(int &x){
	x=0;char h=' ';
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<3)+(x<<1)+h-48;
}
bool cmp(node a,node b){
	return a.t<b.t;
}

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(k);
	for (int l=1;l<=k;l++){
		read(n);
		x=0;y=0;p=0;lt=0;
		for (int i=1;i<=n;i++)
		read(a[i].t),read(a[i].x),read(a[i].y);
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++){
			if ((abs(a[i].x-x)+abs(a[i].y-y))%2==(a[i].t-lt)%2
			 && (abs(a[i].x-x)+abs(a[i].y-y))<=(a[i].t-lt)) p=0;
			 										   else {p=1;break;}
			x=a[i].x;y=a[i].y;lt=a[i].t;
		}
		if (p==0) cout<<"Yes"<<endl;
			 else cout<<"No"<<endl;
	}
	return 0;
}

