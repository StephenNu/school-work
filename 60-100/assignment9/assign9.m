p906 [] = []
p906 (x:xs) = xs ++ xs ++ p906 xs
p7 [y] = [y]
p7 (x:xs) = p7 [x] ++ (x:xs) ++ p7 xs

