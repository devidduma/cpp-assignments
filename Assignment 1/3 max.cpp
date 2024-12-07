#include <iostream>
using namespace std;

int max(int x1, int x2 = INT32_MIN, int x3 = INT32_MIN, int x4 = INTMAX_MIN) {
    int max = INT32_MIN;
    if(x1 > max) max = x1;
    if(x2 > max) max = x2;
    if(x3 > max) max = x3;
    if(x4 > max) max = x4;
    return max;
}

int main() {
    cout<<max(2,3)<<endl;
    cout<<max(2,3,4)<<endl;
    cout<<max(2,3,4,5)<<endl;
}