#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "extras.h"

// Function: add_a_record()
// Input: NODE* head - No empty Space
// Output: none
// - Leave a brief information about the function
// choose mode, get input, check input, assign input -> 4steps
void add_a_record(NODE* head){
	Record temp;
	NODE *newNode = malloc(sizeof(NODE)); //new space for record
	char mode;
	printf("Choose input method (K-keyboard, D-data file): ");
	scanf("%c",&mode);
	getchar(); // Buffer clear

	if(mode=='K'){
		printf("\nPlease input member's name: ");
		scanf("%s",temp.name);
		getchar(); // Buffer clear

		printf("\nPlease input member's birthday");
		printf("\nDay.Month.Year: ");
		scanf("%s",temp.birthday);
		getchar(); // Buffer clear

		printf("\nPlease input member's gender(F-female/M-male): ");
		scanf("%c",&temp.gender);
		while((temp.gender != 'M') && (temp.gender != 'F')){ // Check miss input
			printf("\nWrong input! Please reinput: ");
			getchar(); // Buffer clear
			scanf("%c",&temp.gender);		
		}

		printf("\nPlease input member's register day");
		printf("\nDay.Month.Year: ");
		scanf("%s",temp.register_day);
		getchar(); // Buffer clear

		printf("\nPlease input member's end date");
		printf("\nDay.Month.Year: ");
		scanf("%s",temp.end_date);
		getchar(); // Buffer clear
	}
	else{
		char file_name[20];
		printf("Please input the name of data file: "); // get name of a data file
		scanf("%s",file_name);
		getchar(); // Buffer clear
		FILE *mem_f = NULL;

		if(exists(file_name)==0){ //Check file_name exists
			printf("\nFile doesn't exist..\n");
			return;
		}

		mem_f = fopen(file_name, "r"); // Open data file

		NODE *newNode = malloc(sizeof(NODE)); //new space for record
		fgets(temp.name,20,mem_f);
		temp.name[strlen(temp.name) - 1] = '\0';
		fgets(temp.birthday,12,mem_f);
		temp.birthday[strlen(temp.birthday) - 1] = '\0';
		temp.gender=fgetc(mem_f);
		fgetc(mem_f);
		fgets(temp.register_day,12,mem_f);
		temp.register_day[strlen(temp.register_day) - 1] = '\0';
		fgets(temp.end_date,12,mem_f);
		temp.end_date[strlen(temp.end_date) - 1] = '\0';
		if(feof(mem_f))	{
			free(newNode);
		}
	}
	

	if(check_date(temp.birthday)==0 || check_date(temp.register_day)==0 || check_date(temp.end_date)==0){ // Validation of date
		printf("\nInput fail! One of your date is wrong!\n"); // If wrong
	}
	else{ // All date right
		newNode->link = head->link;
		newNode->member = temp;
		head->link = newNode; // Add to head


		printf("\nInput Success!\n"); // For checking input right
		printf("%s, %s, %c, %s, %s\n", newNode->member.name,newNode->member.birthday,newNode->member.gender,newNode->member.register_day, newNode->member.end_date);
	}
}

// Function: print_all_records()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// print all elements from head to tail(NULL)
void print_all_records(NODE* head){
	if(head->link == NULL){ // If there is not any record
		printf("\nThere is not any member! Input first!\n");
	}
	else{
		printf("________________________________________________________\n");
		printf("%10s, %10s, %6s, %12s, %10s\n","name","birthday","gender","register_day","end_date");
		printf("--------------------------------------------------------\n");
		for(NODE* t=head->link; t!=NULL; t=t->link){
			printf("%10s, %10s, %6c, %12s, %10s\n",t->member.name, t->member.birthday, t->member.gender, t->member.register_day, t->member.end_date);
		}
		printf("--------------------------------------------------------\n");
	}
}

