#include <iostream>

using namespace std;

int mas[1000];

void input(int* source, int size){
    for(int i = 0; i < size; i++){
        cin >> source[i];
    }
}

void output(int* source, int size){
    for(int i = 0; i < size; i++){
        cout << source[i];
    }
}

void rShiftMas(int* source,int n, int size){
    for (int i = size - (n + 1); i != -1; i--)
        source[i+n] = source[i]; 
        
    for (int i = 0; i < n; i++)
        source[i] = 0;
}

bool comprasion(int* a, int* b, int size){
	for (int i = 0; i < size; i++){
		if (a[i] != b[i]){
		   return false; 
		}else{
		   return true; 
		}
	}
}
    
bool test(int* a, int* b, int n, int size)
{
	rShiftMas(a, n, size);
	return comprasion(a, b, size);
}

int main(){
    
    int n, size;
    
    n = 3;
    size = 8;
    
    int test_1_input[size] = {1, 2, 3, 4, 5, 6, 7, 8};
	int test_1_output[size] = {0, 0, 0, 1, 2, 3, 4, 5};
	int test_2_input[size] = {5, -4, 3, -2, 1, 0, 0, 0};
	int test_2_output[size] = {0, 0, 0, 5, -4, 3, -2, 1};
	
	if (test(test_1_input, test_1_output, n, size)){
	    cout << "True" << endl;  
	}else{
	    cout << "False" << endl;
	} 
	if (test(test_2_input, test_2_output, n, size)){
	    cout << "True" << endl;  
    }else{
        cout << "False" << endl;
    }
    
    /*
    cin >> n;
    cin >> size;
    
    input(mas, size);
    rShiftMas(mas, n, size);
    output(mas, size);
    */
    
    
    //rShiftMas(mas, n size);
    return 0;
}