#include <stdio.h>  //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()

{   
    //inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fina
	
	   printf("Digite o CPF a ser cadastrado:");//coletando informa��o do usu�rio
	   scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	  FILE *file; // criar o arquivo
	  file = fopen(arquivo,"w");
	  fprintf(file,cpf);// salvar o valor da variavel
	  fclose(file);// fecha o arquivo
	  
	  file = fopen(arquivo,"a");
	  fprintf(file,",");
	  fclose(file);
	  
	  printf("Digite o nome a ser cadastrado:");
	  scanf ("%s",nome);
	  
	  file = fopen(arquivo,"a");
	  fprintf(file,nome);
	  fclose(file);
	  
	  printf("digite o sobrenome a ser cadastrado:");
	  scanf("%s",sobrenome);
	  
	  file = fopen(arquivo,"a");
	  fprintf(file,sobrenome);
	  fclose(file);
	  
	  
	  file = fopen(arquivo,"a");
	  fprintf(file,",");
	  fclose(file);
	  
	  printf("digite o cargo a ser cadastrado:");
	  scanf("%s",cargo);
	  
	  file = fopen(arquivo,"a");
	  fprintf(file,cargo);
	  fclose(file);
	  
	  system("pause");
}

int consultar()//responsavel por consultar os dados do usu�rio
{
   setlocale(LC_ALL, "portuguese");//definido linguagem
	
   char cpf[40];
   char conteudo[200];
   
   printf("digite o cpf a ser consultado:");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	 printf("N�o foi possivel abrir o arquivo, n�o localizado!");
   }

   while(fgets(conteudo,200,file)!=NULL)
   {
   	printf("\nEssas s�o as informa��es do usu�rio:");
   	printf("%s",conteudo);
   	printf("\n\n");
   	fclose(file);
   }

	system("pause");   	
}

int deletar()//responsavel por deletar os dados do usu�rio
{
   char cpf[40];
   
   printf("digite o cpf a ser deletado:");
   scanf("%s",cpf);
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   fclose(file);
   
   if(file == NULL)
   {
   	 printf("usu�rio removido com sucesso do sistema!.\n");
   	 system("pause");
   }
}



int main()
{
   int opcao=0; //definindo vari�veis
   int x=1;
   for(x=1;x=1;)
   {
   
    system ("cls");//responsavel por limpar a tela
     
	setlocale(LC_ALL, "portuguese"); //inicio do menu
	
	printf("Cart�rio da EBAC\n\n");
	printf("Escolha a op��o desejada do menu:\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("op��o:"); //fim do menu
	
	scanf("%d",&opcao); //aemazenamento a escolha do usu�rio
	
	system("cls");
	
	switch(opcao)//menu de variaveis
	{
		case 1://pra op��o de cadastror de dados
		registro();//chamada de fun��es
		break;//enceramento da opcao 1
		
		case 2://pra op��o de consultar dados
		consultar();
		break;//enceramento da opcao 2
		
		case 3:
		deletar();//pra op��o de remover dados
		break;//enceramento da opcao 3
		
		default://pra op��o de dados invalido
		printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
	}
	

	
	}
}
