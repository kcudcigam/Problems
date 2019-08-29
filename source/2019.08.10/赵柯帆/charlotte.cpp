#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
struct node{
	int x,y,t;
}a[100010];
void doit(){
	memset(a,0,sizeof(a));
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].t);read(a[i].x);read(a[i].y);
	}
	int nx=0,ny=0,t=0;
	for(int i=1;i<=n;i++){
		if(a[i].t-(abs(a[i].x-nx)+abs(a[i].y-ny)+t)>=0&&(a[i].t-(abs(a[i].x-nx)+abs(a[i].y-ny)+t))%2==0){
			nx=a[i].x;ny=a[i].y;t=a[i].t;
		}else{
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int t1;
	read(t1);
	
	while(t1--){
		doit();
	}
	return 0;
}

