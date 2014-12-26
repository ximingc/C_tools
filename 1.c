#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********
My questions:
  1. how about enum values?
  2. how to use "%*s", "%-10d" ?
  3. how does the "struct xxx" work without explicit defination?
  4. what is the difference between  *(int *)(p_data) and  *(int *)(*p_data)
  5. strtok
  6. srand() rand()
  7, passing a pointer to subfunction may modify this pointer? No!
************/

enum AA {
	aa = 0,
	bb,
	cc,
	dd = 1,
	ee,
};

struct xxx;

static int get_xxx_value(struct xxx *xxx)
{
	return 0xAA;
}

void make_pointer_null(int *p)
{
    printf("\tfist:%p\n", p);
    p = NULL;
    printf("\tthen:%p\n", p);
}

int main()
{
	int data[1] = { 0xDEAD };
	int *p_data = data;
	char body[20] = "abcd\nebf\nsss\n";
	char *p = NULL;
    int i;
    int *mypointer = (int*)0xAABBCCDD;

	// question 1
	printf("%d  %d  %d  %d  %d\n", aa, bb, cc, dd, ee);

	// question 2
	printf("%*s %s\n", 50, "this is a dog", "END");
	printf("%-*s %s\n", 50, "this is a dog", "END");

	printf("%10d %s\n", 5, "END");
	printf("%-10d %s\n", 5, "END");

	printf("%10lu %s\n", 5LU, "END");
	printf("%-10lu %s\n", 5LU, "END");

	// question 3
	printf("xxx return val: 0X%0X\n", 
			get_xxx_value((struct xxx *)NULL));

	//question 4
	printf("*(int *)(p_data) :0X%X\n", *(int *)(p_data));
	//printf("*(int *)(*p_data) :0X%X\n", *(int *)(*p_data));
		
	//question 5
	p = strtok(body, "\n");
	do {
		if(p) printf("%s\n", p);
		p = strtok(NULL, "\n");
	} while (p);

    //question 6
    srand((int)time(NULL)); //seed
    for(i = 0; i < 100; i++)
    printf("random data: %d\n", rand());

    //question 7
    printf("mypointer:%p\n", mypointer);
    make_pointer_null(mypointer);
    printf("mypointer:%p after subfunction.\n", mypointer);

	return 0;
}
