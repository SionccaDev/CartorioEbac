#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca respons�vel por cuidar das strings
 
int registro()   //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio da cria��o das vari�veis /string
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da cria��o das vari�veis /string
	
	printf("Digite o cpf a ser cadastrado: ");   //coletando informa��o do usu�rio
	scanf("%s", cpf);   //enquanto o numero de vari�veis for menor que 40 digitos, a string armazenar�. %s refere-se a string
	
	strcpy(arquivo, cpf);   //respons�vel por copiar os valores da string, e colar no nome do arquivo, renomeando-o
	
	FILE *file;   //cria o arquivo que vai armazenar o banco de dados
	file = fopen(arquivo, "w");   // o w indica "write", ou seja, criar o arquivo
	fprintf(file, cpf);   //fprintf: ao inves de mostrar para o usu�rio, mostra na pasta e salva o valor da vari�vel
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
	 //criando as vari�veis em string
	 char cpf[40];
	 char conteudo[200];
	 
	 printf("Digite o cpf a ser consultado: ");   //hora de receber os dados do usu�rio
	 scanf("%s", cpf);   //varredura para armazenar a string digitada pelo usu�rio
	 
	 FILE *file;   //refere-se ao arquivo file
	 file = fopen(cpf, "r");   //abre o arquivo file e o l�
	
	if(file == NULL)   //se o cpf n�o for encontrado, os comandos comandos a baixo seguir�o
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");   //mensagem mostrada ao usu�rio
    }
		while(fgets(conteudo, 200, file) != NULL)	//fgets, ele est� indo buscar o arquivo
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
	
}
	 	 
	 

int delecao()
{
     char cpf[40];
     
     printf("Digite o CPF do usu�rio a ser deletado: ");
     scanf("%s", cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("O usu�rio n�o se encontra no sistema! \n");   //toda vez que o sistema v� uma barra invertida, ele entender que � um comando, mesmo estando dentro das aspas
     	
     	system("pause");	
	 }
     

}


int main()
{
	int opcao=0;   //definindo a vari�vel
	int laco=1;
	
	for(laco=1;laco=1;)   //usa-se a fun��o for para definir um loop para voltar ao menu toda vez que uma op��o for negada
	{
 	
 	  system("cls");   //respons�vel por limpar a tela
 	
	  setlocale(LC_ALL, "Portuguese");   //definindo a linguagem 
	
	  printf("### Cart�rio da EBAC ###\n\n");   //inicio do menu
	  printf("escolha a op�ao desejada no menu:\n\n");
	  printf("\t1 - registrar os nomes\n"); 	
	  printf("\t2 - consultar os nomes\n");
	  printf("\t3 - deletar os nomes\n\n"); 
	  printf("\t4 - sair do sistema\n\n");
	  printf("Op��o:");   //fim do menu
	
	  scanf("%d" , &opcao);   //armazenando a escolha do usu�rio
	
	  system("cls");   //uma vez que a opcao � colocada, o sistema operacional deletar� todas as informa��es que tinham antes
	  
	  
	  switch(opcao)
	  {
	  	 case 1:   //os dois pontos simbolizam que o case 1 significa o que vem a seguir
	  	 registro();
	     break;   //lembrar do break no final de cada instru��o
	     
	     case 2:
	     consulta();   //basicamente, agora os case s�o seguidos da instru��o para o sistema
	  	 break;
	  	 
	  	 case 3:
		 delecao();
	  	 break; 	
	  	 
	  	 case 4:
	  	 printf("Obrigado por utilizar o sistema!\n");
	  	 return 0;
	  	 break;
	
	  	 default:
	  	 printf("\tEssa op��o n�o est� disponivel!\n");
		 system("pause");
	  	 break;
	  }
    }
}
	


