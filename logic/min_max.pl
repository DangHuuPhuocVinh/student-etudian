max([T|Q],X):-max_(Q,T,X).
max_([],Acc,Acc).
max_([T|Q],Acc,X):- T =< Acc, max(Q,Acc,X).

min([T|Q],M):-min_(Q,T,M).
min_([],Acc,Acc).
min_([T|Q],Acc,M):-T > Acc, min_(Q,Acc,M).
min_([T|Q],Acc,M):-T <= Acc, min_(Q,T,M).
/*san accumulateur*/
max1([T|Q],Y):-,max1_([T|Q],[_|Q],Y).
max1_([T],T).
max1_([_|Q],[],Y):-Y < _, max1_(Q,[_],Y).
max1_([_|Q],[],Y):-Y >= _, max1_(Q,[_|Q],Y).

min1([M],M).
min1([T|Q],M):-min1(Q,M1), T =< M1, M is T.
min1([T|Q],M):-min1(Q,M1), T > M1, M is M1.

max1([M],M).
max1([T|Q],M):-max1(Q,M1), T >= M1, M is T.
max1([T|Q],M):-max1(Q,M1), T < M1, M is M1.