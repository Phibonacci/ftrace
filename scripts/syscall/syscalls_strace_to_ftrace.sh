#!/bin/bash

cat strace_syscalls.c | sed '/",/{n; /$/d}' | sed '/      {/,+7d' > syscalls.c
