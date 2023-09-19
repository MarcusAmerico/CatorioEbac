#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

//fun��o respons�vel por cadastrar os usu�rios no sistema
int registro() 
{
	//inicio da cria��o de vari�veis/string (conjunto de vari�veis)
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o das vari�veis/string (conjunto de vari�veis)


	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��es do usu�rio
		
	scanf("%s", cpf); //armazenando a variavel "cpf" utilizado a fun��o string "%s"
		
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo foi utilizado "w" de write (escrever)
	
	fprintf(file,cpf); //salvo o valor da varialvel cpf
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //constante "a" utilizada para atualiza��o do arquivo
		
	fprintf(file,";"); //inclus�o do ";" para separar o CPF da proxima informa��o
	fclose(file); //fecha o arquivo
	
	printf("\nDigite o nome a ser cadastrado: \n");
	scanf("%s", nome); //armazenando a variavel nome utilizado a constante string "%s"
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualiza��o do arquivo
	fprintf(file, nome); //salvo o valor da varialvel no caso nome 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualiza��o do arquivo
	fprintf(file,";"); //inclus�o do ";" para separar o CPF da proxima informa��o
	fclose(file); //fecha o arquivo
	
	printf("\nDigite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome); //armazenando a variavel "sobrenome" utilizado a fun��o string "%s"
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualiza��o do arquivo
	fprintf(file, sobrenome); //salvo o valor da varialvel no caso sobrenome 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualiza��o do arquivo
	fprintf(file,";"); //inclus�o do ";" para separar o CPF da proxima informa��o
	fclose(file); //fecha o arquivo

	printf("\nDigite o cargo a ser cadastrado: \n");
	scanf("%s", cargo); //armazenando a variavel "cargo" utilizado a fun��o string "%s"
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualiza��o do arquivo
	fprintf(file, cargo); //salvo o valor da varialvel no caso cargo 
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta()
{

	setlocale(LC_ALL, "Portuguese"); //Denifi��o da linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s", cpf); //armazenando a variavel "cpf" utilizado a fun��o string "%s"
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo CPF e "R" de Read (Ler) a informa��o
	
	if(file == NULL) //Se a informa��o n�o existir traz a seguinte informa��o
	{
		printf("\nN�o foi localizado registros pare o CPF!\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL) //While (enquanto) tiver informa��o, armazene a informa��o em conteudo se for diferente de NULL (nulo)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n"); //informa��o a aparecer antes dos dados
		
		token = strtok(conteudo, ";"); //variavel utilizado para dividir a string em linhas
		printf("CPF: %s\n", token); //informa��o a aparecer antes dos dados do CPF
		
		token = strtok(NULL, ";"); //variavel utilizado para dividir a string em linhas 
		printf("Nome: %s\n", token); //informa��o a aparecer antes dos dados do nome
		
		token = strtok(NULL, ";"); //variavel utilizado para dividir a string em linhas 
		printf("Sobrenome: %s\n", token); //informa��o a aparecer antes dos dados do sobrenome
		
		token = strtok(NULL, ";"); //variavel utilizado para dividir a string em linhas 
		printf("Cargo: %s\n", token); //informa��o a aparecer antes dos dados do cargo
		
	}
	
	printf("\n"); //comando utilizado para pular uma linha no final
	
	system("pause");

}
	
	
int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf); // comando para salvar esse valor a vari�vel (cpf), foi utilizado "%s" de string (conjunto de vari�veis)
	
	remove(cpf); //fun��o utilizada para deletar
	
	FILE *file;
	file = fopen(cpf, "r"); //abra o arquivo indicado, foi utilizado "r" de reading (ler)

	if(file != NULL)
	{
		printf("\n O CPF foi deletado com sucesso!\n");
		system("pause"); //comando utilizado para pausar para que o sistema aguarda quando a msg aparecer
	}
	else 
	{
		printf("\nEste CPF n�o existe no sistema!\n");
		system("pause"); // comando utilizado para pausar para que o sistema aguarda quando a msg aparecer
	}
	
	return 0;
	
}

int main()
{	
	int opcao=0; //definindo a vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //comando respons�vel por deletar tudo que foi escrito (limpar a tela)
		
		setlocale(LC_ALL, "Portuguese"); //denifi��o da linguagem
					
		printf("### Cart�rio da EBAC ###\n\n"); //titulo do programa	
		printf("Escolha a op��o desejada do menu:\n\n"); //inicio do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opc�o: "); //fim do menu
		
		scanf("%d", &opcao);//armazenando a escolha do usu�rio neste caso foi utilizado %d variavel tipo inteiro
			
		system("cls"); //limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();
			break;

			case 2:
			consulta();
			break;

			case 3:
			deletar();
			break;
			
			default:
			printf("Esta op��o n�o est� dispin�vel!\n");
			system("pause");
			break;
		}//final da sele��o do menu
	}
}

