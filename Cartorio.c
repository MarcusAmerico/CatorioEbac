#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

//função responsável por cadastrar os usuários no sistema
int registro() 
{
	//inicio da criação de variáveis/string (conjunto de variáveis)
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação das variáveis/string (conjunto de variáveis)


	printf("Digite o CPF a ser cadastrado: \n"); //coletando informações do usuário
		
	scanf("%s", cpf); //armazenando a variavel "cpf" utilizado a função string "%s"
		
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo foi utilizado "w" de write (escrever)
	
	fprintf(file,cpf); //salvo o valor da varialvel cpf
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //constante "a" utilizada para atualização do arquivo
		
	fprintf(file,";"); //inclusão do ";" para separar o CPF da proxima informação
	fclose(file); //fecha o arquivo
	
	printf("\nDigite o nome a ser cadastrado: \n");
	scanf("%s", nome); //armazenando a variavel nome utilizado a constante string "%s"
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualização do arquivo
	fprintf(file, nome); //salvo o valor da varialvel no caso nome 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualização do arquivo
	fprintf(file,";"); //inclusão do ";" para separar o CPF da proxima informação
	fclose(file); //fecha o arquivo
	
	printf("\nDigite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome); //armazenando a variavel "sobrenome" utilizado a função string "%s"
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualização do arquivo
	fprintf(file, sobrenome); //salvo o valor da varialvel no caso sobrenome 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualização do arquivo
	fprintf(file,";"); //inclusão do ";" para separar o CPF da proxima informação
	fclose(file); //fecha o arquivo

	printf("\nDigite o cargo a ser cadastrado: \n");
	scanf("%s", cargo); //armazenando a variavel "cargo" utilizado a função string "%s"
	
	file = fopen(arquivo, "a"); //constante "a" utilizada para atualização do arquivo
	fprintf(file, cargo); //salvo o valor da varialvel no caso cargo 
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta()
{

	setlocale(LC_ALL, "Portuguese"); //Denifição da linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s", cpf); //armazenando a variavel "cpf" utilizado a função string "%s"
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo CPF e "R" de Read (Ler) a informação
	
	if(file == NULL) //Se a informação não existir traz a seguinte informação
	{
		printf("\nNão foi localizado registros pare o CPF!\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL) //While (enquanto) tiver informação, armazene a informação em conteudo se for diferente de NULL (nulo)
	{
		printf("\nEssas são as informações do usuário: \n"); //informação a aparecer antes dos dados
		
		token = strtok(conteudo, ";"); //variavel utilizado para dividir a string em linhas
		printf("CPF: %s\n", token); //informação a aparecer antes dos dados do CPF
		
		token = strtok(NULL, ";"); //variavel utilizado para dividir a string em linhas 
		printf("Nome: %s\n", token); //informação a aparecer antes dos dados do nome
		
		token = strtok(NULL, ";"); //variavel utilizado para dividir a string em linhas 
		printf("Sobrenome: %s\n", token); //informação a aparecer antes dos dados do sobrenome
		
		token = strtok(NULL, ";"); //variavel utilizado para dividir a string em linhas 
		printf("Cargo: %s\n", token); //informação a aparecer antes dos dados do cargo
		
	}
	
	printf("\n"); //comando utilizado para pular uma linha no final
	
	system("pause");

}
	
	
int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf); // comando para salvar esse valor a variável (cpf), foi utilizado "%s" de string (conjunto de variáveis)
	
	remove(cpf); //função utilizada para deletar
	
	FILE *file;
	file = fopen(cpf, "r"); //abra o arquivo indicado, foi utilizado "r" de reading (ler)

	if(file != NULL)
	{
		printf("\n O CPF foi deletado com sucesso!\n");
		system("pause"); //comando utilizado para pausar para que o sistema aguarda quando a msg aparecer
	}
	else 
	{
		printf("\nEste CPF não existe no sistema!\n");
		system("pause"); // comando utilizado para pausar para que o sistema aguarda quando a msg aparecer
	}
	
	return 0;
	
}

int main()
{	
	int opcao=0; //definindo a variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //comando responsável por deletar tudo que foi escrito (limpar a tela)
		
		setlocale(LC_ALL, "Portuguese"); //denifição da linguagem
					
		printf("### Cartório da EBAC ###\n\n"); //titulo do programa	
		printf("Escolha a opção desejada do menu:\n\n"); //inicio do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opcão: "); //fim do menu
		
		scanf("%d", &opcao);//armazenando a escolha do usuário neste caso foi utilizado %d variavel tipo inteiro
			
		system("cls"); //limpar a tela
		
		switch(opcao) //inicio da seleção do menu
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
			printf("Esta opção não está dispinível!\n");
			system("pause");
			break;
		}//final da seleção do menu
	}
}

