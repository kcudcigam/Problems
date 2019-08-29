#include<bits/stdc++.h>
using namespace std;
int n,m,a[1<<19],b[1<<19];
int read(){
	char c;int r=0;
	do c=getchar();while(!isdigit(c));
	do r=r*10+c-48,c=getchar();while(isdigit(c));
	return r;
}
int getv(int l,int r,int T,int p,int*a){
	int st=(T-r+l-1)/2;
	return p<=st?-1e9:(p>T-(T-r+l)/2?2e9:a[l+p-st-1]);
}
int main(){
	freopen("median.in","r",stdin),freopen("median.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	while(m--){
		int op=read();int l1=read(),r1=read(),l2=read(),r2;
		if(op==1)if(l1)b[r1]=l2;else a[r1]=l2;else{
			r2=read();
			int k=1;
			for(;k<max(r1-l1+1,r2-l2+1);k*=2);
			int L1=1,R1=k,L2=1,R2=k;
			while(L1<=R1){
				int mid1=L1+R1>>1,mid2=L2+R2>>1;
				int x1=getv(l1,r1,k,mid1,a),x2=getv(l2,r2,k,mid2,b);
				if(L1==R1||x1==x2){printf("%d\n",min(x1,x2));break;}
				if(x1<x2)L1=mid1+1,R2=mid2;else R1=mid1,L2=mid2+1;
			}
		}
	}
	return 0;
}
