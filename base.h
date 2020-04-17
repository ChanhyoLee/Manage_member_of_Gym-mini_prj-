#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"
#include "node.h"

// function prototypes
void add_a_record(NODE*);
void print_all_records(NODE*);
void change_memberdata(NODE*);
void delete_member(NODE*);
void end_member(NODE*);
void show_member(NODE*);
void load_member_file(NODE*);
void save_as_file(NODE*);
void save_as_report(NODE*);
int check_date(char[]);
int compare_date(int[], char[]);
int exists(const char*);

#endif
