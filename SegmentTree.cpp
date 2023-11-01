#include <iostream>
#include <vector>
using namespace std;

class SegmentTree{
public:
    vector<int> st;
    vector<int> arr;
    SegmentTree(vector<int> &arr){
        st.resize(2*arr.size()-1);
        this->arr = arr;
    }

    int get(int si, int sl, int sr, int i){
      if(sl==sr){
        return (st[si] + arr[i]);
      }
      else{
        int mid = (sl+sr)/2;
        if(i<=mid){
            return st[si] + get(2*si+1, sl, mid, i);
        }
        else{
            return st[si] + get(2*si+2, mid+1, sr, i);
        }
      }  
    }

    void update(int si, int sl, int sr, int i, int val, int sum){
        if(sl==sr){
            arr[i] = val - st[si] - sum;
        }
        else{
            int mid = (sl+sr)/2;
            if(mid>=i){
                update(2*si+1, sl, mid, i, val, sum + st[si]);
            }
            else{
                update(2*si+2, mid+1, sr, i, val, sum + st[si]);
            }
        }
    }

    void increment(int si, int sl, int sr, int l, int r, int inc){
        if(l<=sl && r>=sr){
            st[si] += inc;
        }
        else if(l>sr || r<sl){
            return;
        }
        else{
            int mid = (sl + sr)/2;
            increment(2*si+1, sl, mid, l, r, inc);
            increment(2*si+2, mid+1, sr, l, r, inc);
        }
    }
};

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    SegmentTree st(arr);
    for(int i=0;i<k;i++){
        char command;
        cin>>command;
        if(command == 'G'){
            int index;
            cin>>index;
            cout<<st.get(0, 0, n-1, index-1);
        }
        else if(command == 'I'){
            int left, right, inc;
            cin>>left>>right>>inc;
            st.increment(0, 0, n-1, left-1, right-1, inc);
        }
        else if(command == 'U'){
            int pos, val;
            cin>>pos>>val;
            st.update(0, 0, n-1, pos-1, val, 0);
        }
    }
}