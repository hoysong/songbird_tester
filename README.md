# Songbird Tester

[English](./README.md) | [한국어](./README.ko.md)

## Overview

Songbird Tester is a collection of lightweight test utilities created while
working through several projects in the 42 curriculum. The tools automate
repetitive checks during development so that failures can be reproduced and
inspected without repeatedly entering the same commands by hand.

The repository includes utilities for comparing program output, exercising
multiple buffer sizes, checking memory with Valgrind, sending scripted input
and signals to Minishell, and running Cub3D parser cases.

## Included Tools

| Tool | Purpose |
| --- | --- |
| `get_next_line_tester/` | Compiles and runs Get Next Line with multiple `BUFFER_SIZE` values, compares output, checks Valgrind results, and runs Norminette |
| `minishell_test_builder_1.5/` | Builds scripted Minishell test input and compares Bash and Minishell behavior by file descriptor |
| `cub3d_pars_tester/` | Runs Cub3D parser cases from configurable map directories, with optional Valgrind checks |
| `compile.sh` | Runs a small set of Push Swap cases, counts operations, invokes `checker_linux`, and checks execution with Valgrind |

## Requirements

The individual tools use different parts of the following environment:

- Linux or a compatible shell environment
- Bash
- A C compiler such as `cc` or `clang`
- GNU Make
- Valgrind
- Norminette for the Get Next Line style check
- The target 42 project and its required source files

Some scripts use relative paths and project-specific executable names. Review
the configuration variables near the top or bottom of each script before
running it.

## Usage

Clone the repository into or next to the target project, depending on the
relative paths expected by the selected tester.

```bash
git clone https://github.com/hoysong/songbird_tester.git
```

### Get Next Line

The Get Next Line tester expects `get_next_line.c`,
`get_next_line_utils.c`, and `get_next_line.h` at the relative paths
configured in its scripts.

```bash
cd get_next_line_tester
bash run.sh
```

It compiles the implementation with `BUFFER_SIZE` values from 1 through 12,
compares the generated output with expected files, checks Valgrind logs, and
reports Norminette errors. Detailed mismatches are recorded in the generated
`trace` file.

### Minishell Test Builder

Edit `minishell_test_builder_1.5/main.c` to define the input sequence to send
to the target shell, then build the test program.

```bash
cd minishell_test_builder_1.5
bash compile.sh
./a.out
```

The test builder can compare Bash and Minishell output by file descriptor and
can send `SIGINT` and `SIGQUIT` during scripted scenarios.

### Cub3D Parser Tester

Set `prog_name` and the test directories in
`cub3d_pars_tester/test.sh`, then run:

```bash
cd cub3d_pars_tester
bash test.sh
```

The script can run parser cases normally or through Valgrind. Map validity
rules may differ between implementations, so the supplied cases should be
reviewed and adjusted for the target parser.

### Push Swap Quick Check

The root `compile.sh` assumes a specific project layout, including
`my_libft/libft.a`, and uses the included Linux checker.

```bash
bash compile.sh
```

Update the compiler command and test arguments when the target project uses a
different layout.

## Scope and Limitations

These tools are development aids, not authoritative project validators. They
are designed to automate frequent checks while keeping the tester itself
small enough that work can remain focused on the main project.

The Get Next Line tester does not impose an execution timeout. If a case runs
for an unusually long time, inspect the target implementation for a possible
infinite loop and terminate the process manually. This is an intentional scope
limit rather than an automatic diagnosis.

Test cases and expected behavior may also need adjustment for differences
between implementations. Use an independent tester or manual verification
when final, exhaustive validation is required.
