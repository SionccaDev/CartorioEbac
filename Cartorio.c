#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h>  //biblioteca responsável por cuidar das strings
 
int registro()   //função responsável por cadastrar usuários no sistema
{
	//início da criação das variáveis /string
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da criação das variáveis /string
	
	printf("Digite o cpf a ser cadastrado: ");   //coletando informação do usuário
	scanf("%s", cpf);   //enquanto o numero de variáveis for menor que 40 digitos, a string armazenará. %s refere-se a string
	
	strcpy(arquivo, cpf);   //responsável por copiar os valores da string, e colar no nome do arquivo, renomeando-o
	
	FILE *file;   //cria o arquivo que vai armazenar o banco de dados
	file = fopen(arquivo, "w");   // o w indica "write", ou seja, criar o arquivo
	fprintf(file, cpf);   //fprintf: ao inves de mostrar para o usuário, mostra na pasta e salva o valor da variável
	fclose(file);   //fecha o arquivo
	
	file = fopen(arquivo, "a");   //o a indica "access", ou seja, abrir o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");   
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");   
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
}

int consulta()
{
	 //criando as variáveis em string
	 char cpf[40];
	 char conteudo[200];
	 
	 printf("Digite o cpf a ser consultado: ");   //hora de receber os dados do usuário
	 scanf("%s", cpf);   //varredura para armazenar a string digitada pelo usuário
	 
	 FILE *file;   //refere-se ao arquivo file
	 file = fopen(cpf, "r");   //abre o arquivo file e o lê
	
	if(file == NULL)   //se o cpf não for encontrado, os comandos comandos a baixo seguirão
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");   //mensagem mostrada ao usuário
    }
		while(fgets(conteudo, 200, file) != NULL)	//fgets, ele está indo buscar o arquivo
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
	
}
	 	 
	 

int delecao()
{
     char cpf[40];
     
     printf("Digite o CPF do usuário a ser deletado: ");
     scanf("%s", cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("O usuário não se encontra no sistema! \n");   //toda vez que o sistema vê uma barra invertida, ele entender que é um comando, mesmo estando dentro das aspas
     	
     	system("pause");	
	 }
     

}


int main()
{
	int opcao=0;   //definindo a variável
	int laco=1;
	
	for(laco=1;laco=1;)   //usa-se a função for para definir um loop para voltar ao menu toda vez que uma opção for negada
	{
 	
 	  system("cls");   //responsável por limpar a tela
 	
	  setlocale(LC_ALL, "Portuguese");   //definindo a linguagem 
	
	  printf("### Cartório da EBAC ###\n\n");   //inicio do menu
	  printf("escolha a opçao desejada no menu:\n\n");
	  printf("\t1 - registrar os nomes\n"); 	
	  printf("\t2 - consultar os nomes\n");
	  printf("\t3 - deletar os nomes\n\n"); 
	  printf("\t4 - sair do sistema\n\n");
	  printf("Opção:");   //fim do menu
	
	  scanf("%d" , &opcao);   //armazenando a escolha do usuário
	
	  system("cls");   //uma vez que a opcao é colocada, o sistema operacional deletará todas as informações que tinham antes
	  
	  
	  switch(opcao)
	  {
	  	 case 1:   //os dois pontos simbolizam que o case 1 significa o que vem a seguir
	  	 registro();
	     break;   //lembrar do break no final de cada instrução
	     
	     case 2:
	     consulta();   //basicamente, agora os case são seguidos da instrução para o sistema
	  	 break;
	  	 
	  	 case 3:
		 delecao();
	  	 break; 	
	  	 
	  	 case 4:
	  	 printf("Obrigado por utilizar o sistema!\n");
	  	 return 0;
	  	 break;
	
	  	 default:
	  	 printf("\tEssa opção não está disponivel!\n");
		 system("pause");
	  	 break;
	  }
    }
}
	


