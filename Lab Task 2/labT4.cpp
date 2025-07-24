#include<iostream>
using namespace std;

int main() {
    char a[20];
    int i = 0;

    cout<<"Enter input: ";
    cin>>a;

    if ((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')||(a[0] == '_')) {
          i = 1;

        while (a[i]!='\0'){
            if ((a[i]>= 'a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')||(a[i]>='0' && a[i]<='9')||(a[i]== '_')){
                i++;
            }
            else{
            cout<<"Invalid Identifier";
        return 0;
            }
        }
        cout<<"Valid Identifier";
         }

    else{
        cout<<"Invalid Identifier";
      }

    return 0;
}
