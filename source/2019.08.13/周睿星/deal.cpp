#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[513],b[513];
int tot1=0,tot2=0;
int mol[9],mos[9],mo[9],used[9];
int ans=0;
int back=0;
void dg1(int num,int last){
	if(num>=x){
		a[num]++;
		return;
	}
	for(int i=last;i<=n;++i){
		int t=mol[i];
		while(t--){
			if(num+(mol[i-1]-t)*mo[i]>=x)break;
			int flg=false;
			for(int j=1;j<=n;++j){
				if(mo[j]<=num+(mol[i]-t)*mo[i]-x&&used[j]){
					flg=true;
					break;
				}
			}
			if(flg)break;
			else used[i]=1;
			dg1(num+(mol[i]-t)*mo[i],last+1);
			used[i]=0;
		}
	}	
} 
void dg2(int num,int last){
	if(num>=back){
		b[num]++;
		return;
	}
	for(int i=last;i<=n;++i){
		int t=mos[i];
		while(t--){
			if(num+(mol[i-1]-t)*mo[i]>=x)break;
			dg1(num+(mos[i]-t)*mo[i],last+1);
		}
	}
} 
int read(){

	int p=1,q=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=read();
	x=read();
	for(int i=1;i<=n;++i){
		mo[i]=read();
		mol[i]=read();
		mos[i]=read();
	}
	dg1(0,1);
	for(int i=512;i>=1;--i)
	if(a[i]){
		back=a[i]-x;
		break;	
	}
	dg2(0,1);
	b[0]=0;
	for(int i=x;i<=512;++i){
		if(a[i]&&b[i-x])
		ans+=a[i]*b[i-x];
	}
	
	cout<<ans<<endl;
	return 0;
}
