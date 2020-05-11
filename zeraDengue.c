#include <stdio.h>
#include <stdlib.h>

struct ListaZeraDengue {

  int capacidadeMax;
  float *dadosLista;
  int inicio;
  int fim;
  int numeroItens;

};

void criarLista(struct ListaZeraDengue *l, int cap){

  l->capacidadeMax = cap;
  l->dadosLista = (float*) malloc (l->capacidadeMax * sizeof(float));
  l->inicio = 0;
  l->fim = -1;
  l->numeroItens = 0;

}

void inserirItem(struct ListaZeraDengue *l, int valor){

  if (l->fim == l->capacidadeMax-1){
    l->fim = -1;
  }

  l->fim++;
  l->dadosLista[l->fim] = valor;
  l->numeroItens++;
  
}

int removerItem(struct ListaZeraDengue *l){

  int tmp = l->dadosLista[l->inicio++];

  if(l->inicio == l->capacidadeMax){
    l->inicio = 0;
  }

  l->numeroItens--;
  return tmp;
}

int verificaVazia(struct ListaZeraDengue *l){
  
  return (l->numeroItens == 0);

}

int verificaFull(struct ListaZeraDengue *l){
  
  return (l->numeroItens == l->capacidadeMax);

}

void exibirLista(struct ListaZeraDengue *l){
  int cont, i;

  for (cont = 0, i = l->inicio; cont < l->numeroItens; cont++){

    printf("%5d - ", cont+1 );
    printf("%.2f\t ", l->dadosLista[i++]);

    if (i == l->capacidadeMax){
      i=0;
    }
  }
  printf("\n\n\033[00;31mNumero Total de itens: \033[00;37m \033[00;39m%d\033[00;37m", l->numeroItens);
  printf("\n\n");
}

void zerarLista(struct ListaZeraDengue *l){
  while(!verificaVazia(l)){  
    removerItem(l);  
  }
}

int menu(void)
{
  int opt;
  printf("\033[00;31m\nMenu:\n\033[00;37m");
  printf("\033[01;39m0.\033[00;37m Sair\n");
  printf("\033[01;39m1.\033[00;37m Adicionar Cadastro na LISTA\n");
  printf("\033[01;39m2.\033[00;37m Retirar Cadastro da LISTA\n");
  printf("\033[01;39m3.\033[00;37m Exibir LISTA\n"); 
  printf("\033[01;39m4.\033[00;37m Zerar LISTA\n ");
  printf("Opção \033[01;39m(0/1/2/3/4)\033[00;37m: "); 
  scanf("%d", &opt);  
  return opt;
}

int main(void) {
  
  int max = 20;
  int opt;
  struct ListaZeraDengue l;  
  printf("\n\033[01;34mLISTA CRIADA COM SUCESSO! \n\033[00;37m");
  printf("\n\033[01;34mVocê pode realizar no máximo %d solicitações: \033[00;37m", max);
  //scanf("%d", &max);
  criarLista(&l, max);

  do{
    float valor;
    opt = menu(); 
    switch(opt){

    case 0: 
      exit(0);
    
    case 1:
      if (verificaFull(&l)){

        printf("\033[01;33m\nA lista está Cheia!!!\n\n\033[00;37m");

      } 
      else {
          float valor;
          printf("\033[01;34mDigite o valor a ser inserido: \033[00;37m");
          scanf("%f", &valor);
          inserirItem(&l, valor);

        }
      break;

    case 2:
      if (verificaVazia(&l)){

        printf("\033[01;33m\nA lista está vazia!!!\n\n\033[00;37m");

      }
      else {

        valor = removerItem(&l);
        printf("\033[01;32m\n%.2f removido com sucesso!!\n\n\033[00;37m", valor);

      }
      break;

    case 3:
      if (verificaVazia(&l)){

        printf("\033[01;33m\nA lista está vazia!!!\n\n\033[00;37m");

      }
      else {

        printf("\033[01;34m\nConteudo da lista ==> \033[00;37m");
        exibirLista(&l);

      }
      break;

    case 4:

      zerarLista(&l);
      printf("\033[01;32m\nLista zerada com Sucesso!!\n\n\033[00;37m");
      break;

    default:
      printf("\033[01;33m\n\n[!] ATENÇÃO [!]\033[00;37m");
      printf("\033[01;33m\n[!] Opção Inválida\n\033[00;37m");
      printf("\033[01;32m[*] Favor reiniciar o programa e utilizar uma opção valida ou somente 'Números'!\n\n\033[00;37m");
      exit(0);    
  }
  }while(opt);

  free(&l);
  return 0;
}