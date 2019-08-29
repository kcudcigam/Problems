#include<bits/stdc++.h>
using namespace std;
int cf(int x,int n)
{
	int o=x;
	for (int i=2;i<=n;i++)
	o*=x;
	return o;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c1,c2,c3,c4,c5;
	cin>>c1>>c2>>c2>>c4>>c5;
	cout<<c1*cf(n,1)+c2*cf(n,2)+c3*cf(n,3)+c4*cf(n,4)+c5*cf(n,5)<<endl;
	return 0;
}


