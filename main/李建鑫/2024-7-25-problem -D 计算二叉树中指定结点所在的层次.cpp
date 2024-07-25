#include<iostream>
using namespace std;
int a[25],c[25],m,b[25][2];
char M;
int main()
{
	string A;
	cin>>A>>M;
	a[0]=A[0]-'A'+1;
	m=M-'A'+1;
	c[0]=1;
	for(int i=1;i<A.length();i++)
	{
		if(A[i]!='^') a[i]=A[i]-'A'+1;
		else 
		{
			a[i]=0;
			b[i][0]=-1;
			b[i][1]=-1;
		}
		
		if(a[i]!=0)
		{
			if(b[i-1][0]==0)
			{
				b[i-1][0]=a[i];
				c[i]=c[i-1]+1;
			}
			else if(b[i-1][1]==0)
			{
				b[i-1][1]=a[i];
				c[i]=c[i-1]+1;
			}
			else
			for(int j=i-1;j>0;j--)
			{
				if(b[j-1][0]==0)
				{
					b[j-1][0]=a[i];
					c[i]=c[j-1]+1;
					break;
				}
				else if(b[j-1][1]==0)
				{
					b[j-1][1]=a[i];
					c[i]=c[j-1]+1;
					break;
				}
			}
		}
		if(a[i]==0)//空结点没有孩子
		{
			if(b[i-1][0]==0)
			{
				b[i-1][0]=-1;
				c[i]=c[i-1]+1;
			}
			else if(b[i-1][1]==0)
			{
				b[i-1][1]=-1;
				c[i]=c[i-1]+1;
			}
			else for(int j=i-1;j>0;j--)
			{
				if(b[j-1][0]==0)
				{
					b[j-1][0]=-1;
					c[i]=c[j-1]+1;
					break;
				}
				else if(b[j-1][1]==0)
				{
					
					c[i]=c[j-1]+1;
					b[j-1][1]=-1;
					break;
				}
			}
			
		}
	}
	for(int i=0;i<A.length();i++)
		if(m==a[i])
		{
			cout<<c[i];
			return 0;
		}
	return 0;
}//ABD^^^CE^^F^^ C