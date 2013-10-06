p1 = ([1,2], "abc")
p2 = [p1,p1]
list x = [x] 
p3 = map(list)
first (x, y) = x
second (x, y) = y 
p7 [] = []
p7 (x:xs) = first(x) * second (x) : p7 xs
p6 x y = x, if x!0 > y!0
       = y, otherwise 
sum1 x = foldr (+) 0 x
p8 = sum1  . map(sum1 )  .  map(p7)

