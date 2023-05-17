#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"dos.h"
#include"string.h"


typedef unsigned char BYTE;
typedef unsigned int WORD;
typedef unsigned long DWORD;

typedef struct
{
	BYTE FileName[8];
	BYTE FileExt[3];
	BYTE Adv[1];
	BYTE no[10];
	BYTE Time[2];
	BYTE Day[2];
	BYTE Cluster[2];
	DWORD Size;
}ENTRY;

void main()
{
	clrscr();
	ENTRY RDET[224];
	if (absread(0,14,19,RDET) != 0)
	{
		printf("loi doc sector");
		getch();
		exit(0);
	}
	for(int i = 0; i <224; i++)
	{
		if((RDET[i].FileName[0] != 0) && (RDET[i].FileName[0] != 0xE5))
		{
			for(int j = 0; j < 8; j++)
				if(RDET[i].FileName[j] != 32 && RDET[i].FileName[j] != 46)
					printf("%c", RDET[i].FileName[j]);
			printf(".");
			for(int k = 0; k<3; k++)
				if(RDET[i].FileExt[k] != 32)
					printf("%c", RDET[i].FileExt[k]);
			printf("\tKich thuocc : %8ld ", RDET[i].Size);
			printf("\n");
		}

	}
	getch();
}
