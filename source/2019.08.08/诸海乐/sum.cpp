#include<bits/stdc++.h>
using namespace std;
int a[101000];
long long b[101000];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	cin>>n;
	b[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	int ans=0;
	for (int k=1;k<=n;k++){
		if (a[k]>0){
			int ma1=0,ma2=0,mi1=0,mi2=0;
			for (int i=1;i<=k;i++){
				if (b[i]<mi1)mi1=b[i];
				if ((b[i]-mi1)>ma1)ma1=b[i]-mi1;
			}
			for (int i=k+1;i<=n;i++){
				if (b[i]<mi2)mi2=b[i];
				if ((b[i]-mi2)>ma2)ma2=b[i]-mi2;
			}
			if ((ma1+ma2)>ans)ans=ma1+ma2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
