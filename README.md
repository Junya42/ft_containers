# C++ Containers Implementation Project

This project involves implementing various container types from the C++ standard template library. The goal is to replicate the structure and functionality of the standard containers while adhering to the C++98 standard. The project emphasizes clean code, proper memory management, and compatibility with C++98 features.

## Objectives

- Implement C++ container types following the structure of their standard counterparts.
- Comply with the C++98 standard; do not use features introduced in later versions.
- Ensure memory leak-free code and proper memory management.
- Provide comprehensive tests for each container.

## General Guidelines

### Compilation

- Compile code using `c++` with flags `-Wall -Wextra -Werror`.
- The code should compile with the `-std=c++98` flag.
- Include a Makefile with `$(NAME)`, `all`, `clean`, `fclean`, and `re` rules.

### Formatting and Naming

- Prioritize readability and maintainability of code.
- No strict coding style enforcement, but clarity is essential.
- Class files for each container should be appropriately named.

### Allowed/Forbidden

- Utilize the C++ standard library.
- Avoid external libraries and features beyond C++98.
- Prohibited functions: *printf(), *alloc(), free().

## Mandatory Part

### Containers to Implement

- `vector` (excluding `vector<bool>` specialization).
- `map`.
- `stack` (optional, but required for bonus).

### Requirements

- Use the namespace `ft`.
- Logical and justified data structures for containers.
- Limit public functions to those of standard containers.
- Implement member functions, non-member functions, and overloads.
- Follow original naming and adhere to C++98 standards.
- Implement iterators if supported by the container.
- Utilize `std::allocator` for memory management.
- `friend` keyword allowed only when justified.

### Testing

- Provide thorough tests in `main.cpp` for defense.
- Create binaries with your containers and compare outputs and performance.
- Note that your containers may have slower performance (up to 20 times).

## Bonus Part

### Additional Container

- Implement a Red-Black tree-based `set`.

## Contributions

Contributions are welcome through issues and pull requests for enhancements and bug fixes.

## Disclaimer

This project conforms to the C++98 standard and focuses on a subset of C++ features. Refer to project documentation for further information.

For references, consult [cplusplus.com](https://www.cplusplus.com/) and [cppreference.com](https://cppreference.com/).
