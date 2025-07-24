#include <iostream>
using namespace std;
int main(){

char a[15];int i;
cout<<"Enter an equation : ";
cin >> a;

while (a[i]!= '\0'){
    if (a[i]== '+'||a[i]== '-'||a[i]== '*' ||a[i]== '/' || a[i]== '='){
        cout<<"Operators : "<<a[i]<<endl;

    }
    i++;
}
return 0;
}
