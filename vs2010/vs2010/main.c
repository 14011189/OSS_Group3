#include <stdio.h>            // 입출력함수(standard input/output) 헤더파일 안의 내용들을 포함
#include <stdlib.h>           // 문자열 변환, 난수 생성 등의 함수(standard library)들을 포함
#ifdef WIN32
#include <windows.h>          // mi serve per la funzione di Sleep(); // Sleep(); 함수를 실행시키기 위해 필요
#endif                        // ifdef와 함께 쓰이며 컴파일시에 WIN32가 포함돼있을 경우에만 사이에 있는 절들을 실행

#ifdef __unix__
#include <unistd.h>           // POSIX 운영체제 API에 접근하게 해주는 헤더파일을 포함
#endif // __unix__             //ifdef와 함께 쓰이며 사이에 있는 절들을 실행
#include <conio.h>            // Mi serve per la funzione di getch e ptuch e kbhit(funzione che realizza condizione se premo un tasto)
                              //getch, ptuch, kbhit을 실행시킬 때에 필요한 기능을 포함(키 를 누를 경우 조건을 실현 기능)
#include <time.h>            // srand( time( NULL ) );  num=1 +rand()%n  per numeri casuali
                             // srand( time( NULL ) );를 사용하기 위해 필요(랜덤으로 수를 지정)


//1. 이탈리아어를 영어로 변경하기 KHJ->LSR->SDH->ASY:완료
//2. 함수 분리 하기

#define dim 18  //dim을 18로 정의

#include "condition.h"
#include "screen.h"
#include "object.h"

