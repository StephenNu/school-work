p1 = (1, 'b')
p2 = [p1]
p3 = map(#)
p4 = foldr (\/) False
p5 x = True, if x = 0
     = False, otherwise
p6 [] = 0
p6 (x:xs) = first(x) + p6 xs
first (x,y) = x
p7 = p4 . map (p5) . p3
second (x,y) = y
p8 x = [y | (y,z) <- x; z > 0]
