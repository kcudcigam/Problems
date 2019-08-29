#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAXN=10005;
int n,Q;
int b[MAXN],c[MAXN];    //a为初始，b指向柠檬堆 
int s,tx,ty;
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	scanf("%d %d",&n,&Q);
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	for(int i=1;i<=Q;i++){
	scanf("%d %d %d",&s,&tx,&ty);
	if(s==1){
		b[tx]=ty;
	}
	else if(s==2){
		int place=b[tx];
		for(int j=1;j<=n;j++){
			if(b[j]==place) {
				c[j]+=ty;			
			}
		}
	}
	}
	for(int i=1;i<=n;i++){
		if(i!=n)
		printf("%d ",c[i]);
		else
		printf("%d\n",c[i]);
	}
	return 0;
}
