#include<bits/stdc++.h>
using namespace std;
#define maxk 32
#define maxa 8
const int totnumber=31;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
//圈子从9号开始顺时针，16号是7 
int lines[maxa][maxk],ltrs[maxa][maxk],rtls[maxa][maxk],quans[maxa][maxk],k,n,first[33],a[6],now[33],sttime=time(0);
bool flag=0;
int line(int x)
{
	if(x<3)
	{
		return 1;
	}
	if(x<8)
	{
		return 2;
	}
	if(x<14)
	{
		return 3;
	}
	if(x<19)
	{
		return 4;
	}
	if(x<25)
	{
		return 5;
	}
	if(x<30)
	{
		return 6;
	}
	return 7;
}
int ltr(int x)
{
	if(x==30)
	{
		return 2;
	}
	if(x==31)
	{
		return 3;
	}
	if(x==1)
	{
		return 5;
	}
	if(x==2)
	{
		return 6;
	}
	if(x==7||x==13)
	{
		return 7;
	}
	return ((x%6)==0?6:(x%6));
}
int rtl(int x)
{
	if(x==3||x==8)
	{
		return 1;
	}
	if(x==1)
	{
		return 2;
	}
	if(x==2)
	{
		return 3;
	}
	if(x==30)
	{
		return 5;
	}
	if(x==31)
	{
		return 6;
	}
	if(x==24||x==29)
	{
		return 7;
	}
	if(x%5==4)
	{
		return 2;
	 } 	
	 if(x%5==1)
	{
		return 4;
	}
	 if(x%5==0)
	 {
	 	return 3;
	 }
	 if(x%5==2)
	 {
	 	return 5;
	 }
	 if(x%5==3)
	 {
	 	return 6;
	 }
}
int quan(int x)
{
	int pos=0;
	if(x==3||x==4||x==8||x==9||x==10||x==14||x==15)
	{
		a[pos]=1;
		pos++;
	}
	if(x==1||x==2||x==6||x==4||x==10||x==11||x==5)
	{
		a[pos]=2;
		pos++;
	}
	if(x==6||x==7||x==11||x==12||x==13||x==17||x==18)
	{
		a[pos]=3;
		pos++;
	}
	if(x==17||x==18||x==22||x==23||x==24||x==28||x==29)
	{
		a[pos]=4;
		pos++;
	}
	if(x==21||x==22||x==26||x==27||x==28||x==30||x==31)
	{
		a[pos]=5;
		pos++;
	}
	if(x==14||x==15||x==19||x==20||x==21||x==25||x==26)
	{
		a[pos]=6;
		pos++;
	}
	if(x==10||x==11||x==15||x==16||x==17||x==21||x==22)
	{
		a[pos]=7;
		pos++;
	}
	return pos;
}
void print()
{
	flag=1;
	puts("Found");
	for(int i=1;i<=totnumber;i++)
	{
		printf("%d ",now[i]);
	}
}
bool vis[32];
int tot;
void dfs(int x)
{
//	cout<<x<<endl;
	if(time(0)-sttime>=1950)
	{
		flag=1;
		puts("No way");
	}
	if(x==32)
	{
		tot++;
		if(tot==n)
		{
			print();
		//	exit(0);
		}	
		return;
	}
	if(first[x])
	{
		dfs(x+1);
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			bool tf=1;	
			int rpos=quan(x);
			if((!lines[line(x)][i])&&(!rtls[rtl(x)][i])&&(!ltrs[ltr(x)][i]))
			{
				for(int j=0;j<rpos;j++)
				{
					if(quans[a[j]][i])
					{
						tf=0;	
						break;
					}
				}
				if(tf)
				{
					lines[line(x)][i]=1;
					rtls[rtl(x)][i]=1;
					ltrs[ltr(x)][i]=1;
					for(int j=0;j<rpos;j++)
					{
						quans[a[j]][i]=1;
					}
					now[x]=i;
					dfs(x+1);				
					if(flag)
					{
						return;
					}				
					rpos=quan(x);
					for(int j=0;j<rpos;j++)
					{
						quans[a[j]][i]=0;
					} 						
					lines[line(x)][i]=0;
					rtls[rtl(x)][i]=0;
					ltrs[ltr(x)][i]=0;
				}
			}

		}
	}
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	read(k);
	read(n);
	if(k<7)
	{
		puts("No way");
	}
	else
	{
		for(int i=1;i<=totnumber;i++)
		{
			read(first[i]);
			now[i]=first[i];
			if(first[i])
			{
				lines[line(i)][first[i]]=1;
				ltrs[ltr(i)][first[i]]=1;
				rtls[rtl(i)][first[i]]=1;
				int rpos=quan(i);
				for(int i=0;i<rpos;i++)
				{
					quans[a[i]][first[i]]=1;
				}
			}
		//	system("pause");
		}
		dfs(1);
		if(!flag)
		{
			puts("No way");
		}
	}
}
/*
8 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0*/

