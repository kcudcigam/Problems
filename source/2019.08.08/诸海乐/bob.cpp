#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	int k,ans=0;
	cin>>k;
	for (int i=1;i<=k-1;i++){
		cin>>a[i];
	}
	for (int i=0;i<=k;i++){
		for (int j=0;j<=k;j++){
			for (int l=0;l<=k;l++){
				for (int m=0;m<=k;m++){
					int A=i,B=j,C=l,D=m,l=0,f1=0;
					while (true){
						int f=0;
						//cout<<l<<endl;
						if (A!=0){
						A--;
						if (A==0){
							f++;
						}
						else
						if (B==0){
							B=a[A];
						}
						else if (C==0){
							C=a[A];
						}
						else if (D==0){
							D=a[A];
						}}
						if (B!=0){B--;
						if (B==0){
							f++;
						}
						else if (A==0){
							A=a[B];
						}
						else if (C==0){
							C=a[B];
						}
						else if (D==0){
							D=a[B];
						}}
						if (C!=0){
						C--;
						if (C==0){
							f++;
						}
						else if (A==0){
							A=a[C];
						}
						else if (B==0){
							B=a[C];
						}
						else if (D==0){
							D=a[C];
						}}
						if (D!=0){
						D--;
						if (D==0){
							f++;
						}
						else if (A==0){
							A=a[D];
						}
						else if (B==0){
							B=a[D];
						}
						else if (C==0){
							C=a[D];
						}}
						l++;
						if (f==0){
							break;
						}
						
						if (l>=150){
							f1=1;
							break;
						}
					}
					if (f1==1)ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

