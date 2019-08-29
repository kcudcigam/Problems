#include<bits/stdc++.h>

using namespace std;

int vis[5][10]; //×´Ñ¹¼ÇÂ¼ÖØ¸´
int a[50],cnt,n,k,flag;
int b[7][7]=
{
	{1,2,4,5,6,10,11},
	{3,4,8,9,10,14,15},
	{6,7,11,12,13,17,18},
	{10,11,15,16,17,21,22},
	{14,15,19,20,21,25,26},
	{17,18,22,23,24,28,29},
	{21,22,26,27,28,30,31}
};

void read(int &p)
{
	p=0;int flag=1;char s=getchar();
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
}

int ask_h(int num)
{
	if(num<=2) return 0;
	if(num<=7) return 1;
	if(num<=13) return 2;
	if(num<=18) return 3;
	if(num<=24) return 4;
	if(num<=29) return 5;
	if(num<=31) return 6;
}

int ask_z(int num)
{
	if(num==3||num==8) return 0;//2
	if(num==1) return 1;//1
	if(num==2) return 2;//1
	if(num==30) return 4;//1
	if(num==31) return 5;//1
	if(num==24||num==29) return 6;//2
	if(num%5==4) return 1;//4
	if(num%5==0) return 2;//5
	if(num%5==1) return 3;//5
	if(num%5==2) return 4;//5
	if(num%5==3) return 5;//4
}

int ask_y(int num)
{
	
	if(num==30) return 5;
	if(num==31) return 4;
	if(num==1) return 2;
	if(num==2) return 1;
	if(num%6==0) return 1;
	if(num==7||num==13) return 0;
	if(num%6==5) return 2; 
	if(num%6==4) return 3;
	if(num%6==3) return 4;
	if(num%6==2) return 5;
	if(num%6==1) return 6;
}

int work_b(int num,int K)
{
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=6;j++)
		if(num==b[i][j]) 
		{
		//	if(K>0) cout<<(vis[3][i]&K)<<endl;
			//else cout<<"O";
			vis[3][i]+=K;
		//	if(K<0)cout<<(vis[3][i]&(-K))<<endl;
		}
	}
}

int chec(int num,int K)
{
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<=6;j++)
		if(num==b[i][j]) 
		{
			if(vis[3][i]&K) return K;
		}
	}
	return 0;
}

void dfs(int x)
{
	if(x==32)
	{
		cnt++;//cout<<cnt<<endl;
		if(cnt==n)
		{
			flag=1;
			puts("Found");
			
			for(int i=1;i<=31;i++) printf("%d ",a[i]);
			puts("");
			//return ;
		}
		return ;
	}
	
	if(a[x]) {dfs(x+1);return ;}
	int temh=ask_h(x),temz=ask_z(x),temy=ask_y(x);
	
	for(int i=1;i<=k;i++)
	{
		int tem=(1<<(i-1));

		if((vis[0][temh]&tem)||(vis[1][temz]&tem)||(vis[2][temy]&tem)||chec(x,tem)) continue;

		//if(a[14]==7) cout<<x<<" "<<i<<endl;
		vis[0][temh]+=tem;
		vis[1][temz]+=tem;
		vis[2][temy]+=tem;
		work_b(x,tem);
		a[x]=i;
		dfs(x+1);
		a[x]=0;
		if(flag) return ;
		vis[0][temh]-=tem;
		vis[1][temz]-=tem;
		vis[2][temy]-=tem;
		work_b(x,-1*tem);
	}
}
 


int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	read(k);read(n);
	for(int i=1;i<=31;i++) read(a[i]);
	
	for(int i=1;i<=31;i++)
	{
		if(a[i])
		{
			if(a[i]>k)
			{
				puts("No way");
				return 0;
			}
			int temh=ask_h(i),temz=ask_z(i),temy=ask_y(i);int tem=(1<<(a[i]-1));
			if(vis[0][temh]&tem) {puts("No way");return 0;}
			else vis[0][temh]+=tem;
			if(vis[1][temz]&tem) {puts("No way");return 0;}
			else vis[1][temz]+=tem;
			if(vis[2][temy]&tem) {puts("No way");return 0;}
			else vis[2][temy]+=tem;
			if(chec(i,tem)) {puts("No way");return 0;}
			else work_b(i,tem);
		}
	}
	
	dfs(1);

	if(!flag) puts("No way");
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
