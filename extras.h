#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"
#include "node.h"

// function prototypes
void sort(NODE*);
void count(NODE*);
void display_stats(NODE*);
int* strdate_to_intdate(char[], int[]);
void stat_age(int[], NODE*);
void stat_gender(int[], NODE*);
int compare_str_date(char[], char[]);

#endif
