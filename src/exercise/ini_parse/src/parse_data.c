/**
 * Author:   KeeneChen
 * DateTime: 2022.07.09-10:47:14
 * Description: 解析ini文件
 */

#include <stdio.h>
#include <stdlib.h>
#include "iniparser/dictionary.h"
#include "iniparser/iniparser.h"

int main(void)
{
	// 加载ini文件
	const char *filepath = "../source/stu.ini";
	dictionary *dict = iniparser_load(filepath);

	// 获取片段
	int len = iniparser_getnsec(dict);
	const char *name = iniparser_getsecname(dict, 0);
	printf("%d %s\n", len, name);
	printf("%s\n", iniparser_getstring(dict, "stu1:id", "false"));
	printf("%f\n", iniparser_getdouble(dict, "stu1:scores", 1));

	// 遍历所有键值对
	if (len) {
		for (int i = 0; i < len; i++) {
			printf("[%s]\n", iniparser_getsecname(dict, i));

			int n = iniparser_getsecnkeys(dict,
						      iniparser_getsecname(dict, i));
			const char *str = iniparser_getsecname(dict, i);
			const char **keys =
				(const char **)malloc(n * sizeof(char *));

			iniparser_getseckeys(dict, str, keys);
			const char **temp = keys;
			for (int j = 0; j < n; j++) {
				printf("%s=%s\n", *temp,
				       iniparser_getstring(dict, *temp, 0));
				temp++;
			}
			printf("\n");
			free(keys);
		}
	} else {
		printf("This file has no section!\n");
		return -1;
	}

	// 释放资源
	iniparser_freedict(dict);

	return 0;
}