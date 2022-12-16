#include <iostream>
using namespace std;

class RAY
{
public:
int Value[100][3];
public:	
	void build()
	{
		Value[0][0]=1;
		Value[0][1]=0;
		Value[0][2]=0;

		for(int i=1;i<100;i++)
		{
			Value[i][0]=Value[i-1][1]+Value[i-1][2];
			Value[i][1]=Value[i-1][0]+Value[i-1][2];
			Value[i][2]=Value[i-1][0];
		}
	}
	void display_Value(int starter,int ender)
	{
		for(int i=starter;i<ender;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<"Value["<<i<<"]["<<j<<"]="<<this->Value[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	int a(int n)
	{
		return Value[n][0]+Value[n][1]+Value[n][2];
	}
};
int main()
{
	RAY *ray=new RAY();
	ray->build();
	ray->display_Value(0,10);
	int ans=ray->a(2);
	cout<<"a(2)="<<ans<<endl;
	return 0;
}
