:- initialization(main).

questao_facil_ge("Quanto vale 2+2?\nA) 5\nB) 7\nC) 4\nD) 2","c").
questao_facil_ge("O que esta escrito na bandeira do Brasil?\nA) Ordem e Regresso\nB) Ordem e Retrocesso\nC) Ordem e Progresso\nD) Progresso e Ordem","c").
questao_facil_ge("Qual a traducao da palavra inglesa 'horse'?\nA) Casa\nB) Cavalo\nC) Elefante\nD) Hipopotamo","b").

lista_perguntas_facil_ge(ListaFacilGe):-
          findall(Pfg, questao_facil_ge(Pfg, _), ListaFacilGe).

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

continua(R):- R =:= 0 -> writeln("Seu premio foi tanto"), halt(0) ; writeln("").

add_elem_inicio(X, L, [X|L]).
add_elem_fim(T, [H], L):- add_elem_inicio(H, [T], L).
add_elem_fim(N, [H|T], L):- add_elem_fim(N, T, X), add_elem_inicio(H, X, L).

rem_elem(Y, [Y], []).
rem_elem(X, [X|List1], List1).
rem_elem(X, [Y|List], [Y|List1]) :- rem_elem(X, List, List1).

escolher_perguntas([], []).
escolher_perguntas(List, List3) :-
    length(List, Length),
    random(0, Length, Index),
    nth0(Index, List, Elem),
    
    add_elem_inicio(Elem, [], List1),
    rem_elem(Elem, List, List2),
    
    length(List2, Length2),
    random(0, Length2, Index2),
    nth0(Index2, List2, Elem2),
    
    add_elem_fim(Elem2, List1, List3).

categoria("1", "Computacao").
categoria("2", "Conhecimentos Gerais").

intro:-
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

imprime_resultado(Resultado) :-
    Resultado =:= 1 -> writeln("Voce acertou");
    writeln("Voce errou!"), halt(0).

main:-
    intro,
    leitura_nome(Nome),
    leitura_categoria(Nome, Opcao),
    impressao_categoria(Opcao),

    lista_perguntas_facil_ge(Fg),
    escolher_perguntas(Fg, Fga),
    itera_sobre_perguntas(Fga).

