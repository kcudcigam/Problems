#include<bits/stdc++.h>
using namespace std;

unsigned long long n,t,s,k;
int ha[100];

int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>n;t=log2(n);
	if (t==log2(n)) t+=2;
			   else t+=3;
	k=1;
	for (int i=1;i<=t-2;i++) k*=2;
	n=k-n;
//	cout<<t<<' '<<k<<endl;
//	cout<<n<<endl;
	for (int i=2;i<=t;i++){
//		cout<<n<<endl;
		if (n&1==1) ha[i]=1,s++;
		n=(n>>1);
	}
	cout<<t<<' '<<t*(t-1)/2-s<<endl;
	for (int i=1;i<t;i++)
		for (int j=i+1;j<t;j++)
		cout<<i<<' '<<j<<endl;
	for (int i=1;i<t;i++)
	if (ha[i]==0) cout<<i<<' '<<t<<endl;
	return 0;
}


