#include<bits/stdc++.h>
using namespace std;
int n,A[400010],cnum,sum; bool check[5010];
multiset<int> a,b,d;

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

int devide(int x,int y){
	return x%y ? x/y+1 : x/y;
}

int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
    n=read();
    if(n==1){puts("0");return 0;}
    for(int i=1;i<=n;i++){
    	int type=read(); A[i]=read();
    	if(type==10)a.insert(A[i]),sum+=A[i];
    	if(type==1)b.insert(A[i]),sum+=A[i];
    	if(type==11)
		  check[A[i]]==1,cnum++,sum+=A[i];
		if(type==0)d.insert(A[i]);
	}
	int anum=a.size(),bnum=b.size();
	multiset<int>::iterator ita=a.begin(),itb=b.begin(),itd=--d.end();
 
    while(anum>bnum&&devide(anum+bnum+cnum,2)>bnum+cnum)
        if(!A[*ita])sum-=*ita,ita++,anum--;else ita++;
    while(bnum>anum&&devide(anum+bnum+cnum,2)>anum+cnum)
        if(!A[*itb])sum-=*itb,itb++,bnum--;else itb++;
    
    int x=0;
    while(devide(anum+bnum+cnum+x+1,2)<=min(anum,bnum)+cnum)
    	 sum+=*itd,itd--,x++;

    printf("%d\n",sum);
	return 0;
}
