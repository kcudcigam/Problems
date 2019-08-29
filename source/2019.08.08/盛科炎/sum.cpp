#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[100005];
int b[1004][1004];
bool x=true;
int f_l,f_r,max_ans;
void make(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i][j]=(b[i][j-1]+a[j]);
		}
	}	
}
int search(int l,int r,bool vis){
	int n_max=0;
	for(int i=l;i<=r;i++){
		for(int o=i;o<=r;o++){
			if(n_max<b[i][o]){
			f_l=i;
			f_r=o;
			n_max=b[i][o];
			}
		}
	}
	printf("%d\n",n_max);
	if(vis){
	x=false;
	return n_max+search(++f_r,n,x);
	}
	else 
	return n_max;
}

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	make();
	int ans=search(1,n,x);
	printf("%d\n",ans);	
	return 0;
}
