#include <stdio.h>
#include "yyjson/yyjson.h"

int main(void)
{
	// 创建可变文档
	yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL);
	yyjson_mut_val *root = yyjson_mut_obj(doc);
	yyjson_mut_doc_set_root(doc, root);

	// 将root["student"]设置为数组
	yyjson_mut_val *student = yyjson_mut_arr(doc);
	yyjson_mut_obj_add_val(doc, root, "student", student);

	// 将student[0]设置为对象
	yyjson_mut_val *item = yyjson_mut_obj(doc);
	yyjson_mut_arr_add_val(student, item);
	// 设置student[0]的属性
	yyjson_mut_obj_add_str(doc, item, "id", "3320190993209");
	yyjson_mut_obj_add_str(doc, item, "name", "zhangsan");
	yyjson_mut_obj_add_str(doc, item, "class", "IOT-19-2");
	yyjson_mut_obj_add_str(doc, item, "depart", "计算机与软件工程学院");
	yyjson_mut_obj_add_uint(doc, item, "age", 18);

	// 将student[0]["address"]设置为对象
	yyjson_mut_val *address = yyjson_mut_obj(doc);
	yyjson_mut_obj_add_val(doc, item, "address", address);
	// 设置student[0]["address"]的属性
	yyjson_mut_obj_add_str(doc, address, "country", "China");
	yyjson_mut_obj_add_str(doc, address, "province", "Szechwan");

	// 将student[0]["skill"]设置为数组
	char *skill_arr[3] = { "C", "Java", "JavaScript" };
	yyjson_mut_val *skill = yyjson_mut_arr_with_str(doc, skill_arr, 3);
	yyjson_mut_obj_add_val(doc, item, "skill", skill);

	// 将student[0]["skill"][0]设置为字符串
	// yyjson_mut_arr_add_str(doc, skill, "C");
	// yyjson_mut_arr_add_str(doc, skill, "Java");
	// yyjson_mut_arr_add_str(doc, skill, "JavaScript");

	// 设置student[0]的属性
	yyjson_mut_obj_add_real(doc, item, "score", 100.2);
	yyjson_mut_obj_add_false(doc, item, "graduate");

	// 写入字符串
	char *json = yyjson_mut_write(doc, YYJSON_WRITE_PRETTY, NULL);
	if (json) {
		printf("%s\n", json);
	}

	// 写入文件
	const char *filepath = "../source/export.json";
	bool result = yyjson_mut_write_file(filepath, doc, YYJSON_WRITE_PRETTY, NULL,
					    NULL);
	if (result) {
		printf("Write succeeded\n");
	} else {
		printf("Write failed\n");
	}

	// 释放所有内存
	yyjson_mut_doc_free(doc);
	free(json);

	return 0;
}