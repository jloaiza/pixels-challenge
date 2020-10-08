# Pixels Challenge

This repository holds the solution of a pixel management fictional scenario
that was part of a coding challenge. This code and its specification doesn’t
match with the way pixels are managed in real life.

Use this project as a reference for:

* C project structure.
* C public headers includes and their linking.
* 3D party library usage in C.
* Documentation.
* C language practice.

Also contains code related to:

* Pointer management.
* Bitwise operations.
* Quick sort algorithm.
* C unit testing using [Unity framework](http://www.throwtheswitch.org/unity).


## Specification

Go to the [project specification](./doc/specification.md) in the doc folder.


## Project status

* :white_check_mark: The pixel solution code is complete and tested.

* :warning: The Unit test framework usage needs to be improved. Right now there
  is a Makefile target for each test file.

* :warning: The `Makefile` needs to be improved.


## Testing

To test the project run:

```bash
make all
```


## Learned lessons

* Do not set the random seed every time a random number is generated. If
  several calls are made immediately one after the other, the random number
  will result in the same value always (giving you a not so random behavior).

* Remember to free the memory you are not using when testing using loops.

* Be careful when subtracting unsigned ints for comparison. If the numbers are
  too big they may overflow the sign bit of the result leading to unwanted
  behaviors.
