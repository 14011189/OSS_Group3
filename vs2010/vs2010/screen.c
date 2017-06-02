#include <windows.h>
#include "screen.h"



void sleep_mil(unsigned int ms)
{
    #if defined(WIN32)
      Sleep(ms);
    #elif defined(__unix__)
      usleep(1000*ms);
    #else
      printf("Unsupported operating system!");
    #endif

}

void clear_screen ( void )
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

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
  HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); // Funzione che mi permette di cambiare colore del testo;
  SetConsoleTextAttribute(hCon,Color);
}

//벡터 [N] [n]에 의해 필드를 구성하는 함수
void disegna_schermo(int vet[dim][dim],int point,int vit,int lv)                   
{
    int i,l;

    printf(" life: %d       (%d)     score: %d",vit,lv,point);

    for(i=0;i<dim;i++){
            printf("\n");
        for(l=0;l<dim;l++){

            if(i==0)
			{// 벡터에있는 어떤 값에 따라 플레이어, 적 
			//또는 기타 그래픽 측면을 그릴 여부를 알수있게 하는 것
                printf(" -");                             
            }
			else if(i==dim-1)
			{
                printf(" -");
            }
			else if(l==0)
			{
                printf(" | ");
            }
			else if(l==dim-1)
			{
                printf(" | ");
            }
            else if(vet[i][l]==0)
			{
                printf("  ");
            }
			else if(vet[i][l]==1)
			{
                printf(" |");
            }
			else if(vet[i][l]==2)
			{
                set_color(11);
                printf(" A");
                set_color(15);
            }
			else if(vet[i][l]==3)
			{
                set_color(14);
                printf(" W");
                set_color(15);
            }
			else if(vet[i][l]==4)
			{
                set_color(12);
                printf(" @");
                set_color(15);
            }
			else if(vet[i][l]==5)
			{
                set_color(6);
                printf(" U");
                set_color(15);
            }
			else if(vet[i][l]==7)
			{
                set_color(2);
                printf(" V");
                set_color(15);
            }
			else if(vet[i][l]==8)
			{
                set_color(10);
                printf(" o");
                set_color(15);
            }
			else if(vet[i][l]==10)
			{
                set_color(3);
                printf(" Y");
                set_color(15);
            }
			else if(vet[i][l]==12)
			{
                set_color(4);
                printf(" W");
                set_color(15);
            }
			else if(vet[i][l]==14)
			{
                set_color(5);
                printf(" X");
                set_color(15);
            }
			else if(vet[i][l]==15)
			{
                set_color(14);
                printf(" *");
                set_color(15);
            }
			else if(vet[i][l]==16)
			{
                set_color(12);
                printf(" @");
                set_color(15);
            }
        }
    }


}