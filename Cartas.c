#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define NUM_CARTAS_TOTAIS 78
#define NUM_CARTAS_ESCOLHIDAS 3
#define TAM_MAX_LINHA 300

typedef struct {
	int id;
    int numero;
    char nome[30];
    char naipe[15];
    char elemento[15];
    char planeta[15];
    char signo_astrologico[15];
    char cabala_kabbalah[50];
    char estacao[15];
    char pedra[20];
    char soun[10];
    char significadoNormal[100];
} TCarta;

void escolha_dos_id (int numeros[]);
void lerarquivo(TCarta cartas[], int numeros[]);
void mostrarcartasselecionadas(TCarta cartas[]);


// Função escolhecartasaleatorias para escolher numcartas de 1 até 78, armazenar em um vetor 
void escolha_dos_id(int numeros[]) 
{
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_CARTAS_ESCOLHIDAS; i++) {
        numeros[i] = (rand() % NUM_CARTAS_TOTAIS) + 1;
        //printf("%d\n", numeros[i]);
    }
    
    
}

// Função para ler o arquivo e armazenar as informações da carta na struct
void lerarquivo(TCarta cartas[], int numeros[]) 
{
    char linha[TAM_MAX_LINHA], *token;
    int i = 0, j, id;

    FILE *arquivo = fopen("C:\\Users\\PC\\Desktop\\Projetos\\Tarot\\TAROT - TODAS.txt", "r");
    if (arquivo == NULL) 
	{
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    while (fgets(linha, TAM_MAX_LINHA, arquivo) != NULL && i < NUM_CARTAS_ESCOLHIDAS) 
	{
        sscanf(linha, "%d,", &id);
        for (j = 0; j < NUM_CARTAS_ESCOLHIDAS; j++) 
		{
            if (id == numeros[j]) //Encontramos o ID correspondente
			{
                // Extrair os dados usando strtok
                token = strtok(linha, ";"); 
                token = strtok(NULL, ";"); // Pular o ID
                token = strtok(NULL, ";"); // Pular o número
                // Agora o token contém o nome da carta
                strcpy(cartas[j].nome, token);
                // O mesmo para o naipe
                token = strtok(NULL, ";");
                strcpy(cartas[j].naipe, token);
                
                // O mesmo para o elemento
                token = strtok(NULL, ";");
                strcpy(cartas[j].elemento, token);
                
                // O mesmo para o planeta
                token = strtok(NULL, ";");
                strcpy(cartas[j].planeta, token);
                
                // O mesmo para o signo_astrologico
                token = strtok(NULL, ";");
                strcpy(cartas[j].signo_astrologico, token);
                
                // O mesmo para o cabala_kabbalah
                token = strtok(NULL, ";");
                strcpy(cartas[j].cabala_kabbalah, token);
                
                // O mesmo para o estacao
                token = strtok(NULL, ";");
                strcpy(cartas[j].estacao, token);
                
                // O mesmo para o pedra
                token = strtok(NULL, ";");
                strcpy(cartas[j].pedra, token);
                
                // O mesmo para o soun
                token = strtok(NULL, ";");
                strcpy(cartas[j].soun, token);
                
                // O mesmo para o significadoNormal
                token = strtok(NULL, ";");
                strcpy(cartas[j].significadoNormal, token);
                
                i++;
            }
        }
    }

    fclose(arquivo);
}

// Ideia completa
/*void mostrarcartasselecionadas(TCarta cartas[]) 
{
	int i;
    for (i = 0; i < NUM_CARTAS_ESCOLHIDAS; i++) {
        printf("ID: %i\n", cartas[i].id);
        printf("Nome: %s\n", cartas[i].nome);
        printf("Naipe: %s\n", cartas[i].naipe);
        printf("Elemento: %s\n", cartas[i].elemento);
        printf("Planeta: %s\n", cartas[i].planeta);
        printf("Signo Astrologico: %s\n", cartas[i].signo_astrologico);
        printf("Kabbalah: %s\n", cartas[i].cabala_kabbalah);
        printf("Estação: %s\n", cartas[i].estacao);
        printf("Pedra: %s\n", cartas[i].pedra);
        printf("Sim ou Não: %s\n", cartas[i].soun);
		printf("Significado: %s\n\n\n", cartas[i].significadoNormal);
        
        // Imprima os outros dados conforme necessário
        printf("\n");
    }
}*/

void mostrarcartasselecionadas(TCarta cartas[]) 
{
	setlocale(LC_ALL, "Portuguese");
	int i;
    for (i = 0; i < NUM_CARTAS_ESCOLHIDAS; i++) {
        printf("Nome: %s\n", cartas[i].nome);
        printf("Elemento: %s\n", cartas[i].elemento);
        printf("Planeta: %s\n", cartas[i].planeta);
        printf("Signo Astrológico: %s\n", cartas[i].signo_astrologico);
        printf("Kabbalah: %s\n", cartas[i].cabala_kabbalah);
        printf("Sim ou Não: %s\n", cartas[i].soun);
		printf("Significado: %s\n\n\n", cartas[i].significadoNormal);
        
        // Imprima os outros dados conforme necessário
        printf("\n");
    }
}


int main() {
    TCarta cartas_escolhidas[NUM_CARTAS_ESCOLHIDAS], baralho[NUM_CARTAS_TOTAIS];
    int i, diz_pro_gpt, numeros_para_id[NUM_CARTAS_ESCOLHIDAS]; 
    
	setlocale(LC_ALL, "Portuguese");

	do
	{
   		// Pergunta ao usuário quantas cartas jogar
   		printf("Pense em uma pergunta sobre os temas:\n");
   		printf("1 - Amor\n2 - Dinheiro\n3 -  Amigos\n4 - Carreira\n5- Estudos\n0 - Para sair\n");
   		scanf("%d", &diz_pro_gpt);
  		
  		// Testa se é zero, se for, acaba logo
  		if(diz_pro_gpt == 0)
  		{
  			printf("Volte sempre!\n");
		}
		else
		{
			// Testa se é uma das opções
			if (diz_pro_gpt == 1 || diz_pro_gpt == 2 || diz_pro_gpt == 3 || diz_pro_gpt == 4 || diz_pro_gpt == 5)
			{
				//Definir os ids
				escolha_dos_id(numeros_para_id);
				//Ler arquivo
				lerarquivo(cartas_escolhidas, numeros_para_id);
				// Mostra as cartas selecionadas
				mostrarcartasselecionadas(cartas_escolhidas);
			}
			//Senão, tente de novo pq testou errado
			else
			{
				printf("Digite novamente!\n");
			}
		}	
  			
  	}while (diz_pro_gpt!=0);	  
  	
    return 0;
}

