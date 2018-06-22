#include "SDB.h"

uint8 count_entries=0;

int main(void)
{
uint32 Student_ID,Student_Year,subjects[3];
uint32 grades[3];
static uint8 count=0;
uint8 IsFull,UsedSize,add_entry,read_entry,existence;	
uint32 choice;	
puts("Database Module,Welcome :)\n\
Note: The maximum size of the database is 10 entries only.");

while(1)
{
	printf("What do you want to do ?\nAdd an entry ? (press 1)\nRead an entry ? (press 2)\
	\nRemove an entry ? (press 3)\nCheck existence of an entry ? (press 4)\nView list of entries ? (press 5)\
	\nExit ? (press 6)\nyour choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case (1) ://Add an entry
		{
			UsedSize=SDB_GetUsedSize();
			printf("The used size of the database = %d\n",UsedSize);
			IsFull=SDB_IsFull();
			if (IsFull==0)//not full
			{
				printf("Enter your ID : ");
				scanf("%d",&Student_ID);
				printf("Enter your Year : ");
				scanf("%d",&Student_Year);
				for (int index = 0; index < 3; ++index)
				{
					printf("Enter the ID of course %d : ",index+1);
					scanf("%d",&subjects[index]);
					printf("Enter the grade of course %d (out of 100): ",index+1);
					scanf("%d",&grades[index]);
					while(grades[index]>100)
					{
						printf("Invalid grade\n");
						printf("Enter the grade of course %d (out of 100): ",index+1);
						scanf("%d",&grades[index]);
					}
				}

				add_entry=SDB_AddEntry(Student_ID, Student_Year, &subjects[0], &grades[0]);

				if (add_entry==1)//entry created
				{
					printf("The entry is created successfully\n");
					++count;
					count_entries=count;
				}
				else//entry not created
				{
					printf("The entry is not created\n");
					break;
				}
			}
			else//full
			{
				printf("The database is full.\nNote: The maximum size of the database is 10 entries only.\n");
			}

			break;

		}
		case (2) ://Read an entry
		{
			uint32 id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			read_entry=SDB_ReadEntry(id);
			if (read_entry==1)
			{
				printf("Your ID exist\n");
			}
			else
			{
				printf("Your ID not exist\n");
			}
			break;
		}
		case (3) ://Remove an entry
		{
			uint32 id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			SDB_DeleteEntry(id);
			break;
		}
		case (4) ://Check existence of an entry
		{
			uint32 id;
			printf("Enter your ID : ");
			scanf("%d",&id);
			existence=SDB_IsIdExist(id);
			if (existence==1)
			{
				printf("Your ID exist\n");
			}
			else
			{
				printf("Your ID not exist\n");
			}
			break;
		}
		case (5) ://View list of entries
		{
			SDB_GetIdList();
			break;
		}
		case (6) ://exit
		{
			break;
		}
		default :
		{
			printf("Invalid choice\n");
			break;
		}
	}

if(choice==6)
{
	break;
}
else{}

puts("");
}

return 0;
}