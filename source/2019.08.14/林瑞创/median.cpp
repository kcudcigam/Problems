#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[500010],b[500010],c[500010];

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
    n=read();  m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    while(m--){
    	int type=read();     
    	if(type==1){
		    int x=read(),y=read(),z=read();
		    if(x)b[y]=z;  else a[y]=z;
		}else{
			int La=read(),Ra=read(),Lb=read(),Rb=read();
			int Len=Ra-La+1+Rb-Lb+1,mid=(Len>>1)+1;

			if(a[Ra]<b[Lb]){
				if(La+mid-1<=Ra){printf("%d\n",a[La+mid-1]);continue;}
				else{mid-=Ra-La+1,printf("%d\n",b[Lb+mid-1]);continue;} 
			}else 
			if(b[Rb]<a[La]){
				if(Lb+mid-1<=Rb){printf("%d\n",b[Lb+mid-1]);continue;}
				else{mid-=Rb-Lb+1,printf("%d\n",a[La+mid-1]);continue;}
			}else{
				if(La+mid-1<=Ra&&a[La+mid-1]<=b[Lb]){printf("%d\n",a[La+mid-1]);continue;}
				if(Lb+mid-1<=Rb&&b[Lb+mid-1]<=a[La]){printf("%d\n",b[Lb+mid-1]);continue;}
				
				memset(c,0,sizeof(c));  
				int i=La,j=Lb,tot=0;
				while(tot<mid&&i<=Ra&&j<=Rb){
					if(a[i]<=b[j]&&i<=Ra&&j<=Rb)c[++tot]=a[i++];
					if(b[j]<a[i]&&j<=Rb&&i<=Ra)c[++tot]=b[j++];
				}
				while(tot<mid&&i<=Ra)c[++tot]=a[i++];
				while(tot<mid&&j<=Rb)c[++tot]=b[j++];
				printf("%d\n",c[tot]);
			}
		}
	}
	return 0;
}

