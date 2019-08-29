#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
for (; isdigit(c);c=getchar()) x=x*10+c -'0';
x*=f;
}
int n,s;
long m;
int main(){
	
	read(n);
	read(m);
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=0;
	}
	for(int k=1;k<=m;k++){
		int l,r,s,e;
		cin>>l>>r>>s>>e;
		int x[n];
		for(int i=0;i<n;i++){
			x[i]=0;
		}
		for(int i=l-1;i<=r-1;i++){
			x[i]=s+(e-s)/(r-l)*(i+1-l);
		}
		for(int j=0;j<=n-1;j++){
			a[j]+=x[j];
		}
	}
	s=a[0];
	for(int i=1;i<=n-1;i++){
		s=s^a[i];
	}
	cout<<s<<endl;
	return 0;
}
