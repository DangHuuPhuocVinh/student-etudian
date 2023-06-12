sumto(1,1).
sumto(N,S):-N > 1, NN is N - 1, sumto(NN,NS), S is NS + N.