p1 = [[1,2],[2,3]]
p2 = p1!1
p3 x = map(^3) x
p4 = foldr (+) 0
p5 x y = x, if x > 0
       = y, otherwise
p6 x y = x, if x!0 > y!0
       = y, otherwise
p7 x = "True", if x = 0
     = "False", if x < 0
     = p7 (x-3), otherwise
p8 [] y = "False"
p8 (x:xs) y = "True", if x = y
            = p8 xs y, otherwise 
p9 = p4 . p3
p10 x y = [(n,c) | n <- x; c <- y; n > c]
