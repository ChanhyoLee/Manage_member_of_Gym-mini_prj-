#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "extras.h"

// Function: defragment()
// Input: none
// Output: none
// - Leave a brief information about the function
// I choose Linked List for save records so i don't need to defrag
/*int defragment(NODE* head){

}*/

// Function: sort()
// Input: NODE* head; No empty space
// Output: none
// - Leave a brief information about the function
// Sort all Records by Name, Age, Period
void sort(NODE* head){
	char sort_type;
	printf("\nName-N,Age-A,Period-P\n");
	printf("Choose standard of sorting: ");
	scanf("%c",&sort_type);
	getchar(); // Buffer Clear

	if(sort_type == 'N'){
		for(NODE* t=head; t->link!=NULL; t=t->link){//First element to last element
			for(NODE* k=t->link; k->link!=NULL; k=k->link){//Next element of t to last element
				if(strcmp(t->link->member.name,k->link->member.name)>0){
					Record temp_member; //swap two member data
					temp_member = t->link->member;
					t->link->member = k->link->member;
					k->link->member = temp_member;
				}
			}
		}
		printf("\nSorted by Name success!\n");
	}
	else if(sort_type == 'A'){
		for(NODE* t=head; t->link!=NULL; t=t->link){//First element to last element
			for(NODE* k=t->link; k->link!=NULL; k=k->link){//Next element of t to last element
				if(compare_str_date(t->link->member.birthday,k->link->member.birthday)>0){
					Record temp_member; //swap two member data
					temp_member = t->link->member;
					t->link->member = k->link->member;
					k->link->member = temp_member;
				}
			}
		}
		printf("\nSorted by Age success!\n");
	}
	else if(sort_type == 'P'){
		for(NODE* t=head; t->link!=NULL; t=t->link){//First element to last element
			for(NODE* k=t->link; k->link!=NULL; k=k->link){//Next element of t to last element
				if(compare_str_date(t->link->member.register_day,k->link->member.register_day)>0){
					Record temp_member; //swap two member data
					temp_member = t->link->member;
					t->link->member = k->link->member;
					k->link->member = temp_member;
				}
			}
		}
		printf("\nSorted by Period success!\n");
	}
	else{
		printf("\nWrong input! Go to main..\n");
		return;
	}
}

// Function: display_stats()
// Input: NODE* head; No empty space
// Output: none
// - Leave a brief information about the function
// Display Statistics of Age, Gender, Used Term
void display_stats(NODE* head){
	char display_type;
	printf("\nAge-A,Gender-G\n");
	printf("Choose type to display: ");
	scanf("%c",&display_type);
	getchar(); // Buffer Clear

	if(display_type == 'A'){
		int count_age[4] = {0,}; //10s, 20s, 30s, Same or over than 40
		stat_age(count_age,head);
		return;
	}
	else if(display_type == 'G'){
		int count_gender[2] = {0,}; //10s, 20s, 30s, Same or over than 40
		stat_gender(count_gender,head);
		return;
	}
	else{
		printf("\nWrong input! Go to main..\n");
		return;
	}
}


// TODO: Add more functions to fulfill the optional requirements

// Function: count()
// Input: NODE* head; No empty space
// Output: none
// - Leave a brief information about the function
// Count number of members in memory now
void count(NODE* head){
	int n=0;
	for(NODE* t=head->link; t!=NULL; t=t->link)
			n++;
	printf("\nThe number of Records are %d!\n",n);
}

// Function: strdate_to_intdate()
// Input: array of date(string), empty array of date(integer)
// Output: array of date(integer)
// - Leave a brief information about the function
// Change string type date to integer type date
int* strdate_to_intdate(char date[], int *date_array){

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

	date_array[0] =day;
	date_array[1] =month;
	date_array[2] =year;
	return date_array;
}

