#include<cstdio>
int n,m,q,head[300010],Exciting,value[300010]; //Excited 水可载舟，亦可赛艇 
struct TuYangTuSenPo //Too young, Too simple, sometimes naiive
{
	int v,nxt;
}e[300030];
void add(int u,int v) //今天天气本来...
					  //我们神仙DWT一来就... 
{
	e[++Exciting]=(TuYangTuSenPo){v,head[u]};
	head[u]=Exciting;
	return ;
}
int main() //Excited Frog (Split by yourself)
/*
/
     ---^-----
    /  -   -  \
---|          |---
|  |             |
---|          |---
   ------------
   ----    ----
   |  |    |  |
   |  |    |  |
   |  |    |  |
   |   /  \  |
 -----------------
  /    -   -    \
   /--| |-| |--\
*/
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	int type,x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&type,&x);
		if(type)
		{
			scanf("%d",&y);
			for(int i=head[x];i;i=e[i].nxt) value[e[i].v]+=y;
		}
		else printf("%d\n",value[x]);
	}
	return 0;
}

//Remind: You successfully took yourself to the shooting list 
