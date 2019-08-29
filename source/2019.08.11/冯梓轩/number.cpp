#include<bits/stdc++.h>
using namespace std;
int a[10],w,v,x,y,b[100],f;
long long n;
int ok(long long m){
	int t=0;
	w=0;
	memset(a,0,sizeof(a));
	while(m){
		a[m%10]++;
		m/=10;
		w++;
	}
	for(int i=0;i<=9;i++)if(a[i])t++;
	return t;
}
void nu(int dep)
{
	if(dep>v)
	{
		int s=0;
		for(int i=1;i<dep;i++)s=s*10+b[i];
		s=n-s;
		if(s<0)return;
		if(ok(s)<=2)f=1;
		return;
	}
	b[dep]=x;
	nu(dep+1);
	b[dep]=y;
	nu(dep+1);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long t,m;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(ok(n)<=2){
			cout<<1<<endl;
			continue;
		}
		v=w;
		f=0;
		for(int j=0;j<=9;j++){
			for(int k=j;k<=9;k++){
				x=i;
				y=j;
				nu(1);
			}
		}
		if(f)cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}
