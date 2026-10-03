% Facts
american(robert).
missile(m1).
owns(america, m1).
sells(robert, m1, country_a).
enemy(country_a, america).

% Rules
weapon(X) :-
    missile(X).

hostile(X) :-
    enemy(X, america).

criminal(X) :-
    american(X),
    weapon(Y),
    sells(X, Y, Z),
    hostile(Z).

