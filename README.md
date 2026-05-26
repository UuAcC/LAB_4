LAB-4_Polynome
============

![C++17](https://img.shields.io/badge/C%2B%2B-17-red.svg)
![Platforms](https://img.shields.io/badge/platform-linux%20%7C%20windows-lightgrey.svg)
![CMake](https://img.shields.io/badge/CMake-3.6+-064F8C.svg)
![GoogleTest](https://img.shields.io/badge/GoogleTest-1.11+-green.svg)
![ANTLR](https://img.shields.io/badge/ANTLR-4.13.2-blue.svg)

The project **LAB-4** is an educational implementation of a **Skip List** data structure, a **Polynomial** class supporting three variables (x, y, z) with operations (addition, subtraction, multiplication, division, evaluation), and a **parser** for polynomial expressions using **ANTLR4**. It is designed for learning purposes, demonstrating probabilistic data structures, generic programming, RAII, move semantics, and visitor-based parsing. The project includes a comprehensive Google Test suite.

## Getting Started

This repository uses git submodules. To clone the repository with all submodules:
```bash
git clone --recursive https://github.com/UuAcC/LAB_4.git
```
If you have already cloned without `--recursive`, initialize and update submodules manually:
```bash
git submodule init
git submodule update
```
The source files are organised in several subdirectories: `lists_lib/`, `polynome_lib/`, `antlr_things/`, and `tests/`. The project uses CMake for building and depends on Google Test (included as a submodule) and ANTLR4 (runtime library required).

## Installing

### Dependencies
- `C++17` compatible compiler (MSVC, GCC, Clang)
- [`CMake`](https://cmake.org/) 3.6 or higher
- `GoogleTest` (included as a git submodule in `googletest/`)
- `ANTLR4 Runtime` (C++ version) – is pre-built and placed in `antlr_things/antlr4_lib/`

### Build
Use CMake to build the project:
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
Available CMake options:
- `-DCMAKE_BUILD_TYPE=Release` – optimised build (default)
- `-DCMAKE_BUILD_TYPE=Debug` – debug build with symbols

### ANTLR4
The parser files in `antlr_things/generated_parser/` were generated from `poly_gram.g4` using:
```bash
antlr4 -Dlanguage=Cpp -visitor -no-listener -o generated_parser poly_gram.g4
```
The ANTLR4 C++ runtime's been built separately and placed at `antlr_things/antlr4_lib/`.

## Running Tests

After building, execute the test runner:
```bash
./tests/test_LAB_4       # Linux/macOS
test_LAB_4.exe           # Windows
```

Test coverage:
- `HListTest` – circular singly linked list with sentinel node: default/copy/move constructors, `addFirst`, `addLast`, `insertAfter`, `delFirst`, `delLast`, `clear`, iterator, output operator
- `MonomeTest` – monomial operations: addition/subtraction/multiplication/division, scalar operations, unary minus, comparison, similarity check, evaluation, overflow protection
- `PolynomeTest` – polynomial operations: addition/subtraction/multiplication/division, compound assignments, operations with monomes, evaluation, associativity/commutativity/distributivity checks, degree range validation

## Usage Example

```cpp
#include "Polynome.h"
#include "Monome.h"
#include <iostream>

int main() {
    // Create polynomial from string expression
    Polynome p("2.0 * x^2 * y^1 + 3.0 * x^1 * y^2 + 1.0 * y^1 * z^1");
    
    // Evaluate at point (x=2, y=3, z=4)
    double result = p.calculate(2.0, 3.0, 4.0);
    std::cout << "p(2, 3, 4) = " << result << std::endl;
    
    // Create monomial and add to polynomial
    Monome m(5.0, degrees());
    m.set_degree(X, 2);
    m.set_degree(Y, 1);
    Polynome p2 = p + m;
    
    // Output polynomial
    std::cout << "Polynomial: " << p2 << std::endl;
    
    return 0;
}
```

Output:
```
p(2, 3, 4) = 48
Polynomial: 5 * x^2 * y^1 * z^0 + 2 * x^2 * y^1 * z^0 + 3 * x^1 * y^2 * z^0 + 1 * y^1 * z^1
```

## Documentation

### Component Overview

**1. Lists Library (`lists_lib/`)**
- `HLink<T>` – circular linked list node with `next` pointer only (sentinel-based)
- `HList<T>` – circular singly linked list with head sentinel. Methods: `addFirst`, `addLast`, `insertAfter`, `clear`, `delFirst`, `delLast`, copy/move constructors and assignments, destructor
- `Iterator<T>` – forward iterator for `HList`
- `List<T>` – simple singly linked list (legacy, used internally)

**2. Monome Class (`polynome_lib/`)**
- `degrees` – union representing monomial degree as either `unsigned N` (packed value) or `char s[4]` (per-variable degrees)
- `Monome` – monomial with coefficient and degree. Methods: arithmetic operators (`+`, `-`, `*`, `/`), scalar operators, compound assignment, comparison (by total degree `N`), `fully_equals` (compares coefficient and degree), `value_in_point`, stream I/O
- Overflow protection using `std::numeric_limits<double>::min()/max()`

**3. SkipList Class (`polynome_lib/`)**
- `SkipLink<T>` – skiplist node with vector of next pointers and random level
- `SkipList<T>` – probabilistic data structure. Methods: `insert` (O(log N) expected), `addLast` (O(1) amortised when inserted in descending order), `delFirst`, `clear`, `isEmpty`, copy/move, iterator
- Maintains `lasts` array for O(1) `addLast` operations (requires descending order insertion)
- Used as base class for `Polynome` (stores monomials in descending degree order)

**4. Polynome Class (`polynome_lib/`)**
- `Polynome` – polynomial as a skiplist of monomials (descending by total degree). Constructors: default, from `Monome`, from `std::string` (via ANTLR parser)
- Arithmetic: `+`, `-`, `*` with `Polynome` or `Monome`, scalar multiplication/division, compound operators
- Evaluation: `calculate(double x, double y, double z)`
- Stream output: `operator<<`
- Degree validation: monomials with degrees outside [`DEGR_MIN`, `DEGR_MAX`] are filtered

**5. ANTLR Parser (`antlr_things/`)**
- `poly_gram.g4` – grammar for polynomial expressions
- Generated parser: `poly_gramLexer`, `poly_gramParser`, `poly_gramBaseVisitor`, `poly_gramVisitor`
- `UserVisitor` – custom visitor implementing:
  - `visitFinalMonome` – constructs `Monome` from coefficient and variable degrees
  - `visitSumOfMonomesPolynome` – accumulates monomes into `Polynome`
  - `visitSingleMonomePolynome` – creates polynomial from single monome
  - `visitUnaryMinusMonome` – negates monome
  - `visitUnaryMinusDegree` – handles negative degree values
  - `visitChar` / `visitDouble` – converts tokens to `int` / `double`

**6. Supported Expression Syntax**
```
polynome := monome { '+' monome }
monome := '-' monome
| '(' monome ')'
| coeff ['' x_var] ['' y_var] ['*' z_var]
x_var := 'x^' degree
y_var := 'y^' degree
z_var := 'z^' degree
degree := '-' degree | number
coeff := number
```
- Numbers: integer (`CHAR`) or floating-point (`DOUBLE`)
- Multiplication sign `*` is optional between coefficient and variables
- Degree range is limited by `DEGR_MAX` (10) and `DEGR_MIN` (-5) – out-of-range monomials are discarded

### Degree Packing
The `degrees` union uses the same memory for two interpretations:
- `unsigned N` – packed total degree (for fast comparison/sorting)
- `char s[4]` – individual degrees for x, y, z (indices: X=2, Y=1, Z=0)

## Grammar File

You can find grammar in `antlr_things/poly_gram.g4`.

## Authors

### Developer
- [Simonov Maksim](https://github.com/UuAcC)

### Supervisor
- [Evgeny Kozinov](https://github.com/kozinove)
