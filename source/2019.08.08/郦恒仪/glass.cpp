#include<bits/stdc++.h>
using namespace std;
long long s,a[100005],b[1000005];
int n,m,i,j,k,l,d,f,r;
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	cin>>n>>m;
	a[0]=1;
	k=0;
	for(i=1;a[i-1]<=n;i++){
		k++;
		a[i]=a[i-1]*2;
	}
	l=n;
	f=0;
	for(i=k;i>=1;i--){
		if(a[i]<=l){
			f++;
			b[f]=i;
			l-=a[i];
		}
	}
	if(l==1){
		f++;
		b[f]=0;
	}
	if(f<=m){
		cout<<0<<endl;
	}
	else{
		r=a[b[m]];
		s=0;
		for(i=m+1;i<=f;i++){
			s+=a[b[i]];
		}
		cout<<r-s<<endl;
	}
	return 0;
}

