#include<bits/stdc++.h>
using namespace std;
const int a[32][21]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,

12,2 ,4 ,5 ,6 ,10,11,17,23,29,9 ,14,19,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
12,1 ,4 ,5 ,6 ,10,11,15,20,25,12,18,24,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,

12,4 ,8 ,9 ,10,14,15,21,27,31,5 ,6 ,7 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
16,3 ,8 ,9 ,10,14,15,19,16,22,28,5 ,6 ,7 ,1 ,2 ,11,0 ,0 ,0 ,0 ,
14,1 ,2 ,4 ,6 ,10,11,15,20,25,17,23,29,3 ,7 ,0 ,0 ,0 ,0 ,0 ,0 ,
16,1 ,2 ,4 ,5 ,10,11,3 ,7 ,16,21,26,12,18,24,13,17,0 ,0 ,0 ,0 ,
12,3 ,4 ,5 ,6 ,11,12,13,17,18,22,27,30,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,

12,3 ,4 ,9 ,10,14,15,11,12,13,20,26,30,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
14,3 ,4 ,8 ,10,14,15,1 ,19,21,27,31,11,12,13,0 ,0 ,0 ,0 ,0 ,0 ,
20,1 ,2 ,3 ,4 ,5 ,6 ,8 ,9 ,11,12,13,14,15,16,17,20,21,22,25,28,
20,1 ,2 ,4 ,5 ,6 ,7 ,8 ,9 ,10,12,13,15,16,17,18,21,22,23,26,29,
14,2 ,6 ,7 ,8 ,9 ,10,11,13,17,18,22,27,30,24,0 ,0 ,0 ,0 ,0 ,0 ,
12,6 ,7 ,8 ,9 ,10,11,12,17,18,23,28,31,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,

16,1 ,3 ,4 ,8 ,9 ,10,15,16,17,18,19,20,21,25,26,30,0 ,0 ,0 ,0 ,
20,2 ,3 ,4 ,5 ,8 ,9 ,10,11,14,16,17,18,19,20,21,22,25,26,27,31,
12,4 ,6 ,10,11,14,15,17,18,21,22,26,28,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
20,1 ,5 ,6 ,7 ,10,11,12,13,14,15,16,18,21,22,23,24,27,28,29,30,
16,2 ,6 ,7 ,11,12,13,14,15,16,17,22,23,24,28,29,31,0 ,0 ,0 ,0 ,

12,1 ,4 ,9 ,14,15,20,21,22,23,24,25,26,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
14,2 ,5 ,8 ,10,14,15,19,21,22,23,24,25,26,30,0 ,0 ,0 ,0 ,0 ,0 ,
20,3 ,6 ,9 ,10,11,14,15,16,17,19,20,22,23,24,25,26,27,28,30,31,
20,4 ,7 ,10,11,12,15,16,17,18,19,20,21,23,24,26,27,28,29,30,31,
14,1 ,5 ,11,13,17,18,19,20,21,22,24,28,29,31,0 ,0 ,0 ,0 ,0 ,0 ,
12,2 ,6 ,12,17,18,19,20,21,22,23,28,29,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,

12,2 ,5 ,10,14,15,19,20,21,26,27,28,29,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
16,6 ,8 ,11,14,15,16,19,20,21,22,25,27,28,29,30,31,0 ,0 ,0 ,0 ,
14,3 ,7 ,9 ,12,15,17,21,22,25,26,28,29,30,31,0 ,0 ,0 ,0 ,0 ,0 ,
16,4 ,10,13,16,17,18,21,22,23,24,25,26,27,29,30,31,0 ,0 ,0 ,0 ,
12,1 ,5 ,11,17,18,22,23,24,25,26,27,28,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,

12,7 ,8 ,12,14,17,20,21,22,26,27,28,31,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
12,3 ,9 ,13,15,18,21,22,23,26,27,28,30,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 

};
int k,t,sum,l;
int f[50],h[50];

void print(){
	for (int i=1;i<=31;i++){
	int p=0;
	for (int j=1;j<=a[i][0];j++)
	if (f[i]!=0 && f[a[i][j]]!=0 && a[i][j]!=0 && f[a[i][j]]==f[i]) {p=1;break;}
	if (p==1) return ;
	}
	sum++;
	if (sum==t) {
		cout<<"Found"<<endl;
		for (int i=1;i<=30;i++) cout<<f[i]<<' ';
		cout<<f[31]<<endl;
		l=1;
	}
	return ;
}
void work(int dep){
	if (dep>31) {print();return ;}
	if (h[dep]==1) {work(dep+1);return ;}
	if (l==1) return ;
	for (int i=1;i<=k;i++){
		if (l==1) return ;
		f[dep]=i;
		int p=0;
		for (int j=1;j<=a[dep][0];j++)
		if (a[dep][j]<dep && a[dep][j]!=0 && f[a[dep][j]]==f[dep]) {p=1;break;}
		if (p==0) work(dep+1);
	}
	return ;
}


int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	cin>>k>>t;l=0;
	if (k<=7) {cout<<"No way"<<endl;return 0;}
	for (int i=1;i<=31;i++){
		cin>>f[i];
		if (f[i]!=0) h[i]=1;
	}
	for (int i=1;i<=31;i++){
		int p=0;
		for (int j=1;j<=a[i][0];j++)
		if (f[i]!=0 && f[a[i][j]]!=0 && a[i][j]!=0 && f[a[i][j]]==f[i]) {p=1;break;}
		if (p==1) {cout<<"No way"<<endl;return 0;}
	}
	work(1);
	if (l==0) cout<<"No way"<<endl;
	return 0;
}

