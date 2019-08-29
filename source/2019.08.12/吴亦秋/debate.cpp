#include<bits/stdc++.h>
using namespace std;
int n,ans,nn;
int k1=0,k2=0,k3=0;
int xo[400005],ox[400005],oo[400005];
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	char t1,t2;
	int t3;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2>>t3;
		if(t1=='1'&&t2=='1'){
			ans+=t3;
			nn++;
		}else if(t1=='1'){
			xo[++k1]=t3;
		}else if(t2=='1'){
			ox[++k2]=t3;
		}else{
			oo[++k3]=t3;
		}
	}
	sort(xo+1,xo+1+k1);
	sort(ox+1,ox+1+k2);
	while(k1&&k2){
		ans+=xo[k1--];
		ans+=ox[k2--];
	}
	while(k1){
		oo[++k3]=xo[k1--];
	}
	while(k2){
		oo[++k3]=ox[k2--];
	}
	sort(oo+1,oo+1+k3);
	while(nn&&k3){
		ans+=oo[k3--];
		nn--;
	}
	cout<<ans;
	return 0;
}
