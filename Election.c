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
	
	
//	      void Vote(president p[],electeurs e[])
//		  {
//		  	int i,j;
//	      	for(i=0;i<10;i++)
//	      	{
//	      		printf("entrer ur CIN \n");
//				scanf("%s",e[i].cin);
//				for(j=0;j<5;j++)
//				{
//					printf("choisir un président \n");
//					printf("%d\t",p[j].id);
//					scanf("%d",&e[j].vote);
//					 if(e[j].vote==p[j].id)
//					 {
//					 	p[j].numVote++;
//					 }
//				}
//			  }
//			 
//		  }

	
	

int main()
{
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
	 	printf("\t %d \t %s \t %s \t %d \n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote);
	 	
	 }
//	 Vote(p,e);
	int j;
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
			 for(i=0;i<5;i++)
	 {
	 	printf("\t %d \t %s \t %s \t %d \n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote);
	 	
	 }
	
}
