#include<bits/stdc++.h>
using namespace std;
int l_1,l_2,ans,r_1,r_2,kz,n,m,a[500005],b[500005],x,y,z,la,c[1000100],t1,t2;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
  n=ri();
  m=ri();
  for (int i=1;i<=n;i++){
  	a[i]=ri();
  }
  for (int i=1;i<=n;i++){
  	b[i]=ri();
  }
  for (int i=1;i<=m;i++){
  	kz=ri();
  	if (kz==1){
  		x=ri();
  		y=ri();
  		z=ri();
  		if (x==0) a[y]=z;
  		if (x==1) b[y]=z;
	  }
	//
	if (kz==2){
		l_1=ri();
		r_1=ri();
		l_2=ri();
		r_2=ri();
		int g=((r_1-l_1+1)+(r_2-l_2+1))/2+1;
	/*	int mid_1= (r_1-l_1+2)/2;
		int mid_2= (r_2-l_2+2)/2;
		if (b[mid_2]==a[mid_1]){
			cout<<a[mid_1]<<endl;
			continue;
		}*/
	//	c[0]=99999999;
		t1=l_1;
		t2=l_2;
		for (int j=1;j<=g;j++){
			if ((a[t1]<=b[t2] && t1<=r_1) || (t2>r_2)){
				c[j]=a[t1];
				t1++;
			}else{
				c[j]=b[t2];
				t2++;
			}
		}
	cout<<c[g]<<endl;
			}
  }
	return 0;
}


