#include<bits/stdc++.h>
#include<cctype>
using namespace std;
inline long long read(){
	long long x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
int a[1005][1005];
long long dian[1005],n,m,i,j,k,l,s,d,f,r;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	k=read();
	if(k==1){
		cout<<2<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
	}
	else
	if(k==2){
		cout<<3<<" "<<3<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<2<<" "<<3<<endl;
	}
	else{
		n=4;
		memset(a,0,sizeof(a));
		memset(dian,0,sizeof(dian));
		a[1][2]=1;
		a[1][3]=1;
		a[2][3]=1;
		a[3][4]=1;
		dian[1]=1;
		dian[2]=1;
		dian[3]=2;
		dian[4]=2;
		s=4;
		l=2;
		while(l*2<k){
			l*=2;
			n++;
			for(i=3;i<=s;i++){
				a[i][n]=1;
			}
			s=n;
			dian[n]=l;
		}
		//cout<<"OK1"<<endl;
		n++;
		while(k!=0){
			//cout<<k<<" "<<l<<endl;
			if(k>=l){
				k-=l;
				d=0;
				for(i=1;i<=n-1;i++){
					if(dian[i]==l){
						d=i;
						break;
					}
				}
				a[d][n]=1;
			}
			if(k==2&&l==2){
				k=0;
				a[4][n]=1;
				break;
			}
			l=l/2;
		}
		//cout<<"OK2"<<endl;
		m=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i][j]){
					m++;
				}
			}
		}
		cout<<n<<" "<<m<<endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i][j]){
					printf("%d ",i);
					printf("%d\n",j);
				}
			}
		}
	}
	return 0;
}

