#include<bits/stdc++.h>
using namespace std;
long long f[20],q,n,mo;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
   freopen("mod.in","r",stdin);
   freopen("mod.out","w",stdout);
   read(q);
    f[1]=0;f[2]=2;f[3]=12;f[4]=58;f[5]=310;f[6]=1886;
    f[7]=13244;f[8]=106002;f[9]=954090;f[10]=9540982;
  while(q--)
    {
    	read(n);read(mo);
    	if(n>=1&&n<=10)
    	cout<<f[n]%mo<<endl;
    	else
    	{
    	for(register int i=11;i<=n;i++)
    	{
    		f[i]=1ll*f[i-1]*i+1ll*i*(i-1);
    		if(i%2==0)
    		f[i]=1ll*f[i]-i+2;
		}
		printf("%lld\n",f[n]%mo);
	}
	}
	return 0;
}
