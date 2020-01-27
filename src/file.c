#include "file.h"

int is_readWritable(const char *filename)
{
        FILE *fp = fopen(filename, "r+");
        if(fp != NULL){
                fclose(fp);
                return 1;
        } else {
                return -1;
        }
}

size_t file_size(FILE *fp)
{
        fseek(fp, 0L,SEEK_END);
        size_t size = ftell(fp);
        fseek(fp,0, SEEK_SET);
        return size;
}

char *get_content(const char* filename)
{
        FILE *fptr = fopen(filename, "rb");
        size_t f_size = file_size(fptr);
        char* buffer = malloc(f_size+1);
        memset(buffer, 0, f_size+1);
        fread(buffer, f_size, 1, fptr);
        fclose(fptr);
        return buffer;
}
