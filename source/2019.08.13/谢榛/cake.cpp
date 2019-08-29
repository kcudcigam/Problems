#include<bits/stdc++.h>
using namespace std;

int n,m;
long long ans;
long long f[310][310];

long long work(int x,int y){
	if (f[x][y]!=0) return f[x][y];
	if (x==1 && y==1) return 1;
	long long sum=0;
	for (int i=1;i<x;i++)
	sum=(sum+work(x-i,y)*work(i,y))%1000000007;
	for (int i=1;i<y;i++)
	sum=(sum+work(x,y-i)*work(x,i))%1000000007;
	f[x][y]=sum;f[y][x]=sum;
	return sum;
}

int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	/*if (m>n) swap(n,m);
	f[1][1]=1;*/
	ans=work(n,m);
	cout<<ans<<endl;
	return 0;
}

