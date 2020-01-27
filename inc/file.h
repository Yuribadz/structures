#ifndef FILE_H
#define FILE_H
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_readWritable(const char *filename);

size_t file_size(FILE *fp);

char *get_content(const char* filename);
#endif // FILE_H
