#include <time.h> 
#include <stdlib.h> 
#include <stdio.h>
#include "object.h"


void boss(int vet[dim][dim],int dif)
{
	int i,l,num,flag,k,spara;

	srand(time(NULL));

	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if(vet[i][l]==10)
			{
				num=1+rand()%dif;
				if(vet[i+1][l]==1&&l!=1&&num<dif)
				{
					vet[i][l]=0;
					vet[i][l-1]=6;
				}else if(vet[i+1][l]==1&&l!=dim-2&&num<dif)        // evita i proiettili del giocatore se un numero casuale e' minore di 10
				{
					vet[i][l]=0;
					vet[i][l+1]=6;

				}

				else{

					num=1+rand()%dif;                           //genero un numero random che provoca diversi comportamneti


					if(num==1){
						if(vet[i][l-1]==0&&l!=1){              // comportmaneto 1: va a sinistra oppure se non può spara
							vet[i][l]=0;
							vet[i][l-1]=6;
						}else{
							flag=0;
							for(k=i+1;k<dim;k++){
								if(vet[k][l]==3||vet[k][l]==6){    //controlla se ha la traiettoria di tiro libera, se ha un compagno davanti restituisce 1
									flag=1;
								}
							}
							if(flag==0){
								spara=1+rand()%10;            // genera un numero fra 1 e 10 , se è pari lo sparo va a buon fine, altrimenti non spara
								if(spara%2==0){
									vet[i+1][l]=5;
									vet[i][l]=6;
								}else{
									if(vet[i+2][l]==0){
										vet[i+1][l]=8;
									}
									vet[i][l]=6;
								}
							}
						}

					}
					if(num==2){                            // comportamento 2: va su, e se non può spara
						if(vet[i-1][l]==0&&i!=1){
							vet[i][l]=0;
							vet[i-1][l]=6;
						}else{
							flag=0;
							for(k=i+1;k<dim;k++){
								if(vet[k][l]==3||vet[k][l]==6){
									flag=1;
								}
							}
							if(flag==0){
								spara=1+rand()%10;
								if(spara%2==0){
									vet[i+1][l]=5;
									vet[i][l]=6;
								}else{
									if(vet[i+2][l]==0){
										vet[i+1][l]=8;
									}
									vet[i][l]=6;
								}
							}
						}


					}
					if(num==3){
						if(vet[i][l+1]==0&&l!=dim-2){         // comportamento 3: va a destra, e se non può spara
							vet[i][l]=0;
							vet[i][l+1]=6;
						}else{
							flag=0;
							for(k=i+1;k<dim;k++){
								if(vet[k][l]==3||vet[k][l]==6){
									flag=1;
								}
							}
							if(flag==0){
								spara=1+rand()%10;
								if(spara%2==0){
									vet[i+1][l]=5;
									vet[i][l]=6;
								}else{
									if(vet[i+2][l]==0){
										vet[i+1][l]=8;
									}
									vet[i][l]=6;
								}
							}
						}


					}
					if(num==4){
						if(vet[i+1][l]==0&&i!=(dim/2)-2){
							vet[i][l]=0;
							vet[i+1][l]=6;                // comportamento 4: va giu, e se non può spara
						}else{
							flag=0;
							for(k=i+1;k<dim;k++){
								if(vet[k][l]==3||vet[k][l]==6){
									flag=1;
								}
							}
							if(flag==0){
								spara=1+rand()%10;
								if(spara%2==0){
									vet[i+1][l]=5;
									vet[i][l]=6;
								}else{
									if(vet[i+2][l]==0){
										vet[i+1][l]=8;
									}
									vet[i][l]=6;
								}
							}
						}

					}
					if(num==5){
						flag=0;
						for(k=i+1;k<dim;k++){
							if(vet[k][l]==3||vet[k][l]==6){    // comportamento 5: spara, ovviamente evitando se davanti a se ha un alleato
								flag=1;
							}
						}
						if(flag==0){
							spara=1+rand()%10;
							if(spara%2==0){
								vet[i+1][l]=5;
								vet[i][l]=6;
							}else{
								if(vet[i+2][l]==0){
									vet[i+1][l]=8;
								}
								vet[i][l]=6;
							}
						}
					}
				}

			}


		}
	}
	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if(vet[i][l]==6){
				vet[i][l]=10;
			}
		}
	}



}

