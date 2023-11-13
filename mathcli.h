#include <stdio.h>
#include "mathtools.h"

void template(){

    unsigned long long n;

    printf("\n---Tool Name---\n");
    printf("Description of tool.\n");

    while(true){
        printf("\nEnter a valid number or 0 to terminate: ");

        scanf("%lli", &n);
        if(!n){
            break;
        }
    }

    printf("\n---Terminated---\n");

    return;
}

void call_prime_checker(){
    unsigned long long n;

    printf("\n---Prime Checker---\n");
    printf("Checks if a natural number (ℕ), is prime.\n");

    while(true){
        printf("\nEnter a natural number (ℕ) or 0 to terminate: ");

        scanf("%lli", &n);
        if(!n){
            break;
        }

        if(is_prime(n)){
            printf("\n%lli is a prime number.\n", n);
        }
        else{
            printf("\n%lli is not a prime number.\n", n);
        }
    }

    printf("\n---Terminated---\n");

    return;
}

void call_prime_list(){
    unsigned long long a, b, tally;

    printf("\n---Prime Number List---\n");
    printf("Finds all prime numbers in the set [a, b], such that a, and b, are natural numbers (ℕ).\n");

    while(true){
        printf("\nEnter a range of natural numbers (ℕ), [a, b], or zero for both values to terminate.\n\n");

        printf("Enter a: ");
        scanf(" %lli", &a);
        printf("Enter b: ");
        scanf(" %lli", &b);

        if(!a && !b){
            break;
        }

        list_primes(a, b, &tally);

        printf("\nThere are %lli primes within [%lli, %lli].\n", tally, a, b);
    }

    printf("\n---Terminated---\n");

    return;
}

void call_solve_quadratic(){

    double a, b, c, t1, t2;
    bool imaginary;

    printf("\n---Quadratic Solver---\n");
    printf("Solves a quadratic of the form ax^2 + bx + c = 0, such that all variables are real numbers (ℝ).\n");

    while(true){
        printf("\nEnter a (or 0 to terminate): ");
        scanf("%lf", &a);
        if(!a){
            break;
        }
        printf("Enter b: ");
        scanf("%lf", &b);
        printf("Enter c: ");
        scanf("%lf", &c);

        solve_quadratic(a, b, c, &t1, &t2, &imaginary);

        if(imaginary){
            printf("\nx = %.6g ± %.6gi\n", t1, t2);
        }
        else{
            printf("\nx1 = %.6g\nx2 = %.6g\n", t1 + t2, t1 - t2);
        }
        
    }

    printf("\n---Terminated---\n");

    return;
}

void call_factoriser(){

    unsigned long long n, num_factors;

    printf("\n---Factoriser---\n");
    printf("Lists all positive factors of a natural number (ℕ).\n");

    while(true){
        printf("\nEnter a natural number (ℕ) or 0 to terminate: ");

        scanf("%lli", &n);
        if(!n){
            break;
        }

        factorise(n, &num_factors);

        printf("\n%lli has %lli factors.\n", n, num_factors);
    }

    printf("\n---Terminated---\n");

    return;
}

void call_prime_factoriser(){

    unsigned long long n;

    printf("\n---Prime Factoriser---\n");
    printf("Lists prime factors of a natural number (ℕ).\n");

    while(true){
        printf("\nEnter a natural number (ℕ) or 0 to terminate: ");

        scanf("%lli", &n);
        if(!n){
            break;
        }

        if(n == 1){
            printf("\n1 has no prime factors.\n");
        }
        else{
            prime_factorise(n);
        }
    }

    printf("\n---Terminated---\n");

    return;
}