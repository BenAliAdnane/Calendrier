#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha1.h"

int main(){

    BYTE test[] = {"1234"};
    
    SHA1_CTX ctx;
    BYTE buf[400];

    sha1_init(&ctx);

    sha1_update(&ctx, test, strlen(test));

    sha1_final(&ctx, buf);

    printf("%x\n", buf);

    return 0;
}