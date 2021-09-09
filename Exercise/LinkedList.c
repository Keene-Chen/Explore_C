#include <stdio.h>
#include <stdlib.h>

//声明节点结构
typedef struct Link
{
    int data;          //存储整形元素
    struct Link *next; //指向直接后继元素的指针
} link;

//创建链表的函数
link *initLink()
{
    link *p = (link *)malloc(sizeof(link)); //创建一个头结点
    link *temp = p;                         //声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i = 1; i <= 5; i++)
    {
        //创建节点并初始化
        link *a = (link *)malloc(sizeof(link));
        a->data = i;
        a->next = NULL;
        //建立新节点与直接前驱节点的逻辑关系
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

//打印链表
void printlink(link *p)
{
    link *temp = p; //将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next)
    {
        temp = temp->next;
        printf("%d", temp->data);
    }
    printf("\n");
}

int main(void)
{
    link *list;
    list = initLink();
    printlink(list);
    return 0;
}