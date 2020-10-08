# Pixels Challenge

This repository holds the solution of a pixel management fictional scenario
that was part of a coding challenge. This code and its specification doesn’t
match with the way pixels are managed in real life.

Use this project as a reference for:

* C project structure.
* C public headers includes and their linking.
* 3D party library usage in C.
* Documentation.

Also contains code related to:

* Pointer management.
* Bitwise operations.
* Quick sort algorithm.
* C unit testing using [Unity framework](http://www.throwtheswitch.org/unity).

## Specification

Go to the [project specification](./doc/specification.md) in the doc folder.


## Project status

* :white_check_mark: The pixel solution code is complete and tested.

* :warning: The Unit test framework usage needs to be improved. Right now you
  have to uncomment the `main`, `setUp` and `tearDown` functions of the test
  file you want to run and comment the same functions in the other files.

* :warning: The `Makefile` needs to be improved. There is only one target
  used for testing that could've been coded better.


## Testing

To test the project run:

```bash
make test
```
