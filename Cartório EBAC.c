#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//bibliotecarespons�lvel por cuidar dos strings

int registro()
{ 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("______________________________________\n\n");
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das strings
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
    char cpf [40];
    char conteudo[200];
     
    printf("______________________________________\n\n"); 
    printf("digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file==NULL)
	{
		printf("n�o foi possilvel abrir o arquivo, n�o localizado!.\n");
	}
	else
	{
	 printf("\nEssas s�o as informa��es do usuario: \n\n");	
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("------ %s ------",conteudo);
		printf("\n\n");
	}
   
    system("pause");
    
}
int deletar()
{
	char cpf[40];
	
	int deletado;
	printf("______________________________________\n\n");
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	deletado = remove(cpf);

	if (deletado == 0)
	{
        printf("O usu�rio foi apagado com sucesso.\n");
        system("pause");
    }
	else
	{
        printf("O usu�rio n�o se encontra no sistema!\n");
        system("pause");
    }
}


int main()
{
   int opcao=0;//definindo valores 
   int laco=1;
   char senhadigitada[10]= "a";
   int comparacao;
   
   printf("#### Cart�rio da EBAC ####\n\n");
   printf("Loguin de adiministrador!\n\n Digite sua senha: ");
   scanf("%s",senhadigitada);
   
   comparacao = strcmp(senhadigitada, "admin");
   
   if (comparacao == 0)
  {
     for(laco=1;laco=1;)
	 {
      system("cls");
   
      setlocale(LC_ALL,"portuguese");//definindo linguagem
    
      printf("______________________________________\n\n");
      printf("#### Cart�rio da EBAC ####\n\n");//inicio do menu
      printf("Escolha a op��o desejada do menu:\n\n");
      printf("\t1 - registrar nomes\n");
      printf("\t2 - consultar nomes\n");
      printf("\t3 - deletar nomes\n");
      printf("\t4 - sair do sistema\n\n");
      printf("op��es:");//fim do menu
      
      scanf("%d", &opcao);//armazenando a escoha do usu�rio
      
      system("cls");
     
      switch(opcao)
	  {
      
	   case 1:
	   registro();
	   break;
	  
	   case 2:  
	   consultar();
	   break;
	  
	   case 3:
	   deletar();
       break;
      
       case 4:
       printf("obrigado por usar o sistema.\n");
       return 0;
       break;
       
       default:
	   printf ("essa po��o n�o est� disponivel!\n\n");
	   system("pause");
	   break;
	  
	   }
   	 } 
  } 
   else 
  
    printf("senha incoreta!");
	
		//fim da sele��o
}
