# Job Control using the Terminal

> content based [on here](http://linuxcommand.org/lc3_lts0100.php) seems useful

This is to explore the miltitasking nature of Linux and how this is manipulated using the CLI

Linux executes multiple, simultanious processes.

- They appear simultaneous but a sungle processor pc can only execute one program at a time
- The Linux Kernel can give each process its turn at the processor, and can appear to be running at the same time.

To contol proceeses
- `ps` - list process running
- `kill` - send a signal to one or more processes (often to "kill" it)
- `jobs` - list process running
- `bg` - put a process in the background
- `fg` - put a process in the foreground


> use `man` to see more about it

---

## Putting program in the background

> add an `&` to send processes into the background

OR

> type `ctrl+z` to suspend (although the process is idle)
> - then enter `bg` to resume the process in the background

## Killing a process

suppose there is an unresponsive process you want to end manually

you can either

- use `jobs` to list the process and `kill %id` to end the process
- use `ps` to list processes and `kill id` to end the process
