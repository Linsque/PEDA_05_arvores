// Rafael Bonfim Zacco

/*
Sua tarefa será construir uma árvore binária, lembrando que árvore binária são aquelas que possuem no máximo dois filhos em cada vértice. Esta árvore será gerada de forma aleatória e deve possuir um número de vértices aleatoriamente selecionado entre 10 e 26 vértices. Para criar esta árvore você irá criar um array capaz de armazenar uma quantidade de itens equivalente ao número de vértices da árvore que será gerada e preencher estes vértices com valores aleatórios entre 1 e 1000. Este array será usado para montar a árvore binária.

Você deverá criar uma regra de montagem para varrer o array e colocar seus valores nos vértices da árvore. Com a árvore binária montada, no terminal, você deverá apresentar as seguintes saídas:

a) A impressão do array gerado no formato apresentado a seguir para apenas 5 vertices:
Array Gerado: [1, 12, 45, 3, 6]

b) A impressão da árvore em ASCII usando o modelo a seguir que mostra uma árvore com o valor 12 na raiz, com dois filhos com os valores 5 e 1. Nesta árvore o vértice de valor 5 possui dois filhos com valores 11 e 2.
12
+ 5
 +11
 +2
+1
Observe que os nós estão sendo deslocados horizontalmente por meio do caracter tab “\t” de forma que os vértices filhos estão deslocados para direita de um tab em relação ao seu pai. Todas as linhas começam com + para indicar que é um vértice.

c) A impressão dos valores armazenados no vértices da árvore usando os algoritmos de transversalidade in-order, pre-order e post-order, segundo os modelos a seguir nos quais os valores utilizados são meramente ilustrativos:
In-order: {D, B, E, A, F, C, G}
Pre-order: {A, B, D, E, C, F, G}
Post-order: {D, E, B, F, G, C, A}

d) Uma lista dos valores armazenados em todas as folhas da árvore gerada segundo o modelo a seguir, para apenas 5 folhas:
Folhas: [1, 5, 7, 8, 12]

e) Uma lista do resultado da busca de 10 valores aleatoriamente gerados entre 300 e 575 e o diagnóstico da existência, ou não, deste número na árvore gerada. Este diagnóstico deve ser feito com as palavras: presente e ausente, conforme o modelo a seguir para dois valores:
Valor gerado: 312; Diagnóstico: Presente
Valor gerado: 542; Diagnóstico: Ausente
Observação, os valores utilizados para criar o array serão gerados de forma aleatória, sendo assim, não há nenhum problema que existam valores repetidos nos vértices da árvore. Além disso, lembre-se: uma estrutura de dados precisa da definição de uma arquitetura de memória e de no mínimo, um método para inclusão, um para exclusão e um para busca.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void arrayGerado(int array[],int tamanho){

  int i;
  
  for (i=0;i<tamanho;i++){
    if (i==0){
      printf("\nArray Gerado[%d] = [",tamanho);
    }
    if (i==(tamanho-1)){
      printf("%d]",array[i]);
    }
    else{
      printf("%d,",array[i]);
    }
  }
}

int filho_DIREITA(int i) {
  return (i * 2 + 1) + 1 ;
}

int filho_ESQUERDA(int i) {
  return (i * 2 + 1);
}

void ascii(int array[], int inicio,int max, int andar){ 
  andar++;
  
  if(inicio < max){
    for(int i=1;i<andar;i++){
      printf("\t");
    }
    if (andar != 1){
      printf("+");
    }
    printf("%d\n",array[inicio]);
    ascii(array,filho_ESQUERDA(inicio),max,andar);
    ascii(array,filho_DIREITA(inicio),max,andar); 
  }
}

void in_order(int array[], int inicio,int max, int andar){ 
  andar++;

  if(inicio < max){
    in_order(array,filho_ESQUERDA(inicio),max,andar);
    printf("%d, ",array[inicio]);
    in_order(array,filho_DIREITA(inicio),max,andar);
  }
}

void pre_order(int array[], int inicio,int max, int andar){ 
  andar++;

  if(inicio < max){
    printf("%d, ",array[inicio]);
    pre_order(array,filho_ESQUERDA(inicio),max,andar);
    pre_order(array,filho_DIREITA(inicio),max,andar);
  }
}

void post_order(int array[], int inicio,int max, int andar){ 
  andar++;

  if(inicio < max){
    printf("%d, ",array[inicio]);
    post_order(array,filho_DIREITA(inicio),max,andar);
    post_order(array,filho_ESQUERDA(inicio),max,andar);
  }
}

void folhas(int array[], int inicio,int max, int andar){ 
  andar++;

  if(inicio < max){
    if( (filho_ESQUERDA(inicio) > max) && (filho_DIREITA(inicio) > max) ){
      printf("%d, ",array[inicio]);
    }
    folhas(array,filho_DIREITA(inicio),max,andar);
    folhas(array,filho_ESQUERDA(inicio),max,andar);
  }
}

void busca(int array[], int max){
  int valores_aleatorios[10];
  int valor_aleatorio;
  int semente;
  int i, j, achou;
  
  srand(time(NULL));
  semente = 1 + rand() % 100; // 1 até 100
  for (i=0;i<10;i++){
    srand(semente+i);
    valor_aleatorio = 300 + rand() % 276; // vai de 300 até 575
    valores_aleatorios[i] = valor_aleatorio;
  }

  j = 0;
  while (j < 10){
    achou = 0;
    for(i=0;i<max;i++){
      if (valores_aleatorios[j] == array[i]){
        achou = 1;
      }
    }
    if (achou){
      printf("Valor gerado: %d; Diagnóstico: Presente\n",valores_aleatorios[j]);
    }
    else{
      printf("Valor gerado: %d; Diagnóstico: Ausente\n",valores_aleatorios[j]);
    }
    j++;
  }
}

int preencher(int tamanho, int array[]){

  int semente;
  int valor_aleatorio;
  int i;
  
  srand(time(NULL));
  semente = 1 + rand() % 100;
  for (i=0;i<tamanho;i++){
    srand(semente+i);
    valor_aleatorio = 1 + rand() % 1000; // vai de 1 até 1000
    array[i] = valor_aleatorio;
  }

  return array[tamanho];
}

int main(){
  
  int tamanho;

  srand(time(NULL));
  tamanho = 10 + rand() % 17; // vai de 10 até 26

  int array[tamanho];
  array[tamanho] = preencher(tamanho,array);
  
  arrayGerado(array,tamanho); //printando a)
  
  printf("\n\nASCII:\n"); //printando b)
  ascii(array,0,tamanho,0);

  printf("\nIn-order: {"); //printando c)
  in_order(array, 0, tamanho, 0); 
  printf("}\n");
  printf("\nPre-order: {");
  pre_order(array, 0, tamanho, 0); 
  printf("}\n");
  printf("\nPost-order: {");
  post_order(array, 0, tamanho, 0);
  printf("}\n");

  printf("\n\nFolhas: ["); //printando d)
  folhas(array, 0, tamanho, 0);
  printf("]\n\n");

  busca(array,tamanho); //printando e)
  
  return 0;
}