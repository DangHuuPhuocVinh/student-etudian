/* Ex 1 */
main:- open('sortieavecformat.txt',write,Str),
       tab(Str,10),write(Str,'un'),nl(Str),
       tab(Str,5),write(Str,'deux'),tab(Str,5),write(Str,"trois"),nl(Str),
       tab(Str,1),write(Str,'quatre'),tab(Str,3),write(Str,'cinq'),tab(Str,5),write(Str,'six'),
       close(Str).

/* Ex 2 */    
main2:- open('sortieavecformat.txt',read,Str),
		get_code(Str,X),
		read_line(X,Str,Liste),
		print(Liste),
		close(Str).

read_line(-1, _, []).

read_line(N, M, [N1|N2]):- 
	check(N, Chars, M), 
	atom_codes(N1, Chars), 
	get_code(M,Y), 
	read_line(Y,M,N2).

check(10, [], _):- !.
check(32, [], _):- !.
check(46, [], _):- !.
check(44, [], _):- !.
check(-1, [], _):- !.
check(9, [], _):- !.
check(Char, [Char|L2], S):- 
	get_code(S, NextChar), 
	check(NextChar,L2,S).

print([]).
print([X|L]):- X \= '', writeln(X), print(L).
print([X|L]):- X == '', print(L).

/* Ex 3 */
main3:-open('sortieavecformat.txt',read,Str),
	get_code(Str,X), read_line2(X,Str,L), copy_list(L,R), count(L,R,E), list_to_set(E,R1), output(R1),
	close(Str).

read_line2(-1, _, []).

read_line2(X,M,[A|L]):-
	check2(X,Chars,M),
	atom_codes(A,Chars),
	get_code(M,Y),
	read_line2(Y, M, L).

check2(10, [], _):- !.
check2(32, [], _):- !.
check2(46, [], _):- !.
check2(44, [], _):- !.
check2(-1, [], _):- !.
check2(Char,[Char|L],S):-
			get_code(S,NextChar),
			check2(NextChar,L,S).
		
copy_list([],[]).
copy_list([X|L],[X|LR]):- copy_list(L,LR).
			
output([]).
output([X|L]):- writeln(X), output(L). 

count([],_,[]).
count([X|X1],R,[E|Arc]):- count_(X,R,N), atomic_list_concat([X,': ',N], E), count(X1,R,Arc).

count_(_, [], 0).
count_(X,[H|T], N) :- X == H, count_(X, T, Acc), N is Acc + 1.
count_(X,[H|T], N) :- X \= H, count_(X, T, N).