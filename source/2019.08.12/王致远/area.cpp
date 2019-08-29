#include<bits/stdc++.h>
using namespace std;
int a,b,x[100010],y[100010],n[210][210],l,r;
bool ff,f[210][210];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);
	if ((a>100)||(b>100))
	{
		cout<<"infinity"<<endl;
		return 0;
	}
	l=2;n[0][0]=1;n[0][1]=1;n[1][0]=1;n[1][1]=-1;
	while (l<=100)
	{
		for (int i=0;i<l;i++)
			for (int j=l;j<l*2;j++)
			n[i][j]=n[i][j-l];
		for (int i=l;i<l*2;i++)
			for (int j=0;j<l;j++)
			n[i][j]=n[i-l][j];
		for (int i=l;i<l*2;i++)
			for (int j=l;j<l*2;j++)
			if (n[i-l][j-l]==-1) 
			n[i][j]=1;
			else n[i][j]=-1;
		l=l*2;
	}
	l=1;r=1;x[1]=a;y[1]=b;memset(f,0,sizeof(f));f[a][b]=1;
	while (l<=r)
	{
		if ((x[l]+1<128)&&(n[x[l]+1][y[l]]==n[x[l]][y[l]])&&(f[x[l]+1][y[l]]==0))
		{
			r++;
			x[r]=x[l]+1;
			y[r]=y[l];
			f[x[r]][y[r]]=1;
		}
		if ((y[l]+1<128)&&(n[x[l]][y[l]+1]==n[x[l]][y[l]])&&(f[x[l]][y[l]+1]==0))
		{
			r++;
			x[r]=x[l];
			y[r]=y[l]+1;
			f[x[r]][y[r]]=1;
		}
		if ((x[l]-1>=0)&&(n[x[l]-1][y[l]]==n[x[l]][y[l]])&&(f[x[l]-1][y[l]]==0))
		{
			r++;
			x[r]=x[l]-1;
			y[r]=y[l];
			f[x[r]][y[r]]=1;
		}
		if ((y[l]-1>=0)&&(n[x[l]][y[l]-1]==n[x[l]][y[l]])&&(f[x[l]][y[l]-1]==0))
		{
			r++;
			x[r]=x[l];
			y[r]=y[l]-1;
			f[x[r]][y[r]]=1;
		}
		l++;
	}
	ff=0;
	for (int i=0;i<128;i++)
	if (((f[i][127])&&(n[i][127]==1))||((f[127][i])&&(n[127][i]==1)))
	{
		ff=1;
		break;
	}
	if (ff)
	cout<<"infinity"<<endl;
	else cout<<r<<endl;
	return 0;
}
