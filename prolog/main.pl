:- initialization(main).

cabecalho:-
    write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."), nl,
    write(". ______________________________ S H O W ______________________________ ."), nl,
    write(". ________________________________ D O ________________________________ ."), nl,
    write(". ____________________________ M I L H A O ____________________________ ."), nl,
    write(". _____________________________________________________________________ ."), nl,
    write(".  Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao  ."), nl,
    write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."), nl.

pergunta1CC("Qual o valor em decimal do binario 00000111?
							A) 7
							B) 8
							C) 6
							D) 14","a")

main:-
    cabecalho,
    
    write("Qual o seu nome? "),
    read_line_to_string(user_input, Nome),
    
    write(Nome), writeln(", qual categoria de questoes voce deseja?"),
    writeln(" 1 - Computacao"),
    writeln(" 2 - Conhecimentos Gerais"),
    read_line_to_string(user_input, Opcao),
    
    write("Voce escolheu "), write(Opcao), writeln(", boa sorte!"),
    
    questoesCC(Questao, Resposta),
    writeln(Questao).
