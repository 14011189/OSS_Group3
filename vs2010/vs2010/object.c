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