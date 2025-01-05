#ifndef NOYEAU_H_INCLUDED
#define NOYEAU_H_INCLUDED

// Structure for a polynomial term
typedef struct Element {
    int coefficient;  // Coefficient of the term
    int power;        // Power of the term
    struct Element *next;  // Pointer to the next term
} Element;

// Structure for a polynomial list
typedef struct Liste {
    Element *first;  // Pointer to the first term in the polynomial
} Liste;

// Function Prototypes

// Creates an empty polynomial list
Liste *CreationPolynome();

// Inserts a term (coefficient and power) into the polynomial list
void insertion(Liste *liste, int coefficient, int power);

// Displays the polynomial in readable format
void affichagePolynome(Liste *liste);

// Evaluates the polynomial for a given value of x
int calculPolynome(Liste *liste, int x);

// Returns the degree of the polynomial
int degrePolynome(Liste *liste);

// Derives the polynomial and returns the derived polynomial
Liste *DerivePolynome(Liste *liste);

// Multiplies two polynomials and displays the result
void MultiplicationPolynome(Liste *liste1, Liste *liste2);

#endif // NOYEAU_H_INCLUDED
