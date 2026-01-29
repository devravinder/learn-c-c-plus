# Learn C & C++

## Env Setup

- we need compiler + IDE

1. gcc compiler instllation
   1. Linux

      ```bash
         sudo apt update
         sudo apt install build-essential
         # gcc --version # check version

         # compile & run
         # gcc hello.c -o hello
         # ./hello

      ```

2. IDE
   - there are many IDE for C/C++: Code::Blocks, Visual Studio Code(vsc)
   - recomnded : vsc

   1. Install VSC
   2. Essential VS Code Extensions ( trick: create hello.c then vsc auo suggests )
      - C/C++ (Microsoft) : for auto complete, errors, Debugging with GDB, defintion
      - C/C++ Themes: for themes and colors
      - CMake Tools: to manage big projects ( multiple files )
      - Code Runner (optional but handy, to run a piece of code)

3. Optional: Pro Setup
   - Highly recommended once basics are done
   - Enable warnings (makes you better fast)

   ```bash
        gcc -Wall -Wextra -Werror hello.c -o hello

   ```

4. Debugging (Important for pointers)
   1. Linux

     ```bash
     sudo apt install gdb

      # Compile with debug symbols:
      # gcc -g main.c -o main
      # gdb ./main

     ```

## Reference

- [C Programming Tutorial for Beginners](https://www.youtube.com/watch?v=KJgsSFOSQv0)
- [C++ Programming Tutorial for Beginners](https://www.youtube.com/watch?v=vLnPwxZdW4Y)
