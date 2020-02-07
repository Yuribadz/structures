#ifndef FILE_H
#define FILE_H
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yajl/yajl_tree.h"

int is_readWritable(const char *filename);

size_t file_size(FILE *fp);

unsigned char* get_content(const char *filename);

yajl_val get_json_root(const char *filename);
#endif // FILE_H
