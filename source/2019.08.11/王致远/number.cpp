#include<bits/stdc++.h>
using namespace std;
bool f,ff,fff[11];
long long b;
int a,s,l,n[110],t[11],r;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void chck()
{
	ff=0;r=0;
	for (int i=1;i<=l;i++)
	{
		if (t[1]+t[3]+r==n[i]) 
		{
			r=0;
			continue;
		}
		if (t[1]+t[4]+r==n[i])
		{
			r=0;
			continue;
		}
		if (t[2]+t[3]+r==n[i])
		{
			r=0;
			continue;
		}
		if (t[2]+t[4]+r==n[i])
		{
			r=0;
			continue;
		}
		if (t[1]+t[3]+r+10==n[i]) 
		{
			r=1;
			continue;
		}
		if (t[1]+t[4]+r+10==n[i])
		{
			r=1;
			continue;
		}
		if (t[2]+t[3]+r+10==n[i])
		{
			r=1;
			continue;
		}
		if (t[2]+t[4]+r+10==n[i])
		{
			r=1;
			continue;
		}	
		ff=1;
		break;
	}
	if (ff==0) f=1;
}
void wrk(int u)
{
	if (u>4)
	chck();
	else for (int i=0;i<=9;i++)
	     {
	     	t[u]=i;
	     	wrk(u+1);
	     	if (f) return;
		 }
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);
	for (int i=1;i<=a;i++)
	{
		read(b);memset(fff,0,sizeof(fff));s=0;l=0;
		while (b>0)
		{
			l++;
			n[l]=b%10;
			if (fff[b%10]==0)
			{
				s++;
				fff[b%10]=1;
			}
			b=b/10;
		}
		if (s<=2)
		{
			cout<<1<<endl;
			continue;
		}
		f=0;
		wrk(1);
		if (f)
		cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}


