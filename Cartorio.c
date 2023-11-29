#include <stdio.h> // Biblioteca De Comunicação Com o Usuário 
#include <stdlib.h> //Biblioteca De Alocação De Espaço De Memária
#include <locale.h> //Biblioteca De Alocação De Texto Por Região 
#include <string.h> //Biblioteca Responsável por cuidar das string

int registro() //função resposnsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / o "W" significa escrever 
	fprintf(file," | CPF:"); //adiciona o texto aos dados salvos
	fprintf(file,cpf); //salva o valor da váriavel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo,"a"); //atualizar a informação / o"A" significa atualizar
	fprintf(file," | Nome:"); //adiciona o texto aos dados salvos
	fclose(file); //fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file,nome); //salva o valor da váriavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file," | SobreNome:"); //adiciona o texto aos dados salvos
	fprintf(file,sobrenome); //salva o valor da váriavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file," | Cargo:"); //adiciona o texto aos dados salvos
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //atualiza o arquivo / "A" significa atualizar
	fprintf(file,cargo); //salva o valor da váriavel
	fclose(file); //fecha o arquivo
	
	system("pause"); 
	
}

int consulta() //função responsavel por dar informações de cadastros ao usuário
{
	setlocale(LC_ALL, "Portuguese"); //
	
	//inicio da criação de variáveis/string
	char cpf [40];
	char conteudo[200];
	//Final da criação de variáveis/string
	
	printf("\tDigite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file==NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n"); //resposta ao usuário
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("\tDigite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file==NULL)
	{
		printf("\n\n");
		printf("O usuário já foi deletado e não se encontra no sistema!. \n\n");
		system("pause");
	}
	

}

int main()

{
	int opcao=0; //Definindo variáveis 
	
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	    system("cls"); //responsavel por limpar a tela
	    
	
	
	    setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem 
	
	
	    printf("\tCartório EBAC\n\n\n"); //inicio do menu
	    printf("Escolha a opção que deseja no menu a seguir:\n\n");
	    printf("\t1 Registrar nome\n\n");	   
		printf("\t2 Consultar nomes\n\n");
	    printf("\t3 Deletar nomes\n\n"); 
	    printf("\t4 Sair do sistem\n\n");
	    printf("opção?"); //final do menu

      scanf("%d",&opcao); //Armazenando a escolha do usuário
    
      system("cls");
      
      switch(opcao)
      
	  {
      	    //inicio da seleção do menu
      	    
      	    case 1:
      	    	registro(); //chamada de funções 
      	    break;
      	
      	    case 2:
      	    	consulta(); //chamada de funções
		    break;
      	    
      	    case 3:
      	    	deletar(); //chamada de funções 
		    break;
		    
		    case 4:
		    	printf("Obrigado por utilizar o sistema!");
		    	return 0;
		    break;
		
		    default:
		    printf("\tEssa opção não está disponivel!!!\n\n"); //chamada de funções 
		    printf("\tPor favor tente novamente!\n\n");
		    system("pause");
		    break;
		
		     //fim da seleção
	  }
    
      
	     
	
    }

        
}

 
