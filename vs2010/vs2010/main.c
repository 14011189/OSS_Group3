#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <windows.h>          // need it for Sleep () function;
#endif
#ifdef __unix__
#include <unistd.h>
#endif // __unix__

#include <conio.h>            // getch, ptuch, kbhit을 실행시킬 때에 필요한 기능을 포함(키를 누를 경우 조건을 실현 기능) 
#include <time.h>            // Srand (time (NULL)); Num = 1 + rand ()% n for random numbers


//1. 이탈리아어를 영어로 변경하기 KHJ->LSR->SDH->ASY:완료
//2. 함수 분리 하기

#define dim 18

#include "condition.h"
#include "screen.h"
#include "object.h"

int main()    // The main function of the game
{
    int cate[dim][dim],i,l,move=0,condition,speed=100,diff;
    int victory=0, score, final_game=0, level, sound, life;
// Initialize the various variables of the main, including the pointer for the settings file

    int selection=0,record;
    char name[dim];
    FILE *fp;

	RemoveCursor();

    fp=fopen("dati.dat","r");    // Opening and reading the settings file
    if(fp==NULL){
        printf("\nERROR OPENING FILE!");
        sleep_mil(3000);
        return 1;
    }

    if(fscanf(fp,"%d %d %d %d %s",&speed,&diff,&sound,&record,name)==EOF){
        printf("\nERROR READING FILE!");
        sleep_mil(3000);
        return 1;
    }
    fclose(fp);


    while(selection!=5)    // Cycle while the menus until you select the exit from the game
    {
         system("cls");

           fp=fopen("dati.dat","r");
         if(fp==NULL){
             printf("\nERROR OPENING FILE!");
             sleep_mil(3000);
             return 1;
         }

         if(fscanf(fp,"%d %d %d %d %s",&speed,&diff,&sound,&record,name)==EOF){
             printf("\nERROR READING FILE!");
             sleep_mil(3000);
             return 1;
         }
         fclose(fp);

printf("\n     SPACE INVATERS v0.4                   \n");
         printf("\n                                            ");
         printf("\n                                            ");           //It prints on the game menu and waits for the player to choose
         printf("\n   1)New Game                               ");
         printf("\n   2)Game Guide                             ");
         printf("\n   3)Setting                                ");
         printf("\n   4)Credits                                ");
         printf("\n   5)Exit                                 \n");
         sleep_mil(500);
         Beep(450,200);
         printf("\n\n  choice: ");
         fflush(stdin);
         scanf("%d",&selection);


         switch(selection)
         {

             case 1:
             life=3;
             level=1;
             score=0;
             final_game=0;
             printf("\n Get ready to start the game!");    //Get ready to start the game!
             sleep_mil(2000);
             system("cls");     //clean the screen



             while(final_game==0)
             {

                 system("cls");
                 game_level(cate,level);    // Select the level with the function
                 victory=0;
                 disegna_schermo(cate,score,life,level);      // Design the game screen and look before the start of the game

                 sleep_mil(1500);

             while(victory==0)     // Cycle whilst doing the game until someone wins
{
                     clear_screen();
                     disegna_schermo(cate,score,life,level);
                     condition=0; 
                     sleep_mil(speed);
                     condition=_kbhit();                   
                     if(condition==1){      
                         move=_getch();
                         move_player(cate,move,sound);
                     }


                     if(level==4){
                         boss(cate,diff);
                     }else if(level==7||level==11||level==18||level==22||level==29||level==33){
                         ia_boss2(cate,diff);
                     }else{
                     artificial_intelligence(cate,diff);
                     }
                     explosion(cate);
                     score+=attacked(cate,sound); 

                     clear_screen();
                     disegna_schermo(cate,score,life,level);
                     bullet(cate,sound);

                     victory=victory_condition(cate);


                     if(victory==1){
                         printf("\n PLAYER'S WINNING !!!\n");
                         if(score>record&&level==33){
                             record=score;
                             printf("\n Enter the name for records: ");
                             scanf("%s",name);
                         }
                         sleep_mil(1000);
                     }else if(victory==2&&life>1){
                         system("cls");
                         disegna_schermo(cate,score,life,level);
                         life--;
                         sleep_mil(1000);
                         for(i=(dim-2);i>(dim/2);i--){
                           for(l=0;l<dim;l++){          
                         cate[i][l]=0;
                         }
                       }
                       cate[dim-2][(dim/2)-1]=2;
                       system("cls");
                       disegna_schermo(cate,score,life,level);
                       sleep_mil(500);
                       victory=0;


                     }else if(victory==2){
                         life--;
                         system("cls");
                         disegna_schermo(cate,score,life,level);
                         printf("\n THE PLAYER LOSE !!!\n");
                         if(score>record){
                             record=score;
                             printf("\n Enter the name for records: ");
                             scanf("%s",name);
                         }
                         sleep_mil(1000);
                     }else if(victory==3){
                         printf("\n ERROR SEARCH CONDITION VOCTORY!!!\n");
                         sleep_mil(3000);
                     }


                 }
                 if(victory==1&&level<11){
                     level++;
                     printf("\nPREPARE FOR THE NEXT LEVEL!!!\n");
                     Sleep(3000);
                     if(diff==10) score+=10;
                     if(diff==7) score+=20;
                     if(level%3==0){
                         printf("  LIFE BONUS !!!\n");
                         sleep_mil(1000);
                         life++;
                     }

                 }else{
                     system("cls");
                     if(victory==1) printf("\n Congratulations, you finished I'm fucking game!!!!");
                     printf("\n Press 1 to play again or a key to return to the menu: ");
                     sleep_mil(500);
                     fflush(stdin);
                     scanf("%d",&selection);
                     if(selection!=1) selection=6;
                     final_game=1;
                 }
             }
             break;

             case 2:
               system("cls");
	       printf("\n Game controls:                             ");
                printf("\n Use the numeric keypad to play             ");
                printf("\n 4: To go left                              ");
                printf("\n 6: To go right                             ");
                printf("\n 5: To shoot                             \n ");
                printf("\n Lower the enemy spaceships to win, to the initial 3 lives.\n");
                printf("\n Press a key to go back                   : ");
               fflush(stdin);
               scanf("%d",&selection);
               selection=6;
              break;

             case 3:
               system("cls");
               printf("\n Select the speed of play: 1) Normal 2) Fast 3) Crazy\n speed': ");
               scanf("%d",&speed);
             if(speed==2){
                 speed=50;
             }else if(speed==3){
                 speed=25;
             }else if(speed==4){
                 speed=50;
                 life=15;
             }
             else{
                 speed=75;
             }
             printf("\n Select difficulty: 1) easy 2) normal 3) difficult\n difficulty': ");
             scanf("%d",&diff);
             if(diff==3){
                 diff=7;
             }else if(diff==2){
                 diff=10;
             }else if(diff==4){
                 diff=35;
             }
             else{
                 diff=15;
             }
             printf("\n Select sound: 1) on 2) off sound: ");
             scanf("%d",&sound);

              printf("\n Press a key to go back: ");
              scanf("%d",&selection);
              selection=6;
              break;

              case 4:
                  system("cls");
                  printf("\n       SPACE INVATERS VER. 0.4  \n");
                  printf("\n Game made for boredom and for various fucking sticks.");
                  printf("\n Completely programmed in c from the only and inimitable I'm fucking!");
                  printf("\n All rights reserved to me in the event of unauthorized use of this program");
                  printf("\n You will be lynched by a crowd of penguins!!!");
                  printf("\n\n Current record: %d performed by %s",record,name);
                  printf("\n Press a key to go back: ");
                  fflush(stdin);
                  scanf("%d",&selection);
                  selection=6;
                  break;

              case 5:
                  printf("\n Get out of the game... missed!!!");
                  sleep_mil(1000);
                 break;

         }

    }

    fp=fopen("dati.dat","w");
    if(fp==NULL){
        printf("\n ERROR OPENING FILE!");
        sleep_mil(3000);
        return 1;
    }
    fprintf(fp,"%d %d %d %d %s",speed,diff,sound,record,name);
    fclose(fp);




    printf("\n Thank you for playing!\n");
    sleep_mil(3000);
    return 0;
}


