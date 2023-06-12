loop(0):-write('The value is: 0').
loop(N):-N >= 0,write('The value is: '), write(N),nl, NN is N - 1, loop(NN).
