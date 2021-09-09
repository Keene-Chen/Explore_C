/**
* Author:   hellochen
* DateTime: 2021.03.22-17:56:10
* Description: 将所指字符串中下标为偶数同时ASCII值为奇数的字符刪除,所指字符串中剩的字符形成的新串放在所指的数组中。
* 例如,若s所指字符串中的内容为"ABCDEFG12345",其中字符C的ASCⅡ码值为奇数,
* 在数组中的下标为偶数,因此必须刪除;而字符1的ASCⅡ码值为奇数,在数组中的下标为奇数,因此不应当删除,其他依此类推。
* 最后指的数组中的内容应是BDF12345
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = {"ABCDEFG12345"}, a[12], *p = str;

    int count = 0;
    for (int i = 0; i < strlen(str); i++)   // 遍历字符串
    {
        if (!(str[i] % 2 == 1 && (i % 2) == 0)) // 先对下标取偶数，ASCII码取奇数，在整体取反
        {
            a[count++] = str[i];    // 满足条件的每一位字符数组赋值给新数组
        }
    }
    a[count] = 0;   // 字符串结束位
    puts(a);
    return 0;
}