/* Converts a Fahrenheit temperature to Celsius*/

// headers

#include <stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f/9.0f)

int main (void) {

    //declarations
    float fahrenheit, celsius;

    // function calls
    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);
  
    // assignments
    celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
    printf("Celsius equivalent: %.1f\n", celsius);
    
    // function terminates, and returns a value
    return 0;
}

