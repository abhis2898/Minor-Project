#include<stdio.h>
#include<stdlib.h>

struct info {
	char id[100];
	char name[100];
	char age[100];
	char city[100]; 
	char profession[100];
	char food[100];
	char sports[100];
	char movie[100];
	char travelling[100];
	char music[100];
	char fashion[100];
};

int main()
{
	FILE *fp; 
	int rows = 0;
	int i,j,k;
	fp=fopen("minor1dataset.csv","r"); 
    
	char c;
	char ch;

	if (fp==NULL) 
	{ 
		printf("Could not open file "); 
		return 0; 
	} 

	c=fgetc(fp);
//counting the no of rows

	while(c!=EOF)
	{ 
		if (c =='\n')
		rows = rows + 1; 
		c = fgetc(fp);
	}
	
	printf("%d\n",rows);
	fclose(fp);
	int coloums=1;
	fp=fopen("minor1dataset.csv","r");
	c=fgetc(fp); 
	while(c!='\n')
	{
		if(c==',')
		{
			coloums=coloums+1;
			c=fgetc(fp);
		}
		c=fgetc(fp);
	}

	printf("%d\n",coloums);
	fclose(fp);

	fp=fopen("minor2dataset.csv","r"); 
	int ar[100][100];
	for(i=1;i<=rows;++i)
	{
		for(j=1;j<=rows;++j)
		{
			if(j>=1 && j<=9)
			fscanf(fp,"%d,",&ar[i][j]);

			else if(j==10)
			fscanf(fp,"%d",&ar[i][j]);
		}
	}
	
	for(i=1;i<=rows;++i)
	{
		for(j=1;j<=rows;++j)
		{
			printf("%d",ar[i][j]);
		}
		
	printf("\n");
	}
	i=1;

	while(i<=10)
	{
		j=1;
		while(j<=10)
		{
			if(ar[i][j]!=1)
			{
				++j;
			}
			
			else
			{
				k=1;
				while(k<=10)
				{
					if(ar[j][k]!=1 || k==i ||ar[i][k]==1)
					{
						++k;
					}
					
					else
					{
						if(ar[j][k]==1)
						{
							if(ar[i][k]==0)
							{
								ar[i][k]=ar[i][j]+ar[j][k];
							}
						}
						++k;
					}
				}
				++j;
			}

   		}
		++i;
	}
	
	printf("\n");
	for(int i=1;i<=rows;++i)
	{
		for(int j=1;j<=rows;++j)
		{
			printf("%d",ar[i][j]);
		}

		printf("\n");
	}
	printf("\n");
	struct info inf[100];
	fp = fopen("minor1dataset.csv","r");

	for(i=1;i<=coloums;++i)
	{
		fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",inf[i].id,inf[i].name,inf[i].age,inf[i].city,inf[i].profession,inf[i].food,inf[i].sports, inf[i].movie,inf[i].travelling,inf[i].music,inf[i].fashion);

	}

	for(int i=1;i<=rows;++i)
	{
	printf("%s %s %s %s %s %s %s %s %s %s %s",inf[i].id,inf[i].name,inf[i].age,inf[i].city,inf[i].profession,inf[i].food,inf[i].sports,inf[i].movie,inf[i].travelling, inf[i].music,inf[i].fashion);
	}
	printf("\n\n");

	return 0;
}
