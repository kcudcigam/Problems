#include<bits/stdc++.h>
using namespace std;

int num,n,m1,m2,sum,x1[20],y11[20],x2[20],y2[20];
int a[20][20],b[20][20];
int f[20],h[20];

void print(){
	int p=0;
	for (int i=1;i<=m1;i++)
	if (a[f[x1[i]]][f[y11[i]]]==0) {p=1;break;}
	for (int i=1;i<=m2;i++)
	if (b[f[x2[i]]][f[y2[i]]]==0) {p=1;break;}
	if (p==1) sum++;
}
void work(int x){
	if (x>n) {print();return ;}
	for (int i=1;i<=n;i++)
	if (h[i]==0) {
		f[x]=i;h[i]=1;
		work(x+1);
		h[i]=0;
	}
	return ;
}

int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num>>n>>m1>>m2;
	for (int i=1;i<=m1;i++){
		cin>>x1[i]>>y11[i];
		a[x1[i]][y11[i]]=1;
		a[y11[i]][x1[i]]=1;
	}
	for (int i=1;i<=m2;i++){
		cin>>x2[i]>>y2[i];
		b[x2[i]][y2[i]]=1;
		b[y2[i]][x2[i]]=1;
	}
	work(1);
	cout<<sum<<endl;
	return 0;
}


