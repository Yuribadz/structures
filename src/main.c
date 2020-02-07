#include <stdio.h>
#include "file.h"
#include "yajl/yajl_tree.h"

int main(void) {
    yajl_val json_root = get_json_root("example.json");

    const char *path[] = { "book", (const char*) 0 };
    yajl_val v = yajl_tree_get(json_root, path, yajl_t_array);
    if (v && YAJL_IS_ARRAY(v)) {
        printf("is array\n");
    }
    printf("%lu\n", v->u.array.len);
    for (int i = 0; i < v->u.array.len; ++i) {
        yajl_val object = v->u.array.values[i];
        size_t nelem = object->u.object.len;
        printf("Book #%d :\n", i);
        for (int j = 0; j < nelem; ++j) {

            const char *key = object->u.object.keys[j];
            yajl_val val = object->u.object.values[j];
            if (YAJL_IS_STRING(val)) {
                printf("%s : %s\n", key, val->u.string);
            }
        }

    }
    free(json_root);
    return 0;
}
