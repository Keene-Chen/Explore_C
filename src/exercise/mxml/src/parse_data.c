#include "mxml.h"

void parse_stu(mxml_node_t* root);
void parse_tea(mxml_node_t* root);
void show(mxml_node_t* node);

int main(int argc, char const* argv[])
{
    // 从文件中加载XML文档对象
    FILE* fp = fopen("../res/example.xml", "r");
    mxml_node_t* root = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);
    fclose(fp);

    // 解析学生数据
    parse_stu(root);
    // 解析老师数据
    parse_tea(root);
    // 释放XML文档对象
    mxmlDelete(root);

    return 0;
}

// 解析学生数据
void parse_stu(mxml_node_t* root)
{
    mxml_node_t* student = mxmlFindElement(root, root, "student", NULL, NULL, MXML_DESCEND);
    mxml_node_t* stu;
    for (stu = mxmlFindElement(student, root, "group", NULL, NULL, MXML_DESCEND);
         stu != NULL;
         stu = mxmlFindElement(stu, student, "group", NULL, NULL, MXML_DESCEND)) {
        mxml_node_t* id = mxmlFindElement(stu, stu, "id", NULL, NULL, MXML_DESCEND);
        mxml_node_t* name = mxmlFindElement(stu, stu, "name", NULL, NULL, MXML_DESCEND);
        mxml_node_t* class = mxmlFindElement(stu, stu, "class", NULL, NULL, MXML_DESCEND);
        mxml_node_t* depart = mxmlFindElement(stu, stu, "depart", NULL, NULL, MXML_DESCEND);
        mxml_node_t* age = mxmlFindElement(stu, stu, "age", NULL, NULL, MXML_DESCEND);
        mxml_node_t* score = mxmlFindElement(stu, stu, "score", NULL, NULL, MXML_DESCEND);
        mxml_node_t* graduate = mxmlFindElement(stu, stu, "graduate", NULL, NULL, MXML_DESCEND);
        // 地址
        mxml_node_t* address = mxmlFindElement(stu, stu, "address", NULL, NULL, MXML_DESCEND);
        mxml_node_t* country = mxmlFindElement(address, stu, "country", NULL, NULL, MXML_DESCEND);
        mxml_node_t* province = mxmlFindElement(address, stu, "province", NULL, NULL, MXML_DESCEND);
        // 技能
        mxml_node_t* skill = mxmlFindElement(stu, stu, "skill", NULL, NULL, MXML_DESCEND);
        mxml_node_t* item;

        show(id);
        show(name);
        show(class);
        show(depart);
        show(age);
        show(score);
        show(graduate);
        show(address);
        show(country);
        for (item = mxmlFindElement(skill, stu, "item", NULL, NULL, MXML_DESCEND);
             item != NULL;
             item = mxmlFindElement(item, skill, "item", NULL, NULL, MXML_DESCEND)) {
            printf("%-8s▏%s\n", mxmlGetElement(skill), mxmlGetText(item, 0));
        }
        printf("\n");
    }
}

// 解析老师数据
void parse_tea(mxml_node_t* root)
{
    mxml_node_t* teacher = mxmlFindElement(root, root, "teacher", NULL, NULL, MXML_DESCEND);
    mxml_node_t* tea;
    for (tea = mxmlFindElement(teacher, root, "group", NULL, NULL, MXML_DESCEND);
         tea != NULL;
         tea = mxmlFindElement(tea, teacher, "group", NULL, NULL, MXML_DESCEND)) {
        mxml_node_t* id = mxmlFindElement(tea, tea, "id", NULL, NULL, MXML_DESCEND);
        mxml_node_t* name = mxmlFindElement(tea, tea, "name", NULL, NULL, MXML_DESCEND);
        mxml_node_t* depart = mxmlFindElement(tea, tea, "depart", NULL, NULL, MXML_DESCEND);
        mxml_node_t* age = mxmlFindElement(tea, tea, "age", NULL, NULL, MXML_DESCEND);
        mxml_node_t* title = mxmlFindElement(tea, tea, "title", NULL, NULL, MXML_DESCEND);
        mxml_node_t* grade = mxmlFindElement(tea, tea, "grade", NULL, NULL, MXML_DESCEND);
        mxml_node_t* gender = mxmlFindElement(tea, tea, "gender", NULL, NULL, MXML_DESCEND);

        show(id);
        show(name);
        show(depart);
        show(age);
        show(title);
        show(grade);
        show(gender);
        printf("\n");
    }
}

void show(mxml_node_t* node)
{
    printf("%-8s▏%s\n", mxmlGetElement(node), mxmlGetText(node, 0));
}