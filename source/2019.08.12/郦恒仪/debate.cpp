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
struct nodd{
	int h;
	int hh;
	int chang;
	int biao;
}a[400005];
int zuo[400005],hab[400005],you[400005],younum,zuonum,mm,n,m,i,j,k,l,s,d,f,r;
char c;
bool cmp(int aa,int bb){
	return a[aa].chang>a[bb].chang;
}
bool cmp2(nodd aa,nodd bb){
	return aa.chang>bb.chang;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=read();
	zuonum=0;
	younum=0;
	for(i=1;i<=n;i++){
		a[i].biao=i;
		c=getchar();
		if(c=='1'){
			a[i].h=1;
		}
		else{
			a[i].h=0;
		}
		c=getchar();
		if(c=='1'){
			a[i].hh=1;
		}
		else{
			a[i].hh=0;
		}
		a[i].chang=read();
		if(a[i].h==1&&a[i].hh==0){
			zuonum++;
			zuo[zuonum]=i;
		}
		if(a[i].h==0&&a[i].hh==1){
			younum++;
			you[younum]=i;;
		}
	}
	sort(zuo+1,zuo+zuonum+1,cmp);
	sort(you+1,you+younum+1,cmp);
	m=0;
	s=0;
	mm=0;
	memset(hab,0,sizeof(hab));
	for(i=1;i<=n;i++){
		if(a[i].h==1&&a[i].hh==1){
			m++;
			mm++;
			s+=a[i].chang;
			hab[i]=1;
		}
	}
	for(i=1;i<=min(zuonum,younum);i++){
		m+=2;
		mm++;
		s+=a[zuo[i]].chang+a[you[i]].chang;
		hab[zuo[i]]=1;
		hab[you[i]]=1;
	}
	sort(a+1,a+n+1,cmp2);
	//cout<<m<<" "<<mm<<" "<<s<<endl;
	for(i=1;i<=n;i++){
		if((m+2)/2>mm){
			break;
		}
		if(hab[a[i].biao]==0){
			s+=a[i].chang;
			m++;
			if((m+2)/2>mm){
				break;
			}
		}
	}
	cout<<s<<endl;
	return 0;
}


