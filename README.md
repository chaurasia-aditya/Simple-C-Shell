# Simple-C-Shell
This project is a simple shell implementation in C.

## Table of Contents

- [Project Structure](#project-structure)
- [Building the Project](#building-the-project)
- [Usage](#usage)

## Project Structure
```
│
├── include/
│ ├── common.h
| ├── utils.h
│ ├── cmd_exec.h
│ ├── func_impl.h
│ └── shell.h
│
├── src/
│ ├── impl/
│ │ ├── cd_impl.c
│ │ ├── env_impl.c
│ │ ├── exit_impl.c
│ │ ├── ls_impl.c
│ │ └── pwd_impl.c
│ ├── execute_cmd.c
│ ├── read_cmd.c
│ ├── shell.c
| └── main.c
│
├── Makefile
└── README.md
```

## Dependencies

## Building the Project
```bash
make
```

## Usage
```bash
./bin/shell
```

## Supported Commands

* [x] ```pwd```
* [x] ```ls```
* [x] ```cd```
* [x] ```exit```
* [x] ```env```

## References
Here are some blogs that were particularly helpful during the development of this project:

1. **[Stephen Brennan: Tutorial - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)**
2. **[Santiago: Coding your own Shell in C](https://medium.com/@santiagobedoa/coding-a-shell-using-c-1ea939f10e7e)**