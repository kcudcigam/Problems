#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],b[500002],k,c,d,e,f,h[500002],l,r,g;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=ri();
	for(int i=1;i<=n;i++) b[i]=ri();
	for(int i=1;i<=m;i++)
	{
		k=ri();c=ri();d=ri();e=ri();
		if(k==1)
		{
			if(c==0) a[d]=e;
			else b[d]=e;
		}
		else
		{
			f=ri();
			g=(d-c+3+f-e)/2;
			if(a[d]<=b[e])
			{
				if(g<=(d-c+1))printf("%d\n",a[c+g-1]);
				else printf("%d\n",b[g-d+c-2+e]);
			} 
			else
			{
			if(b[f]<=a[c])
			{
				if(g<=(f-e+1))printf("%d\n",b[e+g-1]);
				else printf("%d\n",a[g-f+e-2+c]);
			}
			else
			{
				l=c;r=e;
				for(int j=1;j<=g;j++) 
				{
					if(a[l]<=b[r])
					{
					if(l<=d){h[j]=a[l];l++;}
					else{h[j]=b[r];r++;}	
					}
					else
					if(r>f)
					{
						h[j]=a[l];l++;
					}
					else{h[j]=b[r];r++;}
				}
				printf("%d\n",h[g]);
			}	
			}
		}
	}
	return 0;
}


