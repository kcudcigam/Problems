#include<bits/stdc++.h>
using namespace std;
struct node{
	long long y,c;
}a[1010];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long z,k=2,n=1,m=0,t=0,s=1,b;
	cin>>z;
	b=z;
	if(z==1){
		cout<<2<<' '<<1<<endl;
		cout<<1<<' '<<2<<endl;
		return 0;
	}
	while(z!=1){
		if(z%k==0){
			if(a[t].y==k)a[t].c++;
			else{
				t++;
				a[t].y=k;
				a[t].c=1;
			}
			z/=k;
			n+=k;
			m=m+2*k-1;
		}
		else k++;
	}
	cout<<n<<' '<<m<<endl;
	for(long long i=1;i<=t;i++){
		for(long long j=1;j<=a[i].c;j++){
			for(long long l=1;l<=a[i].y;l++){
				cout<<s<<' '<<s+l<<endl;
				if(l!=a[i].y)cout<<s+l<<' '<<s+a[i].y<<endl;
			}
			s+=a[i].y;
		}
	}
	return 0;
}
