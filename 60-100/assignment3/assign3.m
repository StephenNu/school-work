assign2011 = "assign2011 is p11 through p99"
p11 = 'a'
p22 = (p1, 5)
p33 =  map(tail)
tail (x:xs) = xs
p44 = foldr (+) 0 . map (^3)
p55 x y = "yes", if firstsum x y > 5
        = "no", otherwise
firstsum x y = first x + first y
p66 x y = x, if #x >= #y
        = y, otherwise
p77 [] = []
p77 (x:xs) = [first x * second x] ++ p77 xs
second (x,y) = y
sum1 = foldr (+) 0
p88 = sum1 . map(sum1) . map(p77)
p99 x = [y^2 | y <- x; y > 5; y < 20]
first (x,y) = x

assign2007 = "assign2007 is p1 through p10"
p1 = [7,8,9]
p2 = [6] ++ p1
p3 = map(greater)
greater x = True, if x > 4
          = False, otherwise
p4 = foldr (&) True
p5 x y = "yes", if sum2 x y > 5
       = "no", otherwise
sum2 x y = x + y
p6 x y = x, if x!0 >= y!0
       = y, otherwise
p7 [] = 0
p7 (x:xs) = x + p7 xs
p8 [] = 0
p8 (x:xs) = 1 + p8 xs
p9 = p4 . map(p4) . map (p3)
p10 x = [y*z | (y,z) <- x]

assign2010 = "assign2010 is p111 through p100"
p111 = ["hello", "goodbye"]
p222 = p111!1
p333 = map([3]++)
p444 = foldr (*) 1 . map (first)
p555 x y = "not greater than 2", if #x <= 2 \/ #y <= 2
     = "greater than 2", otherwise
p666 x y = x, if x!0 >= y!0
         = y, otherwise
p777 0 = [0]
p777 x = [x] ++  p777 (x-1)
p888 [] = []
p888 (x:xs) = [x + 3] ++ p888 xs
square n = n * n
p999 = square . sum1 . map(square)
p100 x = [y!0 | y <- x]
