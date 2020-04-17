#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"
#include "node.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], NODE*);
void display_menu();

// main function
int main(){

	NODE* head = malloc(sizeof(NODE));
	head->link = NULL;
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, head);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], NODE* head){

	// TODO: Modify this function as you need

	if(!strcmp(input, "1"))
		add_a_record(head);
	else if(!strcmp(input, "2"))
		print_all_records(head);
	else if(!strcmp(input, "3"))
		change_memberdata(head);	
	else if(!strcmp(input, "4"))
		delete_member(head);	
	else if(!strcmp(input, "5"))
		end_member(head);	
	else if(!strcmp(input, "6"))
		show_member(head);
	else if(!strcmp(input, "7"))
		load_member_file(head);	
	else if(!strcmp(input, "8"))
		save_as_file(head);
	else if(!strcmp(input, "9"))
		save_as_report(head);
	else if(!strcmp(input, "10"))
		sort(head);
	else if(!strcmp(input, "11"))
		count(head);
	else if(!strcmp(input, "12"))
		display_stats(head);
	else if(!strcmp(input, "99"))
		printf("\nTerminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	printf("******************************\n");
	printf(" Membership management system \n");
	printf("******************************\n");
	printf(" 1. Add a new member\n");
	printf(" 2. Print all members\n");
	printf(" 3. Change datas\n");
	printf(" 4. Delete a member\n");
	printf(" 5. Find member whose contract expired\n");
	printf(" 6. Show member data\n");
	printf(" 7. Load a new data file\n");
	printf(" 8. Save to a data file\n");
	printf(" 9. Save as Report\n");
	printf(" 10. Sort\n");
	printf(" 11. Count number of members\n");
	printf(" 12. Show Statistics\n");
	printf(" 99. Quit\n");
}
