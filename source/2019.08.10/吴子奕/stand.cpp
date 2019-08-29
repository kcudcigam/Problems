#include<bits/stdc++.h>
using namespace std;
int a[10000009];int fw[251][3];int o[10000009];
int b[6];long long sum;
long long hs(int p){
	
		return b[1]*p+b[2]*p*p+b[3]*p*p*p+b[4]*p*p*p*p+b[5]*p*p*p*p*p;
}
int main(){
freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
   int n,m;
   cin>>n>>m;sum=0;
   cin>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
   for(int i=1;i<=n;i++){
   	int l,r;
   	cin>>l>>r;fw[i][1]=l;fw[i][2]=r;
   	a[l]++;
   	a[r+1]--;
   }int maxn=-1;int id=-1;int k=0;
  // for(int i=1;i<=m;i++)cout<<a[i]<<" ";
   while(k!=n){
   	for(int i=1;i<=m;i++){
   		o[i]=o[i-1]+a[i];
   		if(o[i]>=maxn){
   			if(o[i]>maxn){
   				maxn=o[i];id=i;
			   }
			   if(o[i]==maxn){
			   	if((fw[i][2]-fw[i][1])<(fw[id][2]-fw[i][1])){
			   		id=i;
				   }
			   }
		   }
		   
	   }
	   sum+=hs(maxn);
	   k+=maxn;
	   maxn=-1;
	   for(int i=1;i<=n;i++){
	   	int l,r;
	   	l=fw[i][1];r=fw[i][2];
	   	if(id<=r&&id>=l){
	   		a[l]--;a[r+1]++;
		   }
	   }id=-1;
   }
   cout<<sum;
	return 0;
}


