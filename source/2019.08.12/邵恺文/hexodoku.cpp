#include<bits/stdc++.h>
#define enter '\n'
using namespace std;
template <class _T> inline _T read(_T &x){
	char ch=getchar(),minus=0;
	x=0;
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')ch=getchar(),minus=1;
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	if(minus)x=-x;
	return x;
}

int r[32]={0,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7};
int c[32]={0,2,3,1,2,3,4,5,1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,7,3,4,5,6,7,5,6};
int a[8][8];
int c1[8]={1,2,4,5,6,10,11};
int c2[8]={3,4,8,9,10,14,15};
int c3[8]={6,7,11,12,13,17,18};
int c4[8]={10,11,15,16,17,21,22};
int c5[8]={14,15,19,20,21,25,26};
int c6[8]={17,18,22,23,24,28,29};
int c7[8]={21,22,26,27,28,30,31};
int num[32];
void print(){
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++)cout<<a[i][j]<<' ';
	cout<<endl; 
	} 
}
bool same(int a,int b,int c,int d,int e,int f,int g){
	int t=INT_MAX,tt[8];
	if(a==0)tt[1]=t,t--;
	else tt[1]=a;
	if(b==0)tt[2]=t,t--;
	else tt[1]=b;
	if(c==0)tt[3]=t,t--;
	else tt[1]=c;
	if(d==0)tt[4]=t,t--;
	else tt[1]=d;
	if(e==0)tt[5]=t,t--;
	else tt[1]=e;
	if(f==0)tt[6]=t,t--;
	else tt[1]=f;
	if(g==0)tt[7]=t,t--;
	else tt[1]=g;
	for(int i=1;i<=7;i++)
	  for(int j=1;j<=7;j++)
	    if(i!=j&&tt[i]==tt[j])return true;
	return false;
}
bool checkall(){   
    //print();
	int t1=0,t2=0;
	for(int i=1;i<=7;i++){
		t1=t2=0;
		for(int j=1;j<=7;j++){
			if(a[i][j]>0&&t1==0)t1=a[i][j];
			else if(t1>0&&a[i][j]>0&&a[i][j]==t1)return false; 
			if(a[j][i]>0&&t2==0)t2=a[j][i];
			else if(t2>0&&a[j][i]>0&&a[j][i]==t2)return false;
		}
	}
	for(int j=-3;j<=3;j++){
		t1=0;
		for(int i=1;i<=7;i++){
			if(i>=1&&i+j>=1&&i<=7&&i+j<=7&&a[i][i+j]>0){
				if(t1==0){
					t1=a[i][i+j];continue;
				}
			    if(a[i][i+j]==t1)return false; 
			}
		}
	}
/*	int b[8];
	for(int i=1;i<=7;i++)
		b[i]=a[r[c1[i]]][c[c1[i]]];
	if(same(b[1],b[2],b[3],b[4],b[5],b[6],b[7])==true)return false;
	for(int i=1;i<=7;i++)
		b[i]=a[r[c2[i]]][c[c2[i]]];
	if(same(b[1],b[2],b[3],b[4],b[5],b[6],b[7])==true)return false;
	for(int i=1;i<=7;i++)
		b[i]=a[r[c3[i]]][c[c3[i]]];
	if(same(b[1],b[2],b[3],b[4],b[5],b[6],b[7])==true)return false;
	for(int i=1;i<=7;i++)
		b[i]=a[r[c4[i]]][c[c4[i]]];
	if(same(b[1],b[2],b[3],b[4],b[5],b[6],b[7])==true)return false;
	for(int i=1;i<=7;i++)
		b[i]=a[r[c5[i]]][c[c5[i]]];
	if(same(b[1],b[2],b[3],b[4],b[5],b[6],b[7])==true)return false;
	for(int i=1;i<=7;i++)
		b[i]=a[r[c6[i]]][c[c6[i]]];
	if(same(b[1],b[2],b[3],b[4],b[5],b[6],b[7])==true)return false;
	for(int i=1;i<=7;i++)
		b[i]=a[r[c7[i]]][c[c7[i]]];
	if(same(b[1],b[2],b[3],b[4],b[5],b[6],b[7])==true)return false;*/
	return true;
}
void dfs(int pos){
	putchar('\n');
}
int h[32],ha[32];
int main(){
    freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	int K,N;
	read(K);
	read(N);
	memset(a,0,sizeof(a));
	for(int i=1;i<=31;i++){
		read(num[i]);
		a[r[i]][c[i]]=num[i];
	}
	if(K<=5){
		cout<<"No way"<<endl; 
		return 0;
	}
	if(!checkall()){
	    cout<<"No way"<<endl;
		return 0;
	}
	if(K==31){
		bool fl=false;
	  	for(int i=1;i<=31;i++)
	  	    if(num[i]!=0)h[num[i]]=1;
	  	    else fl=true;
	  	if(fl==false){
	  		cout<<"No way"<<endl;
	  		return 0;
		}	
	  int tot=0;
	  	for(int i=1;i<=31;i++){
		  if(num[i]!=0){
		  	ha[i]=1;
		  } 
	    }
	    for(int i=1;i<=31;i++)
	    if(ha[i]==0)h[++tot]=i;
	    sort(h+1,h+tot+1);
	    bool f=true;
	    for(int i=1;i<N;i++)
	      if(!next_permutation(h+1,h+tot+1)){
	      	f=false;break;
		  }
         if(f){
         	int tot=0;
         	for(int i=1;i<=31;i++){
         		if(num[i]==0)cout<<h[++tot]<<' ';
         		else cout<<num[i]<<' ';
			 }
			 cout<<endl;
		 }
		 else cout<<"No way"<<endl;
		 return 0;
    }
    cout<<"No way"<<endl;
	return 0;
}


