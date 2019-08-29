#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
  for (; isdigit(c);c=getchar()) x=x*10+c -'0';
  x*=f;
}
long long n,q,x,y;
long long f[500005],s[500005];
int w;
int work(int a){
	if(f[a]==a)
	   return a;
	f[a]=work(f[a]);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
    read(n);
    read(q);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=q;i++){
    	read(w);
    	if(w==1){
    		read(x);
    		read(y);
    		f[f[max(x,y)]]=f[f[min(x,y)]];
		}
		if(w==2){
			for(int i=1;i<=n;i++)
			    f[i]=work(i);
		    read(x);
		    read(y);
		    for(int j=1;j<=n;j++)
		        if(f[j]==f[x])
		           s[j]=s[j]+y;
		}
	}
	for(int i=1;i<=n-1;i++)
	    cout<<s[i]<<' ';
	cout<<s[n]<<endl;
	return 0;
}
