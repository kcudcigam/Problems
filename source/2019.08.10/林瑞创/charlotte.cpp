#include<bits/stdc++.h>
using namespace std;
int n,t[100010],x[100010],y[100010];
int c[100010],num[100010]; bool tt[10000010];
inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
    int T=read();  
    while(T--){
    	n=read();bool flag=0;  
    	for(int i=1;i<=n;i++){
    		t[i]=read(),x[i]=read(),y[i]=read();
//			if(c[x[i]]==y[i]&&!tt[t[i]]){puts("No");flag=1;break;}
//			if(tt[t[i]]&&c[x[i]]!=y[i]){puts("No");flag=1;break;}
//			c[x[i]]=y[i],tt[t[i]]=1;
            if(y[num[x[i]]]==y[i]&&t[num[x[i]]]!=t[i]){puts("No");flag=1;break;}
            if(t[num[x[i]]]==t[i]&&y[num[x[i]]]!=y[i]){puts("No");flag=1;break;}
			num[x[i]]=i; 
		}
    	if(flag)continue;
    	for(int i=1;i<=n;i++)
    	  if(abs(x[i]-x[i-1])+abs(y[i]-y[i-1])>t[i]-t[i-1]){
    	  	flag=1;puts("No");break;
		  }
    	if(!flag)puts("Yes");  
	}
	return 0;
}


