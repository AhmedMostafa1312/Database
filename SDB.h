#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

extern uint8 count_entries;

typedef enum{false , true} bool;

struct list
{
	uint32 Student_ID;
	uint32 Student_Year;
	uint32 subjects[3];
	uint32 grades[3];
	struct list *next;
};






bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint32 id, uint32 year, uint32* subjects, uint32* grades);
void SDB_DeleteEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetIdList(void);
bool SDB_IsIdExist(uint32 id);