int main()
{
	/* 코드의 메인함수 */

    int cate[dim][dim],i,l,move=0,condition,speed=100,diff;
    int victory=0, score, fianl_game=0, level, sound, life;
    /* Setting 파일의 포인터들을 포함하여 메인 함수들의 변수들을 초기화 */
    int selection=0,record;
    char name[dim];
    FILE *fp;

//	RemoveCursor();

    /* Setting 파일 열고 읽기
    읽고 여는 것이 오류 날 경우 sleep_mill=3000 */
    fp=fopen("dati.dat","r");     // fopen = 파일 입력 함수
    if(fp==NULL){
        printf("\nERROR OPENING FILE!");
        sleep_mil(3000);
        return 1;
    }

    if(fscanf(fp,"%d %d %d %d %s",&speed,&diff,&sound,&record,name)==EOF){    //EOF = End of File, 종료
        printf("\nERROR READING FILE!");
        sleep_mil(3000);
        return 1;
    }
    fclose(fp);    // fclose = 파일 출력 함수

    /* 사용자가 게임 탈출을 선택(selection = 5)하기 전까지 루프 반복 */
    while(selection!=5)
    {
        system("cls");    // 콘솔 화면을 깨끗이 지움

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

        /* 사용자의 선택을 위한 게임 메뉴 출력
        1) 새 게임, 2) 게임 설명, 3) 환경설정, 4) 크레딧, 5) 종료*/
        printf("\n     SPACE INVATERS v0.4                  \n");     // 게임 이름
        printf("\n                                            ");
        printf("\n                                            ");
        printf("\n   1) New game                              ");
        printf("\n   2) Game Guide                            ");
        printf("\n   3) Setting                               ");
        printf("\n   4) Credits                               ");
        printf("\n   5) Exit                                \n");
        sleep_mil(500);
        Beep(450,200);
        printf("\n\n  choice: ");
        fflush(stdin);     // 입력버퍼를 지움
        scanf("%d",&selection);    // 위 5가지 중 한 가지 선택 받기


        /* selectiona 값의 선택 따라서 다른 상황 연출 (1~5가지 상황) */
        switch(selection)
        {
            /* 1) 새 게임
            생명 3개, 레벨 1, 시작 점수 0, 최종 점수 0 으로 게임 시작 */
            case 1:
                life=3;
                level=1;
                score=0;
                fianl_game=0;
                printf("\n Get ready to start the game!");     //  게임 준비!
                sleep_mil(2000);
                system("cls");     // clean the screen

                /* 함수와 레벨을 선택하고 게임 화면을 구성
                main 함수 위에서 지정했던 다양한 사용자 지정 함수들 소환 */
                while(fianl_game==0)     // 최종 점수가 0일 동안 반복
                {
                    system("cls");
                    game_level(cate,level);
                    victory=0;
                    disegna_schermo(cate,score,life,level);  // 게임 화면 재 설계
                    sleep_mil(1500);

                    /* 누군가가 승리할 때까지 게임을 계속 수행 */
                    while(victory==0)    // 승리 횟수가 0일 동안 반복
                    {
                        clear_screen();
                        disegna_schermo(cate,score,life,level);
                        condition=0;     // 상태 0으로 입력
                        sleep_mil(speed);
                        condition=_kbhit();
                        if(condition==1){
                            move=_getch();
                            move_player(cate,move,sound);
                        }

                        /* 특정 레벨에 도달 할 경우 보스 등장 */
                        if(level==4){
                            boss(cate,diff);
                        }else if(level==7||level==11||level==18||level==22||level==29||level==33){
                            ia_boss2(cate,diff);
                        }else{
                            artificial_intelligence(cate,diff);     // 인공 지능
                        }

                        explosion(cate);      // 폭발
                        score+=attacked(cate,sound);     // 누가 누구와 충돌했는지 & 점수 계산
                                          // 총알의 움직임을 위해 함수 실행
                        clear_screen();     // 화면을 다시 지우고 일어났던 변화들을 적용
                        disegna_schermo(cate,score,life,level);
                        bullet(cate,sound);

                        victory=victory_condition(cate);

                        /* 플레이어의 생명과 승리 */
                        if(victory==1){
                            printf("\n PLAYER'S WINNING !!!\n");     // 플레이어 승리!
                            if(score>record&&level==33){
                                record=score;
                                printf("\n Enter name for records: ");
                                scanf("%s",name);
                            }
                            sleep_mil(1000);
                        }else if(victory==2&&life>1){     // 생명이 남았을 경우
                            system("cls");
                            disegna_schermo(cate,score,life,level);
                            life--;
                            sleep_mil(1000);
                            for(i=(dim-2);i>(dim/2);i--){
                                for(l=0;l<dim;l++){     // 플레이어를 통해 총알 비움
                                    cate[i][l]=0;
                                }
                            }
                            cate[dim-2][(dim/2)-1]=2;     // 플레이어의 부활
                            system("cls");
                            disegna_schermo(cate,score,life,level);
                            sleep_mil(500);
                            victory=0;

                        }else if(victory==2){
                            life--;
                            system("cls");     // 생명 고갈
                            disegna_schermo(cate,score,life,level);
                            printf("\n THE PLAYER HAD !!!\n");     // 플레이어 패배!
                            if(score>record){
                                record=score;
                                printf("\n Enter name for records: ");
                                scanf("%s",name);
                            }
                            sleep_mil(1000);
                        }else if(victory==3){
                            printf("\n ERROR SEARCH CONDITION VICTORY !!!\n");     // 오류
                            sleep_mil(3000);
                        }

                    }
                    if(victory==1&&level<11){
                        level++;
                        printf("\nPREPARE FOR THE NEXT LEVEL !!!\n");     // 승리와 레벨 업
                        Sleep(3000);
                        if(diff==10) score+=10;
                        if(diff==7) score+=20;
                        if(level%3==0){
                            printf("  LIFE BONUS !!!\n");    // 생명 보너스
                            sleep_mil(1000);
                            life++;
                        }

                    /* 게임 완료 -> 첫 화면으로 */
                    }else{
                        system("cls");
                        if(victory==1) printf("\n Congratulations, you finished I'm fucking game !!!!");
                        printf("\n Press 1 to play again or a key to return to the menu: ");
                        sleep_mil(500);
                        fflush(stdin);
                        scanf("%d",&selection);
                        if(selection!=1) selection=6;
                        fianl_game=1;
                    }
                }
                break;

            /* 2) 게임 설명 */
            case 2:
                system("cls");
                printf("\n Game controls:                             ");     // 게임 설명
                printf("\n Use the numeric keypad to play             ");     // 게임을 위해서 숫자키를 사용
                printf("\n 4: To go left                              ");     // 4 : 좌로 이동
                printf("\n 6: To go right                             ");     // 6 : 우로 이동
                printf("\n 5: To shoot                             \n ");     // 5 : 총알 발사
                printf("\n Lower the enemy spaceships to win, to the initial 3 lives.\n");    // 3개의 생명이 있으며, 적 비행선이 적을수록 게임에서 승리
                printf("\n Press a key to go back                   : ");     // 뒤로 가기
                fflush(stdin);
                scanf("%d",&selection);
                selection=6;     // 어떤 key를 누르던지 초기 화면으로 갈 수 있도록 조절
                break;

            /* 3) 환경 설정 */
            case 3:
                system("cls");
                /* speed 값을 변경하여 게임 속도 조절 */
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
                /* diff 값을 변경하여 게임 난이도 조절 */
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
                /* sound 값을 변경하여 소리 유무 선택 */
                printf("\n Select sound: 1) on 2) off sound: ");
                scanf("%d",&sound);
                /* 뒤로 가기 */
                printf("\n Press a key to go back: ");
                scanf("%d",&selection);
                selection=6;
                break;

            /* 4) 크레딧 */
            case 4:
                system("cls");
                printf("\n       SPACE INVATERS VER. 0.4  \n");
                printf("\n Game made for boredom and for various fucking sticks.");
                printf("\n Completely programmed in c from the only and inimitable I'm fucking!");
                printf("\n All rights reserved to me in the event of unauthorized use of this program");
                printf("\n You will be lynched by a crowd of penguins!!!");
                printf("\n\n Current record: %d performed by %s",record,name);
                printf("\n Press a key to go back: ");     // 뒤로 가기
                fflush(stdin);
                scanf("%d",&selection);
                selection=6;
                break;

            /* 5) 게임 종료 */
            case 5:
                printf("\n Get out of the game ... missed!!!");
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