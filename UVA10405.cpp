#include<iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ROW 1000
#define COL 1000
int c[ROW][COL]={0};
int b[ROW][COL]={0};
int LCS(string s1,string s2)
{
	int n=s1.length();
	int m=s2.length();
	for(int i=0;i<=n;i++)
	{
		c[i][0]=0;
	}
	for(int j=0;j<=m;j++)
	{
		c[0][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i]==s2[j])
			{
				c[i][j]=c[i-1][j]+1;	
				b[i][j]=3;
			}
			else 
			{
				if(c[i][j-1]>c[i-1][j])
				{
					c[i][j]=c[i][j-1];
					b[i][j]=2;
				}else
				{
					c[i][j]=c[i-1][j];
					b[i][j]=1;
				}
			}
		}
	}
	return c[n][m];
}
int main()
{
	string s1="bacad",s2="accbadcb";
	cout<<"LCS("<<s1<<","<<s2<<")="<<LCS(s1,s2)<<endl;
	return 0;
}
