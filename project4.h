#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum STATUS {
	none,
	called,
	waiting
};

typedef struct Group {
	char* group_name;
	int group_size;
	enum STATUS status;
	struct Group* next;
} Group, *GroupPtr;

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;
