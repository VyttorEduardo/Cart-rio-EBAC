#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar dos strings

int registros() // Funçãi responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //DL(Definição de Linguagem)
	
	char arquivo[40]; //inicio da criação de variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	 //Final da criação de variáveis/string
	
	printf("Cadastro do Usuário\n\n");
	
	printf("Digite o CPF:"); // Coletar informações do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"\nCPF:");
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //letra "a" significa atualizar/repetir a função
	fprintf(file,"\nNOME:");
	fclose(file);
	
	printf("Digite o Nome:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSOBRENOME:");
	fclose(file);
	
	printf("Digite o Sobrenome:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nCARGO:");
	fclose(file);
	
	printf("Digite o Cargo:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //DL(Definição de Linguagem)
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para consultar:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo não existe!\n");
	}
	
	printf("\nInformações do usuário:"); //fora do while para não haver repetições
	
	while(fgets(conteudo, 200, file) != NULL )
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //DL(Definição de Linguagem)
	
	char cpf[40];
	
	printf("Digite o CPF para cancelar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não existe \n");
		printf("\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // DV(Definição de variáveis)
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //AC(Apagar o console/Mudar de página)
	
		setlocale(LC_ALL, "Portuguese"); //DL(Definição de Linguagem)
	
		printf("\tRegístros EBAC\n\n"); //IM(Inicio do Menu)
		printf("Menu de opções:\n\n"); 
		printf("1 - Registrar Nomes\n");
		printf("2 - Consultar Nomes\n");
		printf("3 - Deletar Nomes\n\n\n"); 
		printf("Escolha sua opção:"); //FM(Fim do Menu)
	
		scanf("%d", &opcao); //AEU(Armazenamento de escolha do usuário)
	
		system("cls");  //AIC(Apagar informações do console/"Mudar de Página")
		
		switch(opcao) //variavel simplificada do comando if(inicio)
		{
			case 1:
			registros(); //chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível\n\n");
			system("pause");
			break; //variavel simplificada do comando if(fim)
		}
		
		
	}
	
}
