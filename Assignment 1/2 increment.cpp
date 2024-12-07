#include <iostream>
using namespace std;

template <typename T>
void increment(T& first, const T second) {
    first = first + second;
}

int main() {
    int int1, int2;
    float float1, float2;
    double double1, double2;
    char char1, char2;

    cin>>int1>>int2;
    cin>>float1>>float2;
    cin>>double1>>double2;
    cin>>char1>>char2;

    increment(int1, int2);
    cout<<int1<<endl;
    increment(float1, float2);
    cout<<float1<<endl;
    increment(double1, double2);
    cout<<double1<<endl;
    increment(char1, char2);
    cout<<char1<<endl;
}