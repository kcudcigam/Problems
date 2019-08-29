#include<bits/stdc++.h>
using namespace std;
int n,A,B,C,D;
int MAX[1010],m,last;
int ans[1010],an;
int a[1010],a1;
int b[1010],b1;
int Read() {
	char c=getchar();
	int x=0,k=1;
	for(;c<'0'||c>'9';c=getchar())	if(c=='-') k=-1 ;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10-'0'+c;
	return x*k;
}
bool Compare1(){
	if(a[0]>b[0]) return 1;
	if(a[0]<b[0]) return 0;
	for(int i=a[0];i>=1;--i){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return 0;
	}
	return 1;
}
bool Compare2(){
	if(ans[0]>MAX[0]) return 1;
	if(ans[0]<MAX[0]) return 0;
	for(int i=ans[0];i>=1;--i){
		if(ans[i]>MAX[i]) return 1;
		if(ans[i]<MAX[i]) return 0;
	}
	return 1;
}
void Add1(){//a+b
	if(a1==b1){
		a[0]=max(b[0],a[0]);
		for(int i=1;i<=b[0];++i){	a[i]+=b[i];	}
		for(int i=1;i<=a[0];++i){	a[i+1]+=a[i]/10;	a[i]%=10;	}
		while(a[a[0]+1]){	a[0]++;	a[a[0]+1]+=a[a[0]]/10;	a[a[0]]%=10;}
	}
	else{
		if(Compare1()){ //a>b
			for(int i=1;i<=b[0];++i){	a[i]-=b[i];	}
			for(int i=1;i<=a[0];++i){	if(a[i]<0) a[i]+=10,a[i+1]-=1;	}
			while(a[a[0]]==0){	a[0]--;	}
		}
		else{ //b>a
			a1*=-1;
			a[0]=max(b[0],a[0]);
			for(int i=1;i<=b[0];++i){	a[i]=b[i]-a[i];	}
			for(int i=1;i<=a[0];++i){	if(a[i]<0) a[i]+=10,a[i+1]-=1;	}
			while(a[a[0]]==0&&a[0]>0){	a[0]--;	}
		}
	}
	
}
void Add2(){//MAX+ans
	if(an==m){
		ans[0]=max(MAX[0],ans[0]);
		for(int i=1;i<=MAX[0];++i){	ans[i]+=MAX[i];	}
		for(int i=1;i<=ans[0];++i){	ans[i+1]+=ans[i]/10;	ans[i]%=10;	}
		while(ans[ans[0]+1]){	ans[0]++;	ans[ans[0]+1]+=ans[ans[0]]/10;	ans[ans[0]]%=10;}
	}
	else{
		if(Compare2()){ //a>b
			for(int i=1;i<=MAX[0];++i){	ans[i]-=MAX[i];	}
			for(int i=1;i<=ans[0];++i){	if(ans[i]<0) ans[i]+=10,ans[i+1]-=1;	}
			while(ans[ans[0]]==0){	ans[0]--;	}
		}
		else{ //b>a
			ans[0]=max(MAX[0],ans[0]);
			an*=-1;
			for(int i=1;i<=MAX[0];++i){	ans[i]=MAX[i]-ans[i];	}
			for(int i=1;i<=ans[0];++i){	if(ans[i]<0) ans[i]+=10,ans[i+1]-=1;	}
			while(ans[ans[0]]==0&&ans[0]>0){	ans[0]--;	}
		}
	}
}
void Cheng(int x){
	if(x<0) b1*=-1,x=-x;
	for(int i=1;i<=b[0];++i){	b[i]*=x;	}
	for(int i=1;i<=b[0];++i){	b[i+1]+=b[i]/10;	b[i]%=10;	}
	while(b[b[0]+1]){	b[0]++;	b[b[0]+1]=b[b[0]]/10;	b[b[0]]%=10;	}
}
void Clear(){
	memset(b,0,sizeof(b));
	b[1]=1,b[0]=1,b1=1;
}
void Fu(int x){
	m=a1;
	memset(MAX,0,sizeof(MAX));
	for(int i=0;i<=a[0];++i){	MAX[i]=a[i];	}
		last=x;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=Read(),A=Read(),B=Read(),C=Read(),D=Read();
	int x;m=1,an=1;
	for(int i=1;i<=n;++i){
		x=Read();
		a1=1;
		memset(a,0,sizeof(a));
		
		Clear();Cheng(A),Cheng(x),Cheng(x),Cheng(x);Add1();
		Clear();Cheng(B),Cheng(x),Cheng(x);Add1();
		Clear();Cheng(C),Cheng(x);Add1();
		Clear();Cheng(D);Add1();
		
		if(a1==1&&m==1){
			Add2();
			Fu(x);
		}
		else
		if(a1==1&&m==-1){
			if(x>last){
				Add2();	}
			Fu(x);
		}
		else
		if(a1==-1&&m==1){
			if(x<last){
				Add2();
				Fu(x);}
		}else
		if(a1==-1&&m==-1){
			if(x<last){
				Fu(x);}
		}
	}
	Add2();
	for(int j=ans[0];j>=1;--j)
		printf("%d",ans[j]);
	cout<<endl;
	return 0;
}
