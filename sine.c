/******************************************************************************

* Timer value generation program for sine wave Version 0.0.1
*
* Description: This program will calculate the timer value for PWM sine wave which could be 
*  			generated using a microcontroller. The inputs are the carrier frequency, 
*				sinewave frequency and minimum and maximum value of counters. It outputs 
*				the sine table value in a file which could be readly copied to an array.
*
*
* Author: Bharadwaaj RA
* Email: bhaaradwaaj@gmail.com
* Date: 10-JAN-12
*
* Note: This software is given under GPL with no warrenty in any form. Feel free report the bug to the author.
******************************************************************************/

 

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
int i =0;
int main()
{
	double step_val = 0.0;
	double sine_tab = 0.0;
	double counter = 0.0;
	long carrier_freq =0; 
	int sinewave_freq;
	int max_timer = 0;
	int sine_counters =0;
	FILE *fp;
	int start_count = 0;

	
	fp = fopen("Sine_table.txt","w");
	if(fp == NULL)
	{
		fclose(fp);
		printf("Unable to open file");
		return 0;
	}
	
	fputc('{',fp);


	printf("Enter the carrier freqency:");
	scanf("%ld",&carrier_freq);
	printf("Enter the sinewave frequency:");
	scanf("%d",&sine_wave_freq)
	
	step_val = 360/(carrier_freq/(sine_wave_freq*2));

	printf("Enter the Min_value_counter:");
	scanf("%d",&start_count);
	printf("Enter the Max_value_counter:");
	scanf("%d",&max_timer);
	for(counter = 0; counter<360;counter+=step_val)
	{
		i++;
		sine_tab = sin(counter*PI/180);
		sine_counters = ((start_count+max_timer)/2) + round(((max_timer-start_count)/2) * sine_tab);
		printf("The percentage = %lf, counterval = %d\n",sine_tab*100, sine_counters);
		if(i%10)
		fprintf(fp,"%d," ,sine_counters);
		else
		fprintf(fp,"\n%d,",sine_counters);
	}
	fputc('}',fp);
	fprintf(fp,"\n The total count is:%d\n",i);
	fclose(fp);
	return 0;
}
