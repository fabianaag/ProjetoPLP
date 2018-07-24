:- initialization(main).

%Fatos
questao_facil_cc1("Qual o valor em decimal do binario 00000111?\nA) 7\nB) 8\nC) 6\nD) 14","a").
questao_facil_cc2("Qual alternativa nao contem um Hardware?\nA) Mouse\nB) Processador\nC) Chipset\nD) Debian","d").
questao_facil_cc3("Principal modulo de um computador, onde estao conectados todos os perifericos:\nA) CPU\nB) Placa mae\nC) Gabinete\nD) Entrada usb","b").

questao_media_cc1("Na computacao, qual tecnologia substituiu a valvula?\nA) Capacitor\nB) Resistor\nC) Transistor\nD) Diodo","c").
questao_media_cc2("Dizer que a classe A estende a classe B eh o mesmo que dizer que:\nA) As classes sao irmas\nB) A eh superclasse de B\nC) B eh filha de A\nD) A eh filha de B","d").
questao_media_cc3("O que eh um ENIAC?\nA) Um computador\nB) Uma configuracao\nC) Um congresso\nD) Um jogo","a").

questao_dificil_cc1("Pela ordem cronologica, marque a alternativa correta.\nA) Abaco, Eniac, Chip, Transistor e Microprocessador\nB) Eniac, Abaco, Chip, Transistor e Microprocessador\nC) Abaco, Eniac, Transistor, Chip e Microprocessador\nD) Abaco, Eniac, Chip, Microprocessador e Transistor","c").
questao_dificil_cc2("Se X, entao Y. Nao Y, logo:\nA) Nao Y\nB) X\nC) Nao X\nD) Y","c").
questao_dificil_cc3("O que eh mais rapido?\nA) HDD\nB) CD\nC) DVD\nD) SSD","d").

questao_facil_ge("Quanto vale 2+2?\nA) 5\nB) 7\nC) 4\nD) 2","c").
questao_facil_ge("O que esta escrito na bandeira do Brasil?\nA) Ordem e Regresso\nB) Ordem e Retrocesso\nC) Ordem e Progresso\nD) Progresso e Ordem","c").
questao_facil_ge("Qual a traducao da palavra inglesa 'horse'?\nA) Casa\nB) Cavalo\nC) Elefante\nD) Hipopotamo","b").

questao_media_ge1("A frase 'I have a dream' eh associada a:\nA) George W. Bush\nB) Martin Luther King\nC) Michael Jackson\nD) Snoop Dogg","b").
questao_media_ge2("Qual o maior e o menor pais do mundo? \nA) Russia e Vaticano\nB) China e Nepal\nC) Guiana Francesa e Estados Unidos\nD) Canada e Bangladesh","a").
questao_media_ge3("Qual foi o primeiro recurso usado para explicar a origem das coisas?\nA) Mitologia\nB) Filosofia\nC) Matematica\nD) Astronomia","a").

questao_dificil_ge1("Qual a altura em metros da rede de volei masculino e feminino?\nA) 2,5 e 2,0\nB) 2,45 para ambos\nC) 1,8 e 1,55\nD) 2,43 e 2,24","d").
questao_dificil_ge2("Em que periodo pre-historico o fogo foi descoberto?\nA) Neolitico\nB) Paleolitico\nC) Mesolitico\nD) Idade Media","b").
questao_dificil_ge3("Qual desses filmes foi baseado na obra de Shakespeare?\nA) Muito Barulho por Nada (2012)\nB) Capitaes de Areia (2011)\nC) A Dama das Camelias (1936)\nD) Excalibur","a").


% cria lista de fatos (perguntas, respostas), nesse caso ele cria uma lista APENAS das perguntas
% para serem checados os fatos no itera_sobre_perguntas
lista_perguntas_facil_ge(ListaFacilGe):-
          findall(Pfg, questao_facil_ge(Pfg, Rfg), ListaFacilGe).


% Itera sobre as perguntas, OBS.: tem que ver se precisa fazer uma iteração pra cada tipo de pergunta (facil, medio, dificil)
itera_sobre_perguntas([]).
itera_sobre_perguntas([H|T]):-
                        writeln(H),
                        read_line_to_string(user_input, Resposta),
                        write("Voce escolheu: "), writeln(Resposta),
                        questao_facil_ge(H, AlternCorreta),
                        write("Correta: "), writeln(AlternCorreta),
                        verifica_resposta(Resposta, AlternCorreta, Resultado),
                        imprime_resultado(Resposta),
                        itera_sobre_perguntas(T).


escolha_categoria("1", "Computacao").
escolha_categoria("2", "Conhecimentos Gerais").

%Regras
categoria_cc():- write("1 - Computacao"), nl.
categoria_ge():- write("2 - Conhecimentos Gerais"), nl.

verifica_resposta(Resposta, AlternCorreta, Resultado):-
                  Resposta =:= AlternCorreta -> Resultado = 1; Resultado = 0.

imprime_resultado(R):- R =:= 1 -> write("Voce acertou"); write("Voce errou!").

cabecalho:-
    write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."),nl,
    write(". ______________________________ S H O W ______________________________ ."), nl,
    write(". ________________________________ D O ________________________________ ."), nl,
    write(". ____________________________ M I L H A O ____________________________ ."), nl,
    write(". _____________________________________________________________________ ."), nl,
    write(".  Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao  ."), nl,
    write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."), nl.

main:-
    cabecalho,

    write("Qual o seu nome? "),
    read_line_to_string(user_input, Nome),

    write(Nome), writeln(", qual categoria de questoes voce deseja?"),
    categoria_cc(),
    categoria_ge(),
    read_line_to_string(user_input, Opcao),

    write("Voce escolheu "), escolha_categoria(Opcao, X), write(X), writeln(", boa sorte!"),

    lista_perguntas_facil_ge(Fg),
    itera_sobre_perguntas(Fg).
