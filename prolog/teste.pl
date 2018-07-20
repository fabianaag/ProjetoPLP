:- initialization(main).

cabecalho:-
	write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."),nl,
	write(". ______________________________ S H O W ______________________________ ."),nl,
	write(". ________________________________ D O ________________________________ ."),nl,
	write(". ____________________________ M I L H A O ____________________________ ."),nl,
  write(". _____________________________________________________________________ ."),nl,
  write(".  Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao  ."),nl,
  write(". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."),nl.

respostas(Numero, Resposta)
perguntas(Numero, Pergunta)

main:-
  cabecalho,
  write("Bota teu nome aí: "),
  read_line_to_string(user_input, Nome),
  write(Nome), writeln(", qual categoria de questoes voce deseja?"),
  writeln(" 1 - Computacao"),
  writeln(" 2 - Conhecimentos Gerais"),
  read_line_to_string(user_input, Opcao),
  write("Voce escolheu "), write(Opcao), writeln(", boa sorte!"),
  questoesCC(Questao, Resposta),
  writeln(Questao).
