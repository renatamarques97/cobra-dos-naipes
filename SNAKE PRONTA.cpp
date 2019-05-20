#include<windows.h> //janelas
#include<stdio.h>
#include<conio.h> //movimentação continua
#include<iostream>
#include<stdlib.h>
#include<time.h> // gerar bolinha aleatória
void coordenadas(int x, int y){  // função das coordenadas
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}
 // função principal
int main(){
 short x=0; // coordenada principal (y=0)
 int direction=2; // o ponto inicial deve ir para a direita
 int snakex[50]={5,5},snakey[50]={5,5}; //vetores das coordenadas da cobra
 int size=1; //tamanho da cobra
 int foodx,foody;  // coordenadas do alimento
 int wrongx,wrongy; // alimento errado
 int sp=100,sp2=5; // velocidade
 char key='a';  // cordena os movimentos e saida do jogo
 short points = 0; // pontuação
 short level = 1;
 short dificuldade=0;
   coordenadas(12,5); // apresentação
   printf("SNAKE\n\n");
   coordenadas(40,7);
   printf("RENATA MARQUES\n\n");
   coordenadas(40,8);
   printf("renata.nrmarques@gmail.com\n\n");
   coordenadas(6,7);
   printf("1 - EASY\n\n");
   coordenadas(6,8);
   printf("2 - MODERATE\n\n");
   coordenadas(6,9);
   printf("3 - HARD\n\n");
   coordenadas(6,10);
   scanf("%i",&dificuldade);
   system("cls");
   switch(dificuldade){
   case 1:
   	sp = 180; // velocidade de movimento da cobra(baixa)(quanto menor o numero, maior a velocidade)
	   break;
   case 2:
   	sp = 130; // velocidade de movimento da cobra (media)
   	break;
    case 3:
   	sp = 80; // velocidade de movimento da cobra (alta)
   	break;
   default:
	   break;
   }
  // borda do jogo e cobra
 for(x=0;x<20;x++){ //laço para definir tamanho da parede
 coordenadas(0,x); // coordenadas da parede vertical
 printf("%c",219); // parede
 }
 for(x=0;x<60;x++){ 
 coordenadas(x,0);
 printf("%c",219);
 }
 for(x=0;x<20;x++){
 coordenadas(60,x); // coordenadas da parede horizontal
 printf("%c",219);
 }
 for(x=0;x<61;x++){
 coordenadas(x,20);
 printf("%c",219);
 }
 srand(time(NULL)); // valores aleatórios para o alimento da cobra
 foodx=(rand()%58)+1;
 foody=(rand()%18)+1;
 
 srand(time(NULL)); // valores aleatórios para o alimento errado da cobra
 wrongx=(rand()%57)+2;
 wrongy=(rand()%17)+2;
 
 while(key!='s'){
 while(key!='s'&&!(key=kbhit())){ // função kbhit - MOVIMENTO CONTINUO DA COBRA
 for(x=size;x>0;x--){
  snakex[x]=snakex[x-1]; // apaga estado anterior da cobra(horizantal)
  snakey[x]=snakey[x-1]; // apaga estado anterior da cobra(vertical)
  }
 if(direction==0) // esquerda
 snakex[0]--;
 if(direction==1) // para cima
 snakey[0]--;
 if(direction==2) // direita
 snakex[0]++;
 if(direction==3) // para baixo
 snakey[0]++;
 // cobrinha
 coordenadas(snakex[size],snakey[size]);
 printf(" ");
 if(foodx==snakex[0]&&foody==snakey[0]){// se a cobra pegar a bolinha, ela cresce e os pontos tbm
 // tamanho da cobra aumentando conforme os pontos
 Beep (500,300); //som
 size++;
 points+=10;
 level ++;
 foodx=(rand()%58)+1; //sempre que a cobra pegar a bolinha, aparece outra aleatória
 foody=(rand()%18)+1;
 sp-=5; // velocidade aumentando conforme os pontos(quanto menor, maior)
 sp2+=5; //velocidade que vai ser mostrada(crescente)
 }
 if(wrongx==snakex[0]&&wrongy==snakey[0]){  // se a cobra pegar a bolinha errada
 Beep (500,300); //som
 size--; // tamanho diminui
 points-=10; // ponto diminui
 level --;  //nivel diminui
 wrongx=(rand()%57)+1; //sempre que a cobra pegar a bolinha
 wrongy=(rand()%17)+1;
 coordenadas(snakex[size],snakey[size]);
 printf(" "); //simbolo do estado anterior
  if(size == 0){
     key='s';
  }
 sp-=5; // velocidade aumentando conforme os pontos(quanto menor, maior)
 sp2+=5; //velocidade que vai ser mostrada(crescente)
 }
 // coordenadas das informações do jogo
 coordenadas(snakex[0],snakey[0]);
 printf("%c",178); // simbolo da cobra
 coordenadas(foodx,foody);
 printf("%c",4); // simbolo da bolinha
 coordenadas(wrongx,wrongy);
 printf("x"); // simbolo da bolinha errada
 coordenadas(37,22);
 printf ("LEVEL :%d",level);
 coordenadas(49,22);
 printf ("Score: %d",points);
 coordenadas(12,22);
 printf ("Speed: %d",sp2);
 coordenadas(1,22);
 printf("SNAKE");
 Sleep(sp);
  // teclas habilitadas
 for(x=1;x<size;x++){
 if(snakex[0]==snakex[x]&&snakey[0]==snakey[x]) //se a cobra se tocar, jogo para
 key='s';
 }
  if(snakey[0]==0||snakey[0]==20||snakex[0]==0||snakex[0]==60){ // parar o jogo quando bater na parede
    key='s';
    Beep (900,700); //som
  }
 }
 if(key!='s') //limpa o buffer
 key=getch();
 if(key=='K')
 direction=0; // direção da cobra (0=esquerda)
 if(key=='H')
 direction=1; // (1=cima)
 if(key=='M')
 direction=2; // (2=direita)
 if(key=='P')
 direction=3; // (3=baixo)

 }
 printf ("\nYOU LOSE\n");
 system("pause"); // pausa o jogo quando perde
 system("cls"); // limpa a tela
 coordenadas(20,8);
 printf("renata.nrmarques@gmail.com");
 coordenadas(20,10);
 printf ("SCORE :%d",points); //exibe a pontuação;
 coordenadas(20,12);
 printf ("LEVEL :%d",level);
 coordenadas(20,14);
 printf ("SPEED :%d\n",sp2);
 getch();
}