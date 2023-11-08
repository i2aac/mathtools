#include <stdio.h> //printf, scanf
#include <stdbool.h> //bool
#include <stdlib.h> //calloc, free
#include <math.h> //sqrt

void swap(unsigned long long *pA, unsigned long long *pB){ //swaps the values at two addresses
    unsigned long long temp = *pA;
    *pA = *pB;
    *pB = temp;
    return;
}

bool is_prime(unsigned long long n){ //returns true if a number is prime
    if(n == 2 || n == 3 || n == 5){
        return true;
    }
    if(n == 0 || n == 1 || (n >> 1) * 2 == n || n % 3 == 0){ //bitshifting is faster than modulo
        return false;
    }
    for(unsigned long long i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

void list_primes(unsigned long long a, unsigned long long b, unsigned long long *num){

    unsigned long long tally = 0;

    if(a > b){ //ensures that a is the smaller of the two numbers
        swap(&a, &b);
    }
    if(b == 0){
        //deal with a range of [0, 0]
        return;
    }

    /*
    this is an implementation of the sieve of eratosthenes
    positions in the array numbers[] will represent n, and the value at the position will indicate primality
    prime numbers will be marked with 0 (false), and composite numbers will be marked with 1 (true)
    */
    bool *numbers = (bool*) calloc(b + 1, sizeof(bool));
    numbers[0] = true;
    numbers[1] = true;

    for(unsigned long long i = 2; i <= b; i++){
        if(!numbers[i]){
            for(unsigned long long j = i * 2; j <= b; j += i){
                numbers[j] = true;

            }
        }
    }

    for(unsigned long long i = a; i <= b; i++){
        if(!numbers[i]){
            tally++;
            printf("%lli\n", i);
        }
    }

    *num = tally;

    free(numbers);

    return;
}

void solve_quadratic(double a, double b, double c, double *t1, double *t2, bool *imaginary){
    /*
    This function expresses the roots of a quadratic in the form -b/(2a) +- sqrt(b^2 - 4ac)/(2a).
    This form ensures that imaginary roots can be accounted for in one function.
    */

    double discriminant = b * b - 4 * a * c;
    double denominator = 0.5 / a;
    *imaginary = false;

    if(discriminant < 0){
        discriminant *= (-1);
        *imaginary = true;
    }

    *t1 = b * (-1) * denominator;
    *t2 = sqrt(discriminant) * denominator;

    return;
}