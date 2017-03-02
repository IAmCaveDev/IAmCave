# Style Guide

### Table of Contents

1. [Naming](#naming)
2. [Include Order](#include-order)
3. [Headers](#headers)
4. [Formatting](#formatting)
5. [Comments](#comments)
6. [Other Stuff](#other-stuff)
7. [Contributing](#contributing)
8. [Footnotes](#footnotes)


### Naming

#### Files

Files are named after the class they declare or if they contain only non-class
declarations a suitable name (e.g. "vectorhelperfunctions.h").
All `.h` and `.cpp` files' names are in lower-case and may only contain letters
except for the file extension.

#### Classes/Structs/Enums/Namespaces

Classes, structs, enums and namespaces use upper camel case.

#### (Member) Variables/Functions/Parameters

Member variables, member functions, variables, functions and function parameters
use lower camel case.

### Include Order

Includes should be written in this order and each section divided by a blank
line.

1. Header to be implemented (if any)
2. C/C++ files (e.g. \<vector\>)
3. Other files (e.g. \<SFML/Graphics.hpp\>
4. Project files

example.cpp

```c++
#include "example.h"

#include <math.h>
#include <vector>

#include <SFML/Graphics.hpp>

#include "stuff.h"
```

### Headers

#### Header Guards

Every header file has a header guard with the same name as the file:

example.h

```c++
#ifndef EXAMPLE_H
#define EXAMPLE_H

// Header content goes here

#endif
```

#### Forward Declarations

If forward declarations are needed they should be written directly after the
includes.


### Formatting

Files should end with an EOL.

#### Line Length

A line should be at most 80 characters long.

#### Indentation

Four spaces are used to indent a line. Most editors have to option to insert
spaces instead of a tab character.

#### Comma

Commas should always be followed by a space but not preceded by one.

#### Parentheses

Parentheses are not followed or preceded by a space unless it's an operator:

```c++
void someFunction(float n, bool b){
    if(b){
        n = 7;
    }else if(n > (0 + 1)){
        n = (n + 3) / 2
    }
}
```

#### Operators

Operators are always followed and preceded by a space. Exceptions are the `/`
(division) and `*` (multiplication) operators which can be either formatted like
any other operator or not surrounded by spaces at all:

```c++
float a = 10 + 2*2;
float b = a/10;
float c = a * b;
```

`a * b` and `a / b` should be preferred.

#### Numbers

Literals should always have a comment explaining them or be replaced by a
variable with a descriptive name.

#### Blocks

If a block is preceded by a class, function, struct or enum `{` will be placed
on the same line.
If the block is not preceded by another statement `{` gets it's own line.

The body of a block begins on the next line indented by four spaces.
The end of a block `}` gets it's own line.

#### Initialiser Lists

Initialiser lists should be written just like parameter lists (explained in the
next section).

For example:

```c++
StructType name = {4, 3, 2};
```

#### Function Declarations and Definitions

```c++
Type Class::function(Type firstParameter, Type secondParameter){
    ...
}
```

If the parameter list doesn't fit on one line it will be continued on the next
and aligned with the first parameter in the line above:

```c++
Type Class::function(Type firstParameter, Type secondParameter,
                     Type secondParameter){
    ...
}
```

If no parameters fit on one line the parameter list starts on the next one
indented by eight spaces:

```c++
VeryLongReturnTypeName VeryLongClassName::VeryLongFunctionName(
        Type firstParameter, Type secondParameter){
    ...
}
```


### Comments

One line comments use `//` followed by a space and starting with an upper-case
letter unless the first word is a specific name or keyword (e.g. int,
someFunctionName).

Multi-line comments can use either `//` or `/*` and `*/`.
Comments using `/*` and `*/` should be prettified:

```c++
/*
 * Multi
 * line
 * comment
 */
```

Comments should be on the line above the code they are trying to comment and
almost never on the same line.


## Other Stuff

### 0/nullptr/NULL

`0` and `0.0` should be used for numbers.
`nullptr` should be used for pointers. `NULL` should not be used
<sup>[1](#f1)</sup>.

### auto

`auto` should only be used if it improves readability and the resulting type is
easy to deduce from the surrounding code. It should be used especially when
iterating over STL containers:

```c++
std::vector vec;
for(auto& it : vec){
    ...
}
```

### Lambdas

Most of the time lambdas should be replaced by functions to improve readability
and prevent unexpected errors/behaviour. Lambdas can be useful when functions
need to be provided to STL classes/functions. When using lambdas it's usually
best to capture explicitly (e.g. `[foo](){}`) and explicitly provide a return
type (e.g. `[foo]() -> int {}`).


## Contributing

If something in this guide is not mentioned check [Google's C++ Style
Guide](https://google.github.io/styleguide/cppguide.html) on the topic for
inspiration, make a pull request with the suggested changes and discuss
improvements.


--------------


#### Footnotes

<a name="f1">1</a>: http://stackoverflow.com/questions/13091804/whats-better-to-use-in-c11-zero-or-null
