#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[20],b[20],x[20],i,j,time,count=0,smallest,wt[10],tn[20],n,twt=0,ttn=0,end;
    cout<<"enter the number of process: ";
    cin>>n;
    cout<<"\nEnter the arival & burst time: "<<endl;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
        x[i]=b[i];
    }
    b[19]=9999;
    for(time=0;count!=n;time++){
        smallest=19;
        for(i=0;i<n;i++){
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0){
                smallest = i;
            }
        }
        b[smallest]--;
        if(b[smallest]==0){
            count++;
            end=time+1;
            wt[smallest]=end-a[smallest]-x[smallest];
            tn[smallest]=end-a[smallest];

        }
    }
    cout<<"\nprocess    "<<"arivaltime      "<<"bursttime    "<<"wait time   "<<"turn time"<<endl;
    for(i=0;i<n;i++){
        cout<<"p"<<i+1<<"\t\t"<<a[i]<<"\t\t"<<x[i]<<"\t\t"<<wt[i]<<"\t\t"<<tn[i]<<endl;
        twt=twt+wt[i];
        ttn=ttn+tn[i];
    }
    cout<<"avarage waitting time: "<<(float)twt/(float)n<<endl;
    cout<<"avarage turnaround time: "<<(float)ttn/(float)n<<endl;


    return 0;
}
