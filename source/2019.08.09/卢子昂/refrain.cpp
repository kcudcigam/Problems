#include<bits/stdc++.h>
using namespace std;
const int luck=1000000009;
const int Maxn=200000+10;
int a[Maxn],b[Maxn];
long long mi[Maxn];
int num,n,m1,m2,yin,yang,dou,non;
int tim(int x){
	int cnt=1;	
	for(;x;x--){
		cnt*=x;
		cnt%=luck;
	}
	return cnt%luck;
}
int main(){
	int x,y,i,j;
	scanf("%d",&num);
	scanf("%d%d%d",&n,&m1,&m2);
	if(n==1){
		cout<<"0"<<endl;
		return 0;
	}
	for(i=1;i<=m1;i++){
		scanf("%d%d",&x,&y);
		a[x]++;a[y]++;
		yin+=2;
	}
	for(i=1;i<=m2;i++){
		scanf("%d%d",&x,&y);
		b[x]++;b[y]++;
		yang+=2;
	}	
	for(i=1;i<=n;i++){
		if(a[i]==1&&b[i]==1){
			yin--;yang--;
			dou++;
		}
		if(a[i]==0&&b[i]==0){
			non++;
		}
	}
	long long en;
	mi[0]=1;
	for(i=1;i<=60;i++){
		mi[i]=(2*mi[i-1]);
	}
	en=mi[m1+m2];
	long long ans=0;
	ans=(tim(n)-en)%luck;
	printf("%d",ans);
	return 0;
}

