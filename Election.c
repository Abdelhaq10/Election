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
//	void result(president p[5]);
	typedef struct
    {
    	int cin;
    	int vote;
	} electeurs;
void vote(president p[5],electeurs e[],int n);
void result(president p[5]);
void listElecteurs(electeurs e[],int n);
int main()
{

	int choix,n;
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



	do{
    printf("\t 1: Vote \n");
    printf("\t 2: List de electeurs \n");
	printf("\t 3: Resultat \n");
	printf("Entrer ur choix : \n");
    scanf("%d",&choix);
	if(choix == 1)
	{
	    printf("Enter the number of electeurs \n");
        scanf("%d",&n);
        vote(p,e,n);
	}
	else if(choix==2)
        {
        listElecteurs(e,n);
	}
	else if(choix == 3)
    {
//        for(i=0;i<5;i++)
//	 {
//	 	printf("\t %d \t %s \t %s \t %d \n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote);
//
//	 }
result(p);

    }
	  	}while(choix!=3);



}

void vote(president p[5],electeurs e[],int n)
{
    int i,j;
    	for(i=0;i<=n-1;i++)
	      	{
	      		printf("entrer ur CIN \n");
				scanf("%d",&e[i].cin);
    if(e[i].cin!=e[i-1].cin)
    {


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
     else {
        printf("you already voted sir !!\n");
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
}

void result(president p[5])
{
    int i,totalVote=0,percentVote;
    for(i=0;i<5;i++)
    {
        totalVote+=p[i].numVote;
    }
    printf("total is %d \t",totalVote);
//    for(i=0;i<5;i++)
//    {
//
//    }
}
void listElecteurs(electeurs e[],int n)
{
    int i,totalVote=0;
    for(i=0;i<=n-1;i++)
    {
       totalVote+=e[i].vote;
    }
      if(totalVote!=0)
        {
            printf("\t %d \t  %d \n",e[i].cin,e[i].vote);
        }

        else{
        printf("\t *no one have voted yet* \n");
    }

}

//void result(president p[5]){
//    int i;
//for(i=0;i<5;i++)
//	 {
//	 	printf("\t %d \t %s \t %s \t %d \n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote);
//
//	 }
//}
