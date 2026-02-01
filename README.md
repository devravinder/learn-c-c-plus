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
   - recommend : vsc

   1. Install VSC
   2. Essential VS Code Extensions ( trick: create hello.c then vsc auo suggests )
      - C/C++ (Microsoft) : for auto complete, errors, Debugging with GDB, defintion
      - C/C++ Themes: for themes and colors
      - CMake Tools: to manage big projects ( multiple files )
      - Code Runner (optional but handy, to run a piece of code)

   3. add run short key `Ctrl + R, Ctrl + C` (recommend to run quickly)
      1. goto keyboard shortcuts (Ctrl + K, Ctrl + S)
      2. click on json symbol (keybindings.json)
      3. add the below code:

         ```json
         {
            "key": "ctrl+r ctrl+c", // run C
            "command": "workbench.action.terminal.sendSequence",
            "args": { 
                  "text": "gcc \"${file}\" -Wall -Wextra -g -o \"${fileBasenameNoExtension}\" && \"./${fileBasenameNoExtension}\"\u000D"
               } // `\u000D` means Enter key automatically.
         },
         ```

      4. Note:- this works only after opening terminal (open terminal in bin folder )

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
