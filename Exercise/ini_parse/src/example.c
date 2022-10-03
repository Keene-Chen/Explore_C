#include <stdio.h>
#include "iniparser/iniparser.h"
#include "iniparser/dictionary.h"

int main(void)
{
	const char *filepath = "../source/test.ini";

	dictionary *inip = iniparser_load(filepath);
	if (!inip) {
		printf("iniparser_load failure\n");
		return -1;
	}

	int n = iniparser_getnsec(inip);
	if (n) {
		for (int i = 0; i < n; i++) {
			printf("%s\n", iniparser_getsecname(inip, i));
			int i1 = iniparser_getsecnkeys(
				inip, iniparser_getsecname(inip, i));
			char *keys[i1];
			const char *str = iniparser_getsecname(inip, i);
			iniparser_getseckeys(inip, str, keys);
			char **ptr = keys;
			for (int j = 0; j < i1; j++) {
				printf("%s\n", *ptr);
				ptr++;
			}
		}
	} else {
		printf("This file has no section!\n");
		return -1;
	}

	iniparser_set(inip, "ipaddrpool:start", "192");
	iniparser_set(inip, "ipaddrpool:end", "198");
	iniparser_unset(inip, "opt:dns1");

	FILE *fp = fopen(filepath, "w");
	iniparser_dump_ini(inip, fp);
	iniparser_freedict(inip);

	fclose(fp);

	return 0;
}