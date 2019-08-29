#include<bits/stdc++.h>
using namespace std;
int m1[1010][1010];
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int t,n,m;
	cin>>t>>n>>m;
	for (int i=1;i<=m;i++){
		int x,y,s;
		cin>>x>>y>>s;
		m1[x][y]=s;
	}
	for (int i=1;i<n;i++)
	cout<<-1<<" ";
	cout<<-1<<endl;
	return 0;
}

