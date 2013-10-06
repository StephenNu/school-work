g w x y z = x, if y = z
g w x y (t:ts) = t, otherwise
h [] n = [n]
h xs 0 = [2]
h (x:xs) n = h xs (n - 1) ++ h [x] (n - 1)
