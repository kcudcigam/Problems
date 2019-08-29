#include<bits/stdc++.h>
using namespace std;
int a[100],t,b[5];
long long n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++){
    	cin>>n;
    	for (int j=0;j<=9;j++){
    		a[j]=0;
		}
    	int k,f=0;
    	while (n!=0){
    		k=n%10;
    		if (a[k]==0){
    			f++;
    			a[k]++;
    			if (f>=4) {
    				cout<<3<<endl;
    				break;
				}
			}
			n=n/10;
		}
		if (f<=2) {
					cout<<1<<endl;
					continue;
				}
		if (f==3) {
			int fz=0;
				for (int j=0;j<=9;j++){
			      if (a[j]!=0) {fz++;
			      	b[fz]=j;
				  }		
			}
			if (b[3]-b[2]==b[1]) {
				cout<<2<<endl;
			}else cout<<3<<endl;
				}
	}
	return 0;
}


