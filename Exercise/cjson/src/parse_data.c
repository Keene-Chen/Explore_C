/**
 * Author:   KeeneChen
 * DateTime: 2022.07.08-16:23:56
 * Description: 解析json文件
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson/cJSON.h"
#include "cjson/cJSON_Utils.h"

typedef struct tagStudent {
	cJSON *id;
	cJSON *name;
	cJSON *class;
	cJSON *depart;
	cJSON *age;
	cJSON *score;
	cJSON *graduate;
	cJSON *skill[3];
	cJSON *address;
	cJSON *address_country;
	cJSON *address_province;
} Student;

int import_file(const char *filepath, char *json_str);
void show(Student stu);

int main(void)
{
	const char *filepath = "../source/export.json";
	char *json_str = (char *)malloc(2048 * sizeof(char));

	if (import_file(filepath, json_str) != 0) {
		printf("import file error\n");
	}

	/* 解析整段JSO数据 */
	cJSON *item = cJSON_Parse(json_str);
	if (item == NULL) {
		printf("parse fail.\n");
		return -1;
	}

	/* 依次根据名称提取JSON数据（键值对） */
	cJSON *student = cJSON_GetObjectItem(item, "student");
	cJSON *item1 = cJSON_GetArrayItem(student, 0);

	// 获取item1中的键值对
	Student stu1;
	stu1.id = cJSON_GetObjectItem(item1, "id");
	stu1.name = cJSON_GetObjectItem(item1, "name");
	stu1.class = cJSON_GetObjectItem(item1, "class");
	stu1.depart = cJSON_GetObjectItem(item1, "depart");
	stu1.age = cJSON_GetObjectItem(item1, "age");
	stu1.score = cJSON_GetObjectItem(item1, "score");
	stu1.graduate = cJSON_GetObjectItem(item1, "graduate");
	// 获取item1中数组数据
	cJSON *skill = cJSON_GetObjectItem(item1, "skill");
	int skill_size = cJSON_GetArraySize(skill);
	for (int i = 0; i < skill_size; i++) {
		stu1.skill[i] = cJSON_GetArrayItem(skill, i);
	}

	// 获取item1中的嵌套json数据
	stu1.address = cJSON_GetObjectItem(item1, "address");
	stu1.address_country = cJSON_GetObjectItem(stu1.address, "country");
	stu1.address_province = cJSON_GetObjectItem(stu1.address, "province");

	// 打印数据
	show(stu1);

	free(json_str);
	return 0;
}

/**
 * @brief  读取文件内容到json_str
 * @param  filepath 文件路径
 * @param  json_str 用指针带出json_str
 * @return int 成功返回0，失败返回-1
 */
int import_file(const char *filepath, char *json_str)
{
	FILE *fp = fopen(filepath, "r");
	if (fp == NULL) {
		printf("open error\n");
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	fread(json_str, len, sizeof(char), fp);

	fclose(fp);
	return 0;
}

/**
 * @brief  打印Student结构体数据
 * @param  stu 学生结构体
 * @return void
 */
void show(Student stu)
{
	printf("stu.id               ▏%s\n", stu.id->valuestring);
	printf("stu.name             ▏%s\n", stu.name->valuestring);
	printf("stu.class            ▏%s\n", stu.class->valuestring);
	printf("stu.depart           ▏%s\n", stu.depart->valuestring);
	printf("stu.age              ▏%d\n", stu.age->valueint);
	printf("stu.score            ▏%.2f\n", stu.score->valuedouble);
	if (stu.graduate->valueint) {
		printf("stu.graduate         ▏true\n");
	} else {
		printf("stu.graduate         ▏false\n");
	}
	printf("stu.skill            ▏[%s,%s,%s]\n", stu.skill[0]->valuestring,
	       stu.skill[1]->valuestring, stu.skill[2]->valuestring);
	printf("stu.address_country  ▏%s\n", stu.address_country->valuestring);
	printf("stu.address_province ▏%s\n", stu.address_province->valuestring);
}