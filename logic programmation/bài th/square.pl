writesquares(1):-write('1^2=1'),nl.
writesquares(N):-N > 1, NN is N - 1, writesquares(NN), write(N), write('^2='), SQ is N * N, write(SQ),nl.