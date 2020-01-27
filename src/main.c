#include <stdio.h>
#include "file.h"
#include "yajl/yajl_tree.h"

int main(void)
{
        char *content = get_content("sample.config");
        printf("%ld\n", strlen(content));
        //printf("%s\n", content);
        free(content);
        return 0;
}
