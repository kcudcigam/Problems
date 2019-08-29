#include<bits/stdc++.h>
#include<cctype>
using namespace std;
inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
const int maxn=2000055;
int nn,n,m,i,j,k,l,s,r,zuo[maxn],you[maxn];
long long ans,a[maxn],d,f,lan[maxn],zhong[maxn];
void spread(int x){
	if(lan[x]!=0){
		lan[x*2]+=lan[x];
		lan[x*2+1]+=lan[x];
		a[x*2]+=lan[x]*(you[x*2]-zuo[x*2]+1);
		a[x*2+1]+=lan[x]*(you[x*2+1]-zuo[x*2+1]+1);
		lan[x]=0;
	}
	return;
}
void cha(int dep,int f,long long g){
	a[dep]+=g;
	if(zuo[dep]==you[dep]){
		return;
	}
	int k=(zuo[dep]+you[dep])/2;
	if(k<f){
		cha(dep*2+1,f,g);
	}
	else{
		cha(dep*2,f,g);
	}
	return;
}
void jian(int dep,int f,long long g){
	a[dep]-=g;
	if(zuo[dep]==you[dep]){
		return;
	}
	int k=(zuo[dep]+you[dep])/2;
	if(k<f){
		jian(dep*2+1,f,g);
	}
	else{
		jian(dep*2,f,g);
	}
	return;
}
void jia(int dep,int f,int r,long long g){
	if(f==zuo[dep]&&r==you[dep]){
		a[dep]+=g*(r-f+1);
		lan[dep]+=g;
		return;
	}
	spread(dep);
	int k=(zuo[dep]+you[dep])/2;
	if(k>=r){
		jia(dep*2,f,r,g);
	}
	else
	if(k<f){
		jia(dep*2+1,f,r,g);
	}
	else{
		jia(dep*2,f,k,g);
		jia(dep*2+1,k+1,r,g);
	}
	a[dep]=a[dep*2]+a[dep*2+1];
}
void jianshu(int dep,int f,int r){
	zuo[dep]=f;
	you[dep]=r;
	if(f==r){
		return;
	}
	int k=(f+r)/2;
	jianshu(dep*2,f,k);
	jianshu(dep*2+1,k+1,r);
	return;
}
void sou(int dep){
	if(zuo[dep]==you[dep]){
		nn++;
		zhong[nn]=a[dep];
		return;
	}
	spread(dep);
	sou(dep*2);
	sou(dep*2+1);
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();
	jianshu(1,1,n);
	memset(a,0,sizeof(a));
	memset(lan,0,sizeof(lan));
	for(i=1;i<=m;i++){
		l=read();r=read();f=read();d=read();
		if(l==r){
			cha(1,l,f);
			if(r+1<=n){
				jian(1,l+1,f);
			}
			continue;
		}
		cha(1,l,f);
		f=(d-f)/(r-l);
		//cout<<f<<endl;
		if(f!=0){
			jia(1,l+1,r,f);
		}
		if(r+1<=n){
			jian(1,r+1,d);
		}
	}
	nn=0;
	sou(1);
	/*for(i=1;i<=n;i++){
		cout<<zhong[i]<<" ";
	} */
	for(i=2;i<=n;i++){
		zhong[i]+=zhong[i-1];
	}
	/**for(i=1;i<=n;i++){
		cout<<zhong[i]<<" ";
	}
	cout<<endl;*/
	ans=zhong[1];
	for(i=2;i<=n;i++){
		ans=ans^zhong[i];
	}
	cout<<ans<<endl;
	return 0;
}


