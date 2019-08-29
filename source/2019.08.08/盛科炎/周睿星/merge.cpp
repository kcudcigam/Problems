#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[500010],num;
int ans[500010];
void juice(int xx,int yy){
	for(int i=1;i<=n;++i){
		if(a[i]==a[xx]){
			ans[i]+=yy;
		}
	}
}
int read(){
	int p=1,q=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
		p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
void merge(int xx,int yy){
	if(a[xx]==a[yy])
	return;
	else {
		num++;
		for(int i=1;i<=n;++i){
			if(a[i]==a[xx]||a[i]==a[yy])
			a[i]=num;	
		}
		a[xx]=num;
		a[yy]=num;
	}
}
int main(){
	freopen("merge","r",stdin);
	freopen("merge","w",stdout);
	n=read();
	q=read();
	num=n;
	for(int i=1;i<=n;++i){
		a[i]=i;
	}
	while(q--){
		int pd;
		pd=read();
		if(pd==1){
			int x,y;
			x=read();
			y=read();
			merge(x,y);
		}
		if(pd==2){
			int a,b;
			a=read();
			b=read();
			juice(a,b);
		}
	}
	
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
