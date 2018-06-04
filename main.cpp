#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

///Vetores
vector<vector<string>> questoesFaceisCC;
vector<vector<string>> questoesMediasCC;
vector<vector<string>> questoesDificeisCC;
vector<vector<string>> questoesFaceisGeral;
vector<vector<string>> questoesMediasGeral;
vector<vector<string>> questoesDificeisGeral;
vector<vector<string>> faceisAux;
vector<vector<string>> mediasAux;
vector<vector<string>> dificeisAux;
vector<int> premios;

///Variaveis
string ler;
int numeroDaRodadaAtual = 1; ///rodada 1 e 2(perguntas nivel facil), rodada 3 e 4(nivel medio), 5 e 6(nivel dificil)
int indiceDaPerguntaSorteada;
string letraRespostaCertaAtual = "";
string nomeDoJogador;
string resposta;
bool continuar = true;
int qtdCartas = 1;
int qtdUniversitarios = 1;
int qtdPlacas = 1;
int qtdPulos = 3;
bool usouCartas;
bool usouUniversitarios;
bool usouPlacas;
bool usouPulo;
int numeroDaCarta;
int alternativaRemovida = 0;
int variavelAux;
string cartaEscolhida;
string respostaCertaAtual = "";
bool jaUsouAjuda = false;
int a; int b; int c; int d;

///Metodos
void iniciarJogo();
void preencherQuestoes();
void escolherCategoria();
void preencherPremios();
void recebeRespostaDaQuestao();
void sorteiaQuestao();
void imprimirQuestao();
bool alternativaCorreta();
void imprimirResultado();
void prosseguir();
int geraIndiceAleatorio(int qtdDeIndices);
void cabecalho();
void limparTela();
void usarPulo();
void usarCartas();
void usarUniversitarios();///falta implementar
void usarPlacas();///falta implementar
void pararJogo();
void menuAjudas();
void questao();
int indiceRespostaCertaAtual();
void removeAlternativasDasPlacas(vector<vector<string>> &vector);
void tabelaDePremios();
void menuCategorias();





char alternativas[5] = {'a', 'b', 'c', 'd', '\0'};
bool acertou;
int indiceAleatorio;
int premioAtual = 0;
int pulos = 3;
char letraAleatoria(char alt[]);
void perderJogo();
void ganharJogo();
void imprimirPremios();
string escolherAlternativa();
void atualizarPremio();

int main() {
    iniciarJogo();
    do{
        imprimirQuestao();
        recebeRespostaDaQuestao();

    }while(continuar);
    return 0;
}

