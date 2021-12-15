#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Directory
{
	char dName[10];
	char fName[20][20];
	int fno;
};
struct Directory dir[10];

int dno,i,j,d,flag,ch,ch1;
char dirTmp[20],file[20];

void createDirectory()
{
	printf("Create a Directory\n");
	printf("Enter Directory name: ");
	scanf("%s",dir[dno].dName);
	dir[dno].fno=0;
	dno++;
	printf("Directory created successfully\n");
}

void displayDirectory()
{
	for(i=0;i<dno;i++)
	{
		printf("> %s\n",dir[i].dName);
	}
}

void selectDirectory()
{
	int flag1,flag2=0;
	printf("Directories available:\n");
	for(i=0;i<dno;i++)
	{
		printf("> %s\n",dir[i].dName);
	}
	printf("Select a directory(Enter the name of directory): ");
	scanf("%s",dirTmp);
	
	for(i=0;i<dno;i++)
		if(strcmp(dirTmp,dir[i].dName)==0)
		{
			flag=i;
			flag2=1;
		}
	if(flag2==1)
	{
		x:
		printf("1. Insert a file\n2. Delete a file\n3. Display files\n4. Search a file\n5. Exit\n\n>>> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the file to be inserted: ");
				scanf("%s",dir[flag].fName[dir[flag].fno]);
				dir[flag].fno++;
				printf("\nFile inserted\n");
				break;
			case 2: printf("Enter the file to be deleted: ");
				scanf("%s",file);
				for(j=0;j<dir[flag].fno;j++)
				{
					if(strcmp(file,dir[flag].fName[j])==0)
					{
						printf("File %s Deleted\n",file);
						strcpy(dir[flag].fName[j],dir[flag].fName[dir[flag].fno-1]);
						dir[flag].fno--;
						break;
					}
				}
				break;
			case 3: printf("Files are:\n");
				for(i=0;i<dir[flag].fno;i++)
				{
					printf("%s\n",dir[flag].fName[i]);
				}
				break;
			case 4: printf("Enter the file to search: ");
				scanf("%s",file);
				for(i=0;i<dir[flag].fno;i++)
				{
					if(strcmp(file,dir[flag].fName[i])==0)
						flag1=1;
				}
				if(flag1==1)
					printf("The file %s is found. \n",file);
				else
					printf("File not Found\n");
				
				break;
			case 5:
				break;
			
		}	
		printf("\nFile Operation :: Enter 1 to continue; 0 to exit: ");
		scanf("%d",&d);
		if(d==1)
			goto x;
	}
	else
	{
		printf("Directory not Found\n");
	}
}

int main()
{
	int n;
	while(1)
	{
		printf("\n1. Create a directory\n2. Display directories\n3. Select a directory\n4. Exit\n\n>>> ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: createDirectory();
				break;
			case 2: displayDirectory();
				break;
			case 3: selectDirectory();
				break;
			case 4: exit(0);
		}
	printf("\nDirectory Operation :: Enter 1 to continue; 0 to exit: ");
	scanf("%d",&ch1);
	if(ch1==1)
		continue;
	else
		break;
	}
}
