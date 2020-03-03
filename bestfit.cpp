#include <bits/stdc++.h>
using namespace std;
void bestfit(int bsize[], int m, int psize[], int n) {
   int alloc[n];
    memset(alloc, -1, sizeof(alloc));
   for (int i=0; i<n; i++) {
      int bestIdx = -1;
      for (int j=0; j<m; j++) {
         if (bsize[j] >= psize[i]) {
            if (bestIdx == -1)
               bestIdx = j;
            else if (bsize[bestIdx] > bsize[j])
               bestIdx = j;
         }
      }
      if (bestIdx != -1) {
         alloc[i] = bestIdx;
         bsize[bestIdx] -= psize[i];
      }
   }
   cout << "\nProcess No.\tProcess Size\tBlock no.\n";
   for (int i = 0; i < n; i++) {
      cout << " " << i+1 << "\t\t" << psize[i] << "\t\t";
      if (alloc[i] != -1)
         cout << alloc[i] + 1;
      else
         cout << "Not Allocated";
         cout << endl;
   }
}
int main() {
   int bsize[] = {300,50,200,350,70};
   int psize[] = {200,47,212,423,10};
   int m = sizeof(bsize)/sizeof(bsize[0]);
   int n = sizeof(psize)/sizeof(psize[0]);
   bestfit(bsize, m, psize, n);
   return 0 ;
}
