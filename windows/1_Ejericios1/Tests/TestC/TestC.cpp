#include <iostream>
using namespace std;


int largoStr(char* str) {
    int largo = 0;
    while (*str != '\0') {
        largo++;
        str++;
    }
    return largo;
}








int main()
{
    
    /* int largo = strlen(str);
     int consASCII = 32;
     char* num = new char[largo + 1];

     int i = 0;
     while (str[i] != '\0') {

         if ((str[i]) > 96 && (str[i] < 123)) {
             num[i] = str[i] - consASCII;
         }
         else if (str[i] > 64 && str[i] < 91) {
             num[i] = str[i] + consASCII;
         }
         else {
             num[i] = str[i];
         }
         i++;
     }*/
     /* num[largo] = '\0';
      cout << str << endl;
      cout << num << endl;*/
    char* str = new char[5]{ 'h', 'o', 'l','a', '\0' };
    int largo = largoStr(str);
    char* nuevoStr = new char[largo + 1];

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            nuevoStr[i] = str[i] + 32;

        }
        else if (str[i] >= 97 && str[i] <= 122) {
            nuevoStr[i] = str[i] - 32;

        }
        else {
            nuevoStr[i] = str[i];
        }
    }

    nuevoStr[largo] = '\0';
    cout << largo << endl;
    cout << str << endl;
    cout << nuevoStr << endl;
    
}
