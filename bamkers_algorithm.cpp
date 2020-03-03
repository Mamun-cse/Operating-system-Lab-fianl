#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, k;
    n = 5;
    m = 3;
    int alloc[5][3],max[5][3],avail[3],temp[3]={0},instance[3]={0};
    cout<<"Enter instance\n";
    for(i=0;i<m;i++){
        cin>>instance[i];
    }

    cout<<"Enter allocation\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"Enter maximum\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>max[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(j=0;j<n;j++){
            temp[i]=temp[i]+alloc[j][i];
        }
        avail[i]=instance[i]-temp[i];
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;

                    }
                }
                if (flag == 0) {

                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                        f[i] = 1;
                }
            }
        }
    }
    printf("Following is the SAFE Sequence\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
    return (0);

}
/*
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/




