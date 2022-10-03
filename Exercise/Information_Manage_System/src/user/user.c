#include "tools/info.h"
#include "user/user.h"
#include <stdio.h>
#include <string.h>

// TODO: 思考为什么要用static关键字修饰？
static User users[MAX_USER]; // 定义用户数组最大值为MAX_USER
static int total_user = 0;   // 用户总数
static const char *file_path = "data/user.txt";

/**
 * @brief  从外部文件导入用户信息
 */
void PullUsers()
{
    total_user = 0;
    FILE *fp = fopen(file_path, "r");
    IsOpen(fp);
    if (fp)
    {
        while (fscanf(fp, "%s%s%s%s%s%lf", users[total_user].id,
                      users[total_user].name, users[total_user].passwd, users[total_user].contact,
                      users[total_user].address, &(users[total_user].balance)) != EOF)
        {
            total_user++;
        }
        fclose(fp);
    }
}

/**
 * @brief  将用户信息导出到外部文件
 */
void PushUsers()
{
    FILE *fp = fopen(file_path, "w");
    IsOpen(fp);

    for (int i = 0; i < total_user; i++)
    {
        fprintf(fp, "%s,%s,%s,%s,%s,%.2f\n",
                users[i].id, users[i].name, users[i].passwd,
                users[i].contact, users[i].address, users[i].balance);
    }

    fclose(fp);
}

/**
 * @brief  获取用户对象
 * @param  index 用户所在数组下标
 * @return 指向对应用户的指针
 */
// TODO: 返回值中返回的指针是什么？
User *GetUser(int index) { return users + index; }

/**
 * @brief (辅助函数)根据用户名查找用户
 * @param name 待查找的用户名
 * @return 查找成功返回数组下标，失败返回-1
 */
static int SearchUserName(const char *name)
{
    for (int i = 0; i < total_user; i++)
        if (strcmp(users[i].name, name) == 0)
            return i;

    return -1;
}

/**
 * @brief  添加新用户
 * @param  u 待添加的用户指针
 * @return 添加成功返回1，失败返回0
 */
int AddUsers(User *u)
{
    if (total_user == MAX_USER)
        return 0;

    if (SearchUserName(u->name) != -1)
        return 0;

    GenID(u->id, 'U');
    users[total_user++] = *u;

    return 1;
}

/**
 * @brief (辅助函数)查找给定ID的用户
 *
 * @param id 需要查找的用户ID
 * @return int 成功返回下标，失败返回-1
 */
static int SearchUserID(const char *id)
{
    for (int i = 0; i < total_user; i++)
        if (strcmp(users[i].id, id) == 0)
            return i;
    return -1;
}

/**
 * @brief  删除给定ID的用户
 * @param  id 待删除用户的id
 * @param  who 删除操作的执行者id，管理员为null
 * @return 删除成功返回1，失败返回0
 */
int DeleteUsers(const char *id, const char *who)
{
    if (who)
        return 0;

    int idx = SearchUserID(id);
    if (idx == -1)
        return 0;

    for (int j = idx; j < total_user - 1; j++)
        users[j] = users[j + 1];
    total_user--;

    return 1;
}

/**
 * @brief  打印用户的详细信息
 * @param  index 用户所在数组的下标
 */
void UserInfo(int index)
{
    printf("ID:        | %s\n", users[index].id);
    printf("Name:      | %s\n", users[index].name);
    printf("Contact:   | %s\n", users[index].contact);
    printf("Address:   | %s\n", users[index].address);
    printf("Balance:   | %.2f\n", users[index].balance);
}

static const char *header = "|ID         |Name       |Contact    |Address    |Balance    |";
static const char *divide = "+-----------+-----------+-----------+-----------+-----------+";

/**
 * @brief 打印单个用户作为表格的一行
 * @param index 用户下标
 */
static void printUser(int index)
{
    printf("|%-10s |%-10s |%-10s |%-10s |%-10.2f |\n",
           users[index].id,
           users[index].name,
           users[index].contact,
           users[index].address,
           users[index].balance);
}

/**
 * @brief  打印所有用户的信息
 */
void ShowUsers()
{
    print_header 
    for (int i = 0; i < total_user; i++)
    {
        printUser(i);
        print_divide
    }
}

/**
 * @brief  检查用户名和密码是否匹配
 * @param  name 用户名
 * @param  passwd 用户密码
 * @return 匹配成功返回1，失败返回0
 */
int CheckPass(const char *name, const char *passwd, int *index)
{
    *index = SearchUserName(name);
    if (*index == -1)
        return 0;
    return strcmp(users[*index].passwd, passwd) == 0;
}

/**
 * @brief  用户余额充值
 * @param  id 待充值用户id
 * @param  m 充值数额
 * @return 充值成功返回1，失败返回0
 */
int UserTopUp(const char *id, double m)
{
    int idx = SearchUserID(id);
    if (idx == -1)
        return 0;
    users[idx].balance += m;
    return 1;
}
