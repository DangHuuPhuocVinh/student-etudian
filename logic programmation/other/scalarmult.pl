scalarMult(_,[],[]).
scalarMult(X,[T|Q],[T1|Q1]):- T1 is X * T, scalarMult(X,Q,Q1).
/*
dotProduct([],[],_).
dotProduct([T1|Q1],[T2|Q2],X):-T3 is T1 * T2, scalarMult(Q1,Q2,X), scalarMult(Q1,Q2,T2).
*/
dP([T|Q],[T1|Q1],R):-dP_([T|Q],[T1|Q1],0,R).
dP_([],[],Acc,Acc).
dP_([T|Q],[T1|Q1],Acc,R):-M is T * T1, Acc1 is Acc + M, dP_(Q,Q1,Acc1,R).
/*
puissant(_,_,_).
puissant(X,Y,R):-puissant_(X,Y,0,R).
puissant_(X,Y,Acc,R):-Acc =< Y, Acc1 is Acc + 1, XX is X * X, puissant_(X,Y,Acc1,R).
*/

fibo(0,0).
fibo(1,1).
fibo(N,R):-N >= 2, N1 is N - 1, N2 is N - 2, fibo(N1,R1), fibo(N2,R2), R is R1 + R2.
/*
sImp([T|Q],S):-sImp_([T|Q],Acc,S).
sImp_([T|Q],Acc,S):-sImp(Q,Acc),S1 is Acc mod 2, S1 =:= 0, sImp_(S1,Acc,S).
*/
pair(X) :- Y is mod(X,2), Y =:= 0.
impair(X) :- Y is X + 1, pair(Y).
sum_pair(0, []).  
sum_pair(X, [H|T]) :- pair(H), sum_pair(Y, T), X is Y+H.
sum_pair(X, [H|T]) :- impair(H), sum_pair(X, T).
sum_impair(0, []).  
sum_impair(X, [H|T]) :- impair(H), sum_impair(Y, T), X is Y+H.
sum_impair(X, [H|T]) :- pair(H), sum_impair(X, T).

nombrePairs(0,[]).
nombrePairs(N,[T|Q]):-pair(T), nombrePairs(Y, Q), N is Q + 1.





