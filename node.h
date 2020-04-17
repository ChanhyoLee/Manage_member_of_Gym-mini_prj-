#ifndef _NODE_H_
#define _NODE_H_

#include "record.h"

typedef struct NODE{
	Record member;
	struct NODE* link;
} NODE;

#endif
