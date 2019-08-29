#include<bits/stdc++.h>
using namespace std;
long long n,x,s1,s2,ma,ma2,ans;
long long a[1010],b[1010],c[1010];
long long h[30010],h2[30010],ss1[30010],ss2[30010];
void work(int s,int step,int sh){
	if ((s>=x)&&(s<=ma)){
		h[s-x]++;
		s1++;
		ss1[s1]=s-x;
	}
	else{
		if (sh<b[step]){
			if (step<n) work(s+a[step],step+1,0);
			work(s+a[step],step,sh+1);
		}
		if (step<n) work(s,step+1,0);
	}
}
void work2(int s,int step,int sh){
	if (s<=ma){
		h2[s]++;
		s2++;
		ss2[s2]=s;
	}
	if ((sh<b[step])&&(s<=ma)){
		if (step<n) work(s+a[step],step+1,0);
		work(s+a[step],step,sh+1);
	}
	else if ((s<=ma)&&(step<n))
		work(s,step+1,0);
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x;
	for (int i=n;i>=1;i--){
		cin>>a[i]>>b[i]>>c[i];
	}
	ma=max(2*x-1,a[1]);
	ma2=max(x-1,a[1]-x);
	work(0,1,0);
	work2(0,1,0);
	for (int i=0;i<=max(ma-x,ma2);i++){
		cout<<h[i]<<" "<<h2[i]<<endl;
		ans+=h[i]*h2[i];
	}
	cout<<ans-15<<endl;
	return 0;
}


