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
void votePercent(president p[5]);
void initializeElecteur(electeurs e[],int n);
void initializePresident(president p[]);
void restartTour(president p[]);
char* state(president p);

int main()
{

	int choix,n;
	electeurs e[10];
	  president p[5]={
	 	{
	 		1,"James","Polk",0,1
		 },
		 	{
	 		2,"John","Adams",0,1
		 },
		 	{
	 		3,"Vladi","Putin",0,1
		 },
		 	{
	 		4,"Joe","Biden",0,1
		 },
		 	{
	 		5,"John","Tyler",0,1
		 },

	 };
    int *pri;

	 int i;

            printf("\t Id \t Nom \t Prenom   Nombre De Vote     State \n");
      printf("\t -----|--------|---------|----------------|--------\n");
	 for(i=0;i<5;i++)
	 {
	     if(p[i].isVisible==1)
         {

            printf("\t %d \t %s \t %s \t \t %d \t      %s\n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote,state(p[i]));
         }


	 }
	int j;



	do{
    printf("\t 1: Vote \n");
    printf("\t 2: List de electeurs \n");
	printf("\t 3: Resulte \n");

	printf("Enter your choix : \n");
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

                result(p);

                }

    }
    while(choix!=4);



}
                //vote methode
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

                if(e[i].vote==p[j].id && p[j].isVisible==1)
                  {
                    p[j].numVote++;
                  }
                    else if(e[i].vote==p[j].id && p[j].isVisible==0)
                    {
                        printf("The candidate that u've voted on has been eliminated \n");
                          printf("choisir un président \n");

                            scanf("%d",&e[i].vote);
                    }

                  }
                  }
                else
                  {
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
    int ifEqual=p[0].numVote,c=0;
    int i,totalVote=0,percentVote;
    for(i=0;i<5;i++)
    {
        totalVote+=p[i].numVote;
    }

    for(i=1;i<5;i++)
    {
        if(p[0].numVote != p[i].numVote)
        {

c = 1;
break;
        }

    }

    if(c!=0)
    {
         votePercent(p);

    }
    else{
        restartTour(p);
    }

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
void votePercent(president p[])
{


int i,index=0,pos=0;
float totalVote=0;
    for (i = 0; i < 5; i++)
    {
        totalVote+=p[i].numVote;

    }


     printf("\t Id \t Nom \t Prenom   Nombre De Vote     State \n");
    printf("\t -----|--------|---------|----------------|--------\n");
   for (i = 0; i < 5; i++)
    {
            if (p[i].numVote / totalVote*100<=15)
                {
                    p[i].isVisible=0;

                }
            else
            {
                 index++;
                    pos=i;
            }

    }
    for(i = 0; i < 5; i++)
    {
        if(index>1)
            {
                    initializePresident(p);
            printf("\t %d \t %s \t %s \t \t %d \t      %s\n",p[i].id,p[i].nom,p[i].pnom,p[i].numVote,state(p[i]));

            }
        else if(index == 1)
        {
            printf("The winner candidate is %s %s \n",p[pos].nom,p[pos].pnom);
            exit(0);
        }
    }

}

void initializeElecteur(electeurs e[],int n)
{
    int i;
    for(i=0;i<=n-1;i++)
    {
        e[i].cin=0;
        e[i].vote=0;

    }
}
void initializePresident(president p[])
{
    int i;

	 for(i=0;i<5;i++)
	 {
        p[i].numVote=0;
	 }
}
void restartTour(president p[])
{
    int i;
    printf("\t All votes is equals the tour in restartet pls vote again !! \n");
for(i=0;i<5;i++)
	 {
        initializePresident(p);
        p[i].isVisible=1;
	 }
}
char* state(president p)
{
char* stat;
if(p.isVisible==1)
{
    return "Vote";
}
else if(p.isVisible==0)
    return "Don't Vote";
}
