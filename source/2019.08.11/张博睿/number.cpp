#include<bits/stdc++.h>
using namespace std;
long long n,ans,kn;
int t,h[10],duck,sl[30],dz,k;
void fj(long long x)
{
	int a=x%10;
	h[a]++;
	k++;sl[k]=a;
	if(x/10!=0) fj(x/10);
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		k=0;dz=0;
		memset(h,0,sizeof(h));duck=0;memset(sl,0,sizeof(sl));
		cin>>n;
		kn=n;
		fj(kn);
		for(int j=0;j<=9;j++) if(h[j]!=0) duck++;
		if(duck<=2) cout<<1<<endl;
		else
		{
			if(duck<=4) cout<<2<<endl;
			else 
			{
				for(int j=2;j<=k;j++) if(sl[j]<sl[j-1]) dz++;else break;
				if(dz>=k/2) cout<<(duck-1)/2<<endl;
				else cout<<(duck+1)/2<<endl; 
			}
		}
	}
	return 0;
}


