#include <iostream>
#include <fstream>
using namespace std;

int main() {
    FILE *fp = fopen("FinalLab1.txt", "r");
    if (!fp) {
        cout << "Cannot open file.\n";
        return 1;
    }

    char input[100];
    fgets(input, 100, fp);
    fclose(fp);

    string type = "", name = "";
    int i = 0;

    while (input[i] != ' ' && input[i] != '\0') type += input[i++];
    while (input[i] == ' ') i++;
    while (input[i] != ' ' && input[i] != '\0') name += input[i++];
    while (input[i] == ' ') i++;

    if (!(input[i] == '(' && input[i+1] == ')')) {
        cout << "Incorrect Declaration";
        return 0;
    }
    i += 2;
    while (input[i] == ' ') i++;

    if (input[i] == ';') {
        cout << "Correct Declaration";
    } else if (input[i] == '{') {
        while (input[++i] == ' ');
        if (input[i] == '}')
            cout << "Correct Definition";
        else
            cout << "Incorrect Definition";
    } else {
        cout << "Incorrect Definition";
    }

    return 0;
}