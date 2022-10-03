/**
 * Author     : KeeneChen
 * DateTime   : 2022.08.07-13:03:09
 * Description: x86_64-pc-linux-gnu byte alignment
 */

#include <stdio.h>

void alignment_2_byte();
void alignment_4_byte();
void alignment_8_byte();

int main(void)
{
    alignment_2_byte();
    alignment_4_byte();
    alignment_8_byte();

    return 0;
}

void alignment_2_byte()
{
#pragma pack(2)
    struct foo
    {
        // 8
        char a;  // 1+1
        short b; // 2
        int c;   // 4
    };
    struct bar
    {
        // 8
        int c;   // 4
        short b; // 2
        char a;  // 1+1
    };
    struct baz
    {
        // 8
        short b; // 2
        int c;   // 4
        char a;  // 1+1
    };
#pragma pack()

    printf("2字节对齐: foo[%d] bar[%d] baz[%d]\n", sizeof(struct foo), sizeof(struct bar), sizeof(struct baz));
}

void alignment_4_byte()
{
#pragma pack(4)
    struct foo
    {
        // 8
        char a;  // 1+1
        short b; // 2
        int c;   // 4
    };
    struct bar
    {
        // 7+1
        int c;   // 4
        short b; // 2
        char a;  // 1
    };
    struct baz
    {
        // 12
        short b; // 2+2
        int c;   // 4
        char a;  // 1+3
    };
#pragma pack()

    printf("4字节对齐: foo[%d] bar[%d] baz[%d]\n", sizeof(struct foo), sizeof(struct bar), sizeof(struct baz));
}

void alignment_8_byte()
{
#pragma pack(8)
    struct foo
    {
        // 16
        char a;  // 1+3
        short b; // 2+2
        int *c;  // 8
    };
    struct bar
    {
        // 16
        int *c;  // 8
        short b; // 2+2
        char a;  // 1+3
    };
    struct baz
    {
        // 17+7
        short b; // 2+6
        int *c;  // 8
        char a;  // 1
    };
#pragma pack()

    printf("8字节对齐: foo[%d] bar[%d] baz[%d]\n", sizeof(struct foo), sizeof(struct bar), sizeof(struct baz));
}