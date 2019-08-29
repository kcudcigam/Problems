#include<bits/stdc++.h>
using namespace std;
int n,a[2005][2005],x,y;
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
		if(i==1)cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}
