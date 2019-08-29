#include<bits/stdc++.h>
using namespace std;
bool fff[11];
long long b;
int a,s,l,n[110];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
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
		cout<<1<<endl;
		else cout<<2<<endl; 
	}
	return 0;
}


