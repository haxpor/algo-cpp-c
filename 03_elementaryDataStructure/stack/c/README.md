# stack

stack sample demonstrates the use of stack implementation which doesn't assume declaring stack on stack or heap, just plays along with what user has defined. Operate on `struct Stack`'s internal data more.

It also uses

* macros for shortening call of functions
* assertion in which could be toggling with -DNDEBUG in compile time as seen in `Makefile` (i.e. call with `make ndebug` to not include assert)
* option to define data type of stack item via `#define STACK_TYPE` or with compile flags via `-DSTACK_TYPE=float`. `Makefile` also makes use of `-DSTACK_TYPE_FP=1` when compile with target `make float` or `make double` to let main program's source file knows that data type is now in floating-point format. The reason it's needed is that `int` and `float` has the same size and as well we could not do string comparison via preprocessor.

# Build

Use either one of the following options

* `make` (default to use `int` type for Stack's elements)
* `make float`
* `make double`
