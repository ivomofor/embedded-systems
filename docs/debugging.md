#  Embedded Debugging

## Objective

 basics of debugging C programs with GDB.

## Topics Covered

- Compiling with GCC's `-g` debugging flag.
- Starting GDB with `gdb ./embedded_demo`.
- Displaying source code with `list`.
- Setting breakpoints with `break`.
- Starting execution with `run`.
- Inspecting variables with `print`.
- Executing source lines with `next`.
- Entering functions with `step`.
- Returning from functions with `finish`.
- Resuming execution with `continue`.
- Exiting GDB with `quit`.

## Practical 

Debugged the simulated GPIO driver.

Verified that the register changed from 0 to 1 after enabling pin 0, then to 5 after enabling pin 2.

Confirmed that attempting to enable invalid pin 8 did not change the register.

## Result

The program compiled successfully and exited normally.

## Important Note

The GPIO register is simulated in software. No physical hardware was accessed.
