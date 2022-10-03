#ifndef __LIBKC_H__
#define __LIBKC_H__

#include <stdlib.h>
#include <string.h>
#include <time.h>

// Macro Definition
#define KC_MAX(x, y) ({    \
    typeof(x) _x = (x); \
    typeof(y) _y = (y); \
    (void) (&_x == &_y);\
    _x > _y ? _x : _y; })

#define KC_MIN(x, y) ({    \
    typeof(x) _x = (x); \
    typeof(y) _y = (y); \
    (void) (&_x == &_y);\
    _x < _y ? _x : _y; })

#define KC_ErrLog(message) printf("%s failed!", message)

// Function
double KC_GetRandData(int min, int max);
double KC_Add(double num1, double num2);
char *KC_StrCutLeft(char *destination, const char *source, int n);
char *KC_StrCutRight(char *destination, const char *source, int n);
char *KC_StrCutSub(char *destination, const char *source, int start, int len);

// Structure
typedef struct tagStudent
{
    char name[20];
    int age;
    double score;
} Student;

// Constant

// Type Alias
typedef unsigned long ulong;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;

// Global Variable

#endif // __LIBKC_H__