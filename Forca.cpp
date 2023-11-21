#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <iostream>
#include <windows.h>

void limpar_console() {
	#ifdef _WIN32
	    system("cls");
	#else
	    system("clear");
	#endif
}

void desenha_boneco(int vida) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int coracao = 3;

	switch (vida) {
		case 0:
			//Morto
			SetConsoleTextAttribute(hConsole, 15);
			printf("===================================================================\n");	
		    printf("     ._____.\n"); 
		    printf("     |     |\n"); 
		    printf("     |     ");
		    SetConsoleTextAttribute(hConsole, 4);
			printf("O\n"); 
			SetConsoleTextAttribute(hConsole, 15);
		    printf("     |    ");
		    SetConsoleTextAttribute(hConsole, 4);
			printf ("/");
			printf("|");
			printf("\\ \n");
			SetConsoleTextAttribute(hConsole, 15);
		    printf("     |    ");
		    SetConsoleTextAttribute(hConsole, 4);
			printf("/");
			printf(" \\ \n");
			SetConsoleTextAttribute(hConsole, 15);
		    printf("   __|__\n  |     |______\n  |____________|\n");
		    
		    printf("   %c %c %c %c %c %c\n", coracao, coracao, coracao, coracao, coracao, coracao);
		break;
		case 1:
			//Perna Esquerda
			SetConsoleTextAttribute(hConsole, 15);
			printf("===================================================================\n");	
		    printf("     ._____.\n"); 
		    printf("     |     |\n"); 
		    printf("     |     ");
			printf("O\n"); 
		    printf("     |    ");
			printf ("/");
			printf("|");
			printf("\\ \n");
		    printf("     |    ");
			printf("/\n");
		    printf("   __|__\n  |     |______\n  |____________|\n");
		    
		    SetConsoleTextAttribute(hConsole, 4);
		    printf("   %c ", coracao, coracao);
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("%c %c %c %c %c\n", coracao, coracao, coracao, coracao, coracao);
		break;
		case 2:
			//Braco Direito
			SetConsoleTextAttribute(hConsole, 15);
			printf("===================================================================\n");
		    printf("     ._____.\n"); 
		    printf("     |     |\n"); 
		    printf("     |     ");
			printf("O\n"); 
		    printf("     |    ");
			printf ("/");
			printf("|");
			printf("\\ \n");
		    printf("     |    \n");
		    printf("   __|__\n  |     |______\n  |____________|\n");
		    
			SetConsoleTextAttribute(hConsole, 4);
		    printf("   %c %c ", coracao, coracao);
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("%c %c %c %c\n", coracao, coracao, coracao, coracao);
		break;
		case 3:
			//Braco Esquerdo
			SetConsoleTextAttribute(hConsole, 15);
			printf("===================================================================\n");
		    printf("     ._____.\n"); 
		    printf("     |     |\n"); 
		    printf("     |     ");
			printf("O\n"); 
		    printf("     |    ");
			printf ("/");
			printf("|\n");
		    printf("     |    \n");
		    printf("   __|__\n  |     |______\n  |____________|\n");
		
			SetConsoleTextAttribute(hConsole, 4);
		    printf("   %c %c %c ", coracao, coracao, coracao);
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("%c %c %c\n", coracao, coracao, coracao);
		break;
		case 4:  
		    //Tronco
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("===================================================================\n");
		    printf("     ._____.\n"); 
		    printf("     |     |\n"); 
		    printf("     |     ");
			printf("O\n"); 
		    printf("     |    ");
			printf(" |\n");;
		    printf("     |    \n");
		    printf("   __|__\n  |     |______\n  |____________|\n");
		    
		    SetConsoleTextAttribute(hConsole, 4);
		    printf("   %c %c %c %c ", coracao, coracao, coracao, coracao);
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("%c %c\n", coracao, coracao);
		break;
		case 5:
		    //Cabe�a
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("===================================================================\n");
		    printf("     ._____.\n"); 
		    printf("     |     |\n"); 
		    printf("     |     ");
			printf("O\n"); 
		    printf("     |    \n");
		    printf("     |    \n");
		    printf("   __|__\n  |     |______\n  |____________|\n");
		    
		    SetConsoleTextAttribute(hConsole, 4);
		    printf("   %c %c %c %c %c ", coracao, coracao, coracao, coracao, coracao);
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("%c\n", coracao, coracao);
		break;
		case 6:
			//Vivo
		    SetConsoleTextAttribute(hConsole, 15);
		    printf("===================================================================\n");
		    printf("     ._____.\n"); 
		    printf("     |     |\n"); 
		    printf("     |     \n");
		    printf("     |    \n");
		    printf("     |    \n");
		    printf("   __|__\n  |     |______\n  |____________|\n");
		    SetConsoleTextAttribute(hConsole, 4);
		    printf("   %c %c %c %c %c %c\n", coracao, coracao, coracao, coracao, coracao, coracao);
		    SetConsoleTextAttribute(hConsole, 15);
		break;
		case 7:
			//Menu
			SetConsoleTextAttribute(hConsole, 15);
			printf("===================================================================\n");
		 	printf("     ._____.\n"); 
			printf("     |     |\n"); 
			printf("     |     \n");
			printf("     |    \n");
			printf("     |    \n");
			printf("   __|__\n  |     |______\n  |____________|\n");
		}
}

