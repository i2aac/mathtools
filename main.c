#include <stdio.h> //printf and scanf
#include "mathcli.h" //cui for functions

//THIS SOURCE CODE WON'T COMPILE PROPERLY UNLESS YOU LINK MATH.H DURING COMPILATION.
//ON LINUX, "gcc main.c -lm"

void print_list(){

    char c;
    FILE *fptr = fopen("list.txt", "r");
    
    if(fptr == NULL){
        printf("list.txt not found.\n");
        exit(0);
    }

    c = fgetc(fptr);
    while(c != '/'){
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

    return;
}

void use_tool(int n){
    switch(n){
        case 1:
            call_prime_checker();
            break;
        case 2:
            call_prime_list();
            break;
        case 3:
            call_solve_quadratic();
            break;
        case 4:
            call_factoriser();
            break;
        case 5:
            call_prime_factoriser();
            break;
        default:
            printf("\n%d does not have an associated function.\n", n);
            break;
    }

    return;
}

int main(){

    int choice;
    
    printf("---Math Tools---\n");
    printf("Enter a number to use a tool, or enter 0 to terminate.\n");

    while(true){
        putchar('\n');
        print_list();

        printf("\nSelect a program: ");
        scanf("%d", &choice);

        if(!choice){
            break;
        }

        use_tool(choice);
    }

    printf("\n---Terminated---\n");

    return 0;
}
