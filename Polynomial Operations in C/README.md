# Polynomial Operations in C

This project implements a set of functionalities to manipulate polynomials using linked lists in C. The operations include creating, displaying, evaluating, deriving, and performing arithmetic operations like addition, subtraction, and multiplication on polynomials.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Compilation and Execution](#compilation-and-execution)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This project is designed to demonstrate how polynomials can be represented as linked lists in C. Each term in a polynomial is a node in the list, with fields for the coefficient, power, and a pointer to the next term. The program provides a menu-based interface to perform various operations on polynomials.

---

## Features

- Create polynomials dynamically.
- Insert terms into a polynomial.
- Display polynomials in a human-readable format.
- Evaluate polynomials for a given value of \( x \).
- Find the degree of a polynomial.
- Compute the derivative of a polynomial.
- Perform addition, subtraction, and multiplication of polynomials.

---

## Project Structure

The project consists of the following files:

1. **`main.c`**  
   Contains the main logic and menu-driven interface.

2. **`noyeau.h`**  
   Header file defining the data structures and function prototypes.

3. **`noyeau.c`**  
   Implementation of the functions declared in `noyeau.h`.

4. **`README.md`**  
   This documentation file.

---

## Usage

### Menu Options
1. **Create Polynomial**: Input terms dynamically for each polynomial.  
2. **Display Polynomial**: View the polynomial in a mathematical format.  
3. **Evaluate Polynomial**: Calculate the polynomial's value for a given \( x \).  
4. **Find Degree**: Display the highest power of the polynomial.  
5. **Addition**: Compute the sum of two polynomials.  
6. **Subtraction**: Compute the difference between two polynomials.  
7. **Multiplication**: Multiply two polynomials.  
8. **Derivative**: Compute the derivative of a polynomial.

---

## Compilation and Execution

### Requirements
- GCC Compiler

### Steps
1. Compile the project:
   ```bash
   gcc -o polynomial main.c noyeau.c -lm
   ```
   The `-lm` flag links the math library, used for the `pow` function.

2. Run the executable:
   ```bash
   ./polynomial
   ```

---

## Examples

### Creating a Polynomial
Input terms for the polynomial as prompted. For example:
```
Enter the coefficient of your polynomial: 3
Enter the power of your polynomial: 2
```

Resulting polynomial:
```
3 * x^2
```

### Adding Two Polynomials
For two polynomials:
1. \( 3x^2 + 2x + 1 \)
2. \( 4x^2 - 2x + 5 \)

The result will be:
```
7x^2 + 6
```

---

## Contributing

Feel free to fork this repository, open issues, and submit pull requests. Contributions are welcome!

---

## License

This project is licensed under the MIT License.

