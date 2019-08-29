#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAXN=100005;
int n,m;
struct Node{
	//int id;
	int val;
};
Node a[MAXN],b[MAXN];

int temp[MAXN];

void deal(int L1,int R1,int L2,int R2){
	int x=1;
	for(int i=L1;i<=R1;i++){
	temp[x]=a[i].val;
	++x;
	}
	for(int j=L2;j<=R2;j++){
		temp[x]=b[j].val;
		++x;
	}
	sort(temp,temp+x-1);
	int mid=x/2;
	printf("%d\n",temp[mid]);
	/*
	for(int i=1;i<x;i++)
	printf("%d ",temp[i]);
	*/
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		//a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].val);
		//b[i].id=i;
	}
	int mark;
	while(m--){
		scanf("%d",&mark);
		if(mark==1){
			int y,z;
			double x;
			scanf("%lf %d %d",&x,&y,&z);
			if(x==0){
				a[y].val=z;
			}
			else{
				b[y].val=z;
			}
		}
		else if(mark==2){
			int l1,r1,l2,r2;
			scanf("%d %d %d %d",&l1,&r1,&l2,&r2);	
			deal(l1,r1,l2,r2);
		}
	}
	
	return 0;
}

