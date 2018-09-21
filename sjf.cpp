#include<iostream>
using namespace std;
#define swap(x,y) int t;t=x;x=y;y=t;
int main()
{
	int n;
	cout<<"Enter number of processes:";
	cin>>n;
	int watime[n],comtime[n],brutime[n],m=0,l=0,sl;
	double avgtutime=0,avgwatime=0;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Brust time of process no. "<<i+1<<":";
		cin>>brutime[i];
	}		
    for(m=0;m<n-1;m++)
	{
		sl=m;
		for(l=m;l<n;l++)
		{
			if(brutime[l]<brutime[sl])
			{
				sl=l;
			}
		}
		if(sl!=m)
		{
			swap(brutime[sl],brutime[m])
		}
	}
	watime[0]=0;
    comtime[0]=brutime[0];
    avgtutime=comtime[0];
    avgwatime=0;
    cout<<"Process 1:"<<endl;
    cout<<"Waiting time="<<watime[0]<<endl;
	cout<<"Completion time="<<comtime[0]<<endl;
	for(int i=1;i<n;i++)
	{
		watime[i]=comtime[i-1];
		comtime[i]=comtime[i-1]+brutime[i];
		avgtutime=avgtutime+comtime[i];
		avgwatime=avgwatime+watime[i];
		cout<<"Process "<<i+1<<":"<<endl;
		cout<<"Waiting time="<<watime[i]<<endl;
		cout<<"Completion time="<<comtime[i]<<endl;
	}
	avgtutime=avgtutime/n;
	avgwatime=avgwatime/n;
	cout<<endl;
	cout<<"Average Waiting time "<<avgwatime<<endl;
	cout<<"Average TurnAround time "<<avgtutime<<endl;
	}
