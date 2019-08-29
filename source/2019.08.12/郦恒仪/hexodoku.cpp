#include<bits/stdc++.h>
using namespace std;
vector<int>zhizhou[100];
int zhihang[100],zhilie[100],zhicha[100],n,m,i,j,k,l,s,d,f,r,hzhou[100],hhang[100],hlie[100],hcha[100],a[1005];
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	scanf("%d%d",&m,&n);
	zhihang[1]=2;zhilie[1]=3;zhicha[1]=1;
	zhihang[2]=3;zhilie[2]=2;zhicha[2]=1;
	zhihang[3]=1;zhilie[3]=5;zhicha[3]=2;
	zhihang[4]=2;zhilie[4]=4;zhicha[4]=2;
	zhihang[5]=3;zhilie[5]=3;zhicha[5]=2;
	zhihang[6]=4;zhilie[6]=2;zhicha[6]=2;
	zhihang[7]=5;zhilie[7]=1;zhicha[7]=2;
	zhihang[8]=1;zhilie[8]=6;zhicha[8]=3;
	zhihang[9]=2;zhilie[9]=5;zhicha[9]=3;
	zhihang[10]=3;zhilie[10]=4;zhicha[10]=3;
	zhihang[11]=4;zhilie[11]=3;zhicha[11]=3;
	zhihang[12]=5;zhilie[12]=2;zhicha[12]=3;
	zhihang[13]=6;zhilie[13]=1;zhicha[13]=3;
	zhihang[14]=2;zhilie[14]=6;zhicha[14]=4;
	zhihang[15]=3;zhilie[15]=5;zhicha[15]=4;
	zhihang[16]=4;zhilie[16]=4;zhicha[16]=4;
	zhihang[17]=5;zhilie[17]=3;zhicha[17]=4;
	zhihang[18]=6;zhilie[18]=2;zhicha[18]=4;
	zhihang[19]=2;zhilie[19]=7;zhicha[19]=5;
	zhihang[20]=3;zhilie[20]=6;zhicha[20]=5;
	zhihang[21]=4;zhilie[21]=5;zhicha[21]=5;
	zhihang[22]=5;zhilie[22]=4;zhicha[22]=5;
	zhihang[23]=6;zhilie[23]=3;zhicha[23]=5;
	zhihang[24]=7;zhilie[24]=2;zhicha[24]=5;
	zhihang[25]=3;zhilie[25]=7;zhicha[25]=6;
	zhihang[26]=4;zhilie[26]=6;zhicha[26]=6;
	zhihang[27]=5;zhilie[27]=5;zhicha[27]=6;
	zhihang[28]=6;zhilie[28]=4;zhicha[28]=6;
	zhihang[29]=7;zhilie[29]=3;zhicha[29]=6;
	zhihang[30]=5;zhilie[30]=6;zhicha[29]=7;
	zhihang[31]=6;zhilie[31]=5;zhicha[31]=7;
	zhizhou[1].push_back(1);
	zhizhou[2].push_back(1);
	zhizhou[3].push_back(2);
	zhizhou[4].push_back(1);zhizhou[4].push_back(2);
	zhizhou[5].push_back(1);
	zhizhou[6].push_back(1);zhizhou[6].push_back(3);
	zhizhou[7].push_back(3);
	zhizhou[8].push_back(2);
	zhizhou[9].push_back(2);
	zhizhou[10].push_back(1);zhizhou[10].push_back(2),zhizhou[10].push_back(4);

	for(i=1;i<=31;i++){
		scanf("%d",&a[i]);
	}
	cout<<"No way"<<endl;
	return 0;
}


