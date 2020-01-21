#ifndef LOG_H
#define LOG_H
#include "qlibc/extensions/qlog.h"
#include <stdio.h>

qlog_t *logger;
int create_logger(void);
qlog_t *get_logger(void);
int duplicate_log(FILE *outfp, int flush);
void close_logger(void);


#endif // LOG_H
