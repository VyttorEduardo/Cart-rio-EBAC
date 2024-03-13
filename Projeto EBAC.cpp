#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos strings

int registros() // Fun��i respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //DL(Defini��o de Linguagem)
	
	char arquivo[40]; //inicio da cria��o de vari�veis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	 //Final da cria��o de vari�veis/string
	
	printf("Cadastro do Usu�rio\n\n");
	
	printf("Digite o CPF:"); // Coletar informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"\nCPF:");
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //letra "a" significa atualizar/repetir a fun��o
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
	setlocale(LC_ALL, "Portuguese"); //DL(Defini��o de Linguagem)
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para consultar:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo n�o existe!\n");
	}
	
	printf("\nInforma��es do usu�rio:"); //fora do while para n�o haver repeti��es
	
	while(fgets(conteudo, 200, file) != NULL )
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //DL(Defini��o de Linguagem)
	
	char cpf[40];
	
	printf("Digite o CPF para cancelar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o existe \n");
		printf("\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // DV(Defini��o de vari�veis)
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //AC(Apagar o console/Mudar de p�gina)
	
		setlocale(LC_ALL, "Portuguese"); //DL(Defini��o de Linguagem)
	
		printf("\tReg�stros EBAC\n\n"); //IM(Inicio do Menu)
		printf("Menu de op��es:\n\n"); 
		printf("1 - Registrar Nomes\n");
		printf("2 - Consultar Nomes\n");
		printf("3 - Deletar Nomes\n\n\n"); 
		printf("Escolha sua op��o:"); //FM(Fim do Menu)
	
		scanf("%d", &opcao); //AEU(Armazenamento de escolha do usu�rio)
	
		system("cls");  //AIC(Apagar informa��es do console/"Mudar de P�gina")
		
		switch(opcao) //variavel simplificada do comando if(inicio)
		{
			case 1:
			registros(); //chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n\n");
			system("pause");
			break; //variavel simplificada do comando if(fim)
		}
		
		
	}
	
}
