#include <iostream>

using namespace std;

int main(){
    
    int temp = 1;
    
    for (int i = 0; i < 30; i++) {
        temp += 1;
    }
    
    //use gdb to find this infinite loop
    while (1) {
        temp = temp + 1;
    }

    for (int i = 0; i < 30; i++) {
        temp += 1;
    }
    return 0;
}