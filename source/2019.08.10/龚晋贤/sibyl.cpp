#include<bits/stdc++.h>
using namespace std;
vector<int> a[500000];
int n,m,q,i,j,b[500000],x,y,c;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
    cin>>n>>m>>q;
    for (i=1;i<=m;i++)
    {
    	cin>>x>>y;
    	a[x].push_back(y);
    	a[y].push_back(x);
	}
	for (i=1;i<=q;i++)
	{
		cin>>c;
		if (c==1) {
			cin>>x>>y;
			b[x]+=y;
		}
		else {
			cin>>x;
			y=b[x];
			for (j=0;j<a[x].size();j++)
			y+=b[a[x][j]];
			cout<<y<<endl;
		}
	}
	return 0;
}


