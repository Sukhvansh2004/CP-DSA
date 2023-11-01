#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
    int x, y;
};

int angle(Point p, Point q, Point r){
    int val = (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
    if (val == 0) return 0;
    return val>0 ? -1: 1;  
}

int compare(Point p, Point q, Point r){
    int a = angle(p, q, r);
    if(a==0){
        float dist1 = sqrt(pow((q.x - p.x), 2) + pow((q.y - p.y), 2));
        float dist2 = sqrt(pow((r.x - p.x), 2) + pow((r.y - p.y), 2));
        if(dist1<dist2){
            a = -1;
        }
        else if(dist1>dist2){
            a = 1;
        }
    }
    return a;
}

int partition(Point* &arr, int start, int end){
    Point p = arr[end];
    int j = start;
    for(int i=start;i<end;i++){
        if(compare(arr[0], arr[i], p)==-1){
            swap(arr[j++], arr[i]);
        }
    }
    swap(arr[j], arr[end]);
    return j;
}

void point_sort(Point* &arr,int start, int end){
    if(start<end){
        int index = partition(arr, start, end);
        point_sort(arr, start, index-1);
        point_sort(arr, index+1, end);
    }
}

Point nextToTop(stack<Point> arr){
    Point top = arr.top();
    arr.pop();
    Point ntop = arr.top();
    arr.push(top);
    return ntop;
}

stack<Point> convex_hull(Point* &arr, int n){
    Point start = arr[0];
    int index = 0;
    for(int i=0;i<n;i++){
        if(arr[i].y<start.y){
            start = arr[i];
            index = i;
        }
        else if(arr[i].y == start.y && arr[i].x < start.x){
            start = arr[i];
            index = i;
        }
    }
    swap(arr[0], arr[index]);
    point_sort(arr, 1, n-1);
    stack<Point> hull;
    hull.push(arr[0]);
    hull.push(arr[1]);
    hull.push(arr[2]);

    for(int i=3; i<n; i++){
        while(hull.size()>=2 && (compare(nextToTop(hull), hull.top(), arr[i])==1 || angle(nextToTop(hull), hull.top(), arr[i]) ==0)){
            hull.pop();
        }
        hull.push(arr[i]);
    }

    return hull;
}

int main(){
    int n;
    cin>>n;

    Point *points = new Point[n];
    for(int i=0;i<n;i++){
        Point p;
        cin>>p.x>>p.y;
        points[i] = p;
    }

    stack<Point> hull = convex_hull(points, n);
    cout<<"Convex Hull"<<endl;
    int num = hull.size();
    while(!hull.empty()){
        Point p = hull.top();
        cout<<"("<<p.x<<","<<p.y<<")"<<endl;
        hull.pop();
    }
    cout<<"Total Points on Convex Hull: "<<num<<endl;
	return 0;
}