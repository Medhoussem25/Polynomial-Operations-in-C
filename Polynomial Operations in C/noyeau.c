#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "noyeau.h" // Ensure this header file exists or remove this include

// Define the structure for a polynomial element
typedef struct Element {
    int coefficient;
    int power;
    struct Element *next;
} Element;

// Define the structure for the polynomial list
typedef struct Liste {
    Element *first;
} Liste;

// Function to create a new polynomial list
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

// Function to insert a term into the polynomial
void insertTerm(Liste *list, int coefficient, int power) {
    Element *newElement = malloc(sizeof(*newElement));
    if (list == NULL || newElement == NULL) {
        exit(EXIT_FAILURE);
    }

    newElement->coefficient = coefficient;
    newElement->power = power;

    // Insert at the beginning of the list
    newElement->next = list->first;
    list->first = newElement;
}

// Function to display the polynomial
void displayPolynomial(Liste *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    printf("The entered polynomial is:\n");
    while (current != NULL) {
        printf("%d * x^%d", current->coefficient, current->power);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to calculate the value of the polynomial for a given x
int calculatePolynomial(Liste *list, int x) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    int sum = 0;
    while (current != NULL) {
        sum += current->coefficient * pow(x, current->power);
        current = current->next;
    }
    printf("The value of the polynomial is: %d\n", sum);
    return sum;
}

// Function to find the degree of the polynomial
int degreePolynomial(Liste *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    int degree = 0;
    while (current != NULL) {
        if (current->power > degree) {
            degree = current->power;
        }
        current = current->next;
    }
    printf("The degree of the polynomial is: %d\n", degree);
    return degree;
}

// Function to compute the derivative of the polynomial
Liste *derivePolynomial(Liste *list) {
    if (list == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current = list->first;
    while (current != NULL) {
        current->coefficient *= current->power;
        current->power -= 1;
        current = current->next;
    }

    printf("The derivative of the polynomial is:\n");
    displayPolynomial(list);

    return list;
}

// Function to add two polynomials
void addPolynomials(Liste *list1, Liste *list2) {
    if (list1 == NULL || list2 == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *current1 = list1->first;
    while (current1 != NULL) {
        Element *current2 = list2->first;
        while (current2 != NULL) {
            if (current1->power == current2->power) {
                current1->coefficient += current2->coefficient;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
}

// Main function
int main() {
    Liste *myList = createPolynomial();
    Liste *yourList = createPolynomial();

    insertTerm(myList, 4, 3);
    insertTerm(myList, 8, 2);
    insertTerm(myList, 15, 1);

    insertTerm(yourList, 4, 3);
    insertTerm(yourList, 8, 2);
    insertTerm(yourList, 15, 1);

    calculatePolynomial(myList, 2);
    displayPolynomial(myList);
    degreePolynomial(myList);
    derivePolynomial(myList);

    printf("\nAfter derivative:\n");
    displayPolynomial(myList);

    addPolynomials(myList, yourList);
    printf("\nAfter addition:\n");
    displayPolynomial(myList);

    return 0;
}
