#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int Num,n,m,x,y,l;
int len[2005][2005],f[2005][2005];
int main(){
	freopen("rebirth.in","r",stdin);
    freopen("rebirth.out","w",stdout);
    read(Num);
    read(n);
    read(m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
        	len[i][j]=1000000000;
        	f[i][j]=1000000000;
		}  
    len[1][1]=0;
    for(int i=1;i<=m;i++){
    	read(x);read(y);read(l);    	
    	if(len[x][y]!=1000000000){
    		f[x][y]=max(l,len[x][y]);
    	    f[y][x]=f[x][y];
			len[x][y]=min(l,len[x][y]);
    	    len[y][x]=len[x][y];
		}
		else{
		    len[x][y]=min(l,len[x][y]);
    	    len[y][x]=len[x][y];
			f[x][y]=len[x][y];
			f[y][x]=f[x][y];
	    }
	}
	
	for(int k=1;k<=n;k++)
	    for(int i=1;i<=n;i++){
	    	if(i==k)
	    	   continue;
	    	for(int j=1;j<=n;j++){
	        	if(j!=k&&j!=i){
	        		if(len[k][i]>len[k][j]+len[j][i]){
	    	    	    f[k][i]=len[k][i];
	    	    	    len[k][i]=len[k][j]+len[j][i];
	    	    	    len[i][k]=len[k][i];
				    }
				    else{
					    if(f[k][i]==len[k][i])
						   f[k][i]=len[k][j]+len[j][i];
						   else f[k][i]=min(f[k][i],len[k][j]+len[j][i]);
				    }
				}
		    }
		}
	        
	cout<<0;
	for(int i=2;i<=n;i++){
		if(f[1][i]>=1000000000)
		   cout<<" -1";
		   else cout<<' '<<f[1][i];
	}
	cout<<endl;
	return 0;
}

