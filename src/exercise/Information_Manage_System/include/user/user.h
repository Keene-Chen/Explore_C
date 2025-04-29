#include "config.h"

// 用户数据类型定义
typedef struct
{
    char id[MAX_SIZE];      // 用户ID
    char name[MAX_SIZE];    // 用户姓名
    char passwd[MAX_SIZE];  // 用户密码
    char contact[MAX_SIZE]; // 用户联系方式
    char address[MAX_SIZE]; // 用户地址
    double balance;        // 用户余额
} User;

// 用户操作接口
/**
 * @brief  从外部文件导入用户信息
 */
void PullUsers();

/**
 * @brief  将用户信息导出到外部文件
 */
void PushUsers();

/**
 * @brief  获取用户对象
 * @param  index 用户所在数组下标
 * @return 指向对应用户的指针
 */
User *GetUser(int index);

/**
 * @brief  添加新用户
 * @param  u 待添加的用户指针
 * @return 添加成功返回1，失败返回0
 */
int AddUsers(User *u);

/**
 * @brief  删除给定ID的用户
 * @param  id 待删除用户的id
 * @param  who 删除操作的执行者id，管理员为null
 * @return 删除成功返回1，失败返回0
 */
int DeleteUsers(const char *id, const char *who);

/**
 * @brief  打印用户的详细信息
 * @param  index 用户所在数组的下标
 */
void UserInfo(int index);

/**
 * @brief  打印所有用户的信息
 */
void ShowUsers();

/**
 * @brief  检查用户名和密码是否匹配
 * @param  name 用户名
 * @param  passwd 用户密码
 * @return 匹配成功返回1，失败返回0
 */
int CheckPass(const char *name, const char *passwd, int *index);

/**
 * @brief  用户余额充值
 * @param  id 待充值用户id
 * @param  m 充值数额
 * @return 充值成功返回1，失败返回0
 */
int UserTopUp(const char *id, double m);