#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Boxer{
    public:
        string name;
        int strength;
};
struct Comp{
    bool operator()(const Boxer& a, const Boxer& b){
        return a.strength<b.strength;
    }
};

bool operator<(const Boxer& a, const Boxer& b){
        return a.strength>b.strength;
}

int main(){
    Boxer boxer[3];
    boxer[0].name="uday", boxer[0].strength=23;
    boxer[1].name="manoj", boxer[1].strength=33;
    boxer[2].name="rajiv", boxer[2].strength=53;

    priority_queue< Boxer, vector<Boxer>, Comp> pq;
    pq.push(boxer[0]);
    pq.push(boxer[1]);
    pq.push(boxer[2]);
    Boxer b = pq.top();
    cout<<b.name;
    //result is Rajiv

 //   cout<<operator<(boxer[0], boxer[1]);
    return 0;
    
}