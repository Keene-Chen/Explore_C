#ifndef __GOOD_H__
#define __GOOD_H__

#include "config.h"

// 商品状态：销售中、已出售、已下架
typedef enum
{
    SELLING,
    SOLD,
    BANNED
} State;

// 商品数据类型定义
typedef struct
{
    char id[MAX_SIZE];          // 商品ID
    char name[MAX_SIZE];        // 商品名称
    double price;               // 商品价格
    char seller_id[MAX_SIZE];   // 卖家ID
    State state;                // 商品状态
    char date[MAX_SIZE];        // 日期
    char description[MAX_SIZE]; // 商品描述
} Good;

// 商品操作接口
/**
 * @brief  从外部文件导入商品信息
 */
void PullGoods();

/**
 * @brief  将商品信息导出到外部文件
 */
void PushGoods();

/**
 * @brief  获取商品对象
 * @param  index 商品所在数组下标
 * @return 指向对应商品的指针
 */
Good *GetGood(int index);

/**
 * @brief  添加新商品
 * @param  g 待添加的商品指针
 * @return 添加成功返回1，失败返回0
 */
int AddGood(Good *g);

/**
 * @brief  查找给定ID的商品
 * @param  id 需要查找的商品ID
 * @return 成功返回下标，失败返回-1
 */
int SearchGoodID(const char *id);

/**
 * @brief 删除给定ID的商品
 * @param id 待删除商品的id
 * @param who 删除操作执行者的id，管理员为null
 * @return 删除成功返回1，失败返回0
 */
int DeleteGood(const char *id, const char *who);

/**
 * @brief 打印详细的商品信息
 * @param index 商品的数组下标
 */
void GoodInfo(int index);

/**
 * @brief 打印所有商品的信息
 */
void ShowGoods();

/**
 * @brief 为买家搜索商品-只搜索正在出售中的商品
 * @param name 待搜索商品的名称
 */
void SearchGoodNameBuyer(const char *name);

/**
 * @brief 为管理员搜索商品-搜索所有商品
 * @param name 待搜索商品的名称
 */
void SearchGoodNameAdmin(const char *name);

/**
 * @brief 打印给定卖家id的商品
 * @param id 需要打印商品的卖家id
 */
void ShowGoodsSeller(const char *id);

/**
 * @brief 打印出售中的商品
 * @param id 需要打印商品的买家id
 */
void ShowGoodsBuyer(const char *id);

#endif // __GOOD_H__