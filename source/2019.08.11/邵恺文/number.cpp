#include<bits/stdc++.h>
using namespace std;
template <typename _Tp> inline _Tp read(_Tp&x){
    char c11=getchar(),minu=0;x=0;
    while(c11^'-'&&!isdigit(c11))c11=getchar();
	if(c11=='-')c11=getchar(),minu=1;
    while(isdigit(c11)){
    	x=x*10+c11-'0';
		c11=getchar();
	}
	if(minu)x=-x;
	return x;
}
int a[20];
void work(int n){
	memset(a,0,sizeof(a));
	int tot=0,mi=10,one=-1,two=-1,f=true,ans=0;
	while(n>0){
		a[++tot]=n%10;
		mi=min(mi,a[tot]);
		n=n/10;
	}
	for(int i=1;i<=tot;i++){
		if(one==-1){
			one=a[i];continue;
		}
		if(two==-1){
		    if(a[i]!=one)two=a[i];
			continue;	
		}
		if(a[i]!=one&&a[i]!=two){
			f=false;break;
		}
	}
	while(f==false){
		int ma=a[tot];
	    for(int i=1;i<=tot;i++){
	    	if(a[i]>=ma)a[i]=a[i]-ma;
	    	if(a[i]<ma)a[i]=a[i]-mi;
		}
		ans++;
		while(a[tot]==0)tot--;
		one=-1;two=-1;f=true;
		for(int i=1;i<=tot;i++){
		    if(one==-1){
			   one=a[i];
			   continue;
		    }
		    if(two==-1){
		       if(a[i]!=one)two=a[i];
			   continue;	
		    }
		    if(a[i]!=one&&a[i]!=two){
			   f=false;
			   break;
		    }
	    }
	}
	if(ans+1>3)cout<<3<<endl;
	else cout<<ans+1<<endl;
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	read(t);
	for(int i=1;i<=t;i++){
		long long n;int tot=0;
		read(n);
		work(n);
	}
	return 0;
}


