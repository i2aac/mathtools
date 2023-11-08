# mathtools
A program with tools to help out with simple math.

This program is divided into three main components.

mathtools.h contains the raw mathematical tools as functions. There is no interface; parameters are passed in and numbers are spitted out.

mathcli.h contains the command line interface for each tool as functions. Each function is meant to call a function from mathtools.h, and it is here that the user is asked to input parameters.

main.c starts the program and prompts the user to select a tool.

To compile, <math.h> needs to be linked. With gcc, run `gcc main.c -lm`.
