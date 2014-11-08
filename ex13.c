 /* ASPIPO - aspirador de po inteligente                                   */
 /* Copyright 2011. Licenca GNU/GPL                                        */

 #include <stdio.h>
 #include "libaspipo.h"

 int main(void)
 {
   /*Declara as variaveis*/

   int posicao, l;
   int d, e, leita, leitb, leitc;
   int esq, dir;
   int num_sala, num_sala_dir, num_sala_esq;
   int passar, cont;


   d=0;
   dir=0;
   e=0;
   esq=0;
   posicao=1;/*0-direita, 1-esquerda*/
   cont=0;
 

     desempenho md1={0, 0, 0, 0, 0, 0, 0, 0, 0};
     md1.v_limpar=100;
     md1.v_tempolimpo=1;
     md1.v_andar=-10;
     md1.v_ler=-2;
     md1.v_aspirar=-50;
     md1.v_assoprar=-95;
     md1.v_passarvez=0;
     md1.v_desc=100;
     md1.v_bonus=10;

     probabilidade pr1={0.0, 0.0, 0.0, 0.0, 0.0};
     pr1.p_sujar=0.03;
     pr1.p_succao=0.25;
     pr1.p_terremoto=0.01;
     pr1.p_movimento=0.2;
     pr1.p_sensorial=0.1;


   inicializar_ambiente(OBS0, DETSUJEIRA|DETMOVIMENTO|DETSENSORES, 0, APRIORI6, DESC0, FOLGA0, &md1, &pr1);

   while(qtd_acoes()<=MAXACOES)
   {

     /*calibracao inicial para a direita*/
     while (d<3){
         if(ler_sujeira()==1){
             if(ler_sujeira()==1){
             aspirar();
             }}
         dir=ler_posicao();
         direita();
         num_sala_dir=dir;
         d++;
         if(ler_posicao()!=dir){
             d=0;}
     }

    /*calibracao inicial para a esquerda*/
     while (e<3){
         if(ler_sujeira()==1){
             if(ler_sujeira()==1){
             aspirar();
             }}
         esq=ler_posicao();
         esquerda();
         num_sala_esq=esq;
         e++;
         if(ler_posicao()!=esq){
             e=0;}
     }

     cont=0;

     /*inicia um laco de X limpezas e andadas*/
     while(cont<10){
         if(ler_sujeira()==1){
             if(ler_sujeira()==1){
                 aspirar();}}
         if(posicao==1){
             direita();
             }
         else{
             esquerda();
             }
     cont++;
     }

     if(posicao==0)
         posicao=1;
     else
         posicao=0;


     cont=0;

     /*anda e aspira no caso das rodas travarem*/
     while(cont<5){
         l=1;
             while(l>0){
                 leita=ler_posicao();
                 leitb=ler_posicao();
                 leitc=ler_posicao();
                 if(leita==leitb){
                     if(leitb==leitc){
                         num_sala=leitc;
                         l=0;}}
             }
         if(num_sala==num_sala_dir){
             break;}
         if(num_sala==num_sala_esq){
             break;}
         if(ler_sujeira()==1){
             if(ler_sujeira()==1){
                 aspirar();}}
         if(posicao==0)
             direita();
         else
             esquerda();
         cont++;
     }

     /*passar a vez nas salas das bordas*/
     if (num_sala==num_sala_dir){
         passar=0;
             while(passar<3){
             passar_vez();
             passar++;
             }
     }
     if (num_sala==num_sala_esq){
         passar=0;
             while(passar<3){
             passar_vez();
             passar++;
             }
     }
 }

   finalizar_ambiente();
   pontos();
   return 0;
 }
