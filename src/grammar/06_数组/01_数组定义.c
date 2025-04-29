/**
 * Author:   KeeneChen
 * DateTime: 2022.07.19-11:51:21
 * Description: 数组定义
 */
#include <stdio.h>

int main(void)
{
    // 定义一个int类型长度为3的数组
    int arr[3];

    // 为数组赋值
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    // arr[3]=4; 下标越界，下标是从零开始

    // 使用花括号初始化数组
    int foo[3] = {1, 2, 3};
    // foo[3] = {1, 2, 3}; C 语言规定，数组变量一旦声明，就不得修改变量指向的地址

    // 如果花括号中的值少于数组大小会自动赋值为0
    int bar[4] = {1, 2, 3};
    // 等价于 int bar[4] = {1, 2, 3, 0};

    // 将数组全部初始化为0
    int baz[4] = {0};

    // 指定位置赋值
    int qux[3] = {[2] = 3};
    // 等价于 int qux[3] = {0, 0, 3};

    // 初始化省略数组大小
    int foobar[] = {1, 2, 3};
    // 等价于 int foobar[3] = {1, 2, 3};

    // 数组名就是数组的首地址
    arr = &arr;

    return 0;
}