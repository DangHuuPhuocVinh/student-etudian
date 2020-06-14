/* Ex 1 */

main:-open('input.txt',write,Str),
    write(Str,'1 2 7 4 5'),nl(Str),
    write(Str,'3 1 0 7 9'),
    close(Str).

calcule(Input, Output):-
    open(Input,read,Str),
    open(Output,write,Str2),
    get_code(Str,X),
    read_line(X, Str, 0, [], Str2),
    close(Str),
    close(Str2).

read_line(-1, _, Num, L, Str2):-
    sum(Str2, [Num|L], 0).
read_line(-1, _, _, _, _).

read_line(10, M, Num , L, Str2):-
    sum(Str2, [Num|L], 0),
    get_code(M, Y),
    read_line(Y, M, 0, [], Str2).
read_line(32, M, Num, L, Str2):-
    get_code(M, Y),
    read_line(Y, M, 0, [Num|L], Str2).
read_line(N, M, Num, L, Str2):- 
    Num1 is Num * 10 + (N - 48),
	get_code(M,Y),
	read_line(Y, M, Num1, L, Str2).

sum(Str, [], Sum):-writeln(Str, Sum).
sum(Str, [X|Tail],Sum):-
    Sum1 is Sum + X,
    sum(Str, Tail,Sum1).

/* Ex 2 */
grammaire(X):- open(X,read,Str),
    get_code(Str,Y),
    read1(Y, Str),
    close(Str).

check(X):-s(X, []), writeln('True').
check(_):-writeln('False').

printList([X]):-write(X), writeln('.').
printList([X|List]):-write(X), write(' '),printList(List).

read1(-1, _).
read1(X, Str):-
    read_line(X, Str, L),
    flat(L, Liste),
    printList(Liste),
    check(Liste),
    get_code(Str, Y),
    read1(Y, Str).


read_line(-1, _, []).
read_line(10,  _, []).
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

flat([],[]).
flat([X|L], [X|List]):-X \= '', flat(L, List).
flat(L, [X|List]):-X == '', flat(L, List).


s-->np,vp.

np-->det,a.
np-->det1,a.
np-->det1,x.
np-->det2,x.
np-->det,n.
np-->det1,n.
x-->adj3,n.
a-->adj1,b.
a-->adj1,n.
a-->adj2,n.
b-->adj2,n.
b-->adj3,n.
b-->n.

vp-->v,c.
vp-->v.
vp-->c.
c-->np.

adj1-->[large].
adj1-->[small].
adj2-->[brown].
adj3-->[orange].
adj2-->[green].
adj2-->[blue].
v-->[sat].
v-->[saw].
v-->[hears].
v-->[took].
v-->[sees].
v-->[will_see].
n-->[cat].
n-->[mat].
n-->[man].
n-->[boy].
n-->[dog].
det1-->[the].
det-->[a].
det2-->[an].
