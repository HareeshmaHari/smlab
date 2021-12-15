#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct files
{
	char fName[15][20];
	int fno;
};

struct files file;
int i;

int main()
{
	char dName[10];
	int c;
	char ch;
	file.fno=0;
	printf("Enter a directory name: ");
	scanf("%s",dName);
	
	x: 
	printf("\n\n1. Enter  file\n2. Delete a file\n3. Display Files\n4. Exit\n\n> ");
	scanf("%d",&c);
	
		switch(c)
		{
			case 1: printf("\nEnter the file to be entered: ");
				scanf("%s",file.fName[file.fno]);
				file.fno++;
				printf("File inserted\n");
				break;
			case 2: char name[10];
				printf("\nEnter the file to be deleted: ");
				scanf("%s",name);
				for(i=0;i<file.fno;i++)
				{	
					if(strcmp(name,file.fName[i])==0)
					{
						printf("\nFile deleted: %s\n",file.fName[i]);
						strcpy(file.fName[i],file.fName[file.fno-1]);
						file.fno--;
					}
				}
				break;
			case 3: printf("\nFiles are: \n");
				for(i=0;i<file.fno;i++)
				{
		
					printf("%s\n",file.fName[i]);
				}
				break;
			case 4: exit(0);
				break;
		}
	printf("\nDo you want to continue: ");
	scanf("%c",&ch);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y'){
	goto x;
	}
	else{
	
	exit(0);
	}
	return 0;
	
}
