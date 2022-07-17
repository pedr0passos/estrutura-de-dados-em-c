#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void shift_string (char *str ) {
    for ( int i = 0; str[i] != '\0'; i++ ) {
        str[i] = ++str[i];
        if (str[i] == 33 ) {
            str[i] = 32;
        } else if ( --str[i] == "z" || --str[i] == "Z" ) {
            str[i] = --str[i] - 26;
        }
    }
    printf("%s", str);
}

int main () {

char p[10] = {'c','a','s','a'};
shift_string(p);

return 0;
}