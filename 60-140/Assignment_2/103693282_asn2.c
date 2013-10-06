#include <stdio.h>

int main(void)
{
	// Input data are:
	float length_yardft = 0.0, width_yardft = 0.0, length_houseft = 0.0, width_houseft = 0.0;
		 
	// Output data are:
	int hours = 0, minutes = 0, seconds = 0;
	float yard_squareft = 0.0, yard_square_meter = 0.0, house_squareft = 0.0, house_square_meter = 0.0, grass_yard_squareft = 0.0, grass_yard_square_meter = 0.0, yard_perimeterft = 0.0, yard_perimeter_meter = 0.0, house_perimeterft = 0.0, house_perimeter_meter = 0.0;

	// Transitent data are = 0.0,
	float length_yard_meter = 0.0, width_yard_meter = 0.0, length_house_meter = 0.0, width_house_meter = 0.0;
	int full_time_seconds = 0;

	// Constant data,
	float mow_speed = 2.0, meter_convert = 0.3048;
 
	// Prompt for required input.
	printf("What is the length of the rectangular yard in feet?\n");
	scanf("%f", &length_yardft);
	printf("What is the width of the rectangular yard in feet?\n");
	scanf("%f", &width_yardft);
	printf("Please scan in the length of the rectangular house in feet:\n");
	scanf("%f", &length_houseft);
	printf("Please scan in the width of the rectangular house in feet:\n");
	scanf("%f", &width_houseft);

	// Run equations on the input data.
	yard_squareft = length_yardft * width_yardft;
	house_squareft = length_houseft * width_houseft;
	length_yard_meter = length_yardft * meter_convert;
	width_yard_meter = width_yardft * meter_convert;
	yard_square_meter = width_yard_meter * length_yard_meter;
	length_house_meter = length_houseft * meter_convert;
	width_house_meter = width_houseft * meter_convert;
	house_square_meter = width_house_meter * length_house_meter;
	grass_yard_squareft = yard_squareft - house_squareft;
	grass_yard_square_meter = yard_square_meter - house_square_meter;
	yard_perimeterft = 2 * (length_yardft + width_yardft);
	yard_perimeter_meter = 2 * (length_yard_meter + width_yard_meter);
	house_perimeterft = 2 * (length_houseft + width_houseft);
	house_perimeter_meter = 2 * (length_house_meter + width_house_meter);
	full_time_seconds = grass_yard_squareft / mow_speed;
	hours = full_time_seconds / (60 * 60);
	minutes = (full_time_seconds % (60 * 60)) / 60;
	seconds = (full_time_seconds % (60 * 60)) % 60;
	
	// Print out results.
	printf("\nThe time required to cut the grass in the yard is: %d hours %d minutes %d seconds\n", hours, minutes, seconds);
	printf("The area of the yard in square feet is: %0.2f sq. ft.\n", yard_squareft);
	printf("The area of the yard in square meters us: %0.2f sq. meter.\n", yard_square_meter);
	printf("The area of the house in square feet is: %0.2f sq. ft.\n", house_squareft);
	printf("The area of the house in square meters us: %0.2f sq. meter.\n", house_square_meter);
	printf("The area of the grass area in square feet is: %0.2f sq. ft.\n", grass_yard_squareft);
	printf("The area of the grass area in square meters us: %0.2f sq. meter.\n", grass_yard_square_meter);
	
	printf("\nThe perimeter of the yard in feet is: %0.2f ft.\n", yard_perimeterft);
	printf("The perimeter of the yard in meter is: %0.2f meter.\n", yard_perimeter_meter);
	printf("The perimeter of the house in feet is: %0.2f ft.\n", house_perimeterft);
	printf("The perimeter of the house in meter is: %0.2f meter.\n", house_perimeter_meter);
	
	printf("\nThank you for using our property evaluation software !!.\n");
	printf("Have a great day.\n");
	
	// Finish program.
	return 0;
}


