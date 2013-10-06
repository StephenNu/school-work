|| Group ASSIGNMENT #5
|| Go to the Java lab
|| You will be asked to demo your individual assignment 
|| #4 PART I at this lab.
|| At the Java lab, each student will show the GA/TA
|| their web page (using a web browser on a terminal in 
|| the lab), and will also hand in a page with one or two
|| sentences explaining how far the got with PART 2 of 
|| assignment #4.
||
|| IN ADDITION:  
|| You must work as a group on this assignment.
|| Either use a single laptop, or go to the Java lab 
|| and use a single Sunray Terminal
||
|| Download this file from the course website
||
|| under group assignments -> group_assig_5.txt
|| chnge the extension from .txt to .m
|| and compile it using Miranda. 
|| Read Part I, then try using the programs
|| from PART II of this file (see below)
|| then write relational algebra expressions for PART III
||
|| PART I
|| The following is the data for this assignment

metal     = ["bolt", "nut", "washer", "bearing", "cog", "newnut"]
plastic   = ["gasket", "clip", "strap", "spacer", "newclip"]
part          = metal ++ plastic
compound_part = ["c1", "c2", "c3", "c4", "c5", "c6", "c7"]
component     = part ++ compound_part

component_of  
    = [("bolt","c1"), ("nut", "c1"), ("washer", "c1"),
       ("bearing", "c2"), ("cog", "c2"), ("gasket", "c2"),
       ("clip", "c3"), ("strap", "c3"), ("spacer", "c3"),
       ("c1", "c4"), ("c3", "c4"), ("c4", "c5"), 
       ("c2", "c5"), ("c5", "c6")]
	   

|| The following are example programs for relational algebra 
|| You will need to add some operators similar to these
	    
project_first_of_2 r = mkset[(x) | (x, y) <- r]

project_second_of_2 r = mkset[(y) | (x, y) <- r]

project_first_and_third_of_3 r = mkset[(x,z) | (x,y,z) <- r]

project_second_and_third_of_3 r = mkset[(y, z) | (x, y, z) <- r]
join_first_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; x = a]

join_first_of_1_with_first_of_2 r s
      = [(x, y) | (x) <- r; (a , y) <- s; x = a]

join_second_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; y = a]


select_second_of_2 r key = [(x,y) | (x, y) <- r; y = key]

select_first_of_2 r key = [(x,y) | (x, y) <- r; x = key]

remove_reflexives r = [(a, b) | (a, b) <- r; a ~= b]

swap = map switch
       where switch (a, b) = (b, a)

union s t = s ++ (t --s)

intersection s t = s -- (s -- t)

make_transitive [] = []
make_transitive ((x, y):ps)
  = new_direct_paths ++
    [(a,c) | (a,b) <- mtps; (d,c) <- new_direct_paths; b = d] ++ mtps
    where
    mtps = make_transitive ps
    new_direct_paths = (x, y):[(x, b) | (n, b) <- mtps; n = y]

|| PART II
|| Now consider the following new relations that can be defined
|| in terms of the relations above. Try these relations out 
|| by typing their name at the Miranda prompt

sub_component_of  
   = project_first_and_third_of_3
      (join_second_of_2_with_first_of_2 component_of component_of)      

all_parts_of = make_transitive component_of

uses_component = swap component_of

used_together_with 
   = remove_reflexives 
      (project_second_and_third_of_3
        (join_first_of_2_with_first_of_2 uses_component 
	                                       uses_component))

sub_component_of_c5 
  = project_first_of_2
      (select_second_of_2 sub_component_of "c5")

 
all_parts_of_c5 = [x | (x,y) <- (make_transitive component_of); y = "c5"] -- compound_part  
all_parts_of_c5_not_c4 = all_parts_of_c5 -- all_parts_of_c4
all_parts_of_c4 = [x | (x,y) <- (make_transitive component_of); y = "c4"] -- compound_part
plastic_parts_of_c5 = intersection all_parts_of_c5 plastic
all_compound_parts_bolts = [y | (x,y) <-( make_transitive component_of); x = "bolt"]
all_parts_ofa k = [x | (x,y) <- (make_transitive component_of); y = k]
all_parts_used_bolts =intersection( mkset . foldr(++) [] . map(all_parts_ofa) all_compound_parts_bolts) part
|| PART III
||
|| Now write relational algebra expressions 
|| for the following relations
|| all_parts_of_c5
|| all_parts_used_in_c5_but_not_in_c4
|| plastic_parts_of_c5
|| all_compound_parts_which_use_a_bolt
|| parts_which_are_used_together_with_a_bolt
|| Write answers under here and then submit this page






