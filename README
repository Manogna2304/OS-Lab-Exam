# MA3105 – Operating System Lab Examination
## Set 2

**Name:** Manogna  
**Roll Number:** 2401MC46  
**Course:** MA3105 – Operating System Lab  
**Platform:** xv6-public (x86) with QEMU  
**CPU Configuration:** CPUS=1

---

## Question 1: Page Protection using mprotect() and munprotect()

1. Modified `vm.c` to implement a helper function `protect_range()` that accesses page-table entries using `walkpgdir()`.
2. Modified `defs.h` to declare the page protection helper function.
3. Implemented `sys_mprotect()` and `sys_munprotect()` in `sysproc.c` to change page permissions using the `PTE_W` bit.
4. Registered both system calls in `syscall.h`, `syscall.c`, `user.h`, and `usys.S`.
5. Implemented `prottest.c` to test read-only protection, child-process write protection, restoring write permissions, and invalid arguments.

## Question 2: Priority-Based CPU Scheduler

1. Modified `proc.h` by adding an integer field `priority` to `struct proc`.
2. Modified `proc.c` to initialize every new process with priority 10 in `allocproc()`.
3. Replaced the round-robin selection logic in `scheduler()` with priority-based scheduling, selecting the RUNNABLE process with the smallest priority number.
4. Implemented `set_priority()` in `proc.c` to search the process table under `ptable.lock`, update the process priority, and return its previous priority.
5. Implemented `sys_set_priority()` in `sysproc.c` and registered the system call in the required system-call files.
6. Created `schedtest.c` to test scheduling using three child processes with priorities 5, 10, and 15.

## Compilation and Execution

The project was compiled and executed using:

```bash
make clean
make qemu-nox CPUS=1
```

The test programs are executed from the xv6 shell:

```bash
prottest
schedtest
```

## Submission Contents

- Complete modified xv6 source directory.
- `prottest.c` – Question 1 test program.
- `schedtest.c` – Question 2 test program.
- Modified kernel and system-call source files.
- `Q1_output` – Question 1 execution evidence.
- `Q2_output` – Question 2 execution evidence.
- `README.txt` – Implementation details and execution instructions.
