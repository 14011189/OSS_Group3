#include "condition.h"

int victory_condition(int vet[dim][dim])            
// Function to verify the player's win or defeat condition
{
    int i,l,flag=0,giocatore=0;                         // Variable initialization

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==3||vet[i][l]==7||vet[i][l]==10||vet[i][l]==12||vet[i][l]==14){                          
  // I seek the presence of both the player and the enemy on the playing field
                flag=1; 					// There is a flag if I find an enemy

            }if(vet[i][l]==2){
                giocatore=1; 				// Another flag if I find the player
            }
        }
    }

    if(flag==1&&giocatore==1)
    {
        return 0;
    }else if(flag==0&&giocatore==1){                 
// According to who was found on the field, the function returns different values
        return 1;
    }else if(flag==1&&giocatore==0){
        return 2;
    }else{
        return 3;
    }

}

void game_level(int vet[dim][dim],int lv)
{
    int i,l;

	// Empty the field
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){               
            vet[i][l]=0;
        }
    }

    switch(lv)
    {
    case 1:
    vet[dim-2][(dim/2)-1]=2;
    vet[3][10]=3;

	//Insert enemies by algorithm
     for(i=1;i<2;i++){
        for(l=1;l<dim-1;l++){          
            vet[i][l]=3;
            l++;
        }
     }

        break;
    case 2:
    vet[dim-2][(dim/2)-1]=2;

	//Insert enemies by algorithm
     for(i=1;i<3;i++){
        if(i==1){
         for(l=1;l<dim-1;l++){          
            vet[i][l]=3;
            l++;
        }
        }

		//Insert enemies by algorithm
        if(i==2){
            for(l=2;l<dim-1;l++){         
            vet[i][l]=3;
            l++;
        }
        }
     }
      break;
    case 3:
    vet[dim-2][(dim/2)-1]=2;
    vet[3][10]=7;

	//Insert enemies by algorithm
     for(i=1;i<2;i++){
        for(l=1;l<dim-1;l++){          
            vet[i][l]=7;
            l++;
        }
     }



        break;
    case 4:
        vet[dim-2][(dim/2)-1]=2;
        vet[1][(dim/2)-1]=10;
        break;
    case 5:
        vet[dim-2][(dim/2)-1]=2;
        vet[3][10]=12;

		//Insert enemies by algorithm
       for(i=1;i<2;i++){
          for(l=1;l<dim-1;l++){          
              vet[i][l]=12;
              l++;
          }
       }

        break;
    case 6:
         vet[dim-2][(dim/2)-1]=2;

	//Insert enemies by algorithm
     for(i=1;i<3;i++){
        if(i==1){
         for(l=1;l<dim-1;l++){          
            vet[i][l]=12;
            l++;
        }
        }
	//Insert enemies by algorithm
        if(i==2){
            for(l=2;l<dim-1;l++){       
            vet[i][l]=12;
            l++;
        }
        }
     }
        break;
    case 7:
        vet[dim-2][(dim/2)-1]=2;
        vet[1][(dim/2)-4]=14;
        vet[1][(dim/2)+4]=14;
        break;
    case 8:
        vet[dim-2][(dim/2)-1]=2;
         for(i=1;i<4;i++){
        if(i==1){
		//Insert enemies by algorithm
         for(l=1;l<dim-1;l++){          
            vet[i][l]=3;
            l++;
        }
        }
        if(i==2){
			//Insert enemies by algorithm
            for(l=2;l<dim-1;l++){        
            vet[i][l]=3;
            l++;
        }
        }
        if(i==3){
			//Insert enemies by algorithm
            for(l=1;l<dim-1;l++){         
            vet[i][l]=3;
            l++;
        }
        }
     }
        break;
    case 9:
        vet[dim-2][(dim/2)-1]=2;
         for(i=1;i<4;i++){
        if(i==1){
		//Insert enemies by algorithm
         for(l=1;l<dim-1;l++){         
            vet[i][l]=12;
            l++;
        }
        }
        if(i==2){
			//Insert enemies by algorithm
            for(l=2;l<dim-1;l++){         
            vet[i][l]=12;
            l++;
        }
        }
        if(i==3){
			//Insert enemies by algorithm
            for(l=1;l<dim-1;l++){         
            vet[i][l]=12;
            l++;
        }
        }
     }
        break;
    case 10:
     vet[dim-2][(dim/2)-1]=2;

     for(i=1;i<3;i++){
        if(i==1){
		//Insert enemies by algorithm
         for(l=1;l<dim-1;l++){          
            vet[i][l]=7;
            l++;
        }
        }
        if(i==2){
			//Insert enemies by algorithm
            for(l=2;l<dim-1;l++){          
            vet[i][l]=7;
            l++;
        }
        }
     }
      break;
    case 11:
        vet[dim-2][(dim/2)-1]=2;
        vet[1][(dim/2)-4]=14;
        vet[1][(dim/2)+4]=14;
        vet[1][(dim/2)]=14;
        break;


    }


}