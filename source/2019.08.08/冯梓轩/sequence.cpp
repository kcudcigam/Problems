#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int n,m;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar())if (c=='-') f=-f;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
void seq(int l,int r,int s,int e){
	bool f=0;
	int k=r-l+1,g,x=s;
	g=abs(e-s)/(k-1);
	if(s>e)f=1;
	for(int i=l;i<=r;i++){
		a[i]+=x;
		if(f)x-=g;
		else x+=g;
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	long long s,l,r,e;
	read(n);
	read(m);
	for(int i=1;i<=m;i++){
		read(l);
		read(r);
		read(s);
		read(e);
		seq(l,r,s,e);
	}
	s=a[1];
	for(int i=2;i<=n;i++)s=s^a[i];
	cout<<s<<endl;
	return 0;
}
