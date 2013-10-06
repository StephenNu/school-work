#include <stdio.h>

	// Function prototypes:
	double CircleArea(double);
	double WasherWeight(double, double, double,  double, double);
	void PrintWeight(double, double, double, double, double, double, double, double,
				double, double, double, double, double, double, double, double, double);
				
	// Constant data are:
	double PI = 3.142;

int main(void) 
{
	// Input only data:
	double washer1_inner_diameter = 0.0, washer1_outer_diameter = 0.0, washer2_inner_diameter = 0.0, washer2_outer_diameter = 0.0;
	double washer3_inner_diameter = 0.0, washer3_outer_diameter = 0.0, washer4_inner_diameter = 0.0, washer4_outer_diameter = 0.0;
	// And input and outdata are;
	double washer1_quantity = 0.0, washer1_thickness = 0.0, washer1_density = 0.0, washer2_quantity = 0.0, washer2_thickness = 0.0, washer2_density = 0.0;
	double washer3_quantity = 0.0, washer3_thickness = 0.0, washer3_density = 0.0, washer4_quantity = 0.0, washer4_thickness = 0.0, washer4_density = 0.0;
	 
	// Addition Output only data are:
	double washer1_weight = 0.0, washer2_weight = 0.0, washer3_weight = 0.0, washer4_weight = 0.0, total_weight = 0.0;

	printf("Please input the quantity of washer type A.\n");
	scanf("%lf", &washer1_quantity);
	printf("Please input the thickness of washer type A.\n");
	scanf("%lf", &washer1_thickness);
	printf("Please input the density of washer type A.\n");
	scanf("%lf", &washer1_density);
	printf("Please input the inner diameter of washer type A.\n");
	scanf("%lf", &washer1_inner_diameter);
	printf("Please input the outer diameter of washer type A.\n");
	scanf("%lf", &washer1_outer_diameter);
	
	printf("Please input the quantity of washer type B.\n");
	scanf("%lf", &washer2_quantity);
	printf("Please input the thickness of washer type B.\n");
	scanf("%lf", &washer2_thickness);
	printf("Please input the density of washer type B.\n");
	scanf("%lf", &washer2_density);
	printf("Please input the inner diameter of washer type B.\n");
	scanf("%lf", &washer2_inner_diameter);
	printf("Please input the outer diameter of washer type B.\n");
	scanf("%lf", &washer2_outer_diameter);
	
	printf("Please input the quantity of washer type C.\n");
	scanf("%lf", &washer3_quantity);
	printf("Please input the thickness of washer type C.\n");
	scanf("%lf", &washer3_thickness);
	printf("Please input the density of washer type C.\n");
	scanf("%lf", &washer3_density);
	printf("Please input the inner diameter of washer type C.\n");
	scanf("%lf", &washer3_inner_diameter);
	printf("Please input the outer diameter of washer type C.\n");
	scanf("%lf", &washer3_outer_diameter);
	
	printf("Please input the quantity of washer type D.\n");
	scanf("%lf", &washer4_quantity);
	printf("Please input the thickness of washer type D.\n");
	scanf("%lf", &washer4_thickness);
	printf("Please input the density of washer type D.\n");
	scanf("%lf", &washer4_density);
	printf("Please input the inner diameter of washer type D.\n");
	scanf("%lf", &washer4_inner_diameter);
	printf("Please input the outer diameter of washer type D.\n");
	scanf("%lf", &washer4_outer_diameter);
	
	washer1_weight = WasherWeight(washer1_quantity, washer1_thickness, washer1_density, washer1_outer_diameter, washer1_inner_diameter);
	washer2_weight = WasherWeight(washer2_quantity, washer2_thickness, washer2_density, washer2_outer_diameter, washer2_inner_diameter);
	washer3_weight = WasherWeight(washer3_quantity, washer3_thickness, washer3_density, washer3_outer_diameter, washer3_inner_diameter);
	washer4_weight = WasherWeight(washer4_quantity, washer4_thickness, washer4_density, washer4_outer_diameter, washer4_inner_diameter);
	
	total_weight = washer1_weight + washer2_weight + washer3_weight + washer4_weight;
	
	PrintWeight(washer1_quantity, washer1_thickness, washer1_density, washer1_weight, washer2_quantity, washer2_thickness, washer2_density, washer2_weight, 
				washer3_quantity, washer3_thickness, washer3_density, washer3_weight, washer4_quantity, washer4_thickness, washer4_density, washer4_weight,
				total_weight);
}

double CircleArea(double diameter)
{
	return (PI * ((diameter / 2) * (diameter / 2)));
}	

double WasherWeight(double quantity, double thickness, double density,  double outer_diameter, double inner_diameter)
{
	return (((CircleArea(outer_diameter) - CircleArea(inner_diameter)) * thickness) * density) * quantity;
}

void PrintWeight(double washer1_quantity, double washer1_thickness, double washer1_density, double washer1_weight, double washer2_quantity, double washer2_thickness, double washer2_density, double washer2_weight,
			double washer3_quantity, double washer3_thickness, double washer3_density, double washer3_weight, double washer4_quantity, double washer4_thickness, double washer4_density, double washer4_weight, 
			double total_weight)
{
	printf("\nWasher Type	Qty	Thickness	Density		Weight\n\n");
	printf("A          	%0.1lf	%0.1lf		%0.1lf		%0.1lf.\n", washer1_quantity, washer1_thickness, washer1_density, washer1_weight);
	printf("B          	%0.1lf	%0.1lf		%0.1lf		%0.1lf.\n", washer2_quantity, washer2_thickness, washer2_density, washer2_weight);
	printf("C          	%0.1lf	%0.1lf		%0.1lf		%0.1lf.\n", washer3_quantity, washer3_thickness, washer3_density, washer3_weight);
	printf("D          	%0.1lf	%0.1lf		%0.1lf		%0.1lf.\n", washer4_quantity, washer4_thickness, washer4_density, washer4_weight);
	printf("Total Weight **********************************		%0.1lf\n", total_weight);
}


