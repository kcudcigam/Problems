#include<bits/stdc++.h>
using namespace std;
int t,n;
struct edge{
	int t,x,y;
}a[100005];
bool cmp(edge a,edge b){
	return a.t<b.t;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag=1;
		cin>>n;
		a[0].t=0;
		a[0].x=0;
		a[0].y=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].t>>a[i].x>>a[i].y;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].t-a[i-1].t<(abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y))||(a[i].t-a[i-1].t)%2!=(abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y))%2){
				flag=0;
				cout<<"No\n";
				break;
			}
		}
		if(flag){
			cout<<"Yes\n";
		}
	}
	return 0;
}
