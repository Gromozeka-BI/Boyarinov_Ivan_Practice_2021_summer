#include <iostream>

using namespace std;

int funct(int number, int variants){
    return number % variants + 1;
}

int main(){
    
    int number, variants;
    cin >> number;
    cin >> variants;
    
    cout << funct(number, variants);
    return 0;
}
