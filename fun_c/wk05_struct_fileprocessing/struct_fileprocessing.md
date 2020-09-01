- [Structures](#structures)
  - [Struct in struct](#struct-in-struct)
- [File processing](#file-processing)
  - [open close files](#open-close-files)
  - [e.g read till end of a text file](#eg-read-till-end-of-a-text-file)

# Structures

a custom data structure to store **structured** data

defining `struct`

```c
struct planet {
    double diameter;
    int n_moons;
};
typedef struct planet planet_t;
```

> `planet_t` is now a var type. you can use it similar to any other prmitive data type in C.

structs are passed by **value** (a local copy is made)

## Struct in struct

it is also possible to have **nested** structs

```c
struct moon {
    double diameter;
    char name[20];
};
typedef struct moon moon_t;

struct planet {
    double diameter;
    char name[20];
    moon_t moons[10]; /* struct in struct */
}
typedef struct planet planet_t;
```

# File processing

we'll be dealing with 2 file types:
- **Text files**
  - contain human readable char
  - endline marked by `LF`(linux) `CR LF`(win)
  - read write func from `stdio.h` - `fscan`, `fprintf`, `fgetc`, `fputc`
- **Binary files**
  - not limited to human readable chars
  - read write func from `stdio.h` - `fread`, `fwrite`, `fget`, `fputc`

have you already been write read text files? devices as files

`stdin` `stdout` `stderr`

## open close files

Opening files:
```c
FILE* fopen(const char* filename, const char* mode);
```
Common `mode`:
-  **r** read text
-  **w** write text
-  **rb** read binary file
-  **wb** write binary file

Closing files: close any file stream operating in any mode
```c
int fclose(FILE* stream);
```

## e.g read till end of a text file

using `fgetc` to read one char at a time. When **EOF** is reached `fgetc` returns **EOF**

```c
/* assuming file stream finp is open */
char ch;
for (ch = fget(finp); ch != EOF; ch = fgetc(finp)) {
    /* do something */
}
``
