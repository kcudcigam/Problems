#include<bits/stdc++.h>
using namespace std;
int ans,n;
int b[5];
int a[5][400010];
int c[400010];
void Merge(int x,int y){
	memset(c,0,sizeof(c));
	int i=1,j=1;
	while(a[y][i]<=x&&i<=b[y]){
		c[j]=a[y][i];
		i++,j++;
	}
	c[j]=x;	
	j++;
	
	while(i<=b[y]){
		c[j]=a[y][i];
		i++,j++;
	}
	
	for(int i=1;i<j;++i){
		a[y][i]=c[i];
	}
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	int x,y;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		if(x==11){//1
			Merge(y,1);
			b[1]++;
		}
		if(x==0){//2
			Merge(y,2);
			b[2]++;
		}
		if(x==1){//3
			Merge(y,3);
			b[3]++;
		}
		if(x==10){//4
			Merge(y,4);
			b[4]++;
		}
	}
	while(b[3]&&b[4]){
		ans+=a[3][b[3]]+a[4][b[4]];
		b[3]--;
		b[4]--;
	}
	while(b[1]&&(b[2]||b[3]||b[4])){
		int a1=a[1][b[1]],a2=a[2][b[2]],a3=a[3][b[3]],a4=a[4][b[4]];
		if(a2>=a3&&a2>=a4){
			ans+=a1+a2;
			b[2]--;
		}else
		if(a3>=a2&&a3>=a4){
			ans+=a1+a3;
			b[3]--;
		}else{
			ans+=a1+a4;
			b[4]--;
		}
		b[1]--;
	}
	
	
	while(b[1]){
		ans+=a[1][b[1]];
		b[1]--;
	}
	
	cout<<ans<<endl;
	return 0;
}
