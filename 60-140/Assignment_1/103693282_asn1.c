#include <stdio.h>
/*
	Name: Stephen Nusko
	ID#: 103693282
	Program: Cost and weight calculater for three trucks of goods containing cases of water bottles, T-shirts, cereal, and packs of a dozen soaps.
*/
int main(void) 
{
	// Real number input variables:
	float truck1_water_amount, truck1_cereal_amount, truck1_Tshirt_amount, truck1_soap_amount, truck2_water_amount, truck2_cereal_amount, truck2_Tshirt_amount, truck2_soap_amount, truck3_water_amount, truck3_cereal_amount, truck3_Tshirt_amount, truck3_soap_amount;
	float truck1_water_cost, truck1_cereal_cost, truck1_Tshirt_cost, truck1_soap_cost, truck2_water_cost, truck2_cereal_cost, truck2_Tshirt_cost, truck2_soap_cost, truck3_water_cost, truck3_cereal_cost, truck3_Tshirt_cost, truck3_soap_cost;
	// Real number output variables:
	float truck1_cost, truck2_cost = 0.0, truck3_cost = 0.0, total_cost = 0.0, truck1_weight = 0.0, truck2_weight = 0.0, truck3_weight = 0.0, total_weight = 0.0;
	// Real number constants of the weight of the items.
	const float water_weight = 150.0, cereal_weight = 5.0, Tshirt_weight = 4.0, soap_weight = 3.0, HST = 1.13; 


	// Step one: Prompt for number of bottled water cases aboard truck 1.
	printf("\nPlease enter the number of bottled water cases aboard truck 1.\n");
	// Step two: Read and store input into truck1_water_amount.
	scanf("%f", &truck1_water_amount);
	// Step three: Prompt for the cost per case of water without HST.
	printf("Please enter the cost per case of water, without including HST.\n");
	// Step four: Read and store the input into truck1_water_cost.
	scanf("%f", &truck1_water_cost);
	// Step five: truck1_cost = (truck1_water_amount*truck1_water_cost) * HST.
	truck1_cost = (truck1_water_amount * truck1_water_cost) * HST;
	// Step six: truck1_weight = (truck1_water_amount*water_weight).
	truck1_weight = (truck1_water_amount * water_weight);
	// Step seven: prompt for the number of cereal boxes aboard truck 1.
	printf("Please enter the number of cereal boxes aboard truck 1.\n");
	// Step eight: read and store input into truck1_cereal_amount.
	scanf("%f", &truck1_cereal_amount);
	// Step nine: prompt for cost per box of cereal without HST.
	printf("Please enter the cost per box of cereal, without including HST.\n");
	// Step ten: read and store the input into truck1_cereal_cost.
	scanf("%f", &truck1_cereal_cost);
	// Step eleven: truck1_cost = truck1_cost + ((truck1_cereal_amount*truck1_cereal_cost) * HST).
	truck1_cost = truck1_cost + ((truck1_cereal_amount * truck1_cereal_cost) * HST);
	// Step twelve: truck1_weight = truck1_weight + (truck1_cereal_amount*cereal_weight).
	truck1_weight = truck1_weight + (truck1_cereal_amount * cereal_weight);
	// Step thirteen: prompt for number of T-shirts aboard truck 1.
	printf("Please enter the number of T-shirts aboard truck 1.\n");
	// Step fourteen: read and store input into truck1_Tshirt_amount.
	scanf("%f", &truck1_Tshirt_amount);
	// Step fifteen: prompt for the cost per shirt without HST.
	printf("Please enter the cost per T-shirt, without including HST.\n");
	// Step sixteen: read and store the input into truck1_Tshirt_cost.
	scanf("%f", &truck1_Tshirt_cost);
	// Step seventeen: truck1_cost = truck1_cost +((truck1_Tshirt_amount * truck1_Tshirt_cost) * HST).
	truck1_cost = truck1_cost + ((truck1_Tshirt_amount * truck1_Tshirt_cost) * HST);
	// Step eighteen: truck1_weight = truck1_weight + (truck1_water_amount * Tshirt_weight).
	truck1_weight = truck1_weight + (truck1_Tshirt_amount * Tshirt_weight);
	// Step nineteen: prompt for number of dozen units of soap on truck 1.
	printf("Please enter how many dozen of soap is aboard truck 1.\n");
	// Step twenty: read and store input into truck1_soap_amount.
	scanf("%f", &truck1_soap_amount);
	// Step twenty-one: prompt for the cost per dozen soaps without HST.
	printf("Please enter the cost per dozen soaps, without including HST.\n");
	// Step twenty-two: read and store input into truck1_soap_cost.
	scanf("%f", &truck1_soap_cost);
	// Step twenty-three: truck1_cost = truck1_cost + ((truck1_soap_amount * truck1_soap_cost) * HST).
	truck1_cost = truck1_cost + ((truck1_soap_amount * truck1_soap_cost) * HST);
	// Step twenty-four: truck1_weight = truck1_weight + (truck1_soap_amount * soap_weight).
	truck1_weight = truck1_weight + (truck1_soap_amount * soap_weight);
	// Step twenty-five: Prompt for number of bottled water cases aboard truck 2.
	printf("Please enter the number of bottled water cases aboard truck 2.\n");
	// Step twenty-six: Read and store input into truck2_water_amount.
	scanf("%f", &truck2_water_amount);
	// Step twenty-seven: Prompt for the cost per case of water without HST.
	printf("Please enter the cost per case of water, without including HST.\n");
	// Step twenty-eight: Read and store the input into truck2_water_cost.
	scanf("%f", &truck2_water_cost);
	// Step twenty-nine: truck2_cost = (truck2_water_amount*truck2_water_cost) * HST.
	truck2_cost = (truck2_water_amount * truck2_water_cost) * HST;
	// Step thirty: truck2_weight = (truck2_water_amount*water_weight).
	truck2_weight = (truck2_water_amount * water_weight);
	// Step thirty-one: prompt for the number of cereal boxes aboard truck 2.
	printf("Please enter the number of cereal boxes aboard truck 2.\n");
	// Step thirty-two: read and store input into truck2_cereal_amount.
	scanf("%f", &truck2_cereal_amount);
	// Step thirty-three: prompt for cost per box of cereal without HST.
	printf("Please enter the cost per box of cereal, without including HST.\n");
	// Step thirty-four: read and store the input into truck2_cereal_cost.
	scanf("%f", &truck2_cereal_cost);
	// Step thirty-five: truck2_cost = truck2_cost + ((truck2_cereal_amount*truck2_cereal_cost) * HST).
	truck2_cost = truck2_cost + ((truck2_cereal_amount * truck2_cereal_cost) * HST);
	// Step thirty-six: truck2_weight = truck2_weight + (truck2_cereal_amount*cereal_weight).
	truck2_weight = truck2_weight + (truck2_cereal_amount * cereal_weight);
	// Step thirty-seven: prompt for number of T-shirts aboard truck 2.
	printf("Please enter the number of T-shirts aboard truck 2.\n");
	// Step thirty-eight: read and store input into truck2_Tshirt_amount.
	scanf("%f", &truck2_Tshirt_amount);
	// Step thirty-nine: prompt for the cost per shirt without HST.
	printf("Please enter the cost per T-shirt, without including HST.\n");
	// Step fourty: read and store the input into truck2_Tshirt_cost.
	scanf("%f", &truck2_Tshirt_cost);
	// Step fourty-one: truck2_cost = truck2_cost + ((truck2_Tshirt_amount * truck2_Tshirt_cost) * HST).
	truck2_cost = truck2_cost + ((truck2_Tshirt_amount * truck2_Tshirt_cost) * HST);
	// Step fourty-two: truck2_weight = truck2_weight + (truck2_Tshirt_amount * Tshirt_weight).
	truck2_weight = truck2_weight + (truck2_Tshirt_amount * Tshirt_weight);
	// Step fourty-three: prompt for number of dozen units of soap on truck 2.
	printf("Please enter how many dozen of soap is aboard truck 2.\n");
	// Step fourty-four: read and store input into truck2_soap_amount.
	scanf("%f", &truck2_soap_amount);
	// Step fourty-five: prompt for the cost per dozen soaps without HST.
	printf("Please enter the cost per dozen soaps, without including HST.\n");
	// Step fourty-six: read and store input into truck2_soap_cost.
	scanf("%f", &truck2_soap_cost);
	// Step fourty-seven: truck2_cost = truck2_cost + ((truck2_soap_amount * truck2_soap_cost) * HST).
	truck2_cost = truck2_cost + ((truck2_soap_amount * truck2_soap_cost) * HST);
	// Step fourty-eight: truck2_weight = truck2_weight + (truck2_soap_amount * soap_weight).
	truck2_weight = truck2_weight + (truck2_soap_amount * soap_weight);
	// Step fourty-nine: Prompt for number of bottled water cases aboard truck 3.
	printf("Please enter the number of bottled water cases aboard truck 3.\n");
	// Step fifty: Read and store input into truck3_water_amount.
	scanf("%f", &truck3_water_amount);
	// Step fifty-one: Prompt for the cost per case of water without HST.
	printf("Please enter the cost per case of water, without including HST.\n");
	// Step fifty-two: Read and store the input into truck3_water_cost.
	scanf("%f", &truck3_water_cost);
	// Step fifty-three: truck3_cost = (truck3_water_amount*truck3_water_cost) * HST.
	truck3_cost = (truck3_water_amount * truck3_water_cost) * HST;
	// Step fifty-four: truck3_weight = (truck3_water_amount*water_weight).
	truck3_weight = (truck3_water_amount * water_weight);
	// Step fifty-five: prompt for the number of cereal boxes aboard truck 3.
	printf("Please enter the number of cereal boxes aboard truck 3.\n");
	// Step fifty-six: read and store input into truck3_cereal_amount.
	scanf("%f", &truck3_cereal_amount);
	// Step fifty-seven: prompt for cost per box of cereal without HST.
	printf("Please enter the cost per box of cereal, without including HST.\n");
	// Step fifty-eight: read and store the input into truck3_cereal_cost.
	scanf("%f", &truck3_cereal_cost);
	// Step fifty-nine: truck3_cost = truck3_cost + ((truck3_cereal_amount*truck3_cereal_cost) * HST).
	truck3_cost = truck3_cost + ((truck3_cereal_amount * truck3_cereal_cost) * HST);
	// Step sixty: truck3_weight = truck3_weight + (truck3_cereal_amount*cereal_weight).
	truck3_weight = truck3_weight + (truck3_cereal_amount * cereal_weight);
	// Step sixty-one: prompt for number of T-shirts aboard truck 3.
	printf("Please enter the number of T-shirts aboard truck 3.\n");
	// Step sixty-two: read and store input into truck3_Tshirt_amount.
	scanf("%f", &truck3_Tshirt_amount);
	// Step sixty-three: prompt for the cost per shirt without HST.
	printf("Please enter the cost per T-shirt, without including HST.\n");
	// Step sixty-four: read and store the input into truck3_Tshirt_cost.
	scanf("%f", &truck3_Tshirt_cost);
	// Step sixty-five: truck3_cost = truck3_cost + ((truck3_Tshirt_amount * truck3_Tshirt_cost) * HST).
	truck3_cost = truck3_cost + ((truck3_Tshirt_amount * truck3_Tshirt_cost) * HST);
	// Step sixty-six: truck3_weight = truck3_weight + (truck3_Tshirt_amount * Tshirt_weight).
	truck3_weight = truck3_weight + (truck3_Tshirt_amount * Tshirt_weight);
	// Step sixty-seven: prompt for number of dozen units of soap on truck 3.
	printf("Please enter how many dozen of soap is aboard truck 3.\n");
	// Step sixty-eight: read and store input into truck3_soap_amount.
	scanf("%f", &truck3_soap_amount);
	// Step sixty-nine: prompt for the cost per dozen soaps without HST.
	printf("Please enter the cost per dozen soaps, without including HST.\n");
	// Step seventy: read and store input into truck3_soap_cost.
	scanf("%f", &truck3_soap_cost);
	// Step seventy-one: truck3_cost = truck3_cost + ((truck3_soap_amount * truck3_soap_cost) * HST).
	truck3_cost = truck3_cost + ((truck3_soap_amount * truck3_soap_cost) * HST);
	// Step seventy-two: truck3_weight = truck3_weight + (truck3_soap_amount * soap_weight).
	truck3_weight = truck3_weight + (truck3_soap_amount * soap_weight);
	// Step seventy-three: total_cost = truck3_cost + truck2_cost + truck3_cost.
	total_cost = truck3_cost + truck2_cost + truck3_cost;
	// Step seventy-four: total_weight = truck3_weight + truck2_weight + truck3_weight.
	total_weight = truck3_weight + truck2_weight + truck3_weight;

	printf("\n\nDetails of gooods sent by QE Charity Agency:\n");
	printf("********************************************\n");
	// Step seventy-five: print out total of goods in truck 1 with hst by using truck1_cost.
	printf("Total cost of goods in Truck 1 with HST is:	$%6.2f.\n", truck1_cost);
	// Step seventy-six: print out total of goods in truck 2 with HST by using truck2_cost.
	printf("Total cost of goods in Truck 2 with HST is:	$%6.2f.\n", truck2_cost);
	// Step seventy-seven: print out total of goods in truck 3 with HST by using truck3_cost.
	printf("Total cost of goods in Truck 3 with HST is:	$%6.2f.\n", truck3_cost);
	printf("********************************************\n");
	// Step seventy-eight: print out total cost of goods in all three trucks with HST by using total_cost.
	printf("Total cost of goods in the three trunks with HST is:	$%6.2f.\n", total_cost);
	printf("********************************************\n");
	// Step seventy-nine: print out total weight of truck 1 by using truck1_weight.
	printf("Total weight of goods in Trunk 1 is:	%6.1f lbs.\n", truck1_weight);
	// Step eighty: print out total weight of truck 2 by using truck2_weight.
	printf("Total weight of goods in Trunk 2 is:	%6.1f lbs.\n", truck2_weight);
	// Step eighty-one: print out total weight of truck 3 by using truck3_weight.
	printf("Total weight of goods in Trunk 3 is:	%6.1f lbs.\n", truck3_weight);
	printf("********************************************\n");
	// Step eighty-two: print out total weight of all the trucks by using total_weight.
	printf("Total weight of goods in the three trunks is:	%6.1f lbs.\n", total_weight);
	printf("********************************************\n");
	printf("End of processing!!!\n");
	// End
	return 0;
}

