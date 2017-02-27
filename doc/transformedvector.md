# TransformedVector

Template class with one template argument.

TransformedVector should be used for all positions and sizes.

### Constructors

| Constructor                            | Resulting Vector |
|----------------------------------------|:----------------:|
| TransformedVector()                    | (0, 0)           |
| TransformedVector(T c)                 | (c, c)           |
| TransformedVector(T x, T y)            | (x, y)           |
| TransformedVector(const sf::Vector2i&) | copies           |
| TransformedVector(const sf::Vector2f&) | copies           |

### Operators

| Operator                               | Resulting Vector |
|----------------------------------------|:----------------:|
| sf::Vector2i()                         | (getX(), getY()) |
| sf::Vector2f()                         | (getX(), getY()) |

### Getter

`T getX()` and `T getY()` return the transformed component.

`T getRealX()` and `T getRealY()` get the original component (what was passed as
an argument to the constructor).

### updateWinSize

Updates the window size that is used to calculate the return values of `getX`
and `getY`.
