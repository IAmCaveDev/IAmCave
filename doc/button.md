# Button

Inherits from Textbox.

### Constructors

Button provides two constructors. When using the constructor that requires a
`std::string` as it's sixth argument the button will be able to have text.

```c++
Button(const TransformedVector<>& size,
       const TransformedVector<>& newPosition,
       std::string texPath, std::function<void()> newCallback,
       std::function<void()> newAltCallback, std::string newText,
       int padding = 5, int newTextSize = 20,
       sf::Color newTextColor = sf::Color::Black,
       sf::Text::Style newTextStyle = sf::Text::Style::Regular);
```

Since most buttons won't have text and text creation (as it's currently
implemented) is expensive a second constructor is available which creates a
button that is not able to have any text.

```c++
Button(const TransformedVector<>& size,
       const TransformedVector<>& newPosition,
       std::string texPath, std::function<void()> newCallback,
       std::function<void()> newAltCallback = nullptr);
```

### Callbacks

Up to two actions can be assigned to a button by passing callables to the Button
constructor or by using the `setCallback` and `setAltCallback` member functions.
The callback's type is `std::function<void()>`.

To use functions that take arguments (including non-static member functions) as
callbacks `std::bind`<sup>[1](#f1)</sup> can be used.
`std::bind` uses value semantics by default. References need to be passed to it
in a `std::reference_wrapper` which can be generated from a reference using the
`std::ref` and `std::cref` helper functions<sup>[2](#f2)</sup>.

Here is an example of *SomeFunction* which takes a reference as argument being
used as a callback for Button.

```c++
Button example({200, 100}, {100, 100}, "example.png",
               std::bind(&SomeFunction, std::ref(ReferenceArgument));
```

No callback can be provided by passing a `nullptr` as the callback.

### Textures

Even though the constructor only requires one texture for the button three
textures in total are used.
The texture specified in the constructor will be used as the normal button
texture. The other two textures are loaded by appending a "-h" for the
highlighted texture and a "-d" for the disabled texture to the filename of the
normal texture.
Using `example.png` as the normal texture would result in the button trying to
load `example-h.png` and `example-d.png` for the other textures. If none is
found the texture is assigned the normal texture.

### highlighted and executed

These functions can be used to check if the button was pressed by passing
coordinates and a bool to it. The bool determines whether the first or second
callback is used. `executed` calls the callback, `highlighted` just sets the
button texture to the highlighted variant.

<a name="f1">1</a>: http://en.cppreference.com/w/cpp/utility/functional/bind<br>
<a name="f2">2</a>: http://en.cppreference.com/w/cpp/utility/functional/ref
