#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
    {
    	int id;
    	char nom[30];
    	char pnom[30];
    	int numVote;
    	int isVisible;//1 equals true 0 false
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
void Delete(president p[5]);
void initializeElecteur(electeurs e[],int n);
void initializePresident(president p[]);

typedef struct {
    int size;
}globalState;
globalState state;
int main()
{
    state.size = 5;
	int choix,n;
	electeurs e[10];
	  president p[5]={
	 	{
	 		1,"Azer","Tyui",0,1
		 },
		 	{
	 		2,"jklm","wxcv",0,1
		 },
		 	{
	 		3,"opqs","dfgh",2,1
		 },
		 	{
	 		4,"reza","teru",0,1
		 },
		 	{
	 		5,"iopk","ghkd",0,1
		 },

	 };

	 int i;
            printf("\t Id \t Nom \t Prenom \t Nombre De Vote \n");
            printf("\t -----|--------|---------|--------------\n");
	 for(i=0;i<5;i++)
	 {
	     if(p[i].isVisible==1)
         {

             printf("\t %d \t %s \t %s \t \t %d \n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote);
         }


	 }
	int j;



	do{
    printf("\t 1: Vote \n");
    printf("\t 2: List de electeurs \n");
	printf("\t 3: Resultat \n");
	printf("\t 4: Delete \n");
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
    	else if(choix==4)
        {
        Delete(p);
	}
	else if(choix==5)
        {
        initializeElecteur(e,n);
	}
	else if(choix==6)
        {
        initializePresident(p);
	}
	  	}while(choix!=7);



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
            for(i=0;i<=n-1;i++)
    {
      printf("\t num :  %d \t  cin : %d \n",i+1,e[i].cin);
    }

        }

        else{
        printf("\t *no one have voted yet* \n");
    }

}
void Delete(president p[])
{


int i;
float totalVote=0,percentVote=0;
    for (i = 0; i < 5; i++)
    {
        totalVote+=p[i].numVote;

    }
    percentVote=(totalVote*15)/100;
   for (i = 0; i < 5; i++)
    {
    if (p[i].numVote<=percentVote)
        {
            p[i].isVisible=0;
//                    printf(" %d \n",p[i].id);
            }
            else{
                 printf(" %d \n",p[i].id);
            }
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


void initializeElecteur(electeurs e[],int n)
{
    int i;
    for(i=0;i<=n-1;i++)
    {
        e[i].cin=0;
        e[i].vote=0;

    }
        for(i=0;i<=n-1;i++)
    {
      printf("\t num :  %d \t  cin : %d \n",i+1,e[i].cin);
    }
}
void initializePresident(president p[])
{
    int i;

	 for(i=0;i<5;i++)
	 {
        p[i].numVote=0;
	 	 printf("\t %d \t %s \t %s \t \t %d \n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote);

	 }
}
