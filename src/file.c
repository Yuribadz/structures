#include "file.h"
#include <stdio.h>

int is_readWritable(const char *filename)
{
        FILE *fp = fopen(filename, "r+");
        if(fp != NULL){
                fclose(filename);
                return 1;
        } else {
                return 0;
        }
}

