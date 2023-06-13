#include <stdio.h>
#include <string.h>

#include "Core/h/Read.h"

int main() {
    Read(256, "NW.txt", 0);
    Read(256, "TNW.txt", 1);
    return 0;
}