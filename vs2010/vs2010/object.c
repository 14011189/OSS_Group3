﻿#include <time.h> 
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

void intelligenza_artificiale(int vet[dim][dim],int dif)         // Funzione che gestisce le mosse del computer per ogni navicella avversaria
{
    int i,l,num,flag,k,spara;

    srand(time(NULL));

    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==3||vet[i][l]==12)
            {
                if(vet[i-1][l]==5&&vet[i][l-1]==0)
                {
                    if(vet[i][l]==3){
                       vet[i][l-1]=6;
                    }else{
                        vet[i][l-1]=13;
                    }
                    vet[i][l]=0;                         // questi due if servono perchè la navicella eviti un proiettile del compagno, se è possibile

                }else if(vet[i-1][l]==5&&vet[i][l+1]==0)
                {
                     if(vet[i][l]==3){
                       vet[i][l+1]=6;
                    }else{
                        vet[i][l+1]=13;
                    }

                    vet[i][l]=0;

                }else
                {



                num=1+rand()%dif;                           //genero un numero random che provoca diversi comportamneti


                if(num==1){
                    if(vet[i][l-1]==0&&l!=1){
                    if(vet[i][l]==3){
                       vet[i][l-1]=6;
                    }else{
                        vet[i][l-1]=13;
                    }                // comportmaneto 1: va a sinistra oppure se non può spara
                        vet[i][l]=0;

                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13){    //controlla se ha la traiettoria di tiro libera, se ha un compagno davanti restituisce 1
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;            // genera un numero fra 1 e 10 , se è pari lo sparo va a buon fine, altrimenti non spara
                    if(spara%2==0){
                            if(vet[i+2][l]==0){
                                vet[i+1][l]=5;
                            }
                    if(vet[i][l]==3){
                       vet[i][l]=6;
                    }else{
                        vet[i][l]=13;
                    }
                    }
                    }
                    }

                }
                if(num==2){                            // comportamento 2: va su, e se non può spara
                    if(vet[i-1][l]==0&&i!=1){
                    if(vet[i][l]==3){
                       vet[i-1][l]=6;
                    }else{
                        vet[i-1][l]=13;
                    }
                        vet[i][l]=0;

                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                         if(vet[i+2][l]==0){
                                vet[i+1][l]=5;
                            }
                      if(vet[i][l]==3){
                       vet[i][l]=6;
                    }else{
                        vet[i][l]=13;
                    }
                    }
                    }
                    }


                }
                if(num==3){
                    if(vet[i][l+1]==0&&l!=dim-2){
                    if(vet[i][l]==3){
                       vet[i][l+1]=6;
                    }else{
                        vet[i][l+1]=13;
                    }                                      // comportamento 3: va a destra, e se non può spara
                        vet[i][l]=0;

                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                         if(vet[i+2][l]==0){
                                vet[i+1][l]=5;
                            }
                    if(vet[i][l]==3){
                       vet[i][l]=6;
                    }else{
                        vet[i][l]=13;
                    }
                    }
                    }
                    }


                }
                if(num==4){
                    if(vet[i+1][l]==0&&i!=(dim/2)-2){
                    if(vet[i][l]==3){
                       vet[i+1][l]=6;
                    }else{
                        vet[i+1][l]=13;
                    }
                        vet[i][l]=0;                      // comportamento 4: va giu, e se non può spara

                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                         if(vet[i+2][l]==0){
                                vet[i+1][l]=5;
                            }
                     if(vet[i][l]==3){
                       vet[i][l]=6;
                     }else{
                        vet[i][l]=13;
                     }

                    }
                    }
                    }

                }
                if(num==5){
                    flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==3||vet[k][l]==6||vet[k][l]==12||vet[k][l]==13){    // comportamento 5: spara, ovviamente evitando se davanti a se ha un alleato
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        if(vet[i+2][l]==0){
                                vet[i+1][l]=5;
                            }
                     if(vet[i][l]==3){
                       vet[i][l]=6;
                     }else{
                        vet[i][l]=13;
                     }
                    }
                    }
                }

                }

            }
        }
    }
    // INTELLIGENZA BOMBARDIERE
    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==7)
            {
                if(vet[i-1][l]==8&&vet[i][l-1]==0)
                {
                    vet[i][l]=0;                             // questi due if servono perchè la navicella eviti un proiettile del compagno, se è possibile
                    vet[i][l-1]=9;
                }else if(vet[i-1][l]==8&&vet[i][l+1]==0)
                {
                    vet[i][l]=0;
                    vet[i][l+1]=9;

                }else
                {



                num=1+rand()%dif;                           //genero un numero random che provoca diversi comportamneti


                if(num==1){
                    if(vet[i][l-1]==0&&l!=1){              // comportmaneto 1: va a sinistra oppure se non può spara
                        vet[i][l]=0;
                        vet[i][l-1]=9;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==7||vet[k][l]==9){    //controlla se ha la traiettoria di tiro libera, se ha un compagno davanti restituisce 1
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;            // genera un numero fra 1 e 10 , se è pari lo sparo va a buon fine, altrimenti non spara
                    if(spara>7){
                      if(vet[i+2][l]==0){
                        vet[i+1][l]=8;
                        }
                        vet[i][l]=9;
                    }
                    }
                    }

                }
                if(num==2){                            // comportamento 2: va su, e se non può spara
                    if(vet[i-1][l]==0&&i!=1){
                        vet[i][l]=0;
                        vet[i-1][l]=9;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==7||vet[k][l]==9){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara>7){
                        if(vet[i+2][l]==0){
                        vet[i+1][l]=8;
                        }
                        vet[i][l]=9;
                    }
                    }
                    }


                }
                if(num==3){
                    if(vet[i][l+1]==0&&l!=dim-2){         // comportamento 3: va a destra, e se non può spara
                        vet[i][l]=0;
                        vet[i][l+1]=9;
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==7||vet[k][l]==9){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara>7){
                        if(vet[i+2][l]==0){
                        vet[i+1][l]=8;
                        }
                        vet[i][l]=9;
                    }
                    }
                    }


                }
                if(num==4){
                    if(vet[i+1][l]==0&&i!=(dim/2)-2){
                        vet[i][l]=0;
                        vet[i+1][l]=9;                // comportamento 4: va giu, e se non può spara
                    }else{
                        flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==7||vet[k][l]==9){
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara>7){
                        if(vet[i+2][l]==0){
                        vet[i+1][l]=8;
                        }
                        vet[i][l]=9;
                    }
                    }
                    }

                }
                if(num==5){
                    flag=0;
                    for(k=i+1;k<dim;k++){
                        if(vet[k][l]==7||vet[k][l]==9){    // comportamento 5: spara, ovviamente evitando se davanti a se ha un alleato
                            flag=1;
                        }
                    }
                    if(flag==0){
                            spara=1+rand()%10;
                    if(spara%2==0){
                        if(vet[i+2][l]==0){
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


    for(i=0;i<dim;i++){
        for(l=0;l<dim;l++){
            if(vet[i][l]==6){
                vet[i][l]=3;
            }else if(vet[i][l]==9){
                vet[i][l]=7;
            }else if(vet[i][l]==13){
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