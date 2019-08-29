#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int al[500005],bl[500005],ar[500005],br[500005],ao[500005],bo[500005];
int read() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int N=read(),M=read();
	for  (int i=1;i<=N;i++)
		a[i]=read();
	for  (int i=1;i<=N;i++)
		b[i]=read();

	int aa=1,bb=1;int NN=2*N; char c='c';
	for  (int i=1;i<=NN;i++)
		if  ((a[aa]<=b[bb]&&aa<=N)||bb>N)
			{
				if  (c=='b')  {al[aa]=bb-1;br[bb-1]=aa;}
				ao[aa]=i;aa++;c='a';
			}
		else
			{
				if  (c=='a'){bl[bb]=aa-1;ar[aa-1]=bb;}
				bo[bb]=i;bb++;c='b';
			}
			
	for  (int i=1;i<=M;i++)
		{
			int ob=read();
			if  (ob==1)
				{
					bool f;
					int x=read(),y=read(),z=read();
				//	cout<<ob<<' '<<x<<' '<<y<<' '<<z<<endl;
					if  (x==0)
						{
							a[y]=z;
							if  (a[y]==z)	continue;
							if  (a[y]<z)	f=true;
									else	f=false;
							if  (f)
								{
									if  (ar[y]==0)	continue;
									if  (al[y]!=0)
										br[al[y]]=0;
									int yy=ar[y];
									for  (;b[yy]<=z;yy++)
										{
											bo[yy]--;
											ao[y]++;
											if  (br[yy]!=0)	break;
										}
									if  (br[yy-1]==0&&b[yy]>z&&b[yy-1]<=z)//bab
										{
											br[yy-1]=y;bl[yy]=y;
											al[y]=yy-1;ar[y]=yy;
											continue;
										}
									if  (br[yy]==y+1&&b[yy]<=z)//baa
										{
											br[yy]=y; al[y]=yy;
											al[y+1]=0;
											continue;
										}
								}
							else
								{
									if  (al[y]==0)	continue;
									if  (ar[y]!=0)
										bl[ar[y]]=0;
									int yy=ar[y];
									for  (;b[yy]>=z;yy--)
										{
											bo[yy]++;
											ao[y]--;
											if  (br[yy]!=0)	break;
										}
									if  (br[yy+1]==0&&b[yy]<z&&b[yy+1]>=z)//bab
										{
											br[yy]=y;bl[yy+1]=y;
											al[y]=yy;ar[y]=yy+1;
											continue;
										}
									if  (br[yy]==y-1&&b[yy]>=z)//aab
										{
											bl[yy]=y; ar[y]=yy;
											ar[y-1]=0;
											continue;
										}
								}
						}
					else
						{
							if  (b[y]==z)	continue;
							if  (b[y]<z)	f=true;
									else	f=false;
							b[y]=z;
							if  (f)
								{
									if  (br[y]==0)	continue;
									if  (bl[y]!=0)
										ar[bl[y]]=0;
									int yy=br[y];
									for  (;a[yy]<=z;yy++)
										{
											ao[yy]--;
											bo[y]++;
											if  (ar[yy]!=0)	break;
										}
									if  (ar[yy-1]==0&&a[yy]>z&&a[yy-1]<=z)//aba
										{
											ar[yy-1]=y;al[yy]=y;
											bl[y]=yy-1;br[y]=yy;
											continue;
										}
									if  (ar[yy]==y+1&&a[yy]<=z)//abb
										{
											ar[yy]=y; bl[y]=yy;
											bl[y+1]=0;
											continue;
										}
								}
							else
								{
									if  (bl[y]==0)	continue;
									if  (br[y]!=0)
										al[br[y]]=0;
									int yy=br[y];
									for  (;a[yy]>=z;yy--)
										{
											ao[yy]++;
											bo[y]--;
											if  (ar[yy]!=0)	break;
										}
									if  (ar[yy+1]==0&&a[yy]<z&&a[yy+1]>=z)//aba
										{
											ar[yy]=y;al[yy+1]=y;
											bl[y]=yy;br[y]=yy+1;
											continue;
										}
									if  (ar[yy]==y-1&&a[yy]>=z)//aab
										{
											al[yy]=y; br[y]=yy;
											br[y-1]=0;
											continue;
										}
								}
						}
					continue;
				}
			else
				{
					int l1=read(),r1=read(),l2=read(),r2=read();
					int Mid=(r1-l1+r2-l2+2)/2;
					int L=l1,R=r1;
					bool f=true;
					//cout<<Mid<<':';
					while  (L<R)
						{
							int Mid_=(L+R+1)/2;
							int Num=Mid_-l1+max(0,ao[Mid_]-Mid_-l2+1);
							if  (Num==Mid)
								{
									printf("%d\n",a[Mid_]);
									f=false;
									break;
								}
							if  (Num<Mid)
								L=Mid_;
							else
								R=Mid_-1;
						}
					if  (!f)	continue;
					int Num=L-l1+max(0,ao[L]-L-l2+1);
					if  (Num==Mid)
						{
							printf("%d\n",a[L]);
							continue;
						}
					if  (L+1<=r1) L++;
					Num=L-l1+max(0,ao[L]-L-l2+1);
					if  (Num==Mid)
						{
							printf("%d\n",a[L]);
							continue;
						}
					if  (L-1>=l1) L--;
					Num=L-l1+max(0,ao[L]-L-l2+1);
					if  (Num==Mid)
						{
							printf("%d\n",a[L]);
							continue;
						}
					if  (L-1>=l1) L--;
					Num=L-l1+max(0,ao[L]-L-l2+1);
					if  (Num==Mid)
						{
							printf("%d\n",a[L]);
							continue;
						}
					L=l2,R=r2;
					f=true;
					while  (L<R)
						{
							int Mid_=(L+R+1)/2;
							int Num=Mid_-l2+max(0,bo[Mid_]-Mid_-l1+1);
							if  (Num==Mid)
								{
									printf("%d\n",b[Mid_]);
									f=false;
									break;
								}
							if  (Num<Mid)
								L=Mid_;
							else
								R=Mid_-1; 
						}
					if  (!f)	continue;
					Num=L-l2+max(0,bo[L]-L-l1+1);
					if  (Num==Mid)
						{
							printf("%d\n",b[L]);
							continue;
						}
					if  (L+1<=r2)	L++;
					Num=L-l2+max(0,bo[L]-L-l1+1);
					if  (Num==Mid)
						{
							printf("%d\n",b[L]);
							continue;
						}
					if  (L-1>=l2)	L--;
					Num=L-l2+max(0,bo[L]-L-l1+1);
					if  (Num==Mid)
						{
							printf("%d\n",b[L]);
							continue;
						}
					if  (L-1>=l2)	L--;
					Num=L-l2+max(0,bo[L]-L-l1+1);
					if  (Num==Mid)
						{
							printf("%d\n",b[L]);
							continue;
						}
					cout<<"Fuck!"<<endl;
					
				}
		}
	return 0;
}

