main:-see('myfile.txt'),readin,seen.

readin:-get0(X),process(X).
process(-1).
process(X):-X =\= -1,put(X),readin.