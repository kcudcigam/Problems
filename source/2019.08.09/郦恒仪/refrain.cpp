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
int ya1[1005],ya2[1005],yi1[1005],yi2[1005],h[1005],t[1005],p[1005],pp[1005],ruizhi,a[1005][1005],dian[1005],m1,m2,n,m,i,j,k,l,s,d,f,r;
void dg(int dep){
	if(dep>n){
		int d=0;
		for(int i=1;i<=n;i++){
			p[i]=t[t[i]];
		}
		/*for(int i=1;i<=n;i++){
			cout<<t[i]<<" "<<p[i]<<endl;
		}*/
		for(int i=1;i<=m1;i++){
			if(a[p[ya1[i]]][p[ya2[i]]]!=1||a[t[ya1[i]]][t[ya2[i]]]!=1){
				d=1;
				break;
			}
		}
		if(d==1){
			s++;
			//cout<<"OK"<<endl;
			return;
		}
		for(int i=1;i<=m2;i++){
			if(a[p[yi1[i]]][p[yi2[i]]]!=2||a[t[yi1[i]]][t[yi2[i]]]!=2){
				d=1;
				break;
			}
		}
		if(d==1){
			//cout<<"OK"<<endl;
			s++;
			return;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(h[i]==0){
				h[i]=1;
				t[dep]=i;
				dg(dep+1);
				h[i]=0;
			}
		}
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	ruizhi=read();
	n=read();
	m1=read();
	m2=read();
	memset(a,0,sizeof(a));
	memset(dian,0,sizeof(dian));
	for(i=1;i<=m1;i++){
		ya1[i]=read();
		ya2[i]=read();
		a[ya1[i]][ya2[i]]=1;
		a[ya2[i]][ya1[i]]=1;
	}
	for(i=1;i<=m2;i++){
		yi1[i]=read();
		yi2[i]=read();
		a[yi1[i]][yi2[i]]=2;
		a[yi2[i]][yi1[i]]=2;
	}
	memset(h,0,sizeof(h));
	s=0;
	dg(1);
	cout<<s<<endl;
	return 0;
}

