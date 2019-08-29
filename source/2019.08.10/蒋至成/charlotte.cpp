#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int t,x,y;
};
node a[100001];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(T);
	for(int i=1;i<=T;++i){
		memset(a,0,sizeof(a));
		read(n);
		for(int j=1;j<=n;++j){
			read(a[j].t);read(a[j].x);read(a[j].y);
		}
		int lastx=0,lasty=0,lastt=0;
		bool pd=0;
		for(int j=1;j<=n;++j){
			if(abs(a[j].x-lastx)+abs(a[j].y-lasty)>a[j].t-lastt){	
				pd=1;
				cout<<"No"<<'\n';
				break;
			}
			if((abs(a[j].x-lastx)+abs(a[j].y-lasty)-(a[j].t-lastt))%2==0){
				lastx=a[j].x;lasty=a[j].y;lastt=a[j].t;
				continue;
			}
			else {
				pd=1;
				cout<<"No"<<'\n';
				break;
			}
		}
		if(!pd)cout<<"Yes"<<'\n';
		}
	return 0;
}


