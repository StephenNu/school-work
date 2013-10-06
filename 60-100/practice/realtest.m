p3 = map(#)
p4 = foldr (op) 0
op a b = a, if a >= b
       = b, otherwise
p9 x = "yes", if (p4 . p3) x > 4
     = "no", otherwise
first (x,y) = x
second (x,y) = y
p1 = ("stephen", 7)
p2 = (first p1)!(second(p1) - 1)

