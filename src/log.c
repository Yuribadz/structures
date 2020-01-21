#include "log.h"
#include <stdio.h>
int create_logger(void)
{
        qlog_t *logger = qlog("structures-%Y%m%d.log", 0644, 86400, false);
        if(logger == NULL)
                return -1;
        return 1;

}

int duplicate_log(FILE *outfp, int flush)
{
        return logger->duplicate(logger, outfp, flush);
}

qlog_t* get_logger(void)
{
        return logger;
}

void close_logger(void)
{
        logger->free(logger);
}
