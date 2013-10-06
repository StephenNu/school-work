g ys 0 m = 2
g [] n m = 3
g (x:xs) n m = g m (n-3) (x:xs) + g [x] (n-3) m
h ys 0 = 2
h [] n = 3
h (x:xs) n = h (x:xs) (n-3) + h [x] (n-3)
p5 x y = False, if x < 0
       = True, if x = 0
       = p5 (x-y) y, otherwise

p = [('w', 5), ('y', 6), ('z', 5)]
q = [('y', 3), ('a',4)]
select_second_of_3 r key = [(x,y,z) | (x,y,z) <- r; y = key]
project_third_of_3 r = mkset[(z) | (x,y,z) <- r]
join_first_of_2_with_first_of_2 r s = [(x,y,z) | (x,y) <- r; (a,z) <- s; x = a]
select_second_of_2 r key = [(x,y) | (x,y) <- r; y = key]
p6 [] = 0
p6 (x:xs) = x, if p6 xs < x
          = p6 xs, otherwise


||L = ({terminals = {1,0
||		meaning of 1=1
||		meaning of 0=0},
||	start symbol = binnum,
||	non-terminals = {binnum, digit},
||	production rules = {binnum ::= digit
||				value of binnum = value of digit
||			| binnum' digit
||				value of binnum = 2* value of binnum' + value of digit
||			digit ::= 1
||				value of digit = value of 1
||				| 0
||				value of digit = value of 0
