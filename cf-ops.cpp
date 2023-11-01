#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      int x;
      cin>>x;
      char s[x]{};
      cin>>s;
      int operations=0;
      int r=0;
      int l=x-1;
      while(true){
         if(s[r]!=s[l]){
            operations++;
            r++;
            l--;
         }
         else{
            break;
         }
      }
      cout<<x-operations*2<<endl;
   }
}