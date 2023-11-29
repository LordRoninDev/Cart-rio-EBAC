#include <stdio.h> // Biblioteca De Comunica��o Com o Usu�rio 
#include <stdlib.h> //Biblioteca De Aloca��o De Espa�o De Mem�ria
#include <locale.h> //Biblioteca De Aloca��o De Texto Por Regi�o 
#include <string.h> //Biblioteca Respons�vel por cuidar das string

int registro() //fun��o resposns�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / o "W" significa escrever 
	fprintf(file," | CPF:"); //adiciona o texto aos dados salvos
	fprintf(file,cpf); //salva o valor da v�riavel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo,"a"); //atualizar a informa��o / o"A" significa atualizar
	fprintf(file," | Nome:"); //adiciona o texto aos dados salvos
	fclose(file); //fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file,nome); //salva o valor da v�riavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file," | SobreNome:"); //adiciona o texto aos dados salvos
	fprintf(file,sobrenome); //salva o valor da v�riavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file," | Cargo:"); //adiciona o texto aos dados salvos
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file,cargo); //salva o valor da v�riavel
	fclose(file); //fecha o arquivo
	
	system("pause"); 
	
}

int consulta() //fun��o responsavel por dar informa��es de cadastros ao usu�rio
{
	setlocale(LC_ALL, "Portuguese"); //
	
	//inicio da cria��o de vari�veis/string
	char cpf [40];
	char conteudo[200];
	//Final da cria��o de vari�veis/string
	
	printf("\tDigite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file==NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); //resposta ao usu�rio
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("\tDigite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file==NULL)
	{
		printf("\n\n");
		printf("O usu�rio j� foi deletado e n�o se encontra no sistema!. \n\n");
		system("pause");
	}
	

}

int main()

{
	int opcao=0; //Definindo vari�veis 
	
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	    system("cls"); //responsavel por limpar a tela
	    
	
	
	    setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem 
	
	
	    printf("\tCart�rio EBAC\n\n\n"); //inicio do menu
	    printf("Escolha a op��o que deseja no menu a seguir:\n\n");
	    printf("\t1 Registrar nome\n\n");	   
		printf("\t2 Consultar nomes\n\n");
	    printf("\t3 Deletar nomes\n\n"); 
	    printf("\t4 Sair do sistem\n\n");
	    printf("op��o?"); //final do menu

      scanf("%d",&opcao); //Armazenando a escolha do usu�rio
    
      system("cls");
      
      switch(opcao)
      
	  {
      	    //inicio da sele��o do menu
      	    
      	    case 1:
      	    	registro(); //chamada de fun��es 
      	    break;
      	
      	    case 2:
      	    	consulta(); //chamada de fun��es
		    break;
      	    
      	    case 3:
      	    	deletar(); //chamada de fun��es 
		    break;
		    
		    case 4:
		    	printf("Obrigado por utilizar o sistema!");
		    	return 0;
		    break;
		
		    default:
		    printf("\tEssa op��o n�o est� disponivel!!!\n\n"); //chamada de fun��es 
		    printf("\tPor favor tente novamente!\n\n");
		    system("pause");
		    break;
		
		     //fim da sele��o
	  }
    
      
	     
	
    }

        
}

 
