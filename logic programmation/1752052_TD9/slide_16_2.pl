main:-see('sortieavecformat.txt'),tell('output.txt'),readin,seen.

readin:-get0(X),process(X).
process(-1).
process(X):-X =\= -1,copy_file('sortieavecformat.txt', 'output.txt'),readin.