// Function: stat_age()
// Input: array of ages, NODE* head
// Output: none
// - Leave a brief information about the function
// show statistics about age
void stat_age(int *count_age, NODE* head){
	float total=0;
	int count =0;
	int total_age =0;
	for(NODE* t=head->link; t!=NULL; t=t->link){
		total = total +1;
		int date_array[3];
		strdate_to_intdate(t->member.birthday, date_array);
		struct tm* t; // Use time.h
		const time_t current = time(NULL);
		t = localtime(&current); // today
		int crr_date[3];
		crr_date[0]=t->tm_mday;
		crr_date[1]=t->tm_mon+1;
		crr_date[2]=t->tm_year+1900;
		int member_age = crr_date[2]-date_array[2]-1;
		if(crr_date[1] - date_array[1] < 0);
			//Confirm age
		else{
			if(crr_date[1]==date_array[1] && crr_date[0] >= date_array[0]){
				member_age++;
			}
			else
				member_age++;
		}
		count++;
		total_age += member_age; //나이의 평균값 구하기

		member_age = member_age/10;
		switch(member_age){
			case 1:
				count_age[0]++;
				break;
			case 2:
				count_age[1]++;
				break;
			case 3:
				count_age[2]++;
				break;
			default:
				count_age[3]++;
				break;
		}
	}
	if(total ==0){
		printf("\nThere is not any member! Input first!\n");
		return;
	}
	float per_age[4] ={0,};
	for(int i=0; i<4; i++){
		per_age[i] = count_age[i]/total*100;
	}
	printf("\n__________________________\n");
	printf("    10s 20s 30s 40s+ Unit\n");
	printf("Num %3d %3d %3d %4d each\n",count_age[0],count_age[1],count_age[2],count_age[3]);
	printf("Per %3.0f %3.0f %3.0f %4.0f %%\n",per_age[0],per_age[1],per_age[2],per_age[3]);
	printf("Average_age : %d",total_age/count);

	printf("\n--------------------------\n");
}

// Function: stat_gender()
// Input: array of genders, NODE* head
// Output: none
// - Leave a brief information about the function
// show statistics about gender
void stat_gender(int *count_gender, NODE* head){
	float total=0;
	for(NODE* t=head->link; t!=NULL; t=t->link){
		total=total+1;
		if(t->member.gender=='F')
			count_gender[0]++;
		else
			count_gender[1]++;
		}
	if(total ==0){
		printf("\nThere is not any member! Input first!\n");
		return;
	}
	float per_gender[2] ={0,};
	for(int i=0; i<2; i++){
		per_gender[i] = count_gender[i]/total*100;
	}
	printf("\n__________________________\n");
	printf("    Female Male Unit\n");
	printf("Num %6d %4d each\n",count_gender[0],count_gender[1]);
	printf("Per %6.0f %4.0f %%",per_gender[0],per_gender[1]);
	printf("\n--------------------------\n");
}
// Function: compare_str_date()
// Input: Two array of string date
// Output: return 1 date1 > date2, return 0 date1 == date2, return -1 date1 <date2
// - Leave a brief information about the function
// Compare two array of string date
int compare_str_date(char date1[], char date2[]){
	char temp_date[5];
	for(int i=0; i<5; i++){
		temp_date[i] = '\0';
	}
	int answer=0;

	temp_date[0]=date1[0];
	temp_date[1]=date1[1];
	int day1 = atoi(temp_date);

	temp_date[0]=date1[3];
	temp_date[1]=date1[4];
	int month1 = atoi(temp_date);

	temp_date[0]=date1[6];
	temp_date[1]=date1[7];
	temp_date[2]=date1[8];
	temp_date[3]=date1[9];
	int year1 = atoi(temp_date);

	for(int i=0; i<5; i++){
		temp_date[i] = '\0';
	}

	temp_date[0]=date2[0];
	temp_date[1]=date2[1];
	int day2 = atoi(temp_date);

	temp_date[0]=date2[3];
	temp_date[1]=date2[4];
	int month2 = atoi(temp_date);

	temp_date[0]=date2[6];
	temp_date[1]=date2[7];
	temp_date[2]=date2[8];
	temp_date[3]=date2[9];
	int year2 = atoi(temp_date);

	if(year1 > year2){
		answer = 1;
		return answer;
	}
	else if(year1 == year2 && month1 > month2){
		answer =1;
		return answer;
	}
	else if(year1 == year2 && month1 == month2 && day1 > day2){
		answer =1;
		return answer;
	}
	else if (year1 == year2 && month1 == month2 && day1 == day2){
		answer =0;
		return answer;
	}
	else{
		answer = -1;
		return answer;
	}
}
