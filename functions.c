#include "SDB.h"
static struct list *head=NULL;
static struct list *prev_entry=NULL;
struct list *temp_head,*prev_head;


/*-----------------------------------------------------------------------------*/
//Description: Check if the database is full
//Return Value: Return 1 if the the database is full, otherwise 0
bool SDB_IsFull(void)
{
	if (count_entries>=10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*-----------------------------------------------------------------------------*/

/*Description: Get the number of entries in the database
The maximum size of the database is 10 entries
 Return: Return the number of entries*/
uint8 SDB_GetUsedSize(void)
{
	return count_entries;
}
/*-----------------------------------------------------------------------------*/

/*Description: Add new entry to the database
 Return: Return 1 if the new entry is successfully added; otherwise 0
 Input Parameter - id: Student ID
 Input Paramater - year: Student Year
 Input Parameter - subjects: Pointer to 3 subject IDs, with each subject id is a uint8 value
 Input Parameter - grades: Pointer to 3 grades, with each grade is a uint23 value
 The allowed range for the grade is only from 0 to 100
 Assume that the caller will always provide the 3 subjects with their grades*/
bool SDB_AddEntry(uint32 id, uint32 year, uint32* subjects, uint32* grades)
{	
	
	struct list *entry;
	entry=malloc(sizeof(struct list));
	entry->next=NULL;
	entry->Student_ID=id;
	entry->Student_Year=year;
	entry->subjects[0]=*(subjects);
	entry->subjects[1]=*(subjects+1);
	entry->subjects[2]=*(subjects+2);
	entry->grades[0]=*(grades);
	entry->grades[1]=*(grades+1);
	entry->grades[2]=*(grades+2);
	if (head==NULL)
	{
		head=entry;
		temp_head=head;
	}
	else
	{
		prev_entry->next=entry;
	}

	prev_entry=entry;

	if (entry->next==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	
}
/*-----------------------------------------------------------------------------*/

/*Description: Delete the entry with the given ID
 Input Parameter - id: ID of the entry to be deleted*/
void SDB_DeleteEntry(uint32 id)
{
	struct list *temp;
	while(1)
	{
		if (head==temp_head)//first entry
		{
			if (head->Student_ID==id)
			{
				temp=head;
				head=head->next;
				temp_head=head;
				prev_entry=head;
				free(temp);
				printf("Your ID is removed from database\n");
				--count_entries;
				break;
			}
			else
			{
				prev_head=head;
				head=head->next;
			}
		}
		else if (head->next==NULL)//last entry
		{
			if (head->Student_ID==id)
			{
				temp=head;
				prev_head->next=NULL;
				prev_entry=prev_head;
				head=temp_head;
				free(temp);
				printf("Your ID is removed from database\n");
				--count_entries;
				break;
			}
			else
			{
				printf("Your ID not exist\n");
				head=temp_head;
				break;
			}
			
		}
		else//center entry
		{
			if (head->Student_ID==id)
			{
				temp=head;
				prev_head->next=head->next;
				head=temp_head;
				free(temp);
				printf("Your ID is removed from database\n");
				--count_entries;
				break;
			}
			else
			{
				prev_head=head;
				head=head->next;
			}
		}
	}	

}
/*-----------------------------------------------------------------------------*/

/*Description: Read an entry matching the provided ID
 Return Value: Return 1 if the entry exist, otherwise 0
 Input Parameter - id: Student ID
 Output Parameter - year: Pointer to the student year
 Output Parameter - subjects: Pointer to the subjects
 Output Parameter - grades: Pointer to the grades*/
bool SDB_ReadEntry(uint32 id)
{	
	while(1)
	{
		if(head!=NULL)
		{	
			if (head->Student_ID==id)
			{
				printf("You ID : %d\n",head->Student_ID);
				printf("Your Year : %d\n",head->Student_Year);
				printf("Subject ID : %d its grade: %d\n",head->subjects[0],head->grades[0]);
				printf("Subject ID : %d its grade: %d\n",head->subjects[1],head->grades[1]);
				printf("Subject ID : %d its grade: %d\n",head->subjects[2],head->grades[2]);
				head=temp_head;
				return 1;
				break;
			}
			else
			{
				head=head->next;
			}
				
		}
		else
		{
			head=temp_head;
			return 0;
			break;
		}
	}
	
}
		
	
	

/*-----------------------------------------------------------------------------*/

/*Description: Get the list of IDs of the students
 Output Parameter - count: Pointer to the number of entries currently exists in the database
 Output Parameter - list: Pointer to the list of IDs*/
void SDB_GetIdList(void)
{
	printf("the number of entries currently exists in the database : %d\n",count_entries);
	printf("the list of IDs : \n");
	while(1)
	{
		if(head!=NULL)
		{
			printf("%d\n",head->Student_ID);
			head=head->next;
		}
		else
		{
			head=temp_head;
			break;
		}
	}
}
/*-----------------------------------------------------------------------------*/

/*Description: Checks if the the provided student ID exists
 Return Value: Return 1 if ID exists in the database, otherwise 0*/
bool SDB_IsIdExist(uint32 id)
{
	while(1)
	{
		if (head!=NULL)
		{
			if (head->Student_ID==id)
			{
				head=temp_head;
				return 1;
			}
			else
			{
				head=head->next;
			}
		}
		else
		{
			head=temp_head;
			return 0;
		}

	}
}