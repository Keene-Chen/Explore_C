#include "config.h"
#include "tools/info.h"
#include "good/good.h"
#include <stdio.h>
#include <string.h>

static Good goods[MAX_GOOD]; // 定义商品数组，最大值为MAX_GOOD
static int total_good = 0;   // 商品总数
static const char *file_path = "data/good.txt";

/**
 * @brief  从外部文件导入商品信息
 */
void PullGoods()
{
    total_good = 0;
    FILE *fp = fopen(file_path, "r");
    IsOpen(fp);

    if (fp)
    {
        while (fscanf(fp, "%s%s%lf%s%u%s%s",
                      goods[total_good].id,
                      goods[total_good].name,
                      &goods[total_good].price,
                      goods[total_good].seller_id,
                      &goods[total_good].state,
                      goods[total_good].date,
                      goods[total_good].description) != EOF)
        {
            total_good++;
        }

        fclose(fp);
    }
}

/**
 * @brief  将商品信息导出到外部文件
 */
void PushGoods()
{
    FILE *fp = fopen(file_path, "w");
    for (int i = 0; i < total_good; i++)
        fprintf(fp, "%s,%s,%.2f,%s,%u,%s,%s\n",
                goods[i].id,
                goods[i].name,
                goods[i].price,
                goods[i].seller_id,
                goods[i].state,
                goods[i].date,
                goods[i].description);

    fclose(fp);
}

/**
 * @brief  获取商品对象
 * @param  index 商品所在数组下标
 * @return 指向对应商品的指针
 */
Good *GetGood(int index)
{
    return goods + index;
}

/**
 * @brief  添加新商品
 * @param  g 待添加的商品指针
 * @return 添加成功返回1，失败返回0
 */
int AddGood(Good *g)
{
    if (total_good == MAX_GOOD) // 判断数组是否为满
        return 0;

    GenID(g->id, 'G');
    GetDate(g->date);
    g->state = SELLING;
    goods[total_good++] = *g;

    return 1;
}

/**
 * @brief  查找给定ID的商品
 * @param  id 需要查找的商品ID
 * @return 成功返回下标，失败返回-1
 */
int SearchGoodID(const char *id)
{
    for (int i = 0; i < total_good; i++)
        if (strcmp(goods[i].id, id) == 0)
            return i;

    return -1;
}

/**
 * @brief 删除给定ID的商品
 * @param id 待删除商品的id
 * @param who 删除操作执行者的id，管理员为null
 * @return 删除成功返回1，失败返回0
 */
int DeleteGood(const char *id, const char *who)
{
    int index = SearchGoodID(id);

    if (index == -1)
        return 0;
    if (who && strcmp(goods[index].seller_id, who))
        return 0;
    goods[index].state = BANNED;

    return 1;
}

static const char *state_name[] = {"Selling", "Sold", "Banned"}; // 打印商品信息时与枚举类型对应

/**
 * @brief 打印详细的商品信息
 * @param index 商品的数组下标
 */
void GoodInfo(int index)
{
    printf("ID:            | %s\n", goods[index].id);
    printf("Name:          | %s\n", goods[index].name);
    printf("Description:   | %s\n", goods[index].description);
    printf("Date:          | %s\n", goods[index].date);
    printf("Price:         | %.2f\n", goods[index].price);
    printf("Seller:        | %s\n", goods[index].seller_id);
    printf("State:         | %s\n", state_name[goods[index].state]);
}

static const char *header = "|ID         |Name       |Price      |Date                 |Seller     |State      |";
static const char *divide = "+-----------+-----------+-----------+---------------------+-----------+-----------+";

/**
 * @brief 打印单个商品作为表格的一行
 * @param index 用户下标
 */
static void PrintGood(int index)
{
    printf("|%-10s |%-10s |%-10.2f |%-20s |%-10s |%-10s |\n",
           goods[index].id,
           goods[index].name,
           goods[index].price,
           goods[index].date,
           goods[index].seller_id,
           state_name[goods[index].state]);
}

/**
 * @brief 打印所有商品的信息
 */
void ShowGoods()
{
    print_header for (int i = 0; i < total_good; i++)
    {
        PrintGood(i);
        print_divide
    }
}

/**
 * @brief 为买家搜索商品-只搜索正在出售中的商品
 * @param name 待搜索商品的名称
 */
void SearchGoodNameBuyer(const char *name)
{
    print_header for (int i = 0; i < total_good; i++) if (goods[i].state == SELLING && strstr(goods[i].name, name))
    {
        PrintGood(i);
        print_divide
    }
}

/**
 * @brief 为管理员搜索商品-搜索所有商品
 * @param name 待搜索商品的名称
 */
void SearchGoodNameAdmin(const char *name)
{
    print_header for (int i = 0; i < total_good; i++) if (strstr(goods[i].name, name))
    {
        PrintGood(i);
        print_divide
    }
}

/**
 * @brief 打印给定卖家id的商品
 * @param id 需要打印商品的卖家id
 */
void ShowGoodsSeller(const char *id)
{
    print_header for (int i = 0; i < total_good; i++) if (strcmp(goods[i].seller_id, id) == 0)
    {
        PrintGood(i);
        print_divide
    }
}

/**
 * @brief 打印出售中的商品
 * @param id 需要打印商品的买家id
 */
void ShowGoodsBuyer(const char *id)
{
    print_header for (int i = 0; i < total_good; i++) if (goods[i].state == SELLING)
    {
        PrintGood(i);
        print_divide
    }
}
