:- initialization(main).

% Fatos
categoria("1", "Computacao").
categoria("2", "Conhecimentos Gerais").

premio(0, "R$0,00.", "R$0,00.", "R$0,00.").
premio(1, "R$1.000,00.", "R$0,00.", "R$0,00.").
premio(2, "R$10.000,00.", "R$500,00.", "R$1.000,00.").
premio(3, "R$50.000,00.", "R$5.000,00.", "R$10.000,00.").
premio(4, "R$100.000,00.", "R$25.000,00.", "R$50.000,00.").
premio(5, "R$500.000,00.", "R$500.00,00.", "R$100.000,00.").
premio(6, "1 MILHÃO.", "PERDEU TUDO.", "R$500.000,00.").

questao("1", "f", 1, "Qual o valor em decimal do binario 00000111?", "A) 7", "B) 8", "C) 6", "D) 14", "a").
questao("1", "f", 2, "Qual alternativa nao contem um Hardware?", "A) Mouse", "B) Processador", "C) Chipset", "D) Debian", "d").
questao("1", "f", 3, "Principal modulo de um computador, onde estao conectados todos os perifericos:", "A) CPU", "B) Placa mae", "C) Gabinete", "D) Entrada usb", "b").

questao("1", "m", 1, "Na computacao, qual tecnologia substituiu a valvula?", "A) Capacitor", "B) Resistor", "C) Transistor", "D) Diodo", "c").
questao("1", "m", 2, "Dizer que a classe A estende a classe B eh o mesmo que dizer que:", "A) As classes sao irmas", "B) A eh superclasse de B", "C) B eh filha de A", "D) A eh filha de B", "d").
questao("1", "m", 3, "O que eh um ENIAC?", "A) Um computador", "B) Uma configuracao", "C) Um congresso", "D) Um jogo", "a").

questao("1", "d", 1, "Pela ordem cronologica, marque a alternativa correta.", "A) Abaco, Eniac, Chip, Transistor e Microprocessador", "B) Eniac, Abaco, Chip, Transistor e Microprocessador", "C) Abaco, Eniac, Transistor, Chip e Microprocessador", "D) Abaco, Eniac, Chip, Microprocessador e Transistor", "c").
questao("1", "d", 2, "Se X, entao Y. Nao Y, logo:", "A) Nao Y", "B) X", "C) Nao X", "D) Y", "c").
questao("1", "d", 3, "O que eh mais rapido?", "A) HDD", "B) CD", "C) DVD", "D) SSD", "d").

questao("2", "f", 1, "Quanto vale 2+2?", "A) 5", "B) 7", "C) 4", "D) 2", "c").
questao("2", "f", 2, "O que esta escrito na bandeira do Brasil?", "A) Ordem e Regresso", "B) Ordem e Retrocesso", "C) Ordem e Progresso", "D) Progresso e Ordem", "c").
questao("2", "f", 3, "Qual a traducao da palavra inglesa 'horse'?", "A) Casa", "B) Cavalo", "C) Elefante", "D) Hipopotamo", "b").

questao("2", "m", 1, "A frase 'I have a dream' eh associada a:", "A) George W. Bush", "B) Martin Luther King", "C) Michael Jackson", "D) Snoop Dogg", "b").
questao("2", "m", 2, "Qual o maior e o menor pais do mundo? ", "A) Russia e Vaticano", "B) China e Nepal", "C) Guiana Francesa e Estados Unidos", "D) Canada e Bangladesh", "a").
questao("2", "m", 3, "Qual foi o primeiro recurso usado para explicar a origem das coisas?", "A) Mitologia", "B) Filosofia", "C) Matematica", "D) Astronomia", "a").

questao("2", "d", 1, "Qual a altura em metros da rede de volei masculino e feminino?", "A) 2,5 e 2,0", "B) 2,45 para ambos", "C) 1,8 e 1,55", "D) 2,43 e 2,24", "d").
questao("2", "d", 2, "Em que periodo pre-historico o fogo foi descoberto?", "A) Neolitico", "B) Paleolitico", "C) Mesolitico", "D) Idade Media", "b").
questao("2", "d", 3, "Qual desses filmes foi baseado na obra de Shakespeare?", "A) Muito Barulho por Nada (2012)", "B) Capitaes de Areia (2011)", "C) A Dama das Camelias (1936)", "D) Excalibur", "a").

% Regras
cabecalho :-
    write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."), nl,
    write(". ______________________________ S H O W ______________________________ ."), nl,
    write(". ________________________________ D O ________________________________ ."), nl,
    write(". ____________________________ M I L H A O ____________________________ ."), nl,
    write(". _____________________________________________________________________ ."), nl,
    write(".  Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao  ."), nl,
    write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."), nl.

leitura_nome(Nome) :-
    write("Qual o seu nome? "),
    read_line_to_string(user_input, Nome).

leitura_categoria(Nome, Opcao) :-
    write(Nome),
    write(", qual categoria de questoes voce deseja?"), nl,
    write("1 - Computacao"), nl,
    write("2 - Conhecimentos Gerais"), nl,
    read_line_to_string(user_input, Opcao).

impressao_categoria(Opcao) :-
    write("Voce escolheu "),
    categoria(Opcao, TextoCategoria),
    write(TextoCategoria),
    write(", boa sorte!"), nl.

nivel(Acertos, Nivel) :-
    (
    Acertos =< 2 -> Nivel = "f";
    Acertos =< 4 -> Nivel = "m";
    Nivel = "d"
    ).

indice_aleatorio(Indice) :- random_between(1, 3, Indice).

impressao_pergunta(Opcao, Nivel, Indice) :-
    questao(Opcao, Nivel, Indice, Pergunta, A, B, C, D, _),
    write(Pergunta), nl,
    write(A), nl,
    write(B), nl,
    write(C), nl,
    write(D), nl.

leitura_resposta(Resposta) :- read_line_to_string(user_input, Resposta).

impressao_resposta(Resposta) :-
    write("Voce escolheu: "),
    write(Resposta), nl.

impressao_alternativa_correta(Opcao, Nivel, Indice, AlternativaCorreta) :-
    questao(Opcao, Nivel, Indice, _, _, _, _, _, AlternativaCorreta),
    write("Correta: "),
    write(AlternativaCorreta), nl.

verifica_resposta(Resposta, AlternativaCorreta, Resultado) :-
    Resposta =:= AlternativaCorreta -> Resultado = 1;
    Resultado = 0.

imprime_resultado(Resultado, Acertos) :-
    premio(Acertos, Acertou, Errou, Parou),

    Resultado =:= 1 -> write("Voce acertou!! Ganhou: "),
    write(Acertou), nl;

    premio(Acertos, Acertou, Errou, Parou),
    write("Voce errou!!! Ganhou: "),
    write(Errou), nl,
    halt(0).

loop(Opcao, Acertos):-
      nivel(Acertos, Nivel),

      indice_aleatorio(Indice),

      impressao_pergunta(Opcao, Nivel, Indice),

      leitura_resposta(Resposta),
      impressao_resposta(Resposta),

      impressao_alternativa_correta(Opcao, Nivel, Indice, AlternativaCorreta),

      verifica_resposta(Resposta, AlternativaCorreta, Resultado),
      Acertos1 is Acertos + 1,
      imprime_resultado(Resultado, Acertos1),
      loop(Opcao, Acertos1).

inicio :-
    cabecalho,

    leitura_nome(Nome),

    leitura_categoria(Nome, Opcao),
    impressao_categoria(Opcao),

    Acertos is 0,
    loop(Opcao, Acertos).

main :-
    inicio,
    halt(0).
