#include <windows.h>           // Sleep(); 함수를 실행시키기 위해 필요
#include "screen.h"            



void sleep_mil(unsigned int ms)
{
    #if defined(WIN32)
      Sleep(ms);             // 이때, ms = 10^-3, us = 10^-6, ns = 10^-9
    #elif defined(__unix__)
      usleep(1000*ms);
    #else
      printf("Unsupported operating system!");
    #endif

}

void clear_screen ( void )
{
  DWORD n;                         // Number of characters written
  DWORD size;                      // number of visible characters
  COORD coord = {0};               //왼쪽 상단 화면을 0으로 지정
  CONSOLE_SCREEN_BUFFER_INFO csbi;  //버퍼 정보 얻기

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

  /* Reset the cursor to the top left position */
  SetConsoleCursorPosition ( h, coord );
}

void set_color(short Color)
{
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); // 텍스트 색상을 변경할 수 있는 기능
                                                 // Function that allows me to change the color of the text
  SetConsoleTextAttribute(hCon,Color);
}

void disegna_schermo(int vet[dim][dim],int punt,int vit,int lv)                   // Funzione che disegna il campo di gioco da un vettore[n][n]
{
    int i,l;

    printf(" vite: %d       (%d)     punteggio: %d",vit,lv,punt);

    for(i=0;i<dim;i++){
            printf("\n");
        for(l=0;l<dim;l++){

            if(i==0){
                printf(" -");                             //secondo quali valori trova nel vettore sa se disegnare il giocatore, i nemici o gli altri aspetti grafici
            }else if(i==dim-1){
                printf(" -");
            }else if(l==0){
                printf(" | ");
            }else if(l==dim-1){
                printf(" | ");
            }
            else if(vet[i][l]==0){
                printf("  ");
            }else if(vet[i][l]==1){
                printf(" |");
            }else if(vet[i][l]==2){
                set_color(11);
                printf(" A");
                set_color(15);
            }else if(vet[i][l]==3){
                set_color(14);
                printf(" W");
                set_color(15);
            }else if(vet[i][l]==4){
                set_color(12);
                printf(" @");
                set_color(15);
            }else if(vet[i][l]==5){
                set_color(6);
                printf(" U");
                set_color(15);
            }else if(vet[i][l]==7){
                set_color(2);
                printf(" V");
                set_color(15);
            }else if(vet[i][l]==8){
                set_color(10);
                printf(" o");
                set_color(15);
            }else if(vet[i][l]==10){
                set_color(3);
                printf(" Y");
                set_color(15);
            }else if(vet[i][l]==12){
                set_color(4);
                printf(" W");
                set_color(15);
            }else if(vet[i][l]==14){
                set_color(5);
                printf(" X");
                set_color(15);
            }else if(vet[i][l]==15){
                set_color(14);
                printf(" *");
                set_color(15);
            }else if(vet[i][l]==16){
                set_color(12);
                printf(" @");
                set_color(15);
            }
        }
    }


}