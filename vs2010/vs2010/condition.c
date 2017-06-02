#include "condition.h"

//플레이어의 승리 또는 패배 상태를 확인하는 기능
int victory_condition(int vet[dim][dim]) 
{
    int i,l,flag=0,player=0;                         //변수 초기화
                                                   
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
			// 필드에서 player와 적  존재를 찾음.
            if(vet[i][l]==3||vet[i][l]==7||vet[i][l]==10||vet[i][l]==12||vet[i][l]==14)
			{  //적을 발견했을 때
                flag=1; 			
            }
			if(vet[i][l]==2)
			{//플레이어를 찾았을 때의 player
                player=1; 	
            }
        }
    }
   //필드에서 발견 된 값에 따라 다른 값을 반환 
   if(flag==1&&giocatore==1) // 적이 있고, 플레이어가 있는 경우
    {
			 return 0;
    }
	else if(flag==0&&giocatore==1)
	{   // 적이 없고 플레이어가 있는 경우              
			return 1;
    }
	else if(flag==1&&giocatore==0) // 적이 있고 플레이어가 없는 경우
	{
			return 2;
	}
	else  //적이 없고 플레이어가 없는 경우
	{
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