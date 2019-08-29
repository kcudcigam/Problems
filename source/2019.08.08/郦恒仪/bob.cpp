#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,l,s,d,f,r,a[1000000],b[1000];
int h[15151520];
void dg(int dep){
	//cout<<"!"<<endl;
	if(dep>4){
		int k=a[1]*1000000+a[2]*10000+a[3]*100+a[4];
		int c[1000];
		int kk,kkk,kkkk;
		f++;
		//cout<<k<<endl;
		//cout<<"!"<<" ";
		while(h[k]!=f){
			if(k==0){
				return;
			}
			else{
				h[k]=f;
				kkkk=0;
				if((k%100000000)/1000000!=0){
					k-=1000000;
					if((k%100000000)/1000000==0){
						kkkk=1;
					}
					else{
						if((k%1000000)/10000==0){
							k+=b[(k%100000000)/1000000]*10000;
						}
						else{
							if((k%10000)/100==0){
								k+=b[(k%100000000)/1000000]*100;
							}
							else{
								if((k%100)==0){
									k+=b[(k%100000000)/1000000];
								}
							}
						}
					}
				}
				if((k%1000000)/10000!=0){
					k-=10000;
					if((k%1000000)/10000==0){
						kkkk=1;
					}
					else{
						if((k%100000000)/1000000==0){
							k+=b[(k%1000000)/10000]*1000000;
						}
						else{
							if((k%10000)/100==0){
								k+=b[(k%1000000)/10000]*100;
							}
							else{
								if(k%100==0){
									k+=b[(k%1000000)/10000];
								}
							}
						}
					}
				}
				if((k%10000)/100!=0){
					k-=100;
					if((k%10000)/100==0){
						kkkk=1;
					}
					else{
						if((k%100000000)/1000000==0){
							k+=b[(k%10000)/100]*1000000;
						}
						else{
							if((k%1000000)/10000==0){
								k+=b[(k%10000)/100]*10000;
							}
							else{
								if(k%100==0){
									k+=b[(k%10000)/100]*1;
								}
							}
						}
					}
				}
				if(k%100!=0){
					k-=1;
					if((k%100)/1==0){
						kkkk=1;
					}
					else{
						if((k%100000000)/1000000==0){
							k+=b[k%100]*1000000;
						}
						else{
							if((k%1000000)/10000==0){
								k+=b[k%100]*10000;
							}
							else{
								if((k%10000)/100==0){
									k+=b[k%100]*100;
								}
							}
						}
					}
				}
				if(kkkk==0){
					return;
				}
				if(k==0){
					return;
				}
				
			}
//			cout<<"!"<<" "<<k<<endl;
		}
		s++;
		//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
	}
	else{
		for(int i=0;i<=n;i++){
			a[dep]=i;
			dg(dep+1);
			a[dep]=-1;
		}
	}
	return;
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	cin>>n;
	for(i=1;i<=n-1;i++){
		cin>>b[i];
	}
	s=0;
	f=0;
	a[1]=-1;
	a[2]=-1;
	a[3]=-1;
	a[4]=-1;
	//cout<<"!"<<endl;
	dg(1);
	cout<<s<<endl;
	return 0;
}

