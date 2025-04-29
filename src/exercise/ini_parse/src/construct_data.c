/**
 * Author:   KeeneChen
 * DateTime: 2022.07.09-10:45:58
 * Description: 构造ini数据
 * Command: gcc ./construct_data.c -liniparser -o construct_data
 */

#include <stdio.h>
#include <stdlib.h>
#include "iniparser/dictionary.h"
#include "iniparser/iniparser.h"

#define MAX_SIZE 1024

int main(void)
{
	// 创建字典结构
	dictionary *dict = dictionary_new(MAX_SIZE);

	// 设置ini数据
	iniparser_set(dict, "stu1", NULL);
	iniparser_set(dict, "stu1:id", "3320190993209");
	iniparser_set(dict, "stu1:name", "zhangsan");
	iniparser_set(dict, "stu1:age", "18");
	iniparser_set(dict, "stu1:skill", "C,Java,Python");
	iniparser_set(dict, "stu1:score", "100.3");
	iniparser_set(dict, "stu1:graduate", "false");
	iniparser_set(dict, "stu2", NULL);
	iniparser_set(dict, "stu2:id", "3320190993210");
	iniparser_set(dict, "stu2:name", "lishi");
	iniparser_set(dict, "stu2:age", "19");
	iniparser_set(dict, "stu2:skill", "C,C++,C sharp");
	iniparser_set(dict, "stu2:score", "120.53");
	iniparser_set(dict, "stu2:graduate", "true");

	// 修改stu1:name为wangwu
	iniparser_set(dict, "stu1:name", "wangwu");
	// 删除stu1:age属性
	iniparser_unset(dict, "stu1:age");

	// 导出ini文件
	const char *filepath = "../source/stu.ini";
	FILE *fp = fopen(filepath, "w+");
	if (fp == NULL) {
		printf("failed to open file\n");
		return -1;
	}
	iniparser_dump_ini(dict, fp);

	// 释放资源
	iniparser_freedict(dict);
	fclose(fp);

	return 0;
}