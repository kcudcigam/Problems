#include<bits/stdc++.h>
using namespace std;
int a[40],b[40],vis[40];
int k,n;
priority_queue<int> v;
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	 
	
	scanf("%d %d",&k,&n);
	for(int i=1;i<=31;i++)
		scanf("%d",&a[i]);
		
	if(k!=31)
	{
		printf("No way\n");
		return 0;
	}//ֻ��k=31�Ĳ��� 
	
	//�ҵ���ǰ�ֵ�����С������Ҫ�������,��Ϊ��0�� 
	for(int i=1;i<=31;i++)
	{
		if(a[i])
		{
			b[i]=a[i];
			vis[a[i]]=1;
		}
	}//����0��ֱ����
	for(int i=1;i<=31;i++)
	{
		if(!vis[i])
			v.push(-i);
	}//��¼û������֣�������С�������� 
	int ii=1;
	while(!v.empty())
	{
		while(b[ii]) ii++;
		b[ii]=-v.top();
		v.pop();
	}//��С�������������������� 
	
	n--;//��1С���ǵ�0������ 
	while(n&&(next_permutation(b+1,b+32)))//next_permutation����������һ�����е�ͬʱ�жϻ���û����һ������ 
	{
		n--;
	}
	
	if(n>0)
	{
		printf("No way\n");
		return 0;
	}//n����ʱ����ǰ���Ѿ��˳�,˵��û�е�n������ 
	
	printf("Found\n");
	printf("%d",b[1]);
	for(int i=2;i<=31;i++)
		printf(" %d",b[i]);
	printf("\n");
	
	return 0;
}
/*
31 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0

31 10
31
30 29 28 27 26 25 24 23 22 21
20 19 18 0 0 0 0 13 12 11
10 9 8 7 6 5 4 3 2 1
*/

