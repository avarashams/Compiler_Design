#include<iostream>
using namespace std;

int main(){
    char a[30];int i;
    cout<<"Enter a comment : ";
    cin >> a;

while (a[i]!= '\0'){
    if (a[0]=='/'&& a[1]=='/'){
        cout<<"Single line comment.";
    break;}
    else if (a[0=='/*']&& a[1]=='*'){
        cout<<"Multi line comment.";
    break;}
    else {
        cout<<"Invalid comment.";
    break;}
      i++ ;
    }
 return 0;
}
