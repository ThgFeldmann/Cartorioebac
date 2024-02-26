#include <stdio.h> //biblioteca de comunicac�o com o usu�rio
#include <stdlib.h> //biblioteca de alocac�o de espaco em mem�ria
#include <locale.h> //biblioteca de alocac�es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //func�o que cadastra CPFs no sistema
{
	//inicio da criac�o de string/variavel
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criac�o de string/variavel
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //pergunta ao usu�rio o CPF desejado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) // caso o CPF digitado n�o exista ou n�o foi cencontrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra ao usu�rio as informac�es do CPF consultado
	{
		printf("\nEssas S�o as informac�es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //solicita o usu�rio a digitar o cpf desejado
	scanf("%s",cpf);
	
	remove(cpf); //remove o CPF do sistema
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O CPF n�o foi encontrado ou n�o existe! \n"); //Indica se o CPF foi deletado ou n�o existe
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vairi�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{ //inicio do laco

		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opc�o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opc�o: "); //Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usu�rio

		system("cls"); //respons�vel por limpar a tela

		switch(opcao) //incio da selec�o
		{	
			case 1:
			registro(); //chamada de func�es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opc�o n�o est� disponivel!\n");
			system("pause");
			break;
			
		} //fim da selec�o

	} //fim do laco
}
