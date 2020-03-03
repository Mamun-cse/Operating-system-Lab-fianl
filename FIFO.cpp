#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, j, m, n, fault=0, last=0;
    bool flag =false;
    cout<<"Total Number of Reference Pages: ";
    cin>>n;
    cout<<"Enter Frame Size: ";
    cin>>m;
    int refstr[n], frame[m];
    cout<<"Enter Reference String: ";
    for(i=0;i<n;i++){
        cin>>refstr[i];
    }
    for(i=0;i<m;i++){
        frame[i]=-1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(frame[j]==refstr[i])
                flag=true;
        }
        if(flag==false){
            fault++;
            frame[last]=refstr[i];
            last++;
            if(last>=m)last=0;
        }
        else flag=false;
        cout<<frame[0]<<" "<<frame[1]<<" "<<frame[2]<<endl;
    }
    cout<<"Number of Page Faults: "<<fault<<endl;
    return 0;
}
