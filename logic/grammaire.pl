s(C):-append(A,B,C), np(A), vp(B).
np(C):-append(A,B,C), det(A), n(B).
vp(C):-append(A,B,C), v(A), np(B).
vp(C):-v(C).
det([the]).
det([a]).
n([man]).
n([woman]).
v([shoots]).