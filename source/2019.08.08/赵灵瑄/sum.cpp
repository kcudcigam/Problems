#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
  for (; isdigit(c);c=getchar()) x=x*10+c -'0';
  x*=f;
}
int l;
long long n,s1,s2,ans,num;
long long s[100005],a[100005],sum[100005];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	s[i]=s[i-1]+a[i];
    	sum[i]=-1000000000;
	}
	ans=a[1]+a[2];
	l=0;
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n-1;j++){
		    s1=s[j]-s[i-1];
		    s2=a[j+1];
		    if(sum[j+1]!=-1000000000){
		    	s2=sum[j+1];
			}
			else{
			for(int x=j+1;x<=n;x++)
		    	for(int y=x;y<=n;y++){
		    		if(s[y]-s[x-1]>s2){
		    			l=x;
		    			num=s[y]-s[x-1];
		    			s2=num;
					}
				}	
				for(int y=j+1;y<=l;y++)
				  sum[y]=num;
			}  
		    ans=max(ans,s1+s2);
		}
	}
	cout<<ans<<endl;
	return 0;
}


