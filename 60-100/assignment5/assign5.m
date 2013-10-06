|| Your name is                 : Stephen Nusko
|| your 60-100 section number is: 01 lab 53
|| functions required
ancestor_of = make_transitive parent_of
brother_or_sister_of = remove_reflexives( project_second_and_third_of_3 (join_first_of_2_with_first_of_2 parent_of parent_of))
sister_of = foldr(++) [] (map (select_first_of_2 brother_or_sister_of) female)
aunty_or_uncle_of = project_first_and_third_of_3(join_second_of_2_with_first_of_2 brother_or_sister_of parent_of)
aunty_or_uncle_of_mary = aunty_or_uncle_of_pick "mary"
aunty_or_uncle_of_pick relation = select_second_of_2 aunty_or_uncle_of relation
neice_of = foldr(++) [] (map(select_first_of_2 (swap aunty_or_uncle_of)) female)
cousin_of = project_second_and_third_of_3(join_first_of_2_with_first_of_2 aunty_or_uncle_of parent_of)
daughter_in_law_of = project_first_and_third_of_3(join_second_of_2_with_first_of_2 married_to child_of)
grandparent_of_bill = select_second_of_2 grandparent "bill"

||additional relations defined
child_of = swap parent_of
swap = map(switch)
switch (a,b) = (b,a)
project_second_and_third_of_3 r = mkset[(y,z) | (x,y,z) <- r]
join_first_of_2_with_first_of_2 r s = [(x, y, z) | (x, y) <- r; (a, z) <- s; x = a]
select_second_of_2 r key = [(x,y) | (x,y) <- r; y = key]

|| Rest is pregiven program downloaded no need to check only thing changed is I added "cathy" and "james".
male   = ["doug",   "paul", "bill", "simon", "james"]
female = ["angela", "sue",  "mary", "beth", "anne", "cathy"] || I added cathy it was missing
parent_of = [("doug", "paul") , ("doug", "sue") ,   ("paul", "cathy"),
             ("paul", "james"), ("sue", "simon") ,  ("sue", "mary"),
             ("mary", "bill") , ("bill", "angela"), ("angela", "beth"),
             ("anne", "cathy")] 
married_to =  [("anne", "paul"), ("paul", "anne")]
project_first_of_2 r           = mkset[(x) | (x, y) <- r]
project_second_of_2 r          = mkset[(y) | (x, y) <- r]
project_first_and_third_of_3 r = mkset[(x,z) | (x,y,z) <- r]
select_first_of_2 r key        = [(x,y) | (x, y) <- r; x = key]
join_second_of_2_with_first_of_2 r s
                 = [(x, y, z) | (x, y) <- r; (a , z) <- s; y = a]
union        s t = s ++ (t --s)
intersection s t = s -- (s -- t)
make_transitive [] = []
make_transitive ((x, y):ps)
  = new_direct_paths ++
    [(a,c) | (a,b) <- mtps; (d,c) <- new_direct_paths; b = d] ++ mtps
    where mtps = make_transitive ps
          new_direct_paths = (x, y):[(x, b) | (n, b) <- mtps; n = y]
grandparent = project_first_and_third_of_3 (join_second_of_2_with_first_of_2 parent_of parent_of)
remove_reflexives r = [(x, y) | (x, y) <- r; x ~= y]

