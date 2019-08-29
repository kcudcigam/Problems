#include<bits/stdc++.h>
using namespace std;
inline long long  read(){
	long long x=0,f=1;
	char c=getchar();
	while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
int n,q;
int f[500005],tot[500005]={0};
int get(int x){
	if(f[x]==x) return x;
	return f[x]=get(f[x]);
}
void meg(int x,int y){
	f[get(x)]=get(y);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	while(q--){
		int cz=read();
		if(cz==1){
			int x=read(),y=read();
			if(get(x)!=get(y))meg(x,y);
		}else{
			int a=read(),b=read(),fath=get(a);
			for(int i=1;i<=n;i++){
				if(get(i)==fath)tot[i]+=b;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<tot[i]<<' ';
	}
	cout<<endl;
	return 0;
}


