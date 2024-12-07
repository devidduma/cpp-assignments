#include <iostream>
using namespace std;
void music(int n) 
{ 
    if(n > 0) 
    { 
        music(n - 1); 
        cout << n <<" "; 
        music(n - 1); 
    } 
} 
  
int main() 
{ 
    music(8); 
    return 0; 
}
