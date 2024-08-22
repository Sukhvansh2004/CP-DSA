#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        unordered_map<long, bool> visited;
        for(int i=1; i<n; i++){
            long a = pq.top();
            pq.pop();
            for(auto prime: primes){
                if(!visited[a*prime]){
                    pq.push(a*prime);
                    visited[a*prime] = true;
                }
            }
        }
        return pq.top();
    }
};

int main(){
    int n = 10000;
    vector<int> primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};
    Solution sol;
    int ans = sol.nthSuperUglyNumber(n, primes);
    cout<<endl<<ans<<endl;
}