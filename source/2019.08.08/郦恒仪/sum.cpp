#include<bits/stdc++.h>
#include<cctype>
using namespace std;
inline int read(){
	int x=0,w=1;
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
int sumzheng[1000005],zhongnum,zhong[100005],xun,nownum,nowzuo[1000005],nowyou[1000005],c[100005],sum[1000005],b[800005],n,m,i,j,k,l,s,d,f,r,a[800005],zuo[800005],you[800005],maxa[800005]; 
/*void sou(int dep){
	if(a[dep]>maxa[dep]){
		nownum++;
		nowzuo[nownum]=zuo[dep];
		nowyou[nownum]=you[dep];
		return;
	}
	if(zuo[dep]==you[dep]){
		nownum++;
		nowzuo[nownum]=zuo[dep];
		nowyou[nownum]=you[dep];
		return;
	}
	sou(dep*2);
	sou(dep*2+1);
	return;
}
void jianshu(int dep,int f,int r){
	a[dep]=sum[r]-sum[f-1];
	zuo[dep]=f;
	you[dep]=r;
	if(f==r){
		maxa[dep]=b[f];
		return;
	}
	int k=(f+r)/2;
	jianshu(dep*2,f,k);
	jianshu(dep*2+1,k+1,r);
	maxa[dep]=max(maxa[dep*2],maxa[dep*2+1]);
}*/
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++){
		b[i]=read();
	}
	if(n==2){
		cout<<b[1]+b[2]<<endl;
		return 0;
	}
	if(b[1]>0){
		xun=1;
	}
	else{
		xun=0;
	}
	s=b[1];
	m=0;
	for(i=2;i<=n;i++){
		if(b[i]>0){
			if(xun==1){
				s+=b[i];
			}
			else{
				m++;
				b[m]=s;
				xun=1;
				s=b[i];
			}
		}
		else{
			if(xun==0){
				s+=b[i];
			}
			else{
				m++;
				b[m]=s;
				xun=0;
				s=b[i];
			}
		}
	}
	if(s>0){
		m++;
		b[m]=s;
	}
	n=m;
	if(b[1]<=0){
		n--;
		for(i=1;i<=m-1;i++){
			b[i]=b[i+1];
		}
	}
	/*cout<<n<<endl;
	for(i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
	sumzheng[0]=0;
	for(i=1;i<=n;i++){
		sumzheng[i]=sumzheng[i-1];
		if(b[i]>0){
			sumzheng[i]+=b[i];
		}
	}
	m=0;
	for(i=2;i<=n;i++){
		if(b[i]<=0){
			m++;
			a[m]=b[i]+b[i+1];
		}
	}
	/*cout<<m<<endl;
	for(i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	sum[0]=0;
	for(i=1;i<=m;i++){
		sum[i]=sum[i-1]+a[i];
	}
	zhongnum=0;
	for(i=1;i<=n;i++){
		if(i&1){
			d=0;
			for(j=(i+1)/2;j<=m;j++){
				//cout<<zhongnum+1<<" "<<b[i]+sum[j]-sum[i/2]<<" "<<sumzheng[j*2+1]-sumzheng[i]<<endl;
				if(a[j]<=0||b[i]+sum[j]-sum[i/2]<=sumzheng[j*2+1]-sumzheng[i]){
					zhongnum++;
					zhong[zhongnum]=b[i]+sum[j-1]-sum[i/2];
					i=j*2;
					d=1;
					break;
				}
			}
			if(d==0){
				zhongnum++;
				zhong[zhongnum]=b[i]+sum[m]-sum[i/2];
				break;
			}
		}
	}
	/*cout<<zhongnum<<endl;
	for(i=1;i<=zhongnum;i++){
		cout<<zhong[i]<<" ";
	}
	cout<<endl;*/
	if(zhongnum==1){
		cout<<zhong[1]<<endl;
	}
	else{
		int zuida=max(zhong[1],zhong[2]),cida=min(zhong[1],zhong[2]);
		for(i=3;i<=zhongnum;i++){
			if(zhong[i]>zuida){
				cida=zuida;
				zuida=zhong[i];
			}
			else
			if(zhong[i]>cida){
				cida=zhong[i];
			}
		}
		cout<<cida+zuida<<endl;
	}
	/*jianshu(1,1,n);
	sou(1);*/
	/*for(i=1;i<=nownum;i++){
		cout<<i<<":"<<nowzuo[i]<<" "<<nowyou[i]<<endl;
	}*/
	return 0;
}