void ia_boss2(int vet[dim][dim],int dif)
{
	int i,l,num,flag,k,spara;

	srand(time(NULL));

	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if(vet[i][l]==14)
			{
				if((vet[i-1][l]==5&&vet[i][l-1]==0)||(vet[i-1][l]==15&&vet[i][l-1]==0))
				{
					vet[i][l]=0;
					vet[i][l-1]=6;
					// questi due if servono perchè la navicella eviti un proiettile del compagno, se è possibile

				}else if((vet[i-1][l]==5&&vet[i][l+1]==0)||(vet[i-1][l]==15&&vet[i][l+1]==0))
				{
					vet[i][l]=0;
					vet[i][l+1]=6;
					// questi due if servono perchè la navicella eviti un proiettile del compagno, se è possibile


				}else{
					num=1+rand()%dif;
					if(vet[i+1][l]==1&&l!=1&&num<dif&&vet[i][l-1]==0)
					{
						vet[i][l]=0;
						vet[i][l-1]=6;
					}else if(vet[i+1][l]==1&&l!=dim-2&&num<dif&&vet[i][l+1]==0)        // evita i proiettili del giocatore se un numero casuale e' minore di 10
					{
						vet[i][l]=0;
						vet[i][l+1]=6;

					}

					else{

						num=1+rand()%dif;                           //genero un numero random che provoca diversi comportamneti


						if(num==1){
							if(vet[i][l-1]==0&&l!=1){              // comportmaneto 1: va a sinistra oppure se non può spara
								vet[i][l]=0;
								vet[i][l-1]=6;
							}else{
								flag=0;
								for(k=i+1;k<dim;k++){
									if(vet[k][l]==14||vet[k][l]==6){    //controlla se ha la traiettoria di tiro libera, se ha un compagno davanti restituisce 1
										flag=1;
									}
								}
								if(flag==0){
									spara=1+rand()%10;            // genera un numero fra 1 e 10 , se è pari lo sparo va a buon fine, altrimenti non spara
									if(spara%2==0){
										if(vet[i+2][l]==0){
											vet[i+1][l]=5;
										}
										vet[i][l]=6;
									}else{
										if(vet[i+2][l]==0){
											vet[i+1][l]=15;
										}
										vet[i][l]=6;
									}
								}
							}

						}
						if(num==2){                            // comportamento 2: va su, e se non può spara
							if(vet[i-1][l]==0&&i!=1){
								vet[i][l]=0;
								vet[i-1][l]=6;
							}else{
								flag=0;
								for(k=i+1;k<dim;k++){
									if(vet[k][l]==14||vet[k][l]==6){
										flag=1;
									}
								}
								if(flag==0){
									spara=1+rand()%10;
									if(spara%2==0){
										if(vet[i+2][l]==0){
											vet[i+1][l]=5;
										}
										vet[i][l]=6;
									}else{
										if(vet[i+2][l]==0){
											vet[i+1][l]=15;
										}
										vet[i][l]=6;
									}
								}
							}


						}
						if(num==3){
							if(vet[i][l+1]==0&&l!=dim-2){         // comportamento 3: va a destra, e se non può spara
								vet[i][l]=0;
								vet[i][l+1]=6;
							}else{
								flag=0;
								for(k=i+1;k<dim;k++){
									if(vet[k][l]==14||vet[k][l]==6){
										flag=1;
									}
								}
								if(flag==0){
									spara=1+rand()%10;
									if(spara%2==0){
										if(vet[i+2][l]==0){
											vet[i+1][l]=5;
										}
										vet[i][l]=6;
									}else{
										if(vet[i+2][l]==0){
											vet[i+1][l]=15;
										}
										vet[i][l]=6;
									}
								}
							}


						}
						if(num==4){
							if(vet[i+1][l]==0&&i!=(dim/2)-2){
								vet[i][l]=0;
								vet[i+1][l]=6;                // comportamento 4: va giu, e se non può spara
							}else{
								flag=0;
								for(k=i+1;k<dim;k++){
									if(vet[k][l]==14||vet[k][l]==6){
										flag=1;
									}
								}
								if(flag==0){
									spara=1+rand()%10;
									if(spara%2==0){
										if(vet[i+2][l]==0){
											vet[i+1][l]=5;
										}
										vet[i][l]=6;
									}else{
										if(vet[i+2][l]==0){
											vet[i+1][l]=15;
										}
										vet[i][l]=6;
									}
								}
							}

						}
						if(num==5){
							flag=0;
							for(k=i+1;k<dim;k++){
								if(vet[k][l]==14||vet[k][l]==6){    // comportamento 5: spara, ovviamente evitando se davanti a se ha un alleato
									flag=1;
								}
							}
							if(flag==0){
								spara=1+rand()%10;
								if(spara%2==0){
									if(vet[i+2][l]==0){
										vet[i+1][l]=5;
									}
									vet[i][l]=6;
								}else{
									if(vet[i+2][l]==0){
										vet[i+1][l]=15;
									}
									vet[i][l]=6;
								}
							}
						}
					}

				}
			}


		}
	}
	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if(vet[i][l]==6){
				vet[i][l]=14;
			}
		}
	}


}

