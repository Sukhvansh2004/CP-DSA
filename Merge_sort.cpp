#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int s,int mid,int n){
  int a[mid - s] {};
  int b[n - mid] {};
  for (int i = s; i < mid; i++) {
      a[i-s]=arr[i];
    }
  for(int i=mid;i<n;i++){
      b[i-mid]=arr[i];
  }
  int j1=0;
  int j2=0;
  for(int i=s;i<n;i++){
      if (j1 == mid - s) {
        arr[i] = b[j2++];
    } 
    else if (j2 == n - mid) {
        arr[i] = a[j1++];
    } 
    else if (a[j1] < b[j2]) {
        arr[i] = a[j1++];
    } 
    else {
        arr[i] = b[j2++];
    }
  }
}

vector<int> mergeSort(vector<int> &arr,int s=0,int n=-1)
{
  if (n == -1) {
    n = arr.size();
  }
  if (n - s > 1) {
    int mid = (s + n) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid, n);
    merge(arr, s, mid, n);
  }
    return arr;
}

