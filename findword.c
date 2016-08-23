#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 15
//char *g_mystring = "bbbwxcwhereIamlinktomissingohxhfewgm";
char *g_mystring = "bbbwxcwherelinktomissingoh";

int find(char *str)
{
	char *dict[] = {"I", "here", "where", "he", "her", "here", "am", "relink", "sing", "link", "ink", "to", "miss","missing", "go", "tom", "ssh", "few"};
	int i;

	for(i = 0; i < sizeof(dict)/sizeof(*dict); i++) {
		if(strcmp(str, dict[i]) == 0) {
			printf("Word: %s\n", str);
			return 0;
		}
	}
	return -1;
}

int method_1(char *str)	//method 1
{
	int i, j;
	int len = strlen(str);
	char *p;
	char temp[MAX_LEN + 1];
	int count = 0;

	for(i = 1; i <= len; i++) {
		p = str + i - 1;

		for(j = 1; j <= MAX_LEN && (i + j - 1 <= len); j++) {
			memset(temp, 0, sizeof(temp));
			memcpy(temp, p, j);
			if(0 == find(temp))
				count++;
		}
	}

	printf("\nTotal Word Count: %d\n", count);
	return 0;
}

//char *g_mystring = "bbbwxcwherelinktomissingoh";
int method_2(char *str)	//method 2
{
	//printf("\nTotal Word Count: %d\n", count);

	static xx = 0;
	int a;
	int i, j;
	int len = strlen(str);
	//char temp_buf[100];
	char temp_buf[100];

	if(find(str) == 0)
		return 0;

	//for(a = 0; a < ++xx; a++)
		//printf("%s", "  ");

	//for(i = 1; i+6 <= len; i++) {
	for(i = 1; i <= len; i++) 
	{
		memset(temp_buf, 0, sizeof(temp_buf));
		memcpy(temp_buf, str, i);
		//memcpy(temp_buf, str+6, i);

		printf("%4d %s\n", i, temp_buf);

		if(0 == find(temp_buf)) {
			memset(temp_buf, 0, sizeof(temp_buf));
			memcpy(temp_buf, str+i, len-i);
			return method_2(temp_buf);
			//return 0;
		}
	}
	return -1;
}

void test_atoi(char *str)
{
	static const unsigned ver_year_offset = 6;
	static const unsigned ver_week_offset = 11;
	unsigned yr, wk;

	printf("%s\n", str);
	yr = atoi(str + ver_year_offset);
	wk = atoi(str + ver_week_offset);

	printf("yr: %d\n", yr);
	printf("wk: %d\n\n", wk);

	printf("atoi(t210) = %d\n\n", atoi("t210"));
}

int main()
{
	//method_1(g_mystring);
	//method_2(g_mystring);
	//method_2("sfwherelinktomissmissmisswherelinkff");
	
	test_atoi("24.00.2015.42-t210-841b3a99");
	test_atoi("15.42-t210-841b3a99");

	return 0;
}
