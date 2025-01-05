#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "noyeau.h"

// Structure Definitions
typedef struct Element {
    int coefficient;
    int power;
    struct Element *next;
} Element;

typedef struct Liste {
    Element *first;
} Liste;

// Function to create a polynomial list
Liste *createPolynomial() {
    Liste *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL) {
        exit(EXIT_FAILURE);
    }

    element->coefficient = 0;
    element->power = 0;
    element->next = NULL;
    list->first = element;

    return list;
}

// Function to insert a term into the polynomial list
void insertTerm(Liste *list, int coefficient, int power) {
    Element *newElement = malloc(sizeof(*newElement));
    if (list == NULL || newElement == NULL) {
        exit(EXIT_FAILURE);
    }

    newElement->coefficient = coefficient;
    newElement->power = power;
    newElement->next = list->first;
    list->first = newElement;
}

// Function to display the polynomial
void displayPolynomial(Liste *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    printf("The polynomial is: \n");
    while (current->next != NULL) {
        printf("%d * x^%d", current->coefficient, current->power);
        current = current->next;
        if (current->next != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to calculate the polynomial value for a given x
int evaluatePolynomial(Liste *list, int x) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    int sum = 0;
    while (current->next != NULL) {
        sum += current->coefficient * pow(x, current->power);
        current = current->next;
    }
    printf("Polynomial value for x = %d is: %d\n", x, sum);
    return sum;
}

// Function to find the degree of the polynomial
int getPolynomialDegree(Liste *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    int degree = 0;
    while (current->next != NULL) {
        if (current->power > degree) {
            degree = current->power;
        }
        current = current->next;
    }
    printf("The degree of the polynomial is: %d\n", degree);
    return degree;
}

// Function to calculate the derivative of the polynomial
Liste *derivePolynomial(Liste *list) {
    Element *current = list->first;

    while (current->next != NULL) {
        current->coefficient *= current->power;
        current->power -= 1;
        current = current->next;
    }

    printf("The derivative of the polynomial is: ");
    displayPolynomial(list);
    return list;
}

// Function to add two polynomials
void addPolynomials(Liste *list1, Liste *list2) {
    Element *current1 = list1->first;
    Element *current2 = list2->first;

    while (current1->next != NULL) {
        current2 = list2->first;
        while (current2->next != NULL) {
            if (current1->power == current2->power) {
                current1->coefficient += current2->coefficient;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
}

// Function to multiply two polynomials
void multiplyPolynomials(Liste *list1, Liste *list2) {
    Liste *result = createPolynomial();
    Element *current1 = list1->first;
    Element *current2 = list2->first;

    while (current1->next != NULL) {
        current2 = list2->first;
        while (current2->next != NULL) {
            int coeff = current1->coefficient * current2->coefficient;
            int power = current1->power + current2->power;
            insertTerm(result, coeff, power);
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    printf("The product of the polynomials is: ");
    displayPolynomial(result);
}

// Main function
int main() {
    Liste *poly1 = createPolynomial();
    Liste *poly2 = createPolynomial();

    // Input and display for the first polynomial
    printf("Enter the terms of the first polynomial (coefficient and power):\n");
    int coeff, power, choice = 0;
    while (choice != 1) {
        printf("Coefficient: ");
        scanf("%d", &coeff);
        printf("Power: ");
        scanf("%d", &power);
        insertTerm(poly1, coeff, power);
        printf("Enter 1 to stop, 0 to continue: ");
        scanf("%d", &choice);
    }
    displayPolynomial(poly1);

    // Input and display for the second polynomial
    printf("Enter the terms of the second polynomial (coefficient and power):\n");
    choice = 0;
    while (choice != 1) {
        printf("Coefficient: ");
        scanf("%d", &coeff);
        printf("Power: ");
        scanf("%d", &power);
        insertTerm(poly2, coeff, power);
        printf("Enter 1 to stop, 0 to continue: ");
        scanf("%d", &choice);
    }
    displayPolynomial(poly2);

    // Menu-driven program
    while (choice != 9) {
        printf("\n===== Menu =====\n");
        printf("2: Evaluate polynomials\n");
        printf("3: Display polynomials\n");
        printf("4: Get polynomial degree\n");
        printf("5: Add polynomials\n");
        printf("7: Multiply polynomials\n");
        printf("8: Derive polynomials\n");
        printf("9: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            int x;
            printf("Enter the value of x: ");
            scanf("%d", &x);
            evaluatePolynomial(poly1, x);
            evaluatePolynomial(poly2, x);
        } else if (choice == 3) {
            displayPolynomial(poly1);
            displayPolynomial(poly2);
        } else if (choice == 4) {
            getPolynomialDegree(poly1);
            getPolynomialDegree(poly2);
        } else if (choice == 5) {
            addPolynomials(poly1, poly2);
            printf("Resultant polynomial after addition: ");
            displayPolynomial(poly1);
        } else if (choice == 7) {
            multiplyPolynomials(poly1, poly2);
        } else if (choice == 8) {
            printf("Derivative of first polynomial:\n");
            derivePolynomial(poly1);
            printf("Derivative of second polynomial:\n");
            derivePolynomial(poly2);
        }
    }

    return 0;
}
