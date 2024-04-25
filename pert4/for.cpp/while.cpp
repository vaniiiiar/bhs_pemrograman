#include <iostream>

using namespace std;

void dowhile(){
    cout << " Penggunaan DO WHILE " << endl;
    int a = 1;
    int b = 2;
    do (a<=b){
        cout << a << endl;
        a = a+1;
    }
}

void penggunaanwhilebreak(){
    cout << " Penggunaan WHILE BREAK" << endl;
    int a = 3 ;
    while(a<=5){
        a = a+1;
        if(a == 2)
        {
            cout << a << endl;
            break;
        }
        cout << " Looping While Berhenti " << endl;
    }
    cout << " Looping diluar while berhenti"<< endl;
}

int main (){
    cout << " Penggunaan WHILE " << endl;
    int a = 1;
    int b = 2;
    while (a<=b){
        cout << a << endl;
        a = a+1;
    }
    return 0;
}