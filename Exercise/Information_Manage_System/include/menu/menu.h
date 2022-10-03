#ifndef __MENU_H__
#define __MENU_H__

// 菜单枚举类型
typedef enum
{
    MAIN,
    ADMIN,
    USER,
    BUYER,
    SELLER,
    INFO,
    MODIFY,
    GOOD
} Menu;

// 不同菜单的选项数目
extern const int option_num[];

/**
 * @brief 提示菜单
 *
 * @param type 菜单类型
 * @return 用户输入
 */
int menu(Menu type);

#endif // __MENU_H__