#include<bits/stdc++.h>
//11 必须选 10和01配对选(最大的） 00和 10,01里剩下尽可能选大的,当1！=2时，如果正好能加大的，就一直加到==，然后再选大的 
//10 -> +1 -1
//01 -> -1 +1
//00 -> -1 -1 
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long good,can1,can2;
int m10[400005],pos_m10;
int m01[400005],pos_m01;
int m00[400005],pos_m00;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,tmp;
	read(n);
	tmp=n;
	for(int i=1;i<=n;++i)
	{
		char a;
		char b;
		int high;
		scanf("%c",&a);
		scanf("%c",&b);
		read(high);
		if(a=='1'&&b=='1')
		{
			good+=high;
			++can1;
			++can2;
			--tmp;
		}
		if(a=='0'&&b=='1')
		{
			m01[pos_m01]=high;
			++pos_m01;
		}
		if(a=='1'&&b=='0')
		{
			m10[pos_m10]=high;
			++pos_m10;
		}
		if(a=='0'&&b=='0')
		{
			m00[pos_m00]=high;
			++pos_m00;
		}
	}	 
	sort(m01,m01+pos_m01,cmp);
	sort(m10,m10+pos_m10,cmp);
	sort(m00,m00+pos_m00,cmp);
	int flag=1,a;
	if(pos_m01>pos_m10)
	{
		flag=0;
		a=pos_m10;
	}
	else
	{
		a=pos_m01;
	}
	tmp-=a;
	tmp-=a;
	for(int i=0;i<a;i++)
	{
		good+=m01[i];
		good+=m10[i];
	}
	if(flag)
	{
		for(int i=a;i<pos_m10;i++)
		{
			m00[pos_m00]=m10[i];
			pos_m00++;
		}
	}
	else
	{
		for(int i=a;i<pos_m01;i++)
		{
			m00[pos_m00]=m01[i];
			pos_m00++;
		}
	}
	stable_sort(m00,m00+pos_m00,cmp);
	for(int i=0;i<pos_m00;i++)
	{
		if(can1)
		{
			good+=m00[i];
			can1--;
		}
		else
		{
			break;
		}
	}
	cout<<good<<endl;
}
//11 10
//11 23
//10 1
//10 5
//01 1
//01 3
//00 1000
//00 100000
//00 999999