void tela_saida() {
    printf("=============================================\n");
    printf("            Obrigado por Jogar!\n");
    printf("=============================================\n");
}

int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, "Portuguese");
	
	// Listas de palavras da forca!! e Lista de vari�veis presentes no programa!!
	char animais[][20] = {"tartaruga", "zebra", "coala", "camelo", "macaco", "cachorro", "cobra", "gato", "galo", "galinha", "cavalo", "vaca", "ganso", "pato", "asno", "avestruz", "rato", "capivara", "carpa", "marmota"};
	char objetos[][20] = {"anzol", "balde", "bola", "borracha", "faca", "canivete", "enxada", "flauta", "funil", "dado", "lanterna", "luva", "martelo", "mouse", "prato", "garfo", "colher", "copo", "tijolo", "mala"};
	char verbos[][20] = {"comer", "beber", "chutar", "bater", "lutar", "chicotear", "passear", "dirigir", "compartilhar", "pesquisar", "obedecer", "ouvir", "elevar", "quebrar", "praticar", "errar", "trair", "invadir", "planejar", "falsificar"};
	char frutas[][20] = {"laranja", "banana", "oliveira", "jaca", "jabuticaba", "abacaxi", "amora", "goiaba", "abacate", "acerola", "graviola", "cacau", "caqui", "carambola", "figo", "kiwi", "jambo", "manga", "morango", "pitaya"};
	
	// Lista de contadores
	int letras_certas, chances, contagem_erros, i, underline;
	//Outras vari�veis importantes
	int indice, tamanho;
	char categoria;
	int acertou = 1;
	int coracao = 3;
	char letra, *dica;
	char letras_usadas[26] = "";
	char x, y, z, a, b, c, d, e, f, g;
	
	// Vari�veis envolvidas no do{} while()
	int vitorias, derrotas;
	char resposta;
	vitorias = 0;
	derrotas = 0;
	
	do{
		memset(letras_usadas, 0, sizeof(letras_usadas)); // reseta a lista de letras usadas ao come�ar outra tentativa!!
		resposta = '\0';
		categoria = '\0';
		srand(time(NULL));/* Esse comando serve para resetar o rand. Pois se n�o houver ele, por algum motivo o rand pega a mesma palavra sempre! 
		Provavelmente ele salva na mem�ria algum endere�o!!*/
		chances = 6;
		char palavra[20];
		int categoriaErrada = 0, multiCaractere = 0;
		do {
			limpar_console();
			// In�cio!!
			//Aqui fica as intru��es iniciais
			if (categoria != '5' && categoria != '6' || categoria == '9') {
				printf("===================================================================\n");
			    printf("-------------------------");
			    SetConsoleTextAttribute(hConsole, 6);
				printf("Vamos Jogar Forca");
				SetConsoleTextAttribute(hConsole, 15);
				printf("-------------------------\n");
				desenha_boneco(7);
				SetConsoleTextAttribute(hConsole, 6);
			    printf("\n  Regras:");
			    SetConsoleTextAttribute(hConsole, 15);
				printf(" Voc� ter� 6");
			    SetConsoleTextAttribute(hConsole, 4);
				printf(" %c ", coracao);
				SetConsoleTextAttribute(hConsole, 15);
				printf("vidas, se errar a letra perder� uma vida.\n  Ao perder todas as vidas, Game over!!\n");
				SetConsoleTextAttribute(hConsole, 6);
			    printf("\n  Objetivos:");
			    SetConsoleTextAttribute(hConsole, 15);
				printf(" Descobrir a palavra com o m�ximo de vidas poss�vel.\n  Chegar no topo do ranking!!\n");
				SetConsoleTextAttribute(hConsole, 6);
				printf("\n  Observe:");
				 SetConsoleTextAttribute(hConsole, 15);
				printf(" Digite o n�mero correspondente a uma categoria. Caso o \n  n�mero informado esteja incorreto, a pergunta ser� repetida at� \n  que uma categoria v�lida seja selecionada.\n");
			    printf("\n  Selecione a categoria de palavras que voc� deseja jogar!\n\n  1 - Animais\n  2 - Objetos\n  3 - Verbos\n  4 - Frutas\n\n");
			    printf("  Ou selecione a tela que deseja acessar!\n\n  5 - Cr�ditos\n  6 - Sair\n\n");
			    if ( multiCaractere == 1 || categoriaErrada == 1) {
		    		SetConsoleTextAttribute(hConsole, 4);
					printf("  Essa categoria ou tela � inv�lida ou n�o existe, digite outro n�mero!!\n\n");
					SetConsoleTextAttribute(hConsole, 15);
				}
				printf("  Digite o n�mero da categoria: ");
				scanf("%c", &categoria);
				categoriaErrada = 0;
				if (categoria != '\n' && (getchar()) != '\n') {
	            	multiCaractere = 1;
		        } else {
		            multiCaractere = 0;
		        }
				fflush(stdin); 
	    	}
	    	
			//Sele��o da categoria e sorteio da palavra!!
			switch (categoria) {
	            case '1':
	                indice = rand() % (sizeof(animais) / sizeof(animais[0]));
	                strcpy(palavra, animais[indice]);
	                strcpy(dica, "Animal");
	                break;
	            case '2':
	                indice = rand() % (sizeof(objetos) / sizeof(objetos[0]));
	                strcpy(palavra, objetos[indice]);
	                strcpy(dica, "Objeto");
	                break;
	            case '3':
	                indice = rand() % (sizeof(verbos) / sizeof(verbos[0]));
	                strcpy(palavra, verbos[indice]);
	                strcpy(dica, "Verbo");
	                break;
	            case '4':
	                indice = rand() % (sizeof(frutas) / sizeof(frutas[0]));
	                strcpy(palavra, frutas[indice]);
	                strcpy(dica, "Fruta");
	                break;
	            case '5':
	            	do {
		            	limpar_console();
					    printf("=============================================\n");
					    printf("           Agradecimento Especial!\n");
					    printf("=============================================\n\n");
					
					    printf("  Agradecemos a contribui��o dos integrantes:\n\n");
					    printf("  - J�lio C�sar Carvalho Santos\n");
					    printf("  - Heitor de Oliveira Mamede\n");
					    printf("  - Perilo Oliveira Viana Sobrinho\n");
					    printf("  - Kau� Ravy Alves Pontes\n\n");
					    printf("  Pelo empenho e dedica��o ao projeto!\n\n");
					    printf("=============================================\n");
					
					    if (multiCaractere == 1 || categoriaErrada == 1) {
					        SetConsoleTextAttribute(hConsole, 4);
					        printf("\n  Essa categoria ou tela � inv�lida ou n�o existe, digite outro n�mero!!\n\n");
					        SetConsoleTextAttribute(hConsole, 15);
					    }
					
					    printf("  Selecione a tela que deseja acessar!\n\n  1 - �nicio\n  2 - Sair\n\n");
					    printf("  Digite o n�mero da categoria: ");
					    scanf(" %c", &categoria);
					    categoriaErrada = 0;
					
					    if (categoria != '\n' && (getchar()) != '\n') {
					        multiCaractere = 1;
					    } else {
					        multiCaractere = 0;
					    }
					    
					    if (categoria != '1' && categoria != '2') {
					        categoriaErrada = 1;
					    }
					    fflush(stdin); 
					} while (categoria < '1' || categoria > '2' || categoriaErrada == 1 || multiCaractere == 1);
					if (categoria == '1') 
						categoria = '9';
					if (categoria == '2')
						categoria = '6';
					break;
				case '6':
					limpar_console();
					tela_saida();
					exit(0);
	            default:
	                categoriaErrada = 1;
	        }
	    } while (categoria < '1' || categoria > '4' || categoriaErrada == 1 || multiCaractere == 1);
	    limpar_console();
		printf("===================================================================\n");	
		printf("  Vamos Come�ar, adivinhe a palavra!!!\n");
		printf("  As palavras que ser�o adivinhadas, n�o possuem acentos!!\n  N�o digite letras repetidas!!\n  Voc� possui 6");
		SetConsoleTextAttribute(hConsole, 4);
		printf(" %c", coracao);
		SetConsoleTextAttribute(hConsole, 15);
		printf(" vidas.\n");
		desenha_boneco(chances);
		
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
				printf("  Dica: %s com %d letras.\n", dica, tamanho);
				printf("\n  Letras Utilizadas: %s\n\n",letras_usadas);
				printf("	%s\n\n", variaveis_com_underline);
				printf("  Digite uma letra: ");
				scanf(" %[^\n]", &letra);
				limpar_console();
				acertou = 1;
				
				/*Verifica��o se realmente � letra e se a letra j� foi utilizada anteriormente. 
				Pensei em colocar repeti��o de letra como puni��o, mas a� seria muito malvado!
				Mesmo j� tendo colocado uma lista das letras usadas para a pessoa ver, mas como wallace disse, � usu�rio*/
				
				//Filtro 1 - Transformar todas as letras em suas vers�es min�sculas!
				if (isupper(letra)) {
					letra = tolower(letra);
				}
				 //Filtro 2 - Verificar se o usu�rio digitou mais de um caractere e impedir a continuidade se isso ocorrer!
	            if (strlen(&letra) > 1) {
	            	desenha_boneco(chances);
	            	SetConsoleTextAttribute(hConsole, 6);
	            	printf("\n  Voc� digitou mais de um caractere e isso n�o � permitido!! Tente novamente!\n\n");
	            	SetConsoleTextAttribute(hConsole, 15);
	                printf("===================================================================\n\n");
	                continue;
				}
				//Filtro 3 - Verifica se o caractere digitado � uma letra, !isalpha = se diferente de letra, entra nos comandos dentro do if 
				if (!isalpha(letra)){
					desenha_boneco(chances);
					SetConsoleTextAttribute(hConsole, 6);
					printf("\n  � necess�rio digitar uma letra e esse caractere n�o � uma letra!! Tente Novamente, digitando uma letra!\n\n");
					SetConsoleTextAttribute(hConsole, 15);
					printf("===================================================================\n\n");
					continue;
				}
				//Filtro 4 - Verificar se a letra j� foi utilizada anteriormente, e impedir isso!!
				if(strchr(letras_usadas, letra) != NULL) {
					desenha_boneco(chances);
					SetConsoleTextAttribute(hConsole, 6);
	                printf("\n  Voc� j� utilizou essa letra e isso n�o � permitido!! Tente novamente!\n\n");
	                SetConsoleTextAttribute(hConsole, 15);
	                printf("===================================================================\n\n");
	                continue;
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
							if (acertou == 1) {	
							desenha_boneco(chances);
							SetConsoleTextAttribute(hConsole, 10);
							printf("\n  Voc� acertou a letra '%c' est� presente na palavra misteriosa.\n\n", letra);
							SetConsoleTextAttribute(hConsole, 15);
							acertou = 0;
							}
						}
						else{
							contagem_erros++;
							if (contagem_erros > tamanho){//Afirma se o usu�rio errou alguma letra e qual letra ele errou
								chances--;
								desenha_boneco(chances);
								SetConsoleTextAttribute(hConsole, 12);
								printf("\n  Voc� errou, a letra '%c' n�o est� presente na palavra misteriosa.\n\n", letra);
								SetConsoleTextAttribute(hConsole, 15);
								if (chances == 0){ //Verifica se o usu�rio perdeu todas as vidas, ou seja, se deu game over
									derrotas++;
									SetConsoleTextAttribute(hConsole, 12);
									printf("  Voc� perdeu todas as suas vidas.\n\n");
									SetConsoleTextAttribute(hConsole, 15);
									printf("  A palavra correta era: ");
									SetConsoleTextAttribute(hConsole, 6);
									printf("%s\n\n", palavra);
									SetConsoleTextAttribute(hConsole, 15);
									if (letras_certas > 0){
										printf("  Voc� acertou %d letra(s)!!\n\n", letras_certas);
									}else{
										printf("  Infelizmente voc� n�o acertou nenhuma letra!!\n\n");
									}
									printf("===================================================================\n\n");
									goto out; // go to serve para ir para uma parte espec�fica do c�digo, e � bom para fugir dos loops
							
								}else{//Afirma quantas vidas remanescentes o usu�rio possui
									printf("  S� lhe restam %d vida(s).\n\n", chances);
							}
						}
						else{
								continue;
						}
					}
				} 
				printf("===================================================================\n\n");
			} 
			//Verifica��o se venceu -- Transformar em fun��o	 
			if (letras_certas == tamanho) {
				limpar_console();
	        	printf("  Voc� acertou a palavra %s!!\n\n", palavra);
	        	printf("  \\O/ \n   |\n  / \\\n");
	        	vitorias++;
				}
		out: // checkpoint do goto out
		printf("\n  Voc� venceu %d e perdeu %d\n", vitorias, derrotas);
		do {
			printf("  Deseja jogar novamente?\n   1 - Sim\n   2 - N�o\n");
			printf("\n  Resposta: ");
			scanf(" %c", &resposta);
			if (resposta != '\n' && (getchar()) != '\n') {
            	multiCaractere = 1;
	        } else {
	            multiCaractere = 0;
	        }
			if ((resposta != '1' && resposta != '2') || multiCaractere == 1) {
				limpar_console();
				SetConsoleTextAttribute(hConsole, 4);
				printf("  Essa resposta � inv�lida ou n�o existe, digite outro n�mero!!\n\n");
				SetConsoleTextAttribute(hConsole, 15);
			}
        } while (resposta != '1' && resposta != '2');
	
	} while(resposta == '1');
	limpar_console();
	tela_saida();
};
