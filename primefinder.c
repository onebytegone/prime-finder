//
//  primefinder.c
//
//  Created by Ethan Smith on 12/7/11.
//  Copyright (c) 2011, 2015 Ethan Smith
//
//  Released under the MIT Licence. Please see LICENSE.md.
//


#include <stdio.h>
#include <string.h>

void printPrime(int num);

int main (void) {
    printf("\nUp to what number do you want to find prime numbers? ");
    fflush(stdout);
    int max;
    scanf("%i", &max);
    printf("Finding up to: %i\n", max);

    // Two is prime, so print
    printPrime(2);

    // Alloc memory for list of primes and prefill array with -1
    int primes[max/3];
    memset(primes, -1, sizeof(primes));

    int number = 3, numberOfPrimes = 0;
    while (number <= max) {

        int i;
        int isPrime = 1;  // Assume number is prime to begin with

        for (i=0; primes[i] != -1; i++) {
            if (number%primes[i] == 0) {  // See if number is divisiable by another prime
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printPrime(number);  // Print prime to screen
            primes[i] = number;  // Add number to list of primes
            numberOfPrimes = i;  // Save current prime count
        }


        number+=2;  // Increment by 2 so only looking at odd values
    }

    printf("Prime Count: %i\n", numberOfPrimes+2);  // Print number found. 2 must be added due to 1 & 2.

    return 0;
}

void printPrime(int num){
    printf("Prime: %i\n", num);
}
