#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
    {
    	int id;
    	char nom[30];
    	char pnom[30];
    	int numVote;
	} president;
	typedef struct
    {
    	int cin;
    	int vote;
	} electeurs;
	
	
int main()
{
	int choix;
	electeurs e[10];
	 president p[5]={
	 	{
	 		1,"Azer","Tyui",0
		 },
		 	{
	 		2,"jklm","wxcv",0
		 },
		 	{
	 		3,"opqs","dfgh",0
		 },
		 	{
	 		4,"reza","teru",0
		 },
		 	{
	 		5,"iopk","ghkd",0
		 },
	 
	 };
	
	 int i;
	 
	 for(i=0;i<5;i++)
	 {
	 	printf("\t %d \t %s \t %s  \n",p[i].id,p[i].nom,p[i].pnom);
	 	
	 }
	int j;
	
	printf("\t 1: Vote \n");
	printf("\t 2: Resultat \n");
	printf("Entrer ur choix : \n");
	scanf("%d",&choix);
	do{

	if(choix == 1)
	{
			for(i=0;i<3;i++)
	      	{
	      		printf("entrer ur CIN \n");
				scanf("%d",&e[i].cin);
					printf("choisir un président \n");
					scanf("%d",&e[i].vote);
				for(j=0;j<5;j++)
				{
						 if(e[i].vote==p[j].id)
					 {
					 	p[j].numVote++;
					
					 }
				
				}
			  }
	}
	  	}while(choix!=2);    


	
}
