// Import the required libraries.
#include <stdio.h>

// Define the function prototype.
void Sales_Price(double, double, double*, double*, double*, double*, double*);

// A program to figure out the sale prices for two items decreasing the price each day by 10%, but never going under the wholesale price.
int main(void)
{
	// Set up the required variables.
	double retailPrice1 = 0.0, wholeSale1 = 0.0, monday1 = 0.0, tuesday1 = 0.0, wednesday1 = 0.0, thursday1 = 0.0, friday1 = 0.0;
	double retailPrice2 = 0.0, wholeSale2 = 0.0, monday2 = 0.0, tuesday2 = 0.0, wednesday2 = 0.0, thursday2 = 0.0, friday2 = 0.0;

	// Prompt for the first item's retail and wholesale price, and read them into the correct variables.
	printf("Please input the retail price and then the wholesale price of the item seperated by a space\n");
	scanf("%lf %lf", &retailPrice1, &wholeSale1);
	// Prompt for the second item's retail and wholesale price, and read them into the correct variables.
	printf("Please input the retail price and then the wholesale price of the item seperated by a space\n");
	scanf("%lf %lf", &retailPrice2, &wholeSale2);
	
	// Call the function Sales_Price for each item to calculate each days sale price.
	Sales_Price(wholeSale1, retailPrice1, &monday1, &tuesday1, &wednesday1, &thursday1, &friday1);
	Sales_Price(wholeSale2, retailPrice2, &monday2, &tuesday2, &wednesday2, &thursday2, &friday2);

	// Print the results.
	printf("Original Retail Price Wholesale Price Monday's Tuesday's Wed's Thurs' Fri's\n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("%0.2lf	%0.2lf	%0.2lf	%0.2lf	%0.2lf	%0.2lf	%0.2lf\n", retailPrice1, wholeSale1, monday1, tuesday1, wednesday1, thursday1, friday1);
	printf("%0.2lf	%0.2lf	%0.2lf	%0.2lf	%0.2lf	%0.2lf	%0.2lf\n", retailPrice2, wholeSale2, monday2, tuesday2, wednesday2, thursday2, friday2);

	// End the program.
	return 0;
}

// The function Sales_Price is used to take a wholesale price and the original retail price, and go through each day and see if the retail can be decreased by 10% without going under the whole price.
void Sales_Price(double wholeSale, double originPrice, double* Monday, double* Tuesday, double* Wednesday, double* Thursday, double* Friday)
{
	// Set up the counter variable to start at 0.
	int day = 0;
	
	/* While the day is less then 5 increase day by one each loop, and decrease the originPrice by 10%,
	then check which day its on, and if the new originPrice is greater then the wholesale price 
	set the result variable for that day to the new originPrice otherwise set it to the wholesale price, 
	and go to the next loop cicle. */
	while (day <= 5)
	{
		day++;
		originPrice *= 0.9;
		switch (day)
		{
			case 1:
			{
				if (originPrice > wholeSale)
				{
					*Monday = originPrice;
					break;
				}
				else
				{
					// Otherwise set up the day variable to the default value of it's wholesale price.
					*Monday = wholeSale;
					break;
				}
			}
			case 2:
			{
				if (originPrice > wholeSale)
				{
					*Tuesday = originPrice;					
					break;
				}
				else
				{
					// Otherwise set up the day variable to the default value of it's wholesale price.
					*Tuesday = wholeSale;
					break;
				}
			}
			case 3:
			{
				if (originPrice > wholeSale)
				{
					*Wednesday = originPrice;					
					break;
				}
				else
				{
					// Otherwise set up the day variable to the default value of it's wholesale price.
					*Wednesday = wholeSale;
					break;
				}
			}
			case 4:
			{
				if (originPrice > wholeSale)
				{
					*Thursday = originPrice;
					break;
				}
				else
				{
					// Otherwise set up the day variable to the default value of it's wholesale price.
					*Thursday = wholeSale;
					break;
				}
			}
			case 5:
			{
				if (originPrice > wholeSale)
				{
					*Friday = originPrice;
					break;
				}
				else
				{
					// Otherwise set up the day variable to the default value of it's wholesale price.
					*Friday = wholeSale;
					break;
				}
			}
		}
	}
	// End the Sales_Price function.
}



