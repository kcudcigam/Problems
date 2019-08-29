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
	}//只做k=31的部分 
	
	//找到当前字典序最小的满足要求的排列,记为第0个 
	for(int i=1;i<=31;i++)
	{
		if(a[i])
		{
			b[i]=a[i];
			vis[a[i]]=1;
		}
	}//不是0就直接填
	for(int i=1;i<=31;i++)
	{
		if(!vis[i])
			v.push(-i);
	}//记录没填的数字，并放在小根堆里面 
	int ii=1;
	while(!v.empty())
	{
		while(b[ii]) ii++;
		b[ii]=-v.top();
		v.pop();
	}//把小根堆里的数字依次填进来 
	
	n--;//第1小就是第0个排列 
	while(n&&(next_permutation(b+1,b+32)))//next_permutation可以在求下一个排列的同时判断还有没有下一个排列 
	{
		n--;
	}
	
	if(n>0)
	{
		printf("No way\n");
		return 0;
	}//n倒计时结束前就已经退出,说明没有第n个排序 
	
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