// 각 반대편 선박에 대한 컴퓨터의 이동을 관리하는 기능
void artificial_intelligence (int vet[dim][dim],int dif) // 인공지능
{
	int i, l, num, flag, k, spara;

	srand(time(NULL));

	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if(vet[i][l]==3||vet[i][l]==12)
			{
				if(vet[i-1][l]==5&&vet[i][l-1]==0)
				{
					if(vet[i][l]==3)
					{
						vet[i][l-1]=6;
					}
					else
					{
						vet[i][l-1]=13;
					}
					vet[i][l]=0;                        
					// 이 2개가 가능하면 배가 총알을 피하는데 도움
				}

				else if(vet[i-1][l]==5&&vet[i][l+1]==0)
				{
					if(vet[i][l]==3)
					{
						vet[i][l+1]=6;
					}
					else
					{
						vet[i][l+1]=13;
					}
					vet[i][l]=0;
				}
				else 
				{
					num=1+rand()%dif;                 
					// 다른 행동을 유발하는 숫자를 랜덤으로 생성

					//행동 1: 왼쪽으로 가거나 쏠 수 없는 경우
					if(num==1) 
					{
						if(vet[i][l-1]==0&&l!=1)
						{
							if(vet[i][l]==3)
							{
								vet[i][l-1]=6;
							}
							else
							{
								vet[i][l-1]=13;
							}              
							vet[i][l]=0;
						}

						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{    
									// front mate가 1을 반환하면 free throw 궤적을 가지고 있는지 확인
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;           
								// 1~10 사이의 숫자를 생성, 일치하면 shot 실패, 일치하지 않으면 shoot이 실행되지 않음 
								if(spara%2==0)
								{
									if(vet[i+2][l]==0)
									{    
										vet[i+1][l]=5;   
									}
									if(vet[i][l]==3)
									{
										vet[i][l]=6; 
									}
									else
									{ 
										vet[i][l]=13;   
									}
								}
							}
						}
					}

					//행동 2: 계속해서 쏘지 못하는 경우
					if(num==2)
					{                           
						if(vet[i-1][l]==0&&i!=1)
						{
							if(vet[i][l]==3)
							{   
								vet[i-1][l]=6;   
							}
							else
							{    
								vet[i-1][l]=13;  
							}
							vet[i][l]=0;
						}
						else{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{       
									flag=1;        
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;
								if(spara%2==0)
								{
									if(vet[i+2][l]==0)
									{ 
										vet[i+1][l]=5;      
									}
									if(vet[i][l]==3)
									{    
										vet[i][l]=6;      
									}
									else
									{     
										vet[i][l]=13;    
									}
								}
							}
						}
					}
					//행동 3: 오른쪽으로 가면 쏘지 못할 경우               
					if(num==3)
					{
						if(vet[i][l+1]==0&&l!=dim-2)
						{
							if(vet[i][l]==3)
							{
								vet[i][l+1]=6;
							}
							else
							{
								vet[i][l+1]=13;
							}                                    
							vet[i][l]=0;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;
								if(spara%2==0)
								{
									if(vet[i+2][l]==0)
									{
										vet[i+1][l]=5;
									}
									if(vet[i][l]==3)
									{
										vet[i][l]=6;
									}
									else
									{
										vet[i][l]=13;
									}
								}
							}
						}
					}
					//행동4: 내려가서 쏘지 못하는 경우
					if(num==4)
					{
						if(vet[i+1][l]==0&&i!=(dim/2)-2)
						{
							if(vet[i][l]==3)
							{
								vet[i+1][l]=6;
							}
							else
							{
								vet[i+1][l]=13;
							}
							vet[i][l]=0;                      
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;
								if(spara%2==0)
								{
									if(vet[i+2][l]==0)
									{
										vet[i+1][l]=5;
									}
									if(vet[i][l]==3)
									{
										vet[i][l]=6;
									}
									else
									{
										vet[i][l]=13;
									}
								}
							}
						}
					}
					// 행동5: 당신 앞에 ally가 있으면 쏘고 피해라
					if(num==5)
					{
						flag=0;
						for(k=i+1;k<dim;k++)
						{
							if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13)
							{    
								flag=1;
							}
						}
						if(flag==0)
						{
							spara=1+rand()%10;
							if(spara%2==0)
							{
								if(vet[i+2][l]==0)
								{
									vet[i+1][l]=5;
								}
								if(vet[i][l]==3)
								{
									vet[i][l]=6;
								}
								else
								{
									vet[i][l]=13;
								}
							}
						}
					}

				}

			}
		}
	}
	// BOMBARDIERE INTELLIGENCE 폭탄 테러 정보
	for(i=0;i<dim;i++)
	{
		for(l=0;l<dim;l++)
		{
			if(vet[i][l]==7)
			{
				if(vet[i-1][l]==8&&vet[i][l-1]==0)
				{
					vet[i][l]=0;                           
					// 이 2개가 가능하면 배가 총알을 피하는데 도움
					vet[i][l-1]=9;
				}
				else if(vet[i-1][l]==8&&vet[i][l+1]==0)
				{
					vet[i][l]=0;
					vet[i][l+1]=9;

				}
				else
				{
					num=1+rand()%dif;                           
					// 다른 행동을 유발하는 숫자를 랜덤으로 생성

					//행동 1: 왼쪽으로 가거나 쏠 수 없는 경우
					if(num==1)
					{
						if(vet[i][l-1]==0&&l!=1)
						{             
							vet[i][l]=0;
							vet[i][l-1]=9;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==7||vet[k][l]==9)
								{    
									// front mate가 1을 반환하면 free throw 궤적을 가지고 있는지 확인
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;     

								// 1~10 사이의 숫자를 생성, 일치하면 shot 실패, 일치하지 않으면 shoot이 실행되지 않음 
								if(spara>7)
								{
									if(vet[i+2][l]==0)
									{
										vet[i+1][l]=8;
									}
									vet[i][l]=9;
								}
							}
						}
					}
					//행동 2: 계속해서 쏘지 못하는 경우
					if(num==2)
					{                           
						if(vet[i-1][l]==0&&i!=1)
						{
							vet[i][l]=0;
							vet[i-1][l]=9;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==7||vet[k][l]==9)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;
								if(spara>7)
								{
									if(vet[i+2][l]==0)
									{
										vet[i+1][l]=8;
									}
									vet[i][l]=9;
								}
							}
						}
					}
					//행동 3: 오른쪽으로 가면 쏘지 못할 경우
					if(num==3)
					{
						if(vet[i][l+1]==0&&l!=dim-2)
						{         
							vet[i][l]=0;
							vet[i][l+1]=9;
						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==7||vet[k][l]==9)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;
								if(spara>7)
								{
									if(vet[i+2][l]==0)
									{
										vet[i+1][l]=8;
									}
									vet[i][l]=9;
								}
							}
						}
					}
					//행동4: 내려가서 쏘지 못하는 경우
					if(num==4)
					{
						if(vet[i+1][l]==0&&i!=(dim/2)-2)
						{
							vet[i][l]=0;
							vet[i+1][l]=9;                

						}
						else
						{
							flag=0;
							for(k=i+1;k<dim;k++)
							{
								if(vet[k][l]==7||vet[k][l]==9)
								{
									flag=1;
								}
							}
							if(flag==0)
							{
								spara=1+rand()%10;
								if(spara>7)
								{
									if(vet[i+2][l]==0)
									{
										vet[i+1][l]=8;
									}
									vet[i][l]=9;
								}
							}
						}

					}

					// 행동5: 당신 앞에 ally가 있으면 쏘고 피해라
					if(num==5)
					{
						flag=0;
						for(k=i+1;k<dim;k++)
						{
							if(vet[k][l]==7||vet[k][l]==9)
							{    
								flag=1;
							}
						}
						if(flag==0)
						{
							spara=1+rand()%10;
							if(spara%2==0)
							{
								if(vet[i+2][l]==0)
								{
									vet[i+1][l]=8;
								}
								vet[i][l]=9;
							}
						}
					}

				}

			}
		}
	}

	for(i=0;i<dim;i++)
	{
		for(l=0;l<dim;l++)
		{
			if(vet[i][l]==6)
			{
				vet[i][l]=3;
			}else if(vet[i][l]==9)
			{
				vet[i][l]=7;
			}else if(vet[i][l]==13)
			{
				vet[i][l]=12;
			}
		}
	}
}

