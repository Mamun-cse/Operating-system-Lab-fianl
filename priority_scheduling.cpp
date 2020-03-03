#include<bits\stdc++.h>
using namespace std;

void sortting(int n,int p[],int b[],int pr[]){
    int i,j,pos,temp=0;
    for(i=1;i<=n;i++){
        pos = i;
        for(j=i+1;j<=n;j++){
            if(pr[j]<pr[pos])
                pos=j;

        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=b[i];
        b[i]=b[pos];
        b[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

    }
}

void fcfs(int n,int pr[],int br[]){
    int wt[20]={0},tn[20]={0},twt=0,ttn=0,i;

    for(i=1;i<=n;i++){
        tn[i]=tn[i-1]+br[i];
        ttn=ttn+tn[i];
    }
    for(i=1;i<=n;i++){
        wt[i]=tn[i]-br[i];
        twt=twt+wt[i];
    }

    cout<<"process     "<<"brust time     "<<"waiting time     "<<"turnaround"<<endl;
    for(i=1;i<=n;i++){
        cout<<"p"<<pr[i]<<"\t\t"<<br[i]<<"\t\t"<<wt[i]<<"\t\t"<<tn[i]<<endl;
    }

    cout<<"total waitting time : "<<(float)twt/(float)n<<endl;
    cout<<"total turn around time : "<<(float)ttn/(float)n<<endl;
}


int main(){
    int i,b[20],p[20],pr[20],n;

    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the process & brust time & priority: "<<endl;

    for(i=1;i<=n;i++){
        cin>>p[i];
        cin>>b[i];
        cin>>pr[i];


    }
    sortting(n,p,b,pr);
    fcfs(n,p,b);
    return 0;
}

