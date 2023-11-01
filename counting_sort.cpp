#include <iostream>
#include <vector>
using namespace std;

vector<int> counting_sort(vector<int> arr){
    if(arr.size() > 0){
        int max = arr[0];
        for(int i : arr){
            if(i > max){
                max = i;
            }
        }
        vector<int> index(max + 1, 0); // Initialize index vector with zeros
        for(int i : arr){
            index[i]++;
        }
        for(int i = 1; i < index.size(); i++){
            index[i] += index[i-1];
        }
        vector<int> r(arr.size());
        for(int i = arr.size() - 1; i >= 0; i--){
            r[index[arr[i]]-- - 1] = arr[i];
        }
        return r;
    }
    return arr;
}

int main(){
    vector<int> arr{2, 9, 3, 5, 1, 8, 6, 7};
    arr = counting_sort(arr);
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
