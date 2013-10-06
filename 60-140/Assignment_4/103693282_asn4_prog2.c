#include <stdio.h>

	// Function prototypes:
	void CircleArea();
	void WasherWeight();
	void PrintWeight();

	// Define global variables:
	// Input data are:
	double washer1_inner_diameter = 0.0, washer1_outer_diameter = 0.0, washer2_inner_diameter = 0.0, washer2_outer_diameter = 0.0;
	double washer3_inner_diameter = 0.0, washer3_outer_diameter = 0.0, washer4_inner_diameter = 0.0, washer4_outer_diameter = 0.0;
	
	// Shared input and output data are:
	double washer1_quantity = 0.0, washer1_thickness = 0.0, washer1_density = 0.0, washer2_quantity = 0.0, washer2_thickness = 0.0, washer2_density = 0.0; 
	double washer3_quantity = 0.0, washer3_thickness = 0.0, washer3_density = 0.0, washer4_quantity = 0.0, washer4_thickness = 0.0, washer4_density = 0.0;

	// Transient variables:
	double washer1_area = 0.0, washer2_area = 0.0, washer3_area = 0.0, washer4_area = 0.0;

	// Output data are:
	double washer1_weight = 0.0, washer2_weight = 0.0, washer3_weight = 0.0, washer4_weight = 0.0, total_weight = 0.0;

	// Constant data are:
	double PI = 3.142;

int main(void) 
{
	printf("Please input the quantity of washer type one.\n");
	scanf("%lf", &washer1_quantity);
	printf("Please input the thickness of washer type one.\n");
	scanf("%lf", &washer1_thickness);
	printf("Please input the density of washer type one.\n");
	scanf("%lf", &washer1_density);
	printf("Please input the inner diameter of washer type one.\n");
	scanf("%lf", &washer1_inner_diameter);
	printf("Please input the outer diameter of washer type one.\n");
	scanf("%lf", &washer1_outer_diameter);
	
	printf("Please input the quantity of washer type two.\n");
	scanf("%lf", &washer2_quantity);
	printf("Please input the thickness of washer type two.\n");
	scanf("%lf", &washer2_thickness);
	printf("Please input the density of washer type two.\n");
	scanf("%lf", &washer2_density);
	printf("Please input the inner diameter of washer type two.\n");
	scanf("%lf", &washer2_inner_diameter);
	printf("Please input the outer diameter of washer type two.\n");
	scanf("%lf", &washer2_outer_diameter);
	
	printf("Please input the quantity of washer type three.\n");
	scanf("%lf", &washer3_quantity);
	printf("Please input the thickness of washer type three.\n");
	scanf("%lf", &washer3_thickness);
	printf("Please input the density of washer type three.\n");
	scanf("%lf", &washer3_density);
	printf("Please input the inner diameter of washer type three.\n");
	scanf("%lf", &washer3_inner_diameter);
	printf("Please input the outer diameter of washer type three.\n");
	scanf("%lf", &washer3_outer_diameter);
	
	printf("Please input the quantity of washer type four.\n");
	scanf("%lf", &washer4_quantity);
	printf("Please input the thickness of washer type four.\n");
	scanf("%lf", &washer4_thickness);
	printf("Please input the density of washer type four.\n");
	scanf("%lf", &washer4_density);
	printf("Please input the inner diameter of washer type four.\n");
	scanf("%lf", &washer4_inner_diameter);
	printf("Please input the outer diameter of washer type four.\n");
	scanf("%lf", &washer4_outer_diameter);
	
	WasherWeight();
	
	PrintWeight();

	return 0;
}

void CircleArea()
{
	washer1_area = (PI * ((washer1_outer_diameter / 2) * (washer1_outer_diameter / 2))) - (PI * ((washer1_inner_diameter / 2) * (washer1_inner_diameter / 2)));
	washer2_area = (PI * ((washer2_outer_diameter / 2) * (washer2_outer_diameter / 2))) - (PI * ((washer2_inner_diameter / 2) * (washer2_inner_diameter / 2)));
	washer3_area = (PI * ((washer3_outer_diameter / 2) * (washer3_outer_diameter / 2))) - (PI * ((washer3_inner_diameter / 2) * (washer3_inner_diameter / 2)));
	washer4_area = (PI * ((washer4_outer_diameter / 2) * (washer4_outer_diameter / 2))) - (PI * ((washer4_inner_diameter / 2) * (washer4_inner_diameter / 2)));
}	

void WasherWeight()
{
	CircleArea();
	washer1_weight = ((washer1_area * washer1_thickness) * washer1_density) * washer1_quantity;
	washer2_weight = ((washer2_area * washer2_thickness) * washer2_density) * washer2_quantity;
	washer3_weight = ((washer3_area * washer3_thickness) * washer3_density) * washer3_quantity;
	washer4_weight = ((washer4_area * washer4_thickness) * washer4_density) * washer4_quantity;
	total_weight = washer1_weight + washer2_weight + washer3_weight + washer4_weight;
}

void PrintWeight()
{
	printf("\nWasher Type	Qty	Thickness	Density	Weight\n\n");
	printf("A          	%3.1lf	%0.1lf		%0.1lf	%0.1lf.\n", washer1_quantity, washer1_thickness, washer1_density, washer1_weight);
	printf("B          	%0.1lf	%0.1lf		%0.1lf	%0.1lf.\n", washer2_quantity, washer2_thickness, washer2_density, washer2_weight);
	printf("C          	%0.1lf	%0.1lf		%0.1lf	%0.1lf.\n", washer3_quantity, washer3_thickness, washer3_density, washer3_weight);
	printf("D          	%0.1lf	%0.1lf		%0.1lf	%0.1lf.\n", washer4_quantity, washer4_thickness, washer4_density, washer4_weight);
	printf("Total Weight **********************************	%0.1lf\n", total_weight);
}



