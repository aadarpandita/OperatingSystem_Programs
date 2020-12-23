#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cout<<"Enter Total Number of Process:";
    cin>>n;
 
    int bt[n],wt[n],tat[n],p[n],pr[n],i,j,total=0,pos,temp,avg_wt,avg_tat;

    cout<<endl<<"Enter Burst Time and Priority"<<endl;
    for(i=0;i<n;i++)
        cin>>bt[i]>>pr[i];           
 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;     
    total=0;
 
    cout<<endl<<"Burst Time\t     Waiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];    
        total+=tat[i];
        cout<<endl<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
 
    avg_tat=total/n;    
    cout<<endl<<endl<<"Average Waiting Time : "<<avg_wt;
    cout<<endl<<"Average Turnaround Time : "<<avg_tat<<endl<<endl;
 
    return 0;
}
