#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m,i,j,k,l,s,d,r,f[10000005],ff[1000005],fff[1000005];
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(ff,0,sizeof(ff));
	memset(fff,0,sizeof(fff));
	f[1]=m;
	if(m>=a[1]){
		f[2]=m-a[1];
		fff[f[2]]=1;
		ff[f[2]]=1;
		k=2;
	}
	else{
		k=1;
	}
	for(i=2;i<=n;i++){
		l=0;
		for(j=1;j<=k;j++){
			if(f[j]-a[i]>=0){
				if(fff[f[j]]!=i-1&&fff[f[j]]!=i){
					if(ff[f[j]-a[i]]<ff[f[j]]+1){
						ff[f[j]-a[i]]=ff[f[j]]+1;
						//cout<<fff[f[j]-a[i]]<<" "<<i<<" ";
						fff[f[j]-a[i]]=i;
						l++;
						f[l+k]=f[j]-a[i];
						//8cout<<f[3]<<" "<<fff[f[3]]<<" ";
					}
				}
			}
			//cout<<fff[f[j]]<<" "<<i-1<<" "<<f[j]<<" "<<ff[f[j]]<<" "<<l<<endl;
		}
		k+=l;
	}
	s=0;
	for(i=0;i<=m;i++){
		s=max(s,ff[i]);
	}
	/*cout<<k<<endl;
	for(i=1;i<=k;i++){
		cout<<f[i]<<" "<<fff[f[i]]<<endl;
	}
	for(i=0;i<=m;i++){
		cout<<i<<" ";
	}
	cout<<endl;
	for(i=0;i<=m;i++){
		cout<<ff[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<=m;i++){
		cout<<fff[i]<<" ";
	}*/
	cout<<s<<endl;
	return 0;
}