void mossa_giocatore(int vet[dim][dim],int azione,int sound)                    // Funzione per le azioni che può fare il giocatore, premendo sul tastierino numerico
{


	int i,l;
	switch(azione)
	{
	case 52:
		for(i=0;i<dim;i++){
			for(l=0;l<dim;l++){                                     // 52 asci sta per 4, ovvero azione per andare a sinistra
				if(vet[i][l]==2){
					if(l>1){
						vet[i][l]=0;
						vet[i][l-1]=2;
					}
				}
			}
		}

		break;
	case 54:
		for(i=0;i<dim;i++){
			for(l=dim;l>0;l--){
				if(vet[i][l]==2){                             // 54 asci sta per 6, ovvero azione per andare a destra
					if(l<dim-2){
						vet[i][l]=0;
						vet[i][l+1]=2;

					}
				}
			}
		}

		break;
	case 53:
		for(i=0;i<dim;i++){
			for(l=0;l<dim;l++){                           // 53 asci sta per 5, ovvero azione per sparare
				if(vet[i][l]==2){
					vet[i-1][l]=1;
					if (sound==1){
						//Beep(950,25);
					}

				}
			}
		}

		break;
	default:
		if (sound==1){
			//Beep(300,25);
		}

	}



}

void esplosione(int vet[dim][dim])                       // funzione che cancella le esplosioni dal vattore del campo una volta innescate
{
	int i,l;
	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if(vet[i][l]==4){
				vet[i][l]=16;
			}else if(vet[i][l]==16){
				vet[i][l]=0;
			}
		}
	}


}

