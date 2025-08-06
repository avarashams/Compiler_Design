#include <iostream>
using namespace std;

char op[]="+-*/=><";
char del[]= ";(){},.";

bool isDigit(char c){
    return c>='0' && c<='9';
         }

bool isOperator(char c){
    for(int i=0; op[i]!='\0';i++)
        if (c==op[i])
        return true;
    return false;
       }

bool isDelimiter(char c){
    for(int i=0; del[i]!='\0';i++)
        if(c==del[i])
    return true;
   return false;
            }

bool isInteger(char str[]) {
    int i = 0;
    if (str[0] == '-' || str[0] == '+') i++;
    for (; str[i] != '\0'; i++)
        if (!isDigit(str[i])) return false;
    return i > 0;
}

bool isReal(char str[]) {
    int i = 0, dot = 0;
    if (str[0] == '-' || str[0] == '+') i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') dot++;
        else if (!isDigit(str[i])) return false;
    }
    return dot == 1;
}

int main() {
    FILE *fp = fopen("lab3task2.txt", "r");
    if (!fp) {
        cout << "File not found\n";
        return 1;
    }

    char ch, token[50];
    int i = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isDigit(ch) || ch == '.' || ch == '-' || ch == '+') {
            token[i++] = ch;
        } else {
            token[i] = '\0';
            if (i > 0) {
                if (isInteger(token))
                    cout << token << " - Integer\n";
                else if (isReal(token))
                    cout << token << " - Real Number\n";
                i = 0;
            }
            if (isOperator(ch))
                cout << ch << " - Operator\n";
            else if (isDelimiter(ch))
                cout << ch << " - Delimiter\n";
        }
    }

    fclose(fp);
    return 0;
}
