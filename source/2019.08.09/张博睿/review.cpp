#include<bits/stdc++.h>
using namespace std;
long long y,m2[70],fh[70],a;
void cf(long long x)
{
	if(x==0) return;
	for(int j=61;j>=0;j--) 
	if(x<=m2[j])
	{
		fh[j+1]=1;
		a=j;
		break;
	}
	cf(x-m2[a]);
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	memset(fh,0,sizeof(fh));
	if(y==1) 
	{
		cout<<2<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
	}
	else
	if(y==2)
	{
		cout<<3<<" "<<3<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<2<<" "<<3<<endl;
		cout<<1<<" "<<3<<endl;
	}
	else
	{
		m2[0]=1;
		for(int i=1;i<=62;i++) m2[i]=m2[i-1]*2;
		for(int i=62;i>=1;i--)
		{
		   if(y==m2[i])
		   {
		   	cout<<i+2<<" "<<(i+1)*(i+2)/2<<endl;
		   	for(int j=1;j<=i+1;j++)
			  for(int k=j+1;k<=i+2;k++) cout<<j<<" "<<k<<endl;
			  return 0; 
		   }
		   if(y+1==m2[i])
		   {
		   	cout<<i+2<<" "<<(i+1)*(i+2)/2-1<<endl;
		   	for(int j=1;j<=i+1;j++)
			  for(int k=j+1;k<=i+2;k++) if(k!=i+2||j!=1)cout<<j<<" "<<k<<endl;
			  return 0; 
		   }
		}
		if(y<=50)
		{
			cout<<y+2<<" "<<2*y<<endl;
			for(int i=2;i<=y+1;i++) cout<<1<<" "<<i<<endl;
			for(int i=2;i<=y+1;i++) cout<<i<<" "<<y+2<<endl;
			return 0;
		}
		for(int i=62;i>=2;i--)
		 for(int j=61;j>=1;j--)
		{
			if(y+m2[j]==m2[i])
			{
			cout<<i+2<<" "<<(i+1)*(i+2)/2-1<<endl;
			for(int k=1;k<=i+1;k++)
			  for(int l=k+1;l<=i+2;l++) if(k!=j+1||l!=i+2)cout<<k<<" "<<l<<endl;
			return 0;	
			}
		}
		for(int i=62;i>=2;i--)
		{
			if(m2[i]>y)
			{
			cf(m2[i]-y);
			cout<<i+2<<" "<<(i+1)*(i+2)/2-(m2[i]-y)<<endl;
			for(int k=1;k<=i+1;k++)
			  for(int l=k+1;l<=i+2;l++) if(fh[k]==0||l!=i+2)cout<<k<<" "<<l<<endl;
			return 0;  	
			}
		}
	}
	return 0;
}