void proiettile(int vet[dim][dim],int sound)           // funzione che calcola i movimenti dei proiettili saprati sia dal giocatore che dal nemico
{
	int i,l;
	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if(vet[i][l]==1){
				if(i==1){               // cerco i proiettili del giocatore e li faccio avanzare
					vet[i][l]=0;
				}else {
					vet[i][l]=0;
					vet[i-1][l]=1;
				}
			}
		}
	}
	for(i=dim-2;i>0;i--){
		for(l=0;l<dim;l++){
			if(vet[i][l]==5){         // cerco i proiettili nemici e li faccio avanzare
				if(i==dim-2){
					vet[i][l]=0;
				}else{
					vet[i][l]=0;
					vet[i+1][l]=5;
				}
			}
		}
	}
	for(i=dim-2;i>0;i--){                // bombe bombardieri
		for(l=0;l<dim;l++){
			if(vet[i][l]==8){         // cerco i proiettili nemici e li faccio avanzare
				if(i==dim-2){
					vet[i][l]=4;
					vet[i][l-1]=4;        //toccano il fondo esplodono
					vet[i][l+1]=4;
					if (sound==1){
						//Beep(150,50);
					}
				}else{
					vet[i][l]=0;
					vet[i+1][l]=8;
				}
			}
		}
	}
	for(i=dim-2;i>0;i--){                // bombe boss2
		for(l=0;l<dim;l++){
			if(vet[i][l]==15){         // cerco i proiettili e li faccio avanzare
				if(i==dim-2){
					vet[i][l]=4;
					vet[i][l-1]=4;
					vet[i][l-2]=4;    //toccano il fondo esplodono
					vet[i][l+1]=4;
					vet[i][l+2]=4;
					if (sound==1){
						//Beep(150,50);
					}
				}else{
					vet[i][l]=0;
					vet[i+1][l]=15;
				}
			}
		}
	}



}