void limparTela() {
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

void cabecalho(){
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    //cout << ". _____________________________________________________________________ ." << endl;
    cout << ". ______________________________ S H O W ______________________________ ." << endl;
    cout << ". ________________________________ D O ________________________________ ." << endl;
    cout << ". ____________________________ M I L H A O ____________________________ ." << endl;
    cout << ". _____________________________________________________________________ ." << endl;
    cout << ".  Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao  ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl << endl;
}

void iniciarJogo() {
    preencherQuestoes(); /// tem que vir antes de escolherCategorias
    preencherPremios();
    cabecalho();
    cout << " Diga-me o seu nome: ";
    cin >> nomeDoJogador;
    limparTela();
    escolherCategoria();
    sorteiaQuestao();
}

void menuCategorias(){
    cout << " Qual categoria de questoes voce deseja?" << endl;
    cout << " 1 - Computacao" << endl;
    cout << " 2 - Conhecimentos Gerais" << endl;
}

void escolherCategoria(){
    cabecalho();
    menuCategorias();
    cout << "\n Digite o numero da categoria: ";
    cin >> resposta;
    while((resposta.compare("1") != 0) && (resposta.compare("2") != 0)){
        limparTela();
        cabecalho();
        menuCategorias();
        cout << "\n Categoria invalida. Digite 1 ou 2: ";
        cin >> resposta;
    }

    if(resposta.compare("1") == 0){
        faceisAux = questoesFaceisCC;
        mediasAux = questoesMediasCC;
        dificeisAux = questoesDificeisCC;
    }else if(resposta.compare("2") == 0){
        faceisAux = questoesFaceisGeral;
        mediasAux = questoesMediasGeral;
        dificeisAux = questoesDificeisGeral;
    }
    limparTela();
}

int indiceRespostaCertaAtual(){
    if(letraRespostaCertaAtual.compare("A") == 0){
        return 1;
    }else if(letraRespostaCertaAtual.compare("B") == 0){
        return 2;
    }else if(letraRespostaCertaAtual.compare("C") == 0){
        return 3;
    }else if(letraRespostaCertaAtual.compare("D") == 0){
        return 4;
    }
}


/// sorteia uma pergunta aleatoria retornando o indice da pergunta
void sorteiaQuestao(){
    if(numeroDaRodadaAtual <= 2){
        indiceDaPerguntaSorteada = geraIndiceAleatorio(faceisAux.size());
        letraRespostaCertaAtual = faceisAux.at(indiceDaPerguntaSorteada).at(5); ///poderia ser a 6, ai seria a letra minuscula
        respostaCertaAtual = faceisAux[indiceDaPerguntaSorteada][indiceRespostaCertaAtual()];

    }else if(numeroDaRodadaAtual >= 3 && numeroDaRodadaAtual <= 4){
        indiceDaPerguntaSorteada = geraIndiceAleatorio(mediasAux.size());
        letraRespostaCertaAtual = mediasAux.at(indiceDaPerguntaSorteada).at(5);
        respostaCertaAtual = mediasAux[indiceDaPerguntaSorteada][indiceRespostaCertaAtual()];

    }else{
        indiceDaPerguntaSorteada = geraIndiceAleatorio(dificeisAux.size());
        letraRespostaCertaAtual = dificeisAux.at(indiceDaPerguntaSorteada).at(5);
        respostaCertaAtual = dificeisAux[indiceDaPerguntaSorteada][indiceRespostaCertaAtual()];
    }
    usouCartas = false;
    usouPlacas = false;
    usouUniversitarios = false;
}

void questao(){
    if(numeroDaRodadaAtual == 1 && qtdPulos == 3 && !jaUsouAjuda){
        cout << "........................................................................." << endl;
        cout << " Bem vindo(a) " << nomeDoJogador << "! O jogo vai comecar, boa sorte!" << endl << endl;
    }
    if(jaUsouAjuda){
        cout << " VOCE USOU UMA AJUDA, AGORA SO RESTA RESPONDER OU PARAR." << endl;
        cout << "........................................................................." << endl << endl;
    }else{
        cout << " Prepare-se para a pergunta que vale R$ " << premios.at(numeroDaRodadaAtual-1) << endl;
        cout << "........................................................................." << endl << endl;
    }
    tabelaDePremios();

    if(numeroDaRodadaAtual <= 2){
        for(int i = 0 ; i < 5 ; ++i)
            cout << " " <<faceisAux.at(indiceDaPerguntaSorteada).at(i) << endl;
    }else if(numeroDaRodadaAtual >= 3 && numeroDaRodadaAtual <= 4){
        for(int i = 0 ; i < 5 ; ++i)
            cout <<  " " <<mediasAux.at(indiceDaPerguntaSorteada).at(i) << endl;
    }else{
        for(int i = 0 ; i < 5 ; ++i)
            cout <<  " " <<dificeisAux.at(indiceDaPerguntaSorteada).at(i) << endl;
    }
}

void tabelaDePremios(){
    cout << " ACERTAR: R$ "<< premios.at(numeroDaRodadaAtual-1);
    if(numeroDaRodadaAtual == 1){
        cout << "   PARAR: 0"; cout << "   ERRAR: 0" << endl <<endl;
    }else{
        cout << "   PARAR: R$ " << premios.at(numeroDaRodadaAtual-2); cout << "   ERRAR: R$ " << premios.at(numeroDaRodadaAtual-2) / 2 << endl <<endl;
    }
}

void removeAlternativasDasPlacas(vector<vector<string>> &vector){
    for(int i = 0 ; i < numeroDaCarta ; i++){
        do{
            alternativaRemovida = geraIndiceAleatorio(4) + 1;
        }while(alternativaRemovida == indiceRespostaCertaAtual() || vector[indiceDaPerguntaSorteada][alternativaRemovida].compare("---------") == 0);
        vector[indiceDaPerguntaSorteada][alternativaRemovida] = "---------";
    }
}

///Como fica a pergunta depois que usa as placas
void questaoDepoisDasCartas(){
    if(numeroDaRodadaAtual <= 2){
        removeAlternativasDasPlacas(faceisAux);

    }else if(numeroDaRodadaAtual >= 3 && numeroDaRodadaAtual <= 4){
        removeAlternativasDasPlacas(mediasAux);

    }else{
        removeAlternativasDasPlacas(dificeisAux);
    }
}

void imprimirQuestao() {
    questao();
    menuAjudas();
}

void menuAjudas(){
    cout << "\n";
    if(usouCartas || usouPlacas || usouUniversitarios){
        cout << " 5 - Parar" << endl << endl;
    }else{
        cout << " 1 - Pular " << qtdPulos << "/3" << endl;
        cout << " 2 - Cartas " << qtdCartas << "/1" << endl;
        cout << " 3 - Placas " << qtdPlacas << "/1" << endl;
        cout << " 4 - Universitarios " << qtdUniversitarios << "/1" << endl;
        cout << " 5 - Parar " << endl << endl;
    }
}

/// recebe a resposta da alternativa e verifica se a letra informada eh valida
void recebeRespostaDaQuestao(){
    bool respostaInvalida;
    cout << " Resposta: ";
    do{
        cin >> resposta;
        if( (resposta.compare("a") == 0) || (resposta.compare("b") == 0) || (resposta.compare("c") == 0) || (resposta.compare("d") == 0) ){
            respostaInvalida = false;
            limparTela();
            imprimirResultado();

        }else if((resposta.compare("5") != 0) && jaUsouAjuda) {
            if(usouCartas)
                usarCartas();
            else if(usouPlacas)
                usarPlacas();
            else if(usouUniversitarios)
                usarUniversitarios();
        }
        else if ( (resposta.compare("1") == 0) || (resposta.compare("2") == 0) || (resposta.compare("3") == 0) || (resposta.compare("4") == 0) || (resposta.compare("5") == 0) ) {
            respostaInvalida = false;
            int valor = atoi(resposta.c_str()); ///converter string para inteiro
            switch(valor){
                case 1:
                    usarPulo();
                    break;
                case 2:
                    usarCartas();
                    break;
                case 3:
                    usarPlacas();
                    break;
                case 4:
                    usarUniversitarios();
                    break;
                case 5:
                    pararJogo();
                    break;
            }
        }else{
            respostaInvalida = true;
            limparTela();
            if(numeroDaRodadaAtual != 1 || usouPulo){
                cout << "........................................................................." << endl;
                cout << " ESSA OPCAO NAO EXISTE... " << endl << endl;
            }
            imprimirQuestao();
            cout << " Digite uma resposta valida: ";
        }
    }while(respostaInvalida);
}

bool alternativaCorreta(){
    bool retorno;
    if(numeroDaRodadaAtual <= 2){ ///questoes faceis
        retorno = faceisAux.at(indiceDaPerguntaSorteada).at(5).compare(resposta) == 0 || faceisAux.at(indiceDaPerguntaSorteada).at(6).compare(resposta) == 0;
        faceisAux.erase(faceisAux.begin() + indiceDaPerguntaSorteada); ///agora apago essa questao pra ela nao se repetir na rodada

    }else if(numeroDaRodadaAtual >= 3 && numeroDaRodadaAtual <= 4){ ///questoes medias
        retorno = mediasAux.at(indiceDaPerguntaSorteada).at(5).compare(resposta) == 0 || mediasAux.at(indiceDaPerguntaSorteada).at(6).compare(resposta) == 0;
        mediasAux.erase(mediasAux.begin() + indiceDaPerguntaSorteada);

    }else{ ///questoes dificeis
        retorno = dificeisAux.at(indiceDaPerguntaSorteada).at(5).compare(resposta) == 0 || dificeisAux.at(indiceDaPerguntaSorteada).at(6).compare(resposta) == 0;
        dificeisAux.erase(dificeisAux.begin() + indiceDaPerguntaSorteada);
    }
    return retorno;
}

void imprimirResultado() {
    if (alternativaCorreta()) {
        cout << "........................................................................." << endl;
        cout << " PARABENS! voce ganhou o premio de R$ " << premios.at(numeroDaRodadaAtual-1) << " Milhao" << endl << endl;
        if(premios.size() == numeroDaRodadaAtual){ ///entao respondeu a ultima rodada
            cout << " $$$ Agora voce eh o mais novo milionario do Brasil! $$$" << endl;
            cout << "........................................................................." << endl;
                prosseguir();
        }else{
            usouCartas = false;
            usouPlacas = false;
            usouUniversitarios = false;
            jaUsouAjuda = false;
            usouPulo = false;
            numeroDaRodadaAtual++;
            sorteiaQuestao();
        }
    } else { ///errou a questao
        cout << "........................................................................." << endl;
        cout << " Que pena " << nomeDoJogador << ", voce errou..." << endl;
        if(numeroDaRodadaAtual == 1){
            cout << endl;
        }
        cout << " A resposta certa era a alternativa: " << respostaCertaAtual << endl;
        if(numeroDaRodadaAtual != 1){
            cout << " Voce leva pra casa R$ " << (premios.at(numeroDaRodadaAtual-2) /2 ) << endl;
        }
        cout << "........................................................................." << endl;
        prosseguir();
    }
}

void prosseguir(){
    bool respostaInvalida;
    cout << "\n Deseja jogar outra partida? s/n ";
		do{
			cin >> resposta;
			if(resposta.compare("n") == 0) {
				continuar = false;
				respostaInvalida = false;
			}else if(resposta.compare("s") == 0) {
				continuar = true;
				respostaInvalida = false;
			}else {
				respostaInvalida = true;
				limparTela();
				cout << "........................................................................." << endl << endl;
                cout << " OPS... " << endl << endl;
                cout << "........................................................................." << endl << endl;
				cout << " Deseja jogar outra partida? Digite s ou n: ";
			}
		}while(respostaInvalida);

		if (continuar) {
            numeroDaRodadaAtual = 1;
			//preencherQuestoes(); //nao precisa
			qtdCartas = 1;
            qtdUniversitarios = 1;
            qtdPlacas = 1;
            qtdPulos = 3;
            usouCartas = false;
            usouPlacas = false;
            usouUniversitarios = false;
            jaUsouAjuda = false;
            usouPulo = false;
			limparTela();
			escolherCategoria();
			sorteiaQuestao();
		}
}

int geraIndiceAleatorio(int qtdDeIndices){
    srand(time(nullptr));
    return rand() % qtdDeIndices;
}

void usarPulo(){

        limparTela();
        if(qtdPulos == 0){
            cout << "........................................................................." << endl;
            cout << " VOCE NAO PODE MAIS PULAR, APENAS RESPONDER OU ESCOLHER UMA AJUDA. " << endl << endl;
        }else{
            usouPulo = true;
            cout << "........................................................................." << endl;
            cout << " Voce pulou, ai vai a proxima pergunta... " << endl << endl;
            qtdPulos--;
            if(numeroDaRodadaAtual <= 2){ ///questoes faceis
                faceisAux.erase(faceisAux.begin() + indiceDaPerguntaSorteada);

            }else if(numeroDaRodadaAtual >= 3 && numeroDaRodadaAtual <= 4){
                mediasAux.erase(mediasAux.begin() + indiceDaPerguntaSorteada);

            }else{ ///questoes dificeis
                dificeisAux.erase(dificeisAux.begin() + indiceDaPerguntaSorteada);
            }
            sorteiaQuestao();
        }

}

void usarCartas(){
    limparTela();
    if(qtdCartas == 0 && !jaUsouAjuda){
        cout << "........................................................................." << endl;
        cout << " VOCE NAO PODE MAIS USAR AS CARTAS, APENAS RESPONDER OU ESCOLHER OUTRA AJUDA. " << endl << endl;
    }else{
        if(!usouCartas){
            qtdCartas--;
            do{
                limparTela();
                cout << "........................................................................." << endl;
                //cout << " Escolha a carta! Digite 1, 2 ou 3 " << endl;
                cout << "  ___           ___           ___" << endl;
                cout << " |###|         |###|         |###|" << endl;
                cout << " |###|         |###|         |###|" << endl;
                cout << " |###|         |###|         |###|" << endl << endl;
                cout << "........................................................................." << endl << endl;
                cout << " Escolha a carta! Digite 1, 2 ou 3: ";
                usouCartas = true;
                cin >> cartaEscolhida;

            }while(cartaEscolhida != "1" && cartaEscolhida != "2" && cartaEscolhida != "3");
            numeroDaCarta = (geraIndiceAleatorio(2) + 1);
        }
        limparTela();
       // if(jaUsouAjuda){
       //     cout << "----------------------------------------------------------------" << endl;
        //    cout << "VOCE JA USOU UMA AJUDA, AGORA SO RESTA RESPONDER OU PARAR." << endl;
       // }
        cout << "........................................................................." << endl;
        if(cartaEscolhida.compare("1") == 0){
            cout << "  ___           ___           ___" << endl;
            cout << " |" << numeroDaCarta << "  |         |###|         |###|" << endl;
            cout << " |   |         |###|         |###|" << "        " << numeroDaCarta << " alternativa(s) eliminada(s)" <<endl;
            cout << " |__" << numeroDaCarta << "|         |###|         |###|" <<endl << endl;
        }else if (cartaEscolhida.compare("2") == 0){
            cout << "  ___           ___           ___" << endl;
            cout << " |###|         |" << numeroDaCarta << "  |         |###|" << endl;
            cout << " |###|         |   |         |###|" << "        " << numeroDaCarta << " alternativa(s) eliminada(s)" << endl;
            cout << " |###|         |__" << numeroDaCarta << "|         |###|" << endl << endl;
        }else if (cartaEscolhida.compare("3") == 0){
            cout << "  ___           ___           ___" << endl;
            cout << " |###|         |###|         |" << numeroDaCarta << "  |" << endl;
            cout << " |###|         |###|         |   |" "        " << numeroDaCarta << " alternativa(s) eliminada(s)" << endl;
            cout << " |###|         |###|         |__" << numeroDaCarta << "|" << endl << endl;
        }

        if(!jaUsouAjuda && usouCartas){
            questaoDepoisDasCartas();
            jaUsouAjuda = true;
        }
    }
}

void usarPlacas(){
    limparTela();
    if(qtdPlacas == 0 && !jaUsouAjuda){
        cout << "........................................................................." << endl;
        cout << " VOCE NAO PODE MAIS USAR AS PLACAS, APENAS RESPONDER OU ESCOLHER OUTRA AJUDA. " << endl << endl;
    }else{
        if(!usouPlacas){
            variavelAux = geraIndiceAleatorio(100);
            usouPlacas = true;
            jaUsouAjuda = true;
            qtdPlacas--;
            a = geraIndiceAleatorio(12);
            b = geraIndiceAleatorio(12 - a);
            c = geraIndiceAleatorio(12 - a - b);
            d = 12 - a - b - c;
        }
        cout << "........................................................................." << endl;

        if(letraRespostaCertaAtual.compare("A") == 0){
            cout << " [A] " << a <<" placas   ";
            cout << "[B] " << b <<" placas   ";
            cout << "[C] " << c <<" placas   ";
            cout << "[D] " << d <<" placas   " << endl << endl;
        }else if(letraRespostaCertaAtual.compare("B") == 0){
            cout << " [A] " << b <<" placas   ";
            cout << "[B] " << a <<" placas   ";
            cout << "[C] " << c <<" placas   ";
            cout << "[D] " << d <<" placas   " << endl << endl;
        }else if(letraRespostaCertaAtual.compare("C") == 0){
            cout << " [A] " << c <<" placas   ";
            cout << "[B] " << b <<" placas   ";
            cout << "[C] " << a <<" placas   ";
            cout << "[D] " << d <<" placas   " << endl << endl;
        } else {
            cout << " [A] " << d <<" placas   ";
            cout << "[B] " << b <<" placas   ";
            cout << "[C] " << c <<" placas   ";
            cout << "[D] " << a <<" placas   " << endl << endl;
        }

    }
}

void usarUniversitarios(){
    limparTela();
    if(qtdUniversitarios == 0 && !jaUsouAjuda){
        cout << "........................................................................." << endl;
        cout << " VOCE NAO PODE MAIS USAR OS UNIVERSITARIOS, APENAS RESPONDER OU ESCOLHER OUTRA AJUDA. " << endl << endl;
    }else{
        if(!usouUniversitarios){
            variavelAux = geraIndiceAleatorio(100);
            usouUniversitarios = true;
            jaUsouAjuda = true;
            qtdUniversitarios--;
        }
        cout << "........................................................................." << endl;
        cout << " Estas sao as respostas dos 3 universitarios: ";
        if(variavelAux == 0 || variavelAux == 10 || variavelAux == 20){
            if(variavelAux == 0){
                cout << " [" << letraRespostaCertaAtual << "]   " << "[A]   "<< "[A]" << endl << endl;
            }else if(variavelAux == 10){
                cout << " [B]   " << "[" << letraRespostaCertaAtual << "]   "<< "[B]" << endl << endl;
            }else{
                cout << " [C]   " << "[C]   "<< "[" << letraRespostaCertaAtual << "]" << endl << endl;
            }
        }else if(variavelAux % 2 == 0){ ///eh par
            if(variavelAux > 10){
                cout << " [" << letraRespostaCertaAtual << "]   " << "[" << letraRespostaCertaAtual << "]   "<< "[" << letraRespostaCertaAtual << "]" << endl << endl;
            }else{
                cout << " [" << letraRespostaCertaAtual << "]   " << "[B]   "<< "[" << letraRespostaCertaAtual << "]" << endl << endl;
            }
        }else{ ///eh impar
            if(variavelAux > 10){
                cout << " [" << letraRespostaCertaAtual << "]   " << "[" << letraRespostaCertaAtual << "]   "<< "[C]" << endl << endl;
            }else{
                cout << " [A]   " << "[" << letraRespostaCertaAtual << "]   "<< "[" << letraRespostaCertaAtual << "]" << endl << endl;
            }
        }

    }
}

void pararJogo(){
    limparTela();
    cout << "........................................................................." << endl;
    if(numeroDaRodadaAtual == 1){
        cout << endl;
    }
    if(numeroDaRodadaAtual <= 3){
        cout << " Mas ja? Tudo bem..." << endl << endl;
    }else{
        cout << " Tudo bem, voce preferiu nao arriscar..." << endl << endl;
    }
    if(numeroDaRodadaAtual != 1){
        cout << " Voce leva pra casa R$ " << premios.at(numeroDaRodadaAtual-2) << endl;
    }
    cout << "........................................................................." << endl;
    prosseguir();
}

void preencherPremios() {
    premios.push_back(1000);
    premios.push_back(premios.at(0) * 10);
    premios.push_back(premios.at(1) * 5);
    premios.push_back(premios.at(2) * 2);
    premios.push_back(premios.at(3) * 5);
    premios.push_back(premios.at(4) * 2);
}

void preencherQuestoes() {
    /// vetor auxiliar que sera adicionado ao vetores principais
    /// depois da insercao esse vetor eh zerado e novas questoes sao atribuidas a ele
    vector<string> vetorAux;

    ///-----------------------CONHECIMENTO GERAL----------------------------
    ///faceis
    ///1
    vetorAux.push_back("Quanto vale 2+2?");
    vetorAux.push_back("A) 5");
    vetorAux.push_back("B) 7");
    vetorAux.push_back("C) 4");
    vetorAux.push_back("D) 2");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///2
    vetorAux.push_back("O que esta escrito na bandeira do Brasil?");
    vetorAux.push_back("A) Ordem e Regresso");
    vetorAux.push_back("B) Ordem e Retrocesso");
    vetorAux.push_back("C) Ordem e Progresso");
    vetorAux.push_back("D) Progresso e Ordem");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///3
    vetorAux.push_back("Qual a traducao da palavra inglesa 'horse'?");
    vetorAux.push_back("A) Casa");
    vetorAux.push_back("B) Cavalo");
    vetorAux.push_back("C) Elefante");
    vetorAux.push_back("D) Hipopotamo");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///4
    vetorAux.push_back("O que recebe uma pessoa que esta sendo doutrinada?");
    vetorAux.push_back("A) Repressao");
    vetorAux.push_back("B) Divertimento");
    vetorAux.push_back("C) Ensinamentos");
    vetorAux.push_back("D) Medicamentos");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///5
    vetorAux.push_back("Qual o nome da boneca que fala do Sitio do Pica Pau Amarelo?");
    vetorAux.push_back("A) Narizinho");
    vetorAux.push_back("B) Baby Alive");
    vetorAux.push_back("C) Annabelle");
    vetorAux.push_back("D) Emilia");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///6
    vetorAux.push_back("Os fantoches sao controlados por quais membros?");
    vetorAux.push_back("A) Maos");
    vetorAux.push_back("B) Pes");
    vetorAux.push_back("C) Bocas");
    vetorAux.push_back("D) Olhos");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///medias
    ///1
    vetorAux.push_back("A frase 'I have a dream' eh associada a: ");
    vetorAux.push_back("A) George W. Bush");
    vetorAux.push_back("B) Martin Luther King");
    vetorAux.push_back("C) Michael Jackson");
    vetorAux.push_back("D) Snoop Dogg");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    ///2
    vetorAux.push_back("Qual o maior e o menor pais do mundo? ");
    vetorAux.push_back("A) Russia e Vaticano");
    vetorAux.push_back("B) China e Nepal");
    vetorAux.push_back("C) Guiana Francesa e Estados Unidos");
    vetorAux.push_back("D) Canada e Bangladesh");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    ///3
    vetorAux.push_back("Qual foi o primeiro recurso usado para explicar a origem das coisas?");
    vetorAux.push_back("A) Mitologia");
    vetorAux.push_back("B) Filosofia");
    vetorAux.push_back("C) Matematica");
    vetorAux.push_back("D) Astronomia");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    ///4
    vetorAux.push_back("Como de chama a navegacao mercante entre portos de um mesmo pais?");
    vetorAux.push_back("A) Cabortice");
    vetorAux.push_back("B) Cabanagem");
    vetorAux.push_back("C) Cabotino");
    vetorAux.push_back("D) Cabotagem");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    ///5
    vetorAux.push_back("O que sao Pantalonas?");
    vetorAux.push_back("A) Calcas");
    vetorAux.push_back("B) Blusas");
    vetorAux.push_back("C) Casacos");
    vetorAux.push_back("D) Sapatos");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    ///6
    vetorAux.push_back("Onde esta localizada a regiao da Toscana?");
    vetorAux.push_back("A) Italia");
    vetorAux.push_back("B) Espanha");
    vetorAux.push_back("C) Alemanha");
    vetorAux.push_back("D) Escocia");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    ///dificeis
    ///1
    vetorAux.push_back("Qual a altura em metros da rede de volei masculino e feminino?");
    vetorAux.push_back("A) 2,5 e 2,0");
    vetorAux.push_back("B) 2,45 para ambos");
    vetorAux.push_back("C) 1,8 e 1,55");
    vetorAux.push_back("D) 2,43 e 2,24");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///2
    vetorAux.push_back("Em que periodo pre-historico o fogo foi descoberto?");
    vetorAux.push_back("A) Neolitico");
    vetorAux.push_back("B) Paleolitico");
    vetorAux.push_back("C) Mesolitico");
    vetorAux.push_back("D) Idade Media");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///3
    vetorAux.push_back("Qual desses filmes foi baseado na obra de Shakespeare?");
    vetorAux.push_back("A) Muito Barulho por Nada (2012)");
    vetorAux.push_back("B) Capit�es de Areia (2011)");
    vetorAux.push_back("C) A Dama das Cam�lias (1936)");
    vetorAux.push_back("D) Excalibur");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///4
    vetorAux.push_back("A mulher casada com o filho do meu avo que nao eh meu pai eh:");
    vetorAux.push_back("A) Minha prima");
    vetorAux.push_back("B) Minha cunhada");
    vetorAux.push_back("C) Minha tia");
    vetorAux.push_back("D) Minha mae");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///5
    vetorAux.push_back("Qual era a capital do Brasil antes de Brasilia?");
    vetorAux.push_back("A) Sao Paulo");
    vetorAux.push_back("B) Belo Horizonte");
    vetorAux.push_back("C) Minas Gerais");
    vetorAux.push_back("D) Rio de Janeiro");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///6
    vetorAux.push_back("Qual a primeira equipe que Ayrton Senna correu na formula 1?");
    vetorAux.push_back("A) Lotus");
    vetorAux.push_back("B) McLaren");
    vetorAux.push_back("C) Williams");
    vetorAux.push_back("D) Toleman");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    ///-----------------------COMPUTACAO----------------------------
    ///faceis
    ///1
    vetorAux.push_back("Qual o valor em decimal do binario 00000111");
    vetorAux.push_back("A) 7");
    vetorAux.push_back("B) 8");
    vetorAux.push_back("C) 6");
    vetorAux.push_back("D) 14");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    ///2
    vetorAux.push_back("Qual alternativa nao contem um Hardware?");
    vetorAux.push_back("A) Mouse");
    vetorAux.push_back("B) Processador");
    vetorAux.push_back("C) Chipset");
    vetorAux.push_back("D) Debian");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    ///3
    vetorAux.push_back("Principal modulo de um computador, onde estao conectados todos os perifericos");
    vetorAux.push_back("A) CPU");
    vetorAux.push_back("B) Placa mae");
    vetorAux.push_back("C) Gabinete");
    vetorAux.push_back("D) Entrada usb");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    ///4
    vetorAux.push_back("Qual o valor em decimal do binario 00010101");
    vetorAux.push_back("A) 21");
    vetorAux.push_back("B) 8");
    vetorAux.push_back("C) 20");
    vetorAux.push_back("D) 14");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    ///5
    vetorAux.push_back("Qual alternativa contem um Hardware?");
    vetorAux.push_back("A) Windows");
    vetorAux.push_back("B) Unix");
    vetorAux.push_back("C) CPU");
    vetorAux.push_back("D) Debian");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    ///6
    vetorAux.push_back("O que significa USB?");
    vetorAux.push_back("A) Universal Sata Bus");
    vetorAux.push_back("B) Universal Serial Bus");
    vetorAux.push_back("C) Universal Sata Branch");
    vetorAux.push_back("D) Universal Serial Builder");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    ///medias
    ///1
    vetorAux.push_back("Em computacao, o que significa C.S.?");
    vetorAux.push_back("A) Command Star");
    vetorAux.push_back("B) Counter Strike");
    vetorAux.push_back("C) Chip Set");
    vetorAux.push_back("D) Computer Science");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    ///2
    vetorAux.push_back("Na computacao, qual tecnologia substituiu a valvula?");
    vetorAux.push_back("A) Capacitor");
    vetorAux.push_back("B) Resistor");
    vetorAux.push_back("C) Transistor");
    vetorAux.push_back("D) Diodo");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    ///3
    vetorAux.push_back("Dizer que a classe A estende a classe B eh o mesmo que dizer que:");
    vetorAux.push_back("A) As classes sao irmas");
    vetorAux.push_back("B) A eh superclasse de B");
    vetorAux.push_back("C) B eh filha de A");
    vetorAux.push_back("D) A eh filha de B");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    ///4
    vetorAux.push_back("Em computacao, a sigla S.O. significa: ");
    vetorAux.push_back("A) Sistema Ocioso");
    vetorAux.push_back("B) Sistema Ondulatorio");
    vetorAux.push_back("C) Sistema Ok");
    vetorAux.push_back("D) Sistema Operacional");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    ///5
    vetorAux.push_back("O que eh um ENIAC");
    vetorAux.push_back("A) Um computador");
    vetorAux.push_back("B) Uma configuracao");
    vetorAux.push_back("C) Um congresso");
    vetorAux.push_back("D) Um jogo");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    ///6
    vetorAux.push_back("Por que um sistema operacional eh importante?");
    vetorAux.push_back("A) Porque eh a unidade central de procedimentos do computador");
    vetorAux.push_back("B) Porque ele organiza e administra os recursos do computador possibilitando seu uso");
    vetorAux.push_back("C) Para assistir Netflix");
    vetorAux.push_back("D) Para fazer trabalhos e salvar documentos com maior seguran�a");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    ///dificeis
    ///1
    vetorAux.push_back("Na ordem cronologica, marque a alternativa correta");
    vetorAux.push_back("A) Abaco, Eniac, Chip, Transistor e Microprocessador");
    vetorAux.push_back("B) Eniac, Abaco, Chip, Transistor e Microprocessador");
    vetorAux.push_back("C) Abaco, Eniac, Transistor, Chip e Microprocessador.");
    vetorAux.push_back("D) Abaco, Eniac, Chip, Microprocessador e Transistor");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();

    ///2
    vetorAux.push_back("Qual o nome completo de Steven Jobs");
    vetorAux.push_back("A) Steven Paul Jobs");
    vetorAux.push_back("B) Steven Apple Jobs");
    vetorAux.push_back("C) Steven Spielberg Jobs");
    vetorAux.push_back("D) Steven Seagal Jobs");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();

    ///3
    vetorAux.push_back("Pela ordem cronologica, marque a alternativa correta");
    vetorAux.push_back("A) Abaco, Eniac, Chip, Transistor e Microprocessador");
    vetorAux.push_back("B) Eniac, Abaco, Chip, Transistor e Microprocessador");
    vetorAux.push_back("C) Abaco, Eniac, Transistor, Chip e Microprocessador.");
    vetorAux.push_back("D) Abaco, Eniac, Chip, Microprocessador e Transistor");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();

    ///4
    vetorAux.push_back("Se X, entao Y. Nao Y, logo: ");
    vetorAux.push_back("A) Nao Y");
    vetorAux.push_back("B) X");
    vetorAux.push_back("C) Nao X");
    vetorAux.push_back("D) Y");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();

    ///5
    vetorAux.push_back("O que eh mais rapido? ");
    vetorAux.push_back("A) HDD");
    vetorAux.push_back("B) CD");
    vetorAux.push_back("C) DVD");
    vetorAux.push_back("D) SSD");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();

    ///6
    vetorAux.push_back("Em OO existe uma medida do grau de dependencia entre objetos que eh: ");
    vetorAux.push_back("A) Integracao");
    vetorAux.push_back("B) Acoplamento");
    vetorAux.push_back("C) Heranca");
    vetorAux.push_back("D) Protocolo");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();
}













string escolherAlternativa() {
    string nome_bot = nomeDoJogador;
    transform(nome_bot.begin(), nome_bot.end(), nome_bot.begin(), ::tolower);
    cout << "\nEscolha uma alternativa:" << endl;
    if (nome_bot.compare("bot") == 0) {
        resposta = letraAleatoria(alternativas);
    } else {
        cin >> resposta;
    }
    return resposta;
}

void imprimirPremios() {
    for (int i = 0; i < premios.size(); ++i) {
        cout << premios.at(i) << endl;
    }
}

void perderJogo() {
    if (premioAtual == 0) {
        cout << "Infelizmente " << nomeDoJogador << ", voce errou e perdeu tudo." << endl;
        cout << "Boa sorte na proxima vez." << endl;
    }

}

void ganharJogo() {
    cout << "PARABENS " << nomeDoJogador << "! Voce ganhou R$ 1 milhao!!!" << endl;
}

void atualizarPremio() {
    if (acertou) {
        premioAtual += 1;
    }
}

/*Faceis: 1mil, 10mil
Medias: 50mil, 100 mil
Dificeis: 500 mil, 1milhao*/



// Essa funcao eh usada para o bot
char letraAleatoria(char alt[]) {
    int randomIndex = rand() % 4;
    return alt[randomIndex];
}
