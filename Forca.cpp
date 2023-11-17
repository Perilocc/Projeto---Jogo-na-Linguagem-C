#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(){
	setlocale(0, "Portuguese");
	
	// Listas de palavras da forca!! e Lista de vari�veis presentes no programa!!
	char animais[][20] = {"tartaruga", "zebra", "coala", "camelo", "macaco", "cachorro", "cobra", "gato", "galo", "galinha", "cavalo", "vaca", "ganso", "pato", "asno", "avestruz", "rato", "capivara", "carpa", "marmota"};
	char objetos[][20] = {"anzol", "balde", "bola", "borracha", "faca", "canivete", "enxada", "flauta", "funil", "dado", "lanterna", "luva", "martelo", "mouse", "prato", "garfo", "colher", "copo", "tijolo", "mala"};
	char verbos[][20] = {"comer", "beber", "chutar", "bater", "lutar", "chicotear", "passear", "dirigir", "compartilhar", "pesquisar", "obedecer", "ouvir", "elevar", "quebrar", "praticar", "errar", "trair", "invadir", "planejar", "falsificar"};
	char frutas[][20] = {"laranja", "banana", "oliveira", "jaca", "jabuticaba", "abacaxi", "amora", "goiaba", "abacate", "acerola", "graviola", "cacau", "caqui", "carambola", "figo", "kiwi", "jambo", "manga", "morango", "pitaya"};
	
	// Lista de contadores
	int letras_certas, chances, contagem_erros, i, underline;
	//Outras vari�veis importantes
	int categoria, indice, tamanho;
	char letra, *dica;
	char letras_usadas[26] = "";
	char x, y, z, a, b, c, d, e, f, g;
	
	// Vari�veis envolvidas no do{} while()
	int vitorias, derrotas, resposta;
	
	vitorias = 0;
	derrotas = 0;
	
	do{
	inicio:
	memset(letras_usadas, 0, sizeof(letras_usadas)); // reseta a lista de letras usadas ao come�ar outra tentativa!!
	resposta = '\0';
	categoria = '\0';
	srand(time(NULL));/* Esse comando serve para resetar o rand. Pois se n�o houver ele, por algum motivo o rand pega a mesma palavra sempre! 
	Provavelmente ele salva na mem�ria algum endere�o!!*/
	chances = 6;
	// In�cio!!
	
	//Aqui fica as intru��es iniciais
	printf("===============================================\n");
	printf("----------------Vamos Jogar Forca--------------\n");
	printf("\nPara isso voc� ter� 6 vidas, se errar a letra perder� uma vida.\nPerdendo todas as vidas, Game over!!\n");
	printf("\nSelecione a categoria de palavras que voc� deseja!\n");
	printf("Digite o n�mero da categoria:\n 1-Animais\n 2-Objetos\n 3-Verbos\n 4-Frutas\n");
	printf("\ncategoria: ");
	scanf("%d", &categoria);
	
	char palavra[20];
		//Sele��o da categoria e sorteio da palavra!!
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
			printf("\nEssa categoria � inv�lida ou n�o existe, digite outro n�mero!!\n\n");
			goto inicio;
	}
	
	printf("===============================================");	
	printf("\nVamos Come�ar, adivinhe a palavra!!!\n");
	printf("Digite apenas letras min�sculas!\nN�o digite letras repetidas!!\nAs palavras que ser�o adivinhadas, n�o possuem acentos!!\nLembre-se, voc� possui 6 vidas\n");
	printf("===============================================\n\n");
	
	// Tamanho da palavra sorteada
	tamanho = strlen(palavra);
	// Adapta o sistema para palavras com at� 10 letras, no qual se a palavra possui 5 letras, haver�o 5 underlines para o usu�rio substituir!
		char variaveis[10] = {x, y, z, a, b, c, d, e, f, g};
		char variaveis_com_underline[10] = {};
		
		for (underline = 0; underline < tamanho; underline++) { // Obs: a vari�vel underline � um contador
    		variaveis[underline] = '_';
    		if (variaveis[underline] == '_') {
    			variaveis_com_underline[underline] = variaveis[underline];
			}
    	}
    	
		//Funcionamento b�sico: Vai mostrar as letras utilizadas, mostrar o progresso e pedir ao usu�rio a letra. tudo isso em loop para ser realizado at� ganhar ou perder.
		for(letras_certas = 0; letras_certas < tamanho;){
			printf("Dica: %s com %d letras\n", dica, tamanho);
			printf("\nLetras Utilizadas: %s\n\n",letras_usadas);
			printf("''''''''''%s''''''''''\n\n", variaveis_com_underline);
			printf("----------Digite uma letra: ");
			scanf(" %[^\n]", &letra);
			
			/*Verifica��o se realmente � letra e se a letra j� foi utilizada anteriormente. 
			Pensei em colocar repeti��o de letra como puni��o, mas a� seria muito malvado!
			Mesmo j� tendo colocado uma lista das letras usadas para a pessoa ver, mas como wallace disse, � usu�rio*/
			
			//Filtro 1 - Verifica se o caractere digitado � uma letra, !isalpha = se diferente de letra, entra nos comandos dentro do if 
			if (!isalpha(letra)){
				printf("\n� necess�rio digitar uma letra, e esse caractere n�o � uma letra!! Tente Novamente, digitando uma letra!\n");
				printf("===============================================\n\n");
				continue;
			}
			//Filtro 2 - Verificar se a letra j� foi utilizada anteriormente, e impedir isso!!
			if(strchr(letras_usadas, letra) != NULL) {
                printf("\nVoc� j� utilizou essa letra, e isso n�o � permitido!! Tente novamente!\n");
                printf("===============================================\n\n");
                continue;
            }
            //Filtro 3 - Verificar se o usu�rio digitou mais de um caractere e impedir a continuidade se isso ocorrer!
            if (strlen(&letra) > 1) {
            	printf("\nVoc� j� , e isso n�o � permitido!! Tente novamente!\n");
                printf("===============================================\n\n");
                continue;
			}
			//Filtro 4 - Transformar todas as letras em suas vers�es min�sculas!
			if (isupper(letra)) {
				letra = tolower(letra);
			}
			//sistema de concatena��o de letras em uma string, para n�o precisar fazer um loop para printar cada letra usada!
			letras_usadas[strlen(letras_usadas)] = letra;
            letras_usadas[strlen(letras_usadas) + 1] = '\0';
			contagem_erros = 0;
			// Abaixo h� a verifica��o se as letras est�o presentes ou n�o da palavra selecionada aleatoriamente
				for(i = 0; i <= tamanho;i++){
					if (letra == palavra[i]){
						letras_certas++;
						variaveis_com_underline[i] = letra;		
					}
					else{
						contagem_erros++;
						if (contagem_erros > tamanho){//Afirma se o usu�rio errou alguma letra e qual letra ele errou
							printf("\nVoc� errou, a letra '%c' n�o est� presente na palavra misteriosa\n", letra);
							chances--;
							if (chances == 0){ //Verifica se o usu�rio perdeu todas as vidas, ou seja, se deu game over
								derrotas++;
								printf("\n----------Voc� perdeu todas as suas vidas\n");
								printf("----------A palavra correta era: %s\n", palavra);
								if (letras_certas > 0){
									printf("----------Pelo menos voc� acertou %d\n", letras_certas);
								}else{
									printf("----------Infelizmente voc� n�o acertou nenhuma letra sequer!!\n");
								}
								printf("===============================================\n\n");
								goto out; // go to serve para ir para uma parte espec�fica do c�digo, e � bom para fugir dos loops
						
							}else{//Afirma quantas vidas remanescentes o usu�rio possui
								printf("S� lhe restam %d vida(s)\n", chances);
						}
					}
					else{
							continue;
					}
				}
			} 
			printf("===============================================\n\n");
		} 
		//Verifica��o se venceu -- Transformar em fun��o	 
		if (letras_certas == tamanho) {
        	printf("Voc� acertou a palavra %s!!!!\n", palavra);
        	vitorias++;
			}
	out: // checkpoint do goto out
	printf("\nVoc� venceu %d e perdeu %d\n", vitorias, derrotas);
	printf("Deseja jogar novamente?\n 1-Sim\n 2-N�o\n");
	printf("\nRespotas: %d", resposta);
	scanf("%d", &resposta);
	} while(resposta == 1);
};
