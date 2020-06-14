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
np-->det,n.
a-->n,v.
a-->adj1,b.
b-->adj2,n.

vp-->det, d.
vp-->det, v.
vp-->c.
c-->det,d.
d-->adj2,n.
d-->adj1,e.
e-->adj2,n.
e-->n.
d-->n.

det-->[the].
det-->[a].
det-->[an].
adj1-->[large].
adj1-->[small].
adj2-->[brown].
adj2-->[orange].
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

