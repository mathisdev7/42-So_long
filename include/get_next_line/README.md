# get_next_line

![Final Score](https://i.ibb.co/xfdVDFc/image.png)

## Project Description
A function that reads a line from a file descriptor, developed as part of the 42 School curriculum. This project focuses on static variables, memory management, and file manipulation in C.

## Journey
This project proved to be quite challenging for me, requiring two attempts to achieve success. The first attempt failed due to memory leaks, which taught me valuable lessons about proper memory management in C. While I didn't particularly enjoy the coding process, the challenges it presented helped me grow as a programmer.

## Key Learnings
- Static variables and their persistence between function calls
- Memory management (malloc/free)
- File descriptor handling
- Buffer manipulation
- Proper memory leak prevention

## Technical Details
- Function reads from a file descriptor until a newline character is found
- Returns the line including the newline character
- Returns NULL if there's nothing else to read or if an error occurred
- Handles multiple file descriptors simultaneously
- Configurable buffer size through BUFFER_SIZE define

## Project Status
- **First Attempt**: Failed (Memory Leaks)
- **Second Attempt**: Success (104/100)
- **Completion Time**: ~2 days

## Challenges Faced
The most challenging aspects of this project were:
- Managing memory correctly without leaks
- Understanding static variables
- Handling edge cases with different buffer sizes
- Proper string manipulation without buffer overflows

## Function Prototype
```c
char *get_next_line(int fd);
```

## Reflection
While this wasn't my favorite project at 42, it significantly improved my understanding of memory management and file operations in C. The struggle with memory leaks in my first attempt taught me the importance of thorough testing and proper memory allocation/deallocation.

## Skills Developed
- Memory management
- File operations
- Buffer manipulation
- Debugging
- Code optimization
