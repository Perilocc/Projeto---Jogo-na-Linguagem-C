#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(){
	setlocale(0, "Portuguese");
	
	// Listas de palavras da forca!! e Lista de variáveis presentes no programa!!
	char animais[][20] = {"tartaruga", "zebra", "coala", "camelo", "macaco", "cachorro", "cobra", "gato", "galo", "galinha", "cavalo", "vaca", "ganso", "pato", "asno", "avestruz", "rato", "capivara", "carpa", "marmota"};
	char objetos[][20] = {"anzol", "balde", "bola", "borracha", "faca", "canivete", "enxada", "flauta", "funil", "dado", "lanterna", "luva", "martelo", "mouse", "prato", "garfo", "colher", "copo", "tijolo", "mala"};
	char verbos[][20] = {"comer", "beber", "chutar", "bater", "lutar", "chicotear", "passear", "dirigir", "compartilhar", "pesquisar", "obedecer", "ouvir", "elevar", "quebrar", "praticar", "errar", "trair", "invadir", "planejar", "falsificar"};
	char frutas[][20] = {"laranja", "banana", "oliveira", "jaca", "jabuticaba", "abacaxi", "amora", "goiaba", "abacate", "acerola", "graviola", "cacau", "caqui", "carambola", "figo", "kiwi", "jambo", "manga", "morango", "pitaya"};
	
	// Lista de contadores
	int letras_certas, chances, contagem_erros, i, underline;
	//Outras variáveis importantes
	int categoria, indice, tamanho;
	char letra, *dica;
	char letras_usadas[26] = "";
	char x, y, z, a, b, c, d, e, f, g;
	
	// Variáveis envolvidas no do{} while()
	int vitorias, derrotas, resposta;
	
	vitorias = 0;
	derrotas = 0;
	
	do{
	inicio:
	memset(letras_usadas, 0, sizeof(letras_usadas)); // reseta a lista de letras usadas ao começar outra tentativa!!
	resposta = '\0';
	categoria = '\0';
	srand(time(NULL));/* Esse comando serve para resetar o rand. Pois se não houver ele, por algum motivo o rand pega a mesma palavra sempre! 
	Provavelmente ele salva na memória algum endereço!!*/
	chances = 6;
	// Início!!
	
	//Aqui fica as intruções iniciais
	printf("===============================================\n");
	printf("----------------Vamos Jogar Forca--------------\n");
	printf("\nPara isso você terá 6 vidas, se errar a letra perderá uma vida.\nPerdendo todas as vidas, Game over!!\n");
	printf("\nSelecione a categoria de palavras que você deseja!\n");
	printf("Digite o número da categoria:\n 1-Animais\n 2-Objetos\n 3-Verbos\n 4-Frutas\n");
	printf("\ncategoria: ");
	scanf("%d", &categoria);
	
	char palavra[20];
		//Seleção da categoria e sorteio da palavra!!
	switch (categoria) {
		case 1:
			//os comados abaixo sorteiam uma das palavras presentes nos vetores declarados acima.
			indice = rand() % (sizeof(animais) / sizeof(animais[0]));
			strcpy(palavra, animais[indice]);
			dica = ("Animal");
			break;
			
		case 2:
			indice = rand() % (sizeof(objetos) / sizeof(objetos[0]));
			strcpy(palavra, objetos[indice]);
			dica = "Objeto";
			break;
		
		case 3: 
			indice = rand() % (sizeof(verbos) / sizeof(verbos[0]));
			strcpy(palavra, verbos[indice]);
			dica = "Verbo";
			break;
		
		case 4:
			indice = rand() % (sizeof(frutas) / sizeof(frutas[0]));
			strcpy(palavra, frutas[indice]);
			dica = "Fruta";
			break;
			
		default:
			printf("\nEssa categoria é inválida ou não existe, digite outro número!!\n\n");
			goto inicio;
	}
	
	printf("===============================================");	
	printf("\nVamos Começar, adivinhe a palavra!!!\n");
	printf("Digite apenas letras minúsculas!\nNão digite letras repetidas!!\nAs palavras que serão adivinhadas, não possuem acentos!!\nLembre-se, você possui 6 vidas\n");
	printf("===============================================\n\n");
	
	// Tamanho da palavra sorteada
	tamanho = strlen(palavra);
	// Adapta o sistema para palavras com até 10 letras, no qual se a palavra possui 5 letras, haverão 5 underlines para o usuário substituir!
		char variaveis[10] = {x, y, z, a, b, c, d, e, f, g};
		char variaveis_com_underline[10] = {};
		
		for (underline = 0; underline < tamanho; underline++) { // Obs: a variável underline é um contador
    		variaveis[underline] = '_';
    		if (variaveis[underline] == '_') {
    			variaveis_com_underline[underline] = variaveis[underline];
			}
    	}
    	
		//Funcionamento básico: Vai mostrar as letras utilizadas, mostrar o progresso e pedir ao usuário a letra. tudo isso em loop para ser realizado até ganhar ou perder.
		for(letras_certas = 0; letras_certas < tamanho;){
			printf("Dica: %s com %d letras\n", dica, tamanho);
			printf("\nLetras Utilizadas: %s\n\n",letras_usadas);
			printf("''''''''''%s''''''''''\n\n", variaveis_com_underline);
			printf("----------Digite uma letra: ");
			scanf(" %[^\n]", &letra);
			
			/*Verificação se realmente é letra e se a letra já foi utilizada anteriormente. 
			Pensei em colocar repetição de letra como punição, mas aí seria muito malvado!
			Mesmo já tendo colocado uma lista das letras usadas para a pessoa ver, mas como wallace disse, é usuário*/
			
			//Filtro 1 - Verifica se o caractere digitado é uma letra, !isalpha = se diferente de letra, entra nos comandos dentro do if 
			if (!isalpha(letra)){
				printf("\nÉ necessário digitar uma letra, e esse caractere não é uma letra!! Tente Novamente, digitando uma letra!\n");
				printf("===============================================\n\n");
				continue;
			}
			//Filtro 2 - Verificar se a letra já foi utilizada anteriormente, e impedir isso!!
			if(strchr(letras_usadas, letra) != NULL) {
                printf("\nVocê já utilizou essa letra, e isso não é permitido!! Tente novamente!\n");
                printf("===============================================\n\n");
                continue;
            }
            //Filtro 3 - Verificar se o usuário digitou mais de um caractere e impedir a continuidade se isso ocorrer!
            if (strlen(&letra) > 1) {
            	printf("\nVocê já , e isso não é permitido!! Tente novamente!\n");
                printf("===============================================\n\n");
                continue;
			}
			//Filtro 4 - Transformar todas as letras em suas versões minúsculas!
			if (isupper(letra)) {
				letra = tolower(letra);
			}
			//sistema de concatenação de letras em uma string, para não precisar fazer um loop para printar cada letra usada!
			letras_usadas[strlen(letras_usadas)] = letra;
            letras_usadas[strlen(letras_usadas) + 1] = '\0';
			contagem_erros = 0;
			// Abaixo há a verificação se as letras estão presentes ou não da palavra selecionada aleatoriamente
				for(i = 0; i <= tamanho;i++){
					if (letra == palavra[i]){
						letras_certas++;
						variaveis_com_underline[i] = letra;		
					}
					else{
						contagem_erros++;
						if (contagem_erros > tamanho){//Afirma se o usuário errou alguma letra e qual letra ele errou
							printf("\nVocê errou, a letra '%c' não está presente na palavra misteriosa\n", letra);
							chances--;
							if (chances == 0){ //Verifica se o usuário perdeu todas as vidas, ou seja, se deu game over
								derrotas++;
								printf("\n----------Você perdeu todas as suas vidas\n");
								printf("----------A palavra correta era: %s\n", palavra);
								if (letras_certas > 0){
									printf("----------Pelo menos você acertou %d\n", letras_certas);
								}else{
									printf("----------Infelizmente você não acertou nenhuma letra sequer!!\n");
								}
								printf("===============================================\n\n");
								goto out; // go to serve para ir para uma parte específica do código, e é bom para fugir dos loops
						
							}else{//Afirma quantas vidas remanescentes o usuário possui
								printf("Só lhe restam %d vida(s)\n", chances);
						}
					}
					else{
							continue;
					}
				}
			} 
			printf("===============================================\n\n");
		} 
		//Verificação se venceu -- Transformar em função	 
		if (letras_certas == tamanho) {
        	printf("Você acertou a palavra %s!!!!\n", palavra);
        	vitorias++;
			}
	out: // checkpoint do goto out
	printf("\nVocê venceu %d e perdeu %d\n", vitorias, derrotas);
	printf("Deseja jogar novamente?\n 1-Sim\n 2-Não\n");
	printf("\nRespotas: %d", resposta);
	scanf("%d", &resposta);
	} while(resposta == 1);
};