int colpito(int vet[dim][dim],int sound)          // funzione che controlla se un nemico o il giocatore è stato colpito, e nel caso cambia il suo valore con quello dell'esplosione
{
	int i,l,punt=0;                   // variabili fra cui quella del punteggio

	for(i=0;i<dim;i++){
		for(l=0;l<dim;l++){
			if((vet[i][l]==3&&vet[i+1][l]==1)||(vet[i][l]==12&&vet[i+1][l]==1)){
				if(vet[i][l]==12){
					vet[i][l]=3;
					vet[i+1][l]=0;
					punt+=2;
					if (sound==1){
						//Beep(150,25);
					}
				}else{

					vet[i][l]=4;                       // controlla se il nemico è stato colpito, se si lo trasforma in esplosione e fa //Beep e aggiunge punteggio
					vet[i+1][l]=0;
					punt+=2;
					if (sound==1){
						//Beep(250,50);
					}
				}

			}else if(vet[i][l]==7&&vet[i+1][l]==1){
				vet[i][l]=4;                       // controlla se il nemico bombardiere è stato colpito, se si lo trasforma in esplosione e fa //Beep
				vet[i+1][l]=0;
				punt+=3;
				if (sound==1){
					//Beep(250,50);
				}
			}else if((vet[i][l]==10&&vet[i+1][l]==1)||(vet[i][l]==14&&vet[i+1][l]==1)){
				vet[i][l]=4;                       // controlla se il boss è stato colpito
				vet[i+1][l]=0;
				punt+=25;
				if (sound==1){
					//Beep(250,50);
				}
			}
		}
	}

	for(i=dim-2;i>0;i--){
		for(l=0;l<dim;l++){
			if(vet[i][l]==2&&vet[i-1][l]==5){       // controlla se è stato colpito il giocatore
				vet[i][l]=4;
				vet[i-1][l]=0;
				if (sound==1){
					//Beep(250,50);
				}
			}
			if(vet[i][l]==2&&vet[i-1][l]==8){       // controlla se è stato colpito il giocatore dalle bombe
				vet[i][l]=4;
				vet[i-1][l]=0;
				if (sound==1){
					//Beep(250,50);
				}
			}
			if(vet[i][l]==2&&vet[i-1][l-1]==8){       // controlla se è stato colpito il giocatore dalle bombe
				vet[i][l]=4;
				vet[i-1][l]=0;
				vet[i][l-1]=4;
				vet[i][l+1]=4;
				if (sound==1){
					//Beep(250,50);
				}
			}
			if(vet[i][l]==2&&vet[i-1][l+1]==8){       // controlla se è stato colpito il giocatore dalle bombe
				vet[i][l]=4;
				vet[i-1][l]=0;
				vet[i][l-1]=4;
				vet[i][l+1]=4;
				if (sound==1){
					//Beep(250,50);
				}
			}
			if(vet[i][l]==2&&vet[i-1][l]==15){       // controlla se è stato colpito il giocatore dalle bombe del boss
				vet[i][l]=4;
				vet[i-1][l]=0;
				if (sound==1){
					//Beep(250,50);
				}
			}
		}
	}

	return punt;


}