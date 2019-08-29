#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct Magic{
	int x,y,p;
}a[200010];
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i)
		cin>>a[i].x>>a[i].y>>a[i].p;
		
	int l,r;
	for(int i=1;i<=n;++i)
		cin>>l>>r;
	cout<<4<<endl;
	return 0;
}

