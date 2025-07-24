#include<iostream>
using namespace std;

int main(){
char a[5]; int i;
   cout<<"Enter string : ";
  // for (int i=0; i<5; i++){
   cin >> a;

        while (a[i]!= '\0'){
                //for (i=0; i<5; i++){
            if (a[i]>='0' && a[i]<='9'){
                cout<<"Is Numeric.";
           break; }

            else{
                cout<<"Is not Numeric.";
           break; }
               i++;


        }


return 0;
}
