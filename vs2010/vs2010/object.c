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
                }else if(vet[i+1][l]==1&&l!=dim-2&&num<dif)        // 랜덤으로 지정된 숫자가 10보다 적으면 사용자의 총알을 피함
                {
                    vet[i][l]=0;
                    vet[i][l+1]=6;

                }

                else{

                num=1+rand()%dif;                           // 행동 조건을 만드는 수를 랜덤으로 지정


                if(num==1){
                    if(vet[i][l-1]==0&&l!=1){              // 행동 1: 왼쪽 이동 또는 총알 발사 불가
                        vet[i][l]=0;
                        vet[i][l-1]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6){    //프론트 메이트가 1번 리턴 하는 경우, 자유 낙하 궤적이 있는지 확인
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;            // 1에서 10사이의 숫자를 생성, 샷이 실패할 수 있으며 그 경우에는 발사되지 않음
                    if(spara%2==0)
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
                if(num==2){                            // 행동 2: 발사되지 않은 경우, 계속해서 진행
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
                    if(vet[i][l+1]==0&&l!=dim-2){         // 행동 3: 발사되지 않을 경우, 오른쪽으로 이동
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
                        vet[i+1][l]=6;                // 행동 4: 발사되지 않은 경우, 아래로 이동
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
                        if(vet[k][l]==3||vet[k][l]==6){    // 행동 5; 발사, 앞에 적이 있을 경우 피할 수 있음
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
                                               // 총알을 피하기 위해 사용

                }else if((vet[i-1][l]==5&&vet[i][l+1]==0)||(vet[i-1][l]==15&&vet[i][l+1]==0))
                {
                    vet[i][l]=0;
                    vet[i][l+1]=6;
                                              // 총알을 방해하지 않기 위해 사용


                }else{
                num=1+rand()%dif;
                if(vet[i+1][l]==1&&l!=1&&num<dif&&vet[i][l-1]==0)
                {
                    vet[i][l]=0;
                    vet[i][l-1]=6;
                }else if(vet[i+1][l]==1&&l!=dim-2&&num<dif&&vet[i][l+1]==0)        // 랜덤으로 지정된 숫자가 10보다 적으면 사용자의 총알을 피함
                {
                    vet[i][l]=0;
                    vet[i][l+1]=6;

                }

                else{

                num=1+rand()%dif;                           // 행동 조건을 만드는 수를 랜덤으로 지정


                if(num==1){
                    if(vet[i][l-1]==0&&l!=1){              // 행동 1: 왼쪽 이동 또는 총알 발사 불가
                        vet[i][l]=0;
                        vet[i][l-1]=6;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==14||vet[k][l]==6){    // 프론트 메이트가 1번 리턴 하는 경우, 자유 낙하 궤적이 있는지 확인
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;            // 1에서 10사이의 숫자를 생성, 샷이 실패할 수 있으며 그 경우에는 발사되지 않음
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
                if(num==2){                            // 행동 2: 발사되지 않은 경우, 계속해서 진행
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
                    if(vet[i][l+1]==0&&l!=dim-2){         // 행동 3: 발사되지 않을 경우, 오른쪽으로 이동
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
                        vet[i+1][l]=6;                          // 행동 4: 발사되지 않은 경우, 아래로 이동
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
                        if(vet[k][l]==14||vet[k][l]==6){    // 행동 5; 발사, 앞에 적이 있을 경우 피할 수 있음
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

//주인공 객체에 대한 키보드 조작 함수
void move_player(int vet[dim][dim],int azione,int sound)
{

    int i,l;
	//azione->입력받은 키보드의 아스키코드 값
    switch(azione)
    {
	//아스키코드가 52인 왼쪽 방향키를 누르면 주인공 객체 왼쪽이동
    case 52:
        for(i=0;i<dim;i++){
            for(l=0;l<dim;l++){                                     
                if(vet[i][l]==2){
                        if(l>1){
                    vet[i][l]=0;
                    vet[i][l-1]=2;
                        }
                }
            }
        }

        break;
	//아스키코드가 54인 오른쪽 방향키를 누르면 주인공 객체 오른쪽이동
    case 54:
        for(i=0;i<dim;i++){
            for(l=dim;l>0;l--){
                if(vet[i][l]==2){                             
                        if(l<dim-2){
                    vet[i][l]=0;
                    vet[i][l+1]=2;

                }
            }
         }
        }

        break;
	//아스키코드가 53인 스페이스바를 누르면 주인공 객체 총알 발사
    case 53:
        for(i=0;i<dim;i++){
            for(l=0;l<dim;l++){                           
                if(vet[i][l]==2){
                    vet[i-1][l]=1;
                    if (sound==1){
                    }

                }
            }
        }

        break;
    default:
         if (sound==1){
        }

   }

}

// 폭발하고 그 폭발을 삭제하는 기능
void explosion(int vet[dim][dim])
{
    int i,l;
    for(i=0; i<dim; i++)
	{
        for(l=0;l<dim;l++)
		{
            if(vet[i][l]==4)
			{
                vet[i][l]=16;
            }
			else if(vet[i][l]==16)
			{
                vet[i][l]=0;
            }
        }
    }
}

//총알의 움직임을 계산하는 기능 
void bullet(int vet[dim][dim],int sound)     
{
    int i,l;
    for(i=0;i<dim;i++)
	{
        for(l=0; l<dim; l++)
		{
            if(vet[i][l]==1)
			{
                    if(i==1)
					{// player 총알 발사 함수               
                        vet[i][l]=0;
                    }
					else 
					{
                      vet[i][l]=0;
                      vet[i-1][l]=1;
                    }
            }
        }
    }
    
    for(i=dim-2;i>0;i--)
	{
        for(l=0;l<dim;l++)
		{
            if(vet[i][l]==5)
			{    // player 총알 발사 궤적 함수
                if(i==dim-2)
				{
                    vet[i][l]=0;
                }
				else
				{
                    vet[i][l]=0;
                    vet[i+1][l]=5;
                }
            }
        }
    }
    
    for(i=dim-2;i>0;i--)
	{               
        for(l=0;l<dim;l++)
		{
            if(vet[i][l]==8)
			{         
                if(i==dim-2)
				{
                    vet[i][l]=4;
                    vet[i][l-1]=4;      
                    vet[i][l+1]=4;
                    if (sound==1)
					{
                    Beep(150,50);
                    }
                }
				else
				{
                    vet[i][l]=0;
                    vet[i+1][l]=8;
                }
            }
        }
    }

	// 보스 2 폭탄
     for(i=dim-2;i>0;i--)
	 {                
        for(l=0;l<dim;l++)
		{
            if(vet[i][l]==15)
			{         
				// boss 2 총알 궤적 함수
                if(i==dim-2)
				{
                    vet[i][l]=4;
                    vet[i][l-1]=4;
                    vet[i][l-2]=4;    //총알이 닿았을 때 효과
                    vet[i][l+1]=4;
                    vet[i][l+2]=4;
                    if (sound==1)
					{
					 Beep(150,50);
                    }
                }
				else
				{
                    vet[i][l]=0;
                    vet[i+1][l]=15;
                }
            }
        }
    }
}

int attcked(int vet[dim][dim],int sound)
{
	/* 적 or 플레이어가 타격을 입었는지 여부 검사 */

    int i,l,point=0;     // 점수를 포함한 변수들 지정

    // Enemy
    for(i=0;i<dim;i++){     // (dim=무(無))
        for(l=0;l<dim;l++){
            if((vet[i][l]==3&&vet[i+1][l]==1)||(vet[i][l]==12&&vet[i+1][l]==1)){
            /* 적이 타격을 입었는지 여부를 확인
            타격 입었을 경우, 폭발효과와 함께 소리가 나고 점수를 획득 */
                if(vet[i][l]==12){
                    vet[i][l]=3;
                    vet[i+1][l]=0;
                    point+=2;
                    if (sound==1){
                        Beep(150,25);     // (beep=삑 하는 소리)
                    }
                }else{
                    vet[i][l]=4;
                    vet[i+1][l]=0;
                    point+=2;
                    if (sound==1){
                        Beep(250,50);
                    }
                }
            }else if(vet[i][l]==7&&vet[i+1][l]==1){
            /* 적 중에서도 폭격기가 타격을 입었는지 여부를 확인
	        타격 입었을 경우, 폭발효과와 함께 소리가 남 */
                vet[i][l]=4;
                vet[i+1][l]=0;
                point+=3;
                if (sound==1){
                    Beep(250,50);
                }
            }else if((vet[i][l]==10&&vet[i+1][l]==1)||(vet[i][l]==14&&vet[i+1][l]==1)){
            /* 보스가 타격을 입었는지 여부 확인
            타격 입었을 경우, 폭발효과와 함께 소리가 나며 큰 점수 획득 */
                vet[i][l]=4;
                vet[i+1][l]=0;
                point+=25;
                if (sound==1){
                    Beep(250,50);
                }
            }
        }
    }

    //Player
    for(i=dim-2;i>0;i--){
        for(l=0;l<dim;l++){
            if(vet[i][l]==2&&vet[i-1][l]==5){
            /* 플레이어가 타격을 입었는지 여부 확인
            위의 적이 타격입은 경우와의 차이점은 점수 변화가 없고 vet[i+1][l]=0이 아닌 vet[i-1][l]=0 */
                vet[i][l]=4;
                vet[i-1][l]=0;
                if (sound==1){
                    Beep(250,50);
                }
            }
            if(vet[i][l]==2&&vet[i-1][l]==8){
            /* 플레이어가 폭탄에 의해 타격을 입었는지 여부 확인 */
                vet[i][l]=4;
                vet[i-1][l]=0;
                if (sound==1){
                    Beep(250,50);
                }
            }
            if(vet[i][l]==2&&vet[i-1][l-1]==8){
            /* 플레이어가 폭탄에 의해 타격을 입었는지 여부 확인
            위의 경우와 차이점은 vet[i][l-1]=4, vet[i][l+1]=4 이 추가됨*/
                vet[i][l]=4;
                vet[i-1][l]=0;
                vet[i][l-1]=4;
                vet[i][l+1]=4;
                if (sound==1){
                    Beep(250,50);
                }
            }
            if(vet[i][l]==2&&vet[i-1][l+1]==8){
            /* 플레이어가 폭탄에 의해 타격을 입었는지 여부 확인
            위와 변화 동일 -> 연산자 || 를 이용해 합쳐서 개선 가능 */
                vet[i][l]=4;
                vet[i-1][l]=0;
                vet[i][l-1]=4;
                vet[i][l+1]=4;
                if (sound==1){
                    Beep(250,50);
                }
            }
            if(vet[i][l]==2&&vet[i-1][l]==15){
            /* 보스로부터 타격 입었는지 여부 확인 */
                vet[i][l]=4;
                vet[i-1][l]=0;
                if (sound==1){
                    Beep(250,50);
                }
            }
        }
    }
    return point;
}
