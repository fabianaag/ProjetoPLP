:- initialization(main).

questao_facil_ge("Quanto vale 2+2?\nA) 5\nB) 7\nC) 4\nD) 2","c").
questao_facil_ge("O que esta escrito na bandeira do Brasil?\nA) Ordem e Regresso\nB) Ordem e Retrocesso\nC) Ordem e Progresso\nD) Progresso e Ordem","c").
questao_facil_ge("Qual a traducao da palavra inglesa 'horse'?\nA) Casa\nB) Cavalo\nC) Elefante\nD) Hipopotamo","b").


lista_perguntas_facil_ge(ListaFacilGe):-
          findall(Pfg, questao_facil_ge(Pfg, Rfg), ListaFacilGe).

itera_sobre_perguntas([]).
itera_sobre_perguntas([H|T]):-
                       writeln(H),
                       read_line_to_string(user_input, Resposta),
                       write("Voce escolheu: "), writeln(Resposta),
                       questao_facil_ge(H, AlternCorreta),
                       write("Correta: "), writeln(AlternCorreta),
                       verifica_resposta(Resposta, AlternCorreta, Resultado),
                       imprime_resultado(Resultado),
                       continua(Resultado),
                       itera_sobre_perguntas(T).



verifica_resposta(Resposta, AlternCorreta, Resultado):-
                  Resposta =:= AlternCorreta -> Resultado = 1; Resultado = 0.


continua(R):- R =:= 0 -> writeln("Seu premio foi tanto"), halt(0) ; writeln("haha").

imprime_resultado(R):- R =:= 1 -> writeln("Voce acertou"); writeln("Voce errou!").


escolha_categoria("1", "Computacao").
escolha_categoria("2", "Conhecimentos Gerais").

categoria_cc():- write("1 - Computacao"), nl.
categoria_ge():- write("2 - Conhecimentos Gerais"), nl.



cabecalho:-
     write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."), nl,
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
