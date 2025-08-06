#include <iostream>
#include <fstream>
using namespace std;

char kw[10][10] = {"int", "float","char","if", "else","for"};
char op[] = "+-*/=><";
char pc[] = ";(){},.";

bool isLetter(char c){
    return (c>= 'a'&& c<='z')||(c>= 'A'&&c<= 'Z');
           }

bool isConst(char c){
    return (c>='0'&&c<='9');
   }

bool isValidChar(char c){
    return isLetter(c)||isConst(c)||c=='_';
        }

bool isKeyword(char token[]){
    for (int i=0; i<10; i++){
     int j=0;
        while(kw[i][j]==token[j] && token[j]!='\0')
            j++;
        if(kw[i][j] =='\0'&&token[j]=='\0')
            return true;
    }
    return false;
}

bool isValidIdentifier(char token[]) {
    if (!isLetter(token[0])&&token[0]!='_')
        return false;
    for (int i = 1; token[i] != '\0'; i++) {
        if (!isValidChar(token[i]))
        return false;
    }
    return true;
}

bool isOperator(char c){
    for (int i=0; op[i]!='\0'; i++){
        if (c==op[i])
            return true;
     }
    return false;
             }

bool isPunctuation(char c){
    for (int i=0; pc[i]!='\0'; i++){
        if (c==pc[i])
            return true;
    }
    return false;
                 }
int main() {
    FILE *fp = fopen("CNlab3.txt","r");
    if (!fp) {
        cout<<"Cannot open file.\n";
        return 1;
    }

    char ch, token[100];
    int i = 0;

    while ((ch = fgetc(fp))!= EOF) {

        if (isLetter(ch)||isConst(ch)||ch=='_'){
            token[i++]=ch;
                      }
        else {
            token[i]='\0';
            if (i>0){
                if (isKeyword(token))
                    cout <<token<<" - Keyword"<<endl;
                else if (isValidIdentifier(token))
                    cout<<token<< " - valid Identifier"<<endl;
                else
                    cout<<token<<" - Invalid Identifier"<<endl;
                i=0;
                     }
            if(isOperator(ch)){
                cout<<ch<<" - Operator"<<endl;
            } else if (isPunctuation(ch)){
                cout << ch << " - Punctuation"<<endl;
            }
        }
    }

    fclose(fp);
    return 0;
}
