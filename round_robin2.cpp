#include<bits\stdc++.h>
using namespace std;
void waiting(int n,int q,int p[],int b[],int wt[]){
    int rem_bt[n],i,t;
    for(i=0;i<n;i++){
        rem_bt[i]=b[i];
    }
    t=0;
    while(1){
        bool done=true;
        for(i=0;i<n;i++){
            if(rem_bt[i]>0){
                done=false;
                if(rem_bt[i]>q){
                    t=t+q;
                    rem_bt[i]=rem_bt[i]-q;
                }
                else{
                    t=t+rem_bt[i];
                    wt[i]=t-b[i];
                    rem_bt[i]=0;
                }
            }
        }
        if(done==true){
            break;
        }
    }

}

void turnaround(int n,int p[],int b[],int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=b[i]+wt[i];
    }
}

void avgtime(int n,int q,int p[],int b[]){
    int i,wt[n],tat[n],t_wt=0,t_tat=0;
    waiting(n,q,p,b,wt);
    turnaround(n,p,b,wt,tat);

    cout<<"process   "<<"burst time  "<<"waiting time  "<<"turnaround time "<<endl;
    for(i=0;i<n;i++){
        t_wt=t_wt+wt[i];
        t_tat=t_tat+tat[i];
        cout<<"p"<<p[i]<<"\t\t"<<b[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    cout<<"avarage waitting time: "<<(float)t_wt/(float)n<<endl;
    cout<<"avarage turnaround time: "<<(float)t_tat/(float)n<<endl;
}

int main()
{
    int i,n,p[20],b[20],q;

    cout<<"Enter the Quantum Number: ";
    cin>>q;
    cout<<endl;

    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<endl;

    cout<<"Enter the process & burst time: ";
    cout<<endl;

    for(i=0;i<n;i++){
        cout<<"p";
        cin>>p[i];
        cin>>b[i];
    }
    avgtime(n,q,p,b);
    return 0;
}
