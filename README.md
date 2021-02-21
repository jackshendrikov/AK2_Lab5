# AK-2 | Lab Work #5
Basic work with the Linux kernel

### Task:
> - Build an executable file and run `insmod` and `rmmod` on the BBB board (or QEMU emulator).
> - Modify the module by adding a parameter of type `uint`, which determines how many times the line *"Hello, world!"* should be printed.
>   - Default parameter value 1.
>   - If the value of parameter 0 or is between 5 and 10, print the warning and continue working.
>   - If the parameter value is greater than 10, the initialization function should print an error message and return the value `-EINVAL` (the module should not load at all).
> - Add a description of the parameter. See it with the `modinfo` command.
> - Execute `insmod` / `rmmod` of the module on the BBB board without a parameter on the command line, with the following values of parameter: 0, arbitrary between 1 and 10, arbitrary more than 10.
>   - After any of the `insmod` look at the value of the parameter.
