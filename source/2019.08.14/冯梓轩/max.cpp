#include<bits/stdc++.h>
using namespace std;
const int mo=1000000007;
struct node{
	int x,y;
	double p;
}a[100010];
long long l[200010],r[2000010],n,m,q;
bool h[100010];
double s=0;
long long ok(){
	long long w=0;
	int ma=0;
	for(int i=1;i<=q;i++){
		for(int j=l[i];j<=r[i];j++)if(h[j]==1)ma=max(ma,a[j].y);
		w+=ma;
	}
	return w;
}
void dfs(int dep,double g){
	if(dep>m){
		s=s+((ok()%mo)*g);
		if(s>mo)s-=mo;
		cout<<ok()<<endl;
		return;
	}
	h[dep]=1;
	dfs(dep+1,g*a[dep].p);
	h[dep]=0;
	if(a[dep].p!=1)dfs(dep+1,g*(1-a[dep].p));
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int p1;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>p1;
		p1%=mo;
		if(p1<=1)a[i].p=p1;
		else a[i].p=p1*1.0/mo;
	}
	for(int i=1;i<=q;i++)cin>>l[i]>>r[i];
	dfs(1,1);
	cout<<((long long)s)%mo<<endl;
	return 0;
}

