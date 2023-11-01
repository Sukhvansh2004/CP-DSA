#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> insertion(vector<int> arr){
    for(int i=1;i<arr.size();i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    return arr; sss
}

int median_of_median(vector<int> &arr, int r){
    int n = arr.size();
    if(n>=5){
        int k = ceil(float(n)/5.0);
        vector<vector<int>> matrix(k);
        int j=0;
        for(int i=0;i<n;i=i+5){
            for(int l=i;l<i+5 && l<n;l++){
                matrix[j].push_back(arr[l]);
            }
            j++;
        }
        vector<int> medians;
        for(int i=0;i<matrix.size();i++){
            medians.push_back(insertion(matrix[i])[matrix[i].size()/2]);
        }
        int median_of_medians = median_of_median(medians, medians.size()/2);
        
        vector<int> left, mid, right;
        for(int i=0;i<arr.size();i++){
            if(median_of_medians>arr[i]){
                left.push_back(arr[i]);
            }
            else if(median_of_medians == arr[i]){
                mid.push_back(arr[i]);
            }
            else{
                right.push_back(arr[i]);
            }
        }
        if(left.size()>(r)){
            return median_of_median(left, r);
        }
        else if(left.size()<=(r) && (r)<(mid.size()+left.size())){
            return median_of_medians;
        }
        else{
            return median_of_median(right, r - left.size() - mid.size());
        }
    }
    else{
        return insertion(arr)[r];
    }
}

int rank_of_n(vector<int> arr, int k){
    int right(0), left(0);
    for(int i=0;i<arr.size();i++){
        if(arr[i]<k){
            left++;
        }
        else{
            right++;
        }
    }
    return left+1;
}

int main() {
    int n, k, m;
    cin>>n>>k>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout <<median_of_median(arr, k)<<endl;
    cout<<rank_of_n(arr, m)<<endl;

    return 0;
}