#include <stdio.h>
#include "yyjson/yyjson.h"

typedef struct tagStudent {
	const char *id;
	const char *name;
	const char *class;
	const char *depart;
	unsigned int age;
	double score;
	bool graduate;
	const char *skill[3];
	const char *address;
	const char *address_country;
	const char *address_province;
} Student;

void show(Student stu);

int main(void)
{
	// 读取 JSON 文件，允许注释和尾随逗号
	yyjson_read_flag flg = YYJSON_READ_ALLOW_COMMENTS |
			       YYJSON_READ_ALLOW_TRAILING_COMMAS;
	yyjson_read_err err;
	const char *filepath = "../source/export.json";
	yyjson_doc *doc = yyjson_read_file(filepath, flg, NULL, &err);

	// 解析json数据
	Student stu;
	yyjson_val *root = yyjson_doc_get_root(doc);
	yyjson_val *student = yyjson_obj_get(root, "student");
	yyjson_val *item = yyjson_arr_get(student, 0);
	stu.id = yyjson_get_str(yyjson_obj_get(item, "id"));
	stu.name = yyjson_get_str(yyjson_obj_get(item, "name"));
	stu.class = yyjson_get_str(yyjson_obj_get(item, "class"));
	stu.depart = yyjson_get_str(yyjson_obj_get(item, "depart"));
	stu.age = yyjson_get_uint(yyjson_obj_get(item, "age"));
	stu.score = yyjson_get_real(yyjson_obj_get(item, "score"));
	stu.graduate = yyjson_get_bool(yyjson_obj_get(item, "graduate"));
	yyjson_val *address = yyjson_obj_get(item, "address");
	stu.address = yyjson_get_str(yyjson_obj_get(address, "address"));
	stu.address_country = yyjson_get_str(yyjson_obj_get(address, "country"));
	stu.address_province = yyjson_get_str(yyjson_obj_get(address, "province"));
	yyjson_val *skill = yyjson_obj_get(item, "skill");
	int skill_size = yyjson_arr_size(skill);
	for (int i = 0; i < skill_size; i++) {
		stu.skill[i] = yyjson_get_str(yyjson_arr_get(skill, i));
	}

	// 打印解析结果
	show(stu);

	// 释放资源
	yyjson_doc_free(doc);

	return 0;
}

/**
 * @brief  打印Student结构体数据
 * @param  stu 学生结构体
 * @return void
 */
void show(Student stu)
{
	printf("stu.id               ▏%s\n", stu.id);
	printf("stu.name             ▏%s\n", stu.name);
	printf("stu.class            ▏%s\n", stu.class);
	printf("stu.depart           ▏%s\n", stu.depart);
	printf("stu.age              ▏%d\n", stu.age);
	printf("stu.skill            ▏[%s,%s,%s]\n", stu.skill[0], stu.skill[1],
	       stu.skill[2]);
	printf("stu.address_country  ▏%s\n", stu.address_country);
	printf("stu.address_province ▏%s\n", stu.address_province);
	printf("stu.score            ▏%.2f\n", stu.score);
	if (stu.graduate) {
		printf("stu.graduate         ▏true\n");
	} else {
		printf("stu.graduate         ▏false\n");
	}
}