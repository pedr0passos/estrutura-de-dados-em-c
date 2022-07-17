#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int pontencia (x,y) {

    x *= x;

    if ( y == 0 ) {

        return x;

    } else {

        return pontencia(x,y-1);
        
    }

}

int main () {


    
    return 0;
}