// Function: change_memberdata()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// Change data of a record
void change_memberdata(NODE* head){
	char name[20];
	printf("Please input name to find: ");
	scanf("%s",name);
	getchar(); // Buffer clear

	for(NODE* t=head->link; t!=NULL; t=t->link){
		if(!strcmp(t->member.name, name)){
			printf("\n%s, %s, %c, %s, %s\n",t->member.name, t->member.birthday, t->member.gender, t->member.register_day, t->member.end_date);
			char data_type;
			printf("\nN-name, B-birthday, G-gender, R-register date, E-end date, S-skip\n");
			printf("Choose data type to Modify: ");
			scanf("%c",&data_type);
			getchar(); // Buffer clear

			if(data_type == 'N'){
				char change_name[20];
				printf("Input name to change: ");
				scanf("%s",change_name);
				getchar(); // Buffer clear
				strcpy(t->member.name, change_name);
				printf("\nInput Success! %s\n",t->member.name);
				continue;
			}
			else if(data_type == 'B'){
				char change_birthday[12];
				printf("Input birthday to change: ");
				scanf("%s",change_birthday);
				getchar(); // Buffer clear
				strcpy(t->member.birthday, change_birthday);
				printf("\nInput Success! %s\n",t->member.birthday);
				continue;
			}
			else if(data_type == 'G'){
				char change_gender;
				printf("Input gender to change: ");
				scanf("%c",&change_gender);
				getchar(); // Buffer clear
				t->member.gender = change_gender;
				printf("\nInput Success! %c\n",t->member.gender);
				continue;
			}
			else if(data_type == 'R'){
				char change_regi_day[12];
				printf("Input register date to change: ");
				scanf("%c",change_regi_day);
				getchar(); // Buffer clear
				strcpy(t->member.register_day, change_regi_day);
				printf("\nInput Success! %s\n",t->member.register_day);
				continue;
			}
			else if(data_type == 'E'){
				char change_end_day[12];
				printf("Input end date to change: ");
				scanf("%s",change_end_day);
				getchar(); // Buffer clear
				strcpy(t->member.end_date, change_end_day);
				printf("\nInput Success! %s\n",t->member.birthday);
				continue;
			}
			else if(data_type == 'S'){
				printf("You choose to skip!\n");
				continue;
			}
			else{
				printf("Wrong input! Go to main..\n");
				break;
			}
		}
	}
}
// Function: add_end_date()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// add end date one month all records or records corresponding name
void add_end_date(NODE* head){
	char name[20];
	int n =0;
	printf("Please input name to add one month(* to add all): ");
	scanf("%s",name);
	getchar(); // Buffer clear

	for(NODE* t=head->link; t!=NULL; t=t->link){
		if(!strcmp(name,"*")){
			int date_arr[3];
			strdate_to_intdate(t->member.end_date,date_arr);
			date_arr[1] +=1;
			if(date_arr[1] >12){
				date_arr[1] -=12;
				date_arr[2] +=1;
			}
			sprintf(t->member.end_date,"%02d.%02d.%d",date_arr[0],date_arr[1],date_arr[2]);
			printf("Success!\n");
			n++;
		}
		else if(!strcmp(t->member.name, name)){
			printf("\n%s, %s, %c, %s, %s\n",t->member.name, t->member.birthday, t->member.gender, t->member.register_day, t->member.end_date);
			char choose;
			printf("Is He/She right?(Y/N): ");
			scanf("%c",&choose);
			getchar(); // Buffer Clear
			if(choose == 'N')
				continue;
			int date_arr[3];
			strdate_to_intdate(t->member.end_date,date_arr);
			date_arr[1] +=1;
			if(date_arr[1] >12){
				date_arr[1] -=12;
				date_arr[2] +=1;
			}
			sprintf(t->member.end_date,"%02d.%02d.%02d",date_arr[0],date_arr[1],date_arr[2]);
			printf("Success!\n");
			n++;	
		}		
	}
	if(n == 0)
		printf("Fail!\n");
	return;
}

// Function: delete_member()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// get name, find name or delete all, confirm, delete -> 4 steps
void delete_member(NODE* head){
	if(head->link == NULL){ // If there is not any record
		printf("\nThere is not any member! Input first!\n");
		return;
	}
	int count=0;
	char name[20];
	char Y_N = 'N';
	printf("Please input name to delete\n(If you want to delete all members, press *): ");
	scanf("%s",name);
	getchar(); // Buffer clear
	if(!strcmp(name,"*")){ // Delete All
		while(head->link !=NULL){ 
			NODE *temp = malloc(sizeof(NODE));
			temp = head->link;
			head->link = temp->link;
			free(temp);
		}
		printf("All members Deleted Success!\n");
	}

	else{
		NODE* t=head;
		while(t->link!=NULL){
			if(!strcmp(t->link->member.name, name)){
				printf("\n%s, %s, %c, %s, %s\n",t->link->member.name, t->link->member.birthday, t->link->member.gender, t->link->member.register_day, t->link->member.end_date);

				printf("Do you really want to delete?\nTo continue .. press Y: "); // Confirm
				scanf("%c",&Y_N);
				getchar();  // Buffer clear

				if(Y_N == 'Y'){ // Delete a record
					NODE *temp = malloc(sizeof(NODE));
					temp=t->link;
					t->link = t->link->link;
					free(temp);
					printf("Delete Success!\n");
					if(t->link==NULL)
						break;
				}
				else {
					printf("You choose to keep\n"); // Cancel
					t=t->link;
				}
			}
			else{
				t = t->link;
			}
		}
	}
}

// Function: end_member()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// find members whose contract expired(Pass the end date)
void end_member(NODE* head){
	int count=0;
	struct tm* t; // Use time.h
	const time_t current = time(NULL);	
	t = localtime(&current); // today
	int crr_date[3];

	crr_date[0]=t->tm_mday;
	crr_date[1]=t->tm_mon+1;
	crr_date[2]=t->tm_year+1900;

	for(NODE* t=head->link; t!=NULL; t=t->link){
		if(compare_date(crr_date,t->member.end_date)){ // Declare new function named Compare date
			printf("\n%s, %s, %c, %s, %s\n",t->member.name, t->member.birthday, t->member.gender, t->member.register_day, t->member.end_date);
			count ++; // Check number of members
		}
	}
	if(count !=0){
		printf("%d result found!\n",count);
	}
	else{
		printf("No member contract expired!\n");
	}

}
// Function: show_member()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// get name, find name, show it to moniter
void show_member(NODE* head){
	char name[20];
	int count=0;
	printf("Please input name to find: "); //get name
	scanf("%s",name);
	getchar();

	for(NODE* t=head->link; t!=NULL; t=t->link){
		if(!strcmp(t->member.name, name)){ //find name
			printf("\n%s, %s, %c, %s, %s\n",t->member.name, t->member.birthday, t->member.gender, t->member.register_day, t->member.end_date); //show to moniter
			count ++;
		}
	}
	if(count !=0){
		printf("%d result found!\n\n",count);
	}
	else
		printf("There isn't member named %s\n",name);
}


// Function: load_member_file()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// Clear memory, get name of a data file, open and read, get data, check data, assign data -> 6 steps
void load_member_file(NODE* head){

	while(head->link !=NULL){ // Clear memory
			NODE *temp = malloc(sizeof(NODE));
			temp = head->link;
			head->link = temp->link;
			free(temp);
		}

	char file_name[20];
	printf("Please input the name of data file: "); // get name of a data file
	scanf("%s",file_name);
	getchar(); // Buffer clear
	FILE *mem_f = NULL;

	if(exists(file_name)==0){ //Check file_name exists
		printf("\nFile doesn't exist..\n");
		return;
	}		

	mem_f = fopen(file_name, "r"); // Open data file
	Record temp;
	
	if (mem_f==NULL){
		printf("File open Error! %s does not exist!", file_name); 
		//If there is not a data file as named file_name
	}
	else{
		while(1){
		NODE *newNode = malloc(sizeof(NODE)); //new space for record
		fgets(temp.name,20,mem_f);
		temp.name[strlen(temp.name) - 1] = '\0'; //Change \n(Enter) to \0(NULL)

		fgets(temp.birthday,12,mem_f);
		temp.birthday[strlen(temp.birthday) - 1] = '\0'; //Change \n(Enter) to \0(NULL)

		temp.gender=fgetc(mem_f);
		fgetc(mem_f);

		fgets(temp.register_day,12,mem_f);
		temp.register_day[strlen(temp.register_day) - 1] = '\0'; //Change \n(Enter) to \0(NULL)

		fgets(temp.end_date,12,mem_f);
		temp.end_date[strlen(temp.end_date) - 1] = '\0'; //Change \n(Enter) to \0(NULL)

		if(feof(mem_f))	{
			free(newNode);
			break;
		}
		if(check_date(temp.birthday)==0 || check_date(temp.register_day)==0 || check_date(temp.end_date)==0){ //Same process Below with 1. Add a new member
			printf("\nInput fail! One of your date is wrong!\n");
			continue;
		}

		newNode->link = head->link;
		newNode->member = temp;
		head->link = newNode;


		printf("\nInput Success!\n");
		printf("%s, %s, %c, %s, %s\n", newNode->member.name,newNode->member.birthday,newNode->member.gender,newNode->member.register_day, newNode->member.end_date);
		}
	}
	fclose(mem_f);
}
// Function: save_as_file()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// get name of a data file, open and overwrite(Or just Write for new data file) -> 2steps
void save_as_file(NODE* head){
	char file_name[20];
	printf("Please input the name of data file: "); // get file name to save as
	scanf("%s",file_name);
	getchar(); // Buffer clear

	FILE *mem_f = fopen(file_name , "w"); //If does not exist, make new file. Else Overwrite

	if(head->link == NULL){
		printf("\nThere is not any member! Input first!\n");
	}
	else{
		for(NODE* t=head->link; t!=NULL; t=t->link){ //Put string to data file
			fputs(t->member.name,mem_f);
			fputs("\n",mem_f);
			fputs(t->member.birthday,mem_f);
			fputs("\n",mem_f);
			fputc(t->member.gender,mem_f);
			fputs("\n",mem_f);
			fputs(t->member.register_day,mem_f);
			fputs("\n",mem_f);
			fputs(t->member.end_date,mem_f);
			fputs("\n",mem_f);
			printf("\n Input Success!\n");
		}
	}
}
// Function: save_as_report()
// Input: NODE* head; No empty space 
// Output: none
// - Leave a brief information about the function
// get name of a data file, open and overwrite(Or just Write for new data file) -> 2steps (Just Add some factor of Design)
void save_as_report(NODE* head){
	char file_name[20];
	printf("Please input the name of data file: ");
	scanf("%s",file_name);
	getchar(); // Buffer clear

	FILE *mem_f = fopen(file_name , "w");

	if(head->link == NULL){
		printf("\nThere is not any member! Input first!\n");
	}
	else{
		fputs("______________________________________________\n",mem_f);
		fputs("name, birthday, gender, register_day, end_date\n",mem_f);
		fputs("----------------------------------------------\n",mem_f);
		for(NODE* t=head->link; t!=NULL; t=t->link){
			fputs(t->member.name,mem_f); fputs(", ",mem_f);	
			fputs(t->member.birthday,mem_f); fputs(", ",mem_f);
			fputc(t->member.gender,mem_f); fputs(", ",mem_f);
			fputs(t->member.register_day,mem_f); fputs(", ",mem_f);
			fputs(t->member.end_date,mem_f); fputs("\n",mem_f);
			printf("\n Input Success!\n");
		}
		fputs("----------------------------------------------\n",mem_f);
	}
}

// TODO: Add more functions to fulfill the requirements

// Function: check_date()
// Input: date - array of char
// Output: integer(If ok: 0, else: 1)
// - Leave a brief information about the function
// use atoi(ASCII to integer), 0<day<31, 0<month<12, year>0
// Validation of date
int check_date(char date[]){
	char temp_date[5];
	for(int i=0; i<5; i++){
		temp_date[i] = '\0';
	}
	

	temp_date[0]=date[0];
	temp_date[1]=date[1];
	int day = atoi(temp_date);

	temp_date[0]=date[3];
	temp_date[1]=date[4];
	int month = atoi(temp_date);

	temp_date[0]=date[6];
	temp_date[1]=date[7];
	temp_date[2]=date[8];
	temp_date[3]=date[9];
	int year = atoi(temp_date);
	int is_right=1;

	if(day<0){
		printf("\nDay must be bigger than 0\n");
		is_right = 0;
	}
	else if(day>31){
		printf("\nDay must be smaller than 31\n");
		is_right = 0;
	}
	
	if(month<0){
		printf("\nMonth must be bigger than 0\n");
		is_right = 0;
	}
	else if(month>12){
		printf("\nMonth must be smaller than 13\n");
		is_right = 0;
	}
	
	if(year<0){
		printf("\nYear must be bigger than 0\n");
		is_right = 0;
	}

	return is_right;
}
// Function: compare_date()
// Input: current date - array of integer, date - array of char
// Output: integer(If today>date: 1, else 0)
// - Leave a brief information about the function
// use atoi(ASCII to integer), Compare order of year-month(if year same)-date(if month same)

int compare_date(int current[], char date[]){
	char temp_date[5];
	for(int i=0; i<5; i++){
		temp_date[i] = '\0';
	}
	int is_right=1;

	temp_date[0]=date[0];
	temp_date[1]=date[1];
	int day = atoi(temp_date);

	temp_date[0]=date[3];
	temp_date[1]=date[4];
	int month = atoi(temp_date);

	temp_date[0]=date[6];
	temp_date[1]=date[7];
	temp_date[2]=date[8];
	temp_date[3]=date[9];
	int year = atoi(temp_date);

	if(current[2] > year){
		return 1;
	}
		
	else if( current[2] == year && current[1] > month){
		return 1;
	}
		
	else if(current[2] == year && current[1] == month && current[0] > day){
		return 1;
	}
	else
		return 0;
}

// Function: exists()
// Input: string-filename
// Output: integer(If file exists: 1, else 0)
// - Leave a brief information about the function
// Check presence of file - To avoid unexpected exit
int exists(const char *fname){ //Check file_name exists
  FILE *file;
  if ((file = fopen(fname, "r"))){
    fclose(file);
    return 1;
  }
  return 0;
}

