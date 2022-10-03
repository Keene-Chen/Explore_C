#include "config.h"
#include "tools/info.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

static const char *file_path = "data/id.txt";

void GetDate(char *dest)
{
    time_t rawtime;
    time(&rawtime);
    struct tm *timeinfo = localtime(&rawtime);
    strftime(dest, MAX_SIZE, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void GenID(char *dest, char type)
{
    int uid = 0, gid = 0, oid = 0; // user, good, order
    FILE *pf = fopen(file_path, "r");
    if (pf)
    {
        fscanf(pf, "%d%d%d", &uid, &gid, &oid);
        fclose(pf);
    }
    int id = 0;
    switch (type)
    {
    case 'U':
        id = uid++;
        break;
    case 'G':
        id = gid++;
        break;
    case 'O':
        id = oid++;
        break;
    }
    sprintf(dest, "%c%05d", type, id);
    pf = fopen(file_path, "w");
    fprintf(pf, "%d,%d,%d\n",uid, gid, oid);
    fclose(pf);
}

void IsOpen(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Fail to open file!\n");
        exit(0);
    }
}