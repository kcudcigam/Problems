#include<cstdio>
#include<iostream>
using namespace std;
char a[501][501];
int dad[250001];
int len,s;
int ord(int i,int j)
{
	return (i-1)*len+j;
}
int find(int x)
{
	return dad[x]=(dad[x]==x)?x:find(dad[x]);
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	/*
	a[1][1]=a[1][2]=a[2][1]='o';
	a[2][2]='x';
	len=2;
	while(len<=500)
	{
		for(int i=1;i<=len;i++)
			for(int j=len+1;j<=len*2;j++)
				a[i][j]=a[i][j-len],
				a[j][i]=a[j-len][i];
		for(int i=1;i<=len;i++)
			for(int j=1;j<=len;j++)
				a[i+len][j+len]='o'+'x'-a[i][j];
		len*=2;
	}
	len/=2;
	for(int i=1;i<=len*len;i++)
		dad[i]=i;
	for(int i=1;i<=len;i++)
		for(int j=1;j<=len;j++)
		{
			if(a[i][j]==a[i][j+1]&&j+1<=len&&find(ord(i,j+1))!=find(ord(i,j)))
				dad[find(ord(i,j+1))]=find(ord(i,j));
			if(a[i][j]==a[i+1][j]&&i+1<=len&&find(ord(i+1,j))!=find(ord(i,j)))
				dad[find(ord(i+1,j))]=find(ord(i,j));
		}
	int x,y;
	cin>>x>>y;
	x++;
	y++;
	for(int i=1;i<=len*len;i++)
		s+=(find(ord(x,y))==find(i));
	cout<<s;*/
	printf("infinity");
}
