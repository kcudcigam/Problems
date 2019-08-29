#include<bits/stdc++.h>
#define N 500001
using namespace std;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int n,m,f,x,y,z,l_1,l_2,r_1,r_2;
int a[N],b[N],s[N],ta,tb,ans;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
n=ri();m=ri();
for(int i=1;i<=n;i++) {
	a[i]=ri();
	
}
for(int i=1;i<=n;i++) {
	b[i]=ri();
	
}
for(int i=1;i<=m;i++){
	f=ri();
	if(f==1) {
		x=ri();y=ri();z=ri();
		if(x==0) a[y]=z;
		else b[y]=z;
		}
    if(f==2) {
    	int t=0;
    	l_1=ri();r_1=ri();ta=r_1-l_1+1;
    	l_2=ri();r_2=ri();tb=r_2-l_2+1;
    	if(a[r_1]<b[l_2]) {
		if(ta>tb) ans=a[(ta+tb)/2+1];
		else ans=b[(ta+tb)/2+1];
	}
	if(a[l_1]>b[r_1]) {
		if(ta>tb) ans=a[(ta+tb)/2+1];
		else ans=b[(ta+tb)/2+1];
	}
    	
	
	else {
		for (int j=l_1;j<=r_1;j++){
    	   t++;s[t]=a[j];
    	   
    	}
  	for(int k=l_2;k<=r_2;k++){
    		t++;s[t]=b[k];
		}
		sort(s+1,s+t+1);
	ans=s[t/2+1];
	}
   // int to=ta+tb;
   // int te=0;
   // int la=1;
  //  int lb=1;
  //  hile(te<to/2+1){
  //  	te++;
   // 	if(a[la]<b[lb]) {
   // if(te==to/2+1) ans=a[la];		la++;
//		}
//		else {
//	if(te==to/2+1) ans=b[lb];		lb++;
//		}
//	}
	cout<<ans<<endl;	
	}
	
}

	return 0;
}


