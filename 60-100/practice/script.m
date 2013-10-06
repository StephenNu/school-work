p1 = "20"
p2 = "Stephen Nusko"
p3 x = 2*x
p4 x y = x, if x > y
       = y, otherwise
p5 = map (*2) 
p6 x = x!0
p7 = foldr (*) 1
p8 1 = 1
p8 x = x * p8 (x-1)
p9 x y = x--(x--y)
rev x y = y++[x]
p10  = foldr (rev) [] 
p11 x = "true", if x mod 2 = 0 
      = "false", otherwise
first (x,y) = x
p12  = foldr (+) 0 . map(first)
