/*
** syscalls.c<2> for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jun 29 19:18:32 2014 Jean Fauquenot
** Last update Sun Jun 29 19:27:49 2014 Jean Fauquenot
*/

#include "syscalls.h"

t_syscall const	g_syscall[346] =
  {
    {
      "read",
      sys_read, sys_read_out,
      0, 3,
      {
	ARG_UINT,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "write",
      sys_write, NULL,
      1, 4,
      {
	ARG_UINT,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "open",
      sys_open, NULL,
      2, 5,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "close",
      NULL, NULL,
      3, 6,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "stat",
      sys_stat, sys_stat_out,
      4, 18,
      {
	ARG_CHAR_PTR,
	ARG_S_STAT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fstat",
      sys_fstat, sys_stat_out,
      5, 28,
      {
	ARG_UINT,
	ARG_S_STAT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "lstat",
      sys_stat, sys_stat_out,
      6, 84,
      {
	ARG_CHAR_PTR,
	ARG_S_STAT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "poll",
      NULL, NULL,
      7, 168,
      {
	ARG_S_POLL_FD_PTR,
	ARG_UINT,
	ARG_LONG_TIMEOUT_MSECS,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "lseek",
      NULL, NULL,
      8, 19,
      {
	ARG_UINT,
	ARG_OFF_T,
	ARG_UINT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mmap",
      sys_mmap, NULL,
      9, -1,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG
      }
    },
    {
      "mprotect",
      NULL, NULL,
      10, 125,
      {
	ARG_ULONG,
	ARG_SIZE_T,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "munmap",
      NULL, NULL,
      11, 91,
      {
	ARG_ULONG,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "brk",
      NULL, NULL,
      12, 45,
      {
	ARG_ULONG,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "rt_sigaction",
      NULL, NULL,
      13, 174,
      {
	ARG_INT,
	ARG_S_SIGACTION_PTR,
	ARG_S_SIGACTION_PTR,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "rt_sigprocmask",
      NULL, NULL,
      14, 175,
      {
	ARG_INT,
	ARG_SIGSET_T_PTR,
	ARG_SIGSET_T_PTR,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "rt_sigreturn",
      NULL, NULL,
      15, 173,
      {
	ARG_ULONG,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ioctl",
      NULL, NULL,
      16, 54,
      {
	ARG_UINT,
	ARG_UINT,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "pread64",
      NULL, NULL,
      17, -1,
      {
	ARG_ULONG,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	ARG_LOFF_T,
	NONE,
	NONE
      }
    },
    {
      "pwrite64",
      NULL, NULL,
      18, -1,
      {
	ARG_UINT,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	ARG_LOFF_T,
	NONE,
	NONE
      }
    },
    {
      "readv",
      NULL, NULL,
      19, 145,
      {
	ARG_ULONG,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "writev",
      NULL, NULL,
      20, 146,
      {
	ARG_ULONG,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "access",
      sys_access, NULL,
      21, 33,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "pipe",
      NULL, NULL,
      22, 42,
      {
	ARG_INT_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "select",
      NULL, NULL,
      23, 142,
      {
	ARG_INT,
	ARG_FD_SET_PTR,
	ARG_FD_SET_PTR,
	ARG_FD_SET_PTR,
	ARG_S_TIMEVAL_PTR,
	NONE
      }
    },
    {
      "sched_yield",
      NULL, NULL,
      24, 158,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mremap",
      NULL, NULL,
      25, 163,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE
      }
    },
    {
      "msync",
      NULL, NULL,
      26, 144,
      {
	ARG_ULONG,
	ARG_SIZE_T,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mincore",
      NULL, NULL,
      27, -1,
      {
	ARG_ULONG,
	ARG_SIZE_T,
	ARG_UCHAR_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "madvise",
      NULL, NULL,
      28, -1,
      {
	ARG_ULONG,
	ARG_SIZE_T,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "shmget",
      NULL, NULL,
      29, -1,
      {
	ARG_KEY_T,
	ARG_SIZE_T,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "shmat",
      NULL, NULL,
      30, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "shmctl",
      NULL, NULL,
      31, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_S_SHMID_DS_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "dup",
      NULL, NULL,
      32, 41,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "dup2",
      NULL, NULL,
      33, 63,
      {
	ARG_UINT,
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "pause",
      NULL, NULL,
      34, 29,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "nanosleep",
      NULL, NULL,
      35, 162,
      {
	ARG_S_TIMESPECT_PTR,
	ARG_S_TIMESPECT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getitimer",
      NULL, NULL,
      36, 105,
      {
	ARG_INT,
	ARG_S_ITIMERVAL_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "alarm",
      NULL, NULL,
      37, 27,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setitimer",
      NULL, NULL,
      38, 104,
      {
	ARG_INT,
	ARG_S_ITIMERVAL_PTR,
	ARG_S_ITIMERVAL_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getpid",
      NULL, NULL,
      39, 20,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sendfile",
      NULL, NULL,
      40, 187,
      {
	ARG_INT,
	ARG_INT,
	ARG_OFF_T,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "socket",
      NULL, NULL,
      41, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "connect",
      NULL, NULL,
      42, -1,
      {
	ARG_INT,
	ARG_S_SOCKADDR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "accept",
      NULL, NULL,
      43, -1,
      {
	ARG_INT,
	ARG_S_SOCKADDR_PTR,
	ARG_INT_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sendto",
      NULL, NULL,
      44, -1,
      {
	ARG_INT,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	ARG_UNSIGNED,
	ARG_S_SOCKADDR_PTR,
	ARG_INT
      }
    },
    {
      "recvfrom",
      NULL, NULL,
      45, -1,
      {
	ARG_INT,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	ARG_UNSIGNED,
	ARG_S_SOCKADDR_PTR,
	ARG_INT_PTR
      }
    },
    {
      "sendmsg",
      NULL, NULL,
      46, -1,
      {
	ARG_INT,
	ARG_S_MSGHDR_PTR,
	ARG_UNSIGNED,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "recvmsg",
      NULL, NULL,
      47, -1,
      {
	ARG_INT,
	ARG_S_MSGHDR_PTR,
	ARG_UINT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "shutdown",
      NULL, NULL,
      48, -1,
      {
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "bind",
      NULL, NULL,
      49, -1,
      {
	ARG_INT,
	ARG_S_SOCKADDR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "listen",
      NULL, NULL,
      50, -1,
      {
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getsockname",
      NULL, NULL,
      51, -1,
      {
	ARG_INT,
	ARG_S_SOCKADDR_PTR,
	ARG_INT_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getpeername",
      NULL, NULL,
      52, -1,
      {
	ARG_INT,
	ARG_S_SOCKADDR_PTR,
	ARG_INT_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "socketpair",
      NULL, NULL,
      53, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	ARG_INT_PTR,
	NONE,
	NONE
      }
    },
    {
      "setsockopt",
      NULL, NULL,
      54, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE
      }
    },
    {
      "getsockopt",
      NULL, NULL,
      55, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT_PTR,
	NONE
      }
    },
    {
      "clone",
      NULL, NULL,
      56, 120,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_VOID_PTR,
	ARG_VOID_PTR,
	NONE,
	NONE
      }
    },
    {
      "fork",
      NULL, NULL,
      57, 2,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "vfork",
      NULL, NULL,
      58, 190,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "execve",
      sys_execve, NULL,
      59, 11,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR_A,
	ARG_CHAR_PTR_A,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "exit",
      NULL, NULL,
      60, 1,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "wait4",
      NULL, NULL,
      61, 114,
      {
	ARG_PID_T,
	ARG_INT_PTR,
	ARG_INT,
	ARG_RUSAGE_PTR,
	NONE,
	NONE
      }
    },
    {
      "kill",
      NULL, NULL,
      62, 37,
      {
	ARG_PID_T,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "uname",
      NULL, NULL,
      63, 109,
      {
	ARG_S_OLD_UTSNAME_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "semget",
      NULL, NULL,
      64, -1,
      {
	ARG_KEY_T,
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "semop",
      NULL, NULL,
      65, -1,
      {
	ARG_INT,
	ARG_S_SEMBUF_PTR,
	ARG_UNSIGNED,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "semctl",
      NULL, NULL,
      66, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	ARG_UNION_SEMUN,
	NONE,
	NONE
      }
    },
    {
      "shmdt",
      NULL, NULL,
      67, -1,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "msgget",
      NULL, NULL,
      68, -1,
      {
	ARG_KEY_T,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "msgsnd",
      NULL, NULL,
      69, -1,
      {
	ARG_INT,
	ARG_S_MSGBUF_PTR,
	ARG_SIZE_T,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "msgrcv",
      NULL, NULL,
      70, -1,
      {
	ARG_INT,
	ARG_S_MSGBUF_PTR,
	ARG_SIZE_T,
	ARG_LONG,
	ARG_INT,
	NONE
      }
    },
    {
      "msgctl",
      NULL, NULL,
      71, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_S_MSQID_DS_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fcntl",
      NULL, NULL,
      72, 55,
      {
	ARG_UINT,
	ARG_UINT,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "flock",
      NULL, NULL,
      73, 143,
      {
	ARG_UINT,
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fsync",
      NULL, NULL,
      74, 118,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fdatasync",
      NULL, NULL,
      75, 148,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "truncate",
      NULL, NULL,
      76, 92,
      {
	ARG_CHAR_PTR,
	ARG_LONG,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ftruncate",
      NULL, NULL,
      77, 93,
      {
	ARG_UINT,
	ARG_ULONG,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getdents",
      sys_getdents, sys_getdents_out,
      78, 141,
      {
	ARG_UINT,
	ARG_S_LINUX_DIRENT_PTR,
	ARG_UINT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getcwd",
      NULL, NULL,
      79, 183,
      {
	ARG_CHAR_PTR,
	ARG_ULONG,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "chdir",
      NULL, NULL,
      80, 12,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fchdir",
      NULL, NULL,
      81, 133,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "rename",
      NULL, NULL,
      82, 38,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mkdir",
      NULL, NULL,
      83, 39,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "rmdir",
      NULL, NULL,
      84, 40,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "creat",
      NULL, NULL,
      85, 8,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "link",
      NULL, NULL,
      86, 9,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "unlink",
      NULL, NULL,
      87, 10,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "symlink",
      NULL, NULL,
      88, 83,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "readlink",
      NULL, NULL,
      89, 85,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "chmod",
      NULL, NULL,
      90, 15,
      {
	ARG_CHAR_PTR,
	ARG_MODE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fchmod",
      NULL, NULL,
      91, 94,
      {
	ARG_UINT,
	ARG_MODE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "chown",
      NULL, NULL,
      92, 182,
      {
	ARG_CHAR_PTR,
	ARG_UID_T,
	ARG_GIT_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fchown",
      NULL, NULL,
      93, 95,
      {
	ARG_UINT,
	ARG_UID_T,
	ARG_GIT_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "lchown",
      NULL, NULL,
      94, 16,
      {
	ARG_CHAR_PTR,
	ARG_UID_T,
	ARG_GIT_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "umask",
      NULL, NULL,
      95, 60,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "gettimeofday",
      NULL, NULL,
      96, 78,
      {
	ARG_S_TIMEVAL_PTR,
	ARG_S_TIMEZONE_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getrlimit",
      NULL, NULL,
      97, 76,
      {
	ARG_UINT,
	ARG_S_RLIMIT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getrusage",
      NULL, NULL,
      98, 77,
      {
	ARG_INT,
	ARG_RUSAGE_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sysinfo",
      NULL, NULL,
      99, 116,
      {
	ARG_S_SYSINFO_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "times",
      NULL, NULL,
      100, 43,
      {
	ARG_S_SYSINFO_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ptrace",
      NULL, NULL,
      101, 26,
      {
	ARG_LONG,
	ARG_LONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE,
	NONE
      }
    },
    {
      "getuid",
      NULL, NULL,
      102, 24,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "syslog",
      NULL, NULL,
      103, 103,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getgid",
      NULL, NULL,
      104, 47,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setuid",
      NULL, NULL,
      105, 23,
      {
	ARG_UID_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setgid",
      NULL, NULL,
      106, 46,
      {
	ARG_GIT_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "geteuid",
      NULL, NULL,
      107, 49,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getegid",
      NULL, NULL,
      108, 50,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setpgid",
      NULL, NULL,
      109, 57,
      {
	ARG_PID_T,
	ARG_PID_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getppid",
      NULL, NULL,
      110, 64,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getpgrp",
      NULL, NULL,
      111, 65,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setsid",
      NULL, NULL,
      112, 66,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setreuid",
      NULL, NULL,
      113, 70,
      {
	ARG_UID_T,
	ARG_UID_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setregid",
      NULL, NULL,
      114, 71,
      {
	ARG_GIT_T,
	ARG_GID_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getgroups",
      NULL, NULL,
      115, 80,
      {
	ARG_INT,
	ARG_GID_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setgroups",
      NULL, NULL,
      116, 81,
      {
	ARG_INT,
	ARG_GID_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setresuid",
      NULL, NULL,
      117, 164,
      {
	ARG_UID_T,
	ARG_UID_T,
	ARG_UID_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getresuid",
      NULL, NULL,
      118, 165,
      {
	ARG_UID_T,
	ARG_UID_T,
	ARG_UID_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setresgid",
      NULL, NULL,
      119, 170,
      {
	ARG_GID_T,
	ARG_GID_T,
	ARG_GID_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getresgid",
      NULL, NULL,
      120, 171,
      {
	ARG_GIT_T,
	ARG_GIT_T,
	ARG_GIT_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getpgid",
      NULL, NULL,
      121, 132,
      {
	ARG_PID_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setfsuid",
      NULL, NULL,
      122, 138,
      {
	ARG_UID_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setfsgid",
      NULL, NULL,
      123, 139,
      {
	ARG_GID_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getsid",
      NULL, NULL,
      124, 147,
      {
	ARG_PID_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "capget",
      NULL, NULL,
      125, 184,
      {
	ARG_CAP_USER_HEADER_T,
	ARG_CAP_USER_DATA_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "capset",
      NULL, NULL,
      126, 185,
      {
	ARG_CAP_USER_HEADER_T,
	ARG_CAP_USER_DATA_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "rt_sigpending",
      NULL, NULL,
      127, 176,
      {
	ARG_SIGSET_T_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "rt_sigtimedwait",
      NULL, NULL,
      128, 177,
      {
	ARG_SIGSET_T_PTR,
	ARG_SIGINFO_T_PTR,
	ARG_S_TIMESPECT_PTR,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "rt_sigqueueinfo",
      NULL, NULL,
      129, 178,
      {
	ARG_PID_T,
	ARG_INT,
	ARG_SIGINFO_T_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "rt_sigsuspend",
      NULL, NULL,
      130, 179,
      {
	ARG_SIGSET_T_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sigaltstack",
      NULL, NULL,
      131, 186,
      {
	ARG_STACK_T_PTR,
	ARG_STACK_T_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "utime",
      NULL, NULL,
      132, 30,
      {
	ARG_CHAR_PTR,
	ARG_S_UTIMBUF_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mknod",
      NULL, NULL,
      133, 14,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_UNSIGNED,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "uselib",
      NULL, NULL,
      134, 86,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "personality",
      NULL, NULL,
      135, 136,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ustat",
      NULL, NULL,
      136, 62,
      {
	ARG_UNSIGNED,
	ARG_S_USTAT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "statfs",
      NULL, NULL,
      137, 99,
      {
	ARG_CHAR_PTR,
	ARG_S_STATFS_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fstatfs",
      NULL, NULL,
      138, 100,
      {
	ARG_UINT,
	ARG_S_STATFS_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sysfs",
      NULL, NULL,
      139, 135,
      {
	ARG_INT,
	ARG_ULONG,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getpriority",
      NULL, NULL,
      140, 96,
      {
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setpriority",
      NULL, NULL,
      141, 97,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_setparam",
      NULL, NULL,
      142, 154,
      {
	ARG_PID_T,
	ARG_S_SCHED_PARAM_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_getparam",
      NULL, NULL,
      143, 155,
      {
	ARG_PID_T,
	ARG_S_SCHED_PARAM_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_setscheduler",
      NULL, NULL,
      144, 156,
      {
	ARG_PID_T,
	ARG_INT,
	ARG_S_SCHED_PARAM_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_getscheduler",
      NULL, NULL,
      145, 157,
      {
	ARG_PID_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_get_priority_max",
      NULL, NULL,
      146, 159,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_get_priority_min",
      NULL, NULL,
      147, 160,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_rr_get_interval",
      NULL, NULL,
      148, 161,
      {
	ARG_PID_T,
	ARG_S_TIMESPECT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mlock",
      NULL, NULL,
      149, 150,
      {
	ARG_ULONG,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "munlock",
      NULL, NULL,
      150, 151,
      {
	ARG_ULONG,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mlockall",
      NULL, NULL,
      151, 152,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "munlockall",
      NULL, NULL,
      152, 153,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "vhangup",
      NULL, NULL,
      153, 111,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "modify_ldt",
      NULL, NULL,
      154, 123,
      {
	ARG_INT,
	ARG_VOID_PTR,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "pivot_root",
      NULL, NULL,
      155, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "_sysctl",
      NULL, NULL,
      156, -1,
      {
	ARG_S___SYSCTL_ARGS_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "prctl",
      NULL, NULL,
      157, 172,
      {
	ARG_INT,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE,
	ARG_ULONG
      }
    },
    {
      "arch_prctl",
      NULL, NULL,
      158, -1,
      {
	ARG_S_TASK_STRUCT_PTR,
	ARG_INT,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "adjtimex",
      NULL, NULL,
      159, 124,
      {
	ARG_S_TIMEX_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setrlimit",
      NULL, NULL,
      160, 75,
      {
	ARG_UINT,
	ARG_S_RLIMIT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "chroot",
      NULL, NULL,
      161, 61,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sync",
      NULL, NULL,
      162, 36,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "acct",
      NULL, NULL,
      163, 51,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "settimeofday",
      NULL, NULL,
      164, 79,
      {
	ARG_S_TIMEVAL_PTR,
	ARG_S_TIMEZONE_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mount",
      NULL, NULL,
      165, 21,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_ULONG,
	ARG_VOID_PTR,
	NONE
      }
    },
    {
      "umount2",
      NULL, NULL,
      166, -1,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "swapon",
      NULL, NULL,
      167, 87,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "swapoff",
      NULL, NULL,
      168, 115,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "reboot",
      NULL, NULL,
      169, 88,
      {
	ARG_INT,
	ARG_INT,
	ARG_UINT,
	ARG_VOID_PTR,
	NONE,
	NONE
      }
    },
    {
      "sethostname",
      NULL, NULL,
      170, 74,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setdomainname",
      NULL, NULL,
      171, 121,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "iopl",
      NULL, NULL,
      172, 110,
      {
	ARG_UINT,
	ARG_S_PT_REGS_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ioperm",
      NULL, NULL,
      173, 101,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "create_module",
      NULL, NULL,
      174, 127,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "init_module",
      NULL, NULL,
      175, 128,
      {
	ARG_VOID_PTR,
	ARG_ULONG,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "delete_module",
      NULL, NULL,
      176, 129,
      {
	ARG_CHAR_PTR,
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "get_kernel_syms",
      NULL, NULL,
      177, 130,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "query_module",
      NULL, NULL,
      178, 167,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "quotactl",
      NULL, NULL,
      179, 131,
      {
	ARG_UINT,
	ARG_CHAR_PTR,
	ARG_QID_T,
	ARG_VOID_PTR,
	NONE,
	NONE
      }
    },
    {
      "nfsservctl",
      NULL, NULL,
      180, 169,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getpmsg",
      NULL, NULL,
      181, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "putpmsg",
      NULL, NULL,
      182, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "afs_syscall",
      NULL, NULL,
      183, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "tuxcall",
      NULL, NULL,
      184, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "security",
      NULL, NULL,
      185, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "gettid",
      NULL, NULL,
      186, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "readahead",
      NULL, NULL,
      187, -1,
      {
	ARG_INT,
	ARG_LOFF_T,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "setxattr",
      NULL, NULL,
      188, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	ARG_INT,
	NONE
      }
    },
    {
      "lsetxattr",
      NULL, NULL,
      189, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	ARG_INT,
	NONE
      }
    },
    {
      "fsetxattr",
      NULL, NULL,
      190, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	ARG_INT,
	NONE
      }
    },
    {
      "getxattr",
      NULL, NULL,
      191, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "lgetxattr",
      NULL, NULL,
      192, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "fgetxattr",
      NULL, NULL,
      193, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "listxattr",
      NULL, NULL,
      194, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "llistxattr",
      NULL, NULL,
      195, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "flistxattr",
      NULL, NULL,
      196, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "removexattr",
      NULL, NULL,
      197, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "lremovexattr",
      NULL, NULL,
      198, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fremovexattr",
      NULL, NULL,
      199, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "tkill",
      NULL, NULL,
      200, -1,
      {
	ARG_PID_T,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "time",
      NULL, NULL,
      201, 13,
      {
	ARG_TIME_T_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "futex",
      NULL, NULL,
      202, -1,
      {
	ARG_U32_PTR,
	ARG_INT,
	ARG_U32D,
	ARG_S_TIMESPECT_PTR,
	ARG_U32_PTR,
	ARG_U32D
      }
    },
    {
      "sched_setaffinity",
      NULL, NULL,
      203, -1,
      {
	ARG_PID_T,
	ARG_UINT,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sched_getaffinity",
      NULL, NULL,
      204, -1,
      {
	ARG_PID_T,
	ARG_UINT,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "set_thread_area",
      NULL, NULL,
      205, 243,
      {
	ARG_VOID_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "io_setup",
      NULL, NULL,
      206, -1,
      {
	ARG_UNSIGNED,
	ARG_AIO_CONTEXT_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "io_destroy",
      NULL, NULL,
      207, -1,
      {
	ARG_AIO_CONTEXT_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "io_getevents",
      NULL, NULL,
      208, -1,
      {
	ARG_AIO_CONTEXT_T,
	ARG_LONG,
	ARG_LONG,
	ARG_S_IO_EVENT_PTR,
	NONE,
	NONE
      }
    },
    {
      "io_submit",
      NULL, NULL,
      209, -1,
      {
	ARG_AIO_CONTEXT_T,
	ARG_LONG,
	ARG_S_IOCB_PTR_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "io_cancel",
      NULL, NULL,
      210, -1,
      {
	ARG_AIO_CONTEXT_T,
	ARG_S_IOCB_PTR,
	ARG_S_IO_EVENT_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "get_thread_area",
      NULL, NULL,
      211, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "lookup_dcookie",
      NULL, NULL,
      212, -1,
      {
	ARG_U64D,
	ARG_LONG,
	ARG_LONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "epoll_create",
      NULL, NULL,
      213, -1,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "epoll_ctl_old",
      NULL, NULL,
      214, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "epoll_wait_old",
      NULL, NULL,
      215, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "remap_file_pages",
      NULL, NULL,
      216, -1,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE
      }
    },
    {
      "getdents64",
      NULL, NULL,
      217, -1,
      {
	ARG_UINT,
	ARG_S_LINUX_DIRENT64_PTR,
	ARG_UINT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "set_tid_address",
      NULL, NULL,
      218, -1,
      {
	ARG_INT_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "restart_syscall",
      NULL, NULL,
      219, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "semtimedop",
      NULL, NULL,
      220, -1,
      {
	ARG_INT,
	ARG_S_SEMBUF_PTR,
	ARG_UNSIGNED,
	ARG_S_TIMESPECT_PTR,
	NONE,
	NONE
      }
    },
    {
      "fadvise64",
      NULL, NULL,
      221, -1,
      {
	ARG_INT,
	ARG_LOFF_T,
	ARG_SIZE_T,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "timer_create",
      NULL, NULL,
      222, -1,
      {
	ARG_CLOCKID_T,
	ARG_S_SIGEVENT_PTR,
	ARG_TIMER_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "timer_settime",
      NULL, NULL,
      223, -1,
      {
	ARG_TIMER_T,
	ARG_INT,
	ARG_S_ITIMERSPEC_PTR,
	ARG_S_ITIMERSPEC_PTR,
	NONE,
	NONE
      }
    },
    {
      "timer_gettime",
      NULL, NULL,
      224, -1,
      {
	ARG_TIMER_T,
	ARG_S_ITIMERSPEC_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "timer_getoverrun",
      NULL, NULL,
      225, -1,
      {
	ARG_TIMER_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "timer_delete",
      NULL, NULL,
      226, -1,
      {
	ARG_TIMER_T,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "clock_settime",
      NULL, NULL,
      227, -1,
      {
	ARG_CLOCKID_T,
	ARG_S_TIMESPECT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "clock_gettime",
      NULL, NULL,
      228, -1,
      {
	ARG_CLOCKID_T,
	ARG_S_TIMESPECT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "clock_getres",
      NULL, NULL,
      229, -1,
      {
	ARG_CLOCKID_T,
	ARG_S_TIMESPECT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "clock_nanosleep",
      NULL, NULL,
      230, -1,
      {
	ARG_CLOCKID_T,
	ARG_INT,
	ARG_S_TIMESPECT_PTR,
	ARG_S_TIMESPECT_PTR,
	NONE,
	NONE
      }
    },
    {
      "exit_group",
      NULL, NULL,
      231, 252,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "epoll_wait",
      NULL, NULL,
      232, -1,
      {
	ARG_INT,
	ARG_S_EPOLL_EVENT_PTR,
	ARG_INT,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "epoll_ctl",
      NULL, NULL,
      233, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	ARG_S_EPOLL_EVENT_PTR,
	NONE,
	NONE
      }
    },
    {
      "tgkill",
      NULL, NULL,
      234, -1,
      {
	ARG_PID_T,
	ARG_PID_T,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "utimes",
      NULL, NULL,
      235, -1,
      {
	ARG_CHAR_PTR,
	ARG_S_TIMEVAL_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "vserver",
      NULL, NULL,
      236, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mbind",
      NULL, NULL,
      237, -1,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_UNSIGNED
      }
    },
    {
      "set_mempolicy",
      NULL, NULL,
      238, -1,
      {
	ARG_INT,
	ARG_ULONG,
	ARG_ULONG,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "get_mempolicy",
      NULL, NULL,
      239, -1,
      {
	ARG_INT_PTR,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE
      }
    },
    {
      "mq_open",
      NULL, NULL,
      240, -1,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_MODE_T,
	ARG_S_MQ_ATTR_PTR,
	NONE,
	NONE
      }
    },
    {
      "mq_unlink",
      NULL, NULL,
      241, -1,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mq_timedsend",
      NULL, NULL,
      242, -1,
      {
	ARG_MQD_T,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	ARG_UINT,
	ARG_S_TIMESPECT_PTR,
	NONE
      }
    },
    {
      "mq_timedreceive",
      NULL, NULL,
      243, -1,
      {
	ARG_MQD_T,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	ARG_UINT,
	ARG_S_TIMESPECT_PTR,
	NONE
      }
    },
    {
      "mq_notify",
      NULL, NULL,
      244, -1,
      {
	ARG_MQD_T,
	ARG_S_SIGEVENT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mq_getsetattr",
      NULL, NULL,
      245, -1,
      {
	ARG_MQD_T,
	ARG_S_MQ_ATTR_PTR,
	ARG_S_MQ_ATTR_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "kexec_load",
      NULL, NULL,
      246, -1,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_S_KEXEC_SEGMENT_PTR,
	ARG_ULONG,
	NONE,
	NONE
      }
    },
    {
      "waitid",
      NULL, NULL,
      247, -1,
      {
	ARG_INT,
	ARG_PID_T,
	ARG_S_SIGINFO_PTR,
	ARG_INT,
	ARG_RUSAGE_PTR,
	NONE
      }
    },
    {
      "add_key",
      NULL, NULL,
      248, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_VOID_PTR,
	ARG_SIZE_T,
	NONE,
	NONE
      }
    },
    {
      "request_key",
      NULL, NULL,
      249, -1,
      {
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_KEY_SERIAL_T,
	NONE,
	NONE
      }
    },
    {
      "keyctl",
      NULL, NULL,
      250, -1,
      {
	ARG_INT,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE
      }
    },
    {
      "ioprio_set",
      NULL, NULL,
      251, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ioprio_get",
      NULL, NULL,
      252, -1,
      {
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "inotify_init",
      NULL, NULL,
      253, -1,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "inotify_add_watch",
      NULL, NULL,
      254, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_U32D,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "inotify_rm_watch",
      NULL, NULL,
      255, -1,
      {
	ARG_INT,
	ARG___S32D,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "migrate_pages",
      NULL, NULL,
      256, -1,
      {
	ARG_PID_T,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE,
	NONE
      }
    },
    {
      "openat",
      sys_openat, NULL,
      257, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "mkdirat",
      NULL, NULL,
      258, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mknodat",
      NULL, NULL,
      259, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_UNSIGNED,
	NONE,
	NONE
      }
    },
    {
      "fchownat",
      NULL, NULL,
      260, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_UID_T,
	ARG_GID_T,
	ARG_INT,
	NONE
      }
    },
    {
      "futimesat",
      NULL, NULL,
      261, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_S_TIMEVAL_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "newfstatat",
      NULL, NULL,
      262, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_S_STAT,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "unlinkat",
      NULL, NULL,
      263, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "renameat",
      NULL, NULL,
      264, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_CHAR_PTR,
	NONE,
	NONE
      }
    },
    {
      "linkat",
      NULL, NULL,
      265, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE
      }
    },
    {
      "symlinkat",
      NULL, NULL,
      266, -1,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "readlinkat",
      NULL, NULL,
      267, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "fchmodat",
      NULL, NULL,
      268, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_MODE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "faccessat",
      NULL, NULL,
      269, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "pselect6",
      NULL, NULL,
      270, -1,
      {
	ARG_INT,
	ARG_FD_SET_PTR,
	ARG_FD_SET_PTR,
	ARG_FD_SET_PTR,
	ARG_S_TIMESPECT_PTR,
	ARG_VOID_PTR
      }
    },
    {
      "ppoll",
      NULL, NULL,
      271, -1,
      {
	ARG_S_POLL_FD_PTR,
	ARG_UINT,
	ARG_S_TIMESPECT_PTR,
	ARG_SIGSET_T_PTR,
	ARG_SIZE_T,
	NONE
      }
    },
    {
      "unshare",
      NULL, NULL,
      272, -1,
      {
	ARG_ULONG,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "set_robust_list",
      NULL, NULL,
      273, -1,
      {
	ARG_S_ROBUST_LIST_HEAD_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "get_robust_list",
      NULL, NULL,
      274, -1,
      {
	ARG_INT,
	ARG_S_ROBUST_LIST_HEAD_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "splice",
      NULL, NULL,
      275, -1,
      {
	ARG_INT,
	ARG_LOFF_T,
	ARG_INT,
	ARG_LOFF_T,
	ARG_SIZE_T,
	ARG_UINT
      }
    },
    {
      "tee",
      NULL, NULL,
      276, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_SIZE_T,
	ARG_UINT,
	NONE,
	NONE
      }
    },
    {
      "sync_file_range",
      NULL, NULL,
      277, -1,
      {
	ARG_LONG,
	ARG_LOFF_T,
	ARG_LOFF_T,
	ARG_LONG,
	NONE,
	NONE
      }
    },
    {
      "vmsplice",
      NULL, NULL,
      278, -1,
      {
	ARG_INT,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	ARG_UINT,
	NONE,
	NONE
      }
    },
    {
      "move_pages",
      NULL, NULL,
      279, -1,
      {
	ARG_PID_T,
	ARG_ULONG,
	ARG_VOID_PTR,
	ARG_INT_PTR,
	ARG_INT_PTR,
	ARG_INT
      }
    },
    {
      "utimensat",
      NULL, NULL,
      280, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_S_TIMESPECT_PTR,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "epoll_pwait",
      NULL, NULL,
      281, -1,
      {
	ARG_INT,
	ARG_S_EPOLL_EVENT_PTR,
	ARG_INT,
	ARG_INT,
	ARG_SIGSET_T_PTR,
	ARG_SIZE_T
      }
    },
    {
      "signalfd",
      NULL, NULL,
      282, -1,
      {
	ARG_INT,
	ARG_SIGSET_T_PTR,
	ARG_SIZE_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "timerfd_create",
      NULL, NULL,
      283, -1,
      {
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "eventfd",
      NULL, NULL,
      284, -1,
      {
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fallocate",
      NULL, NULL,
      285, -1,
      {
	ARG_LONG,
	ARG_LONG,
	ARG_LOFF_T,
	ARG_LOFF_T,
	NONE,
	NONE
      }
    },
    {
      "timerfd_settime",
      NULL, NULL,
      286, -1,
      {
	ARG_INT,
	ARG_INT,
	ARG_S_ITIMERSPEC_PTR,
	ARG_S_ITIMERSPEC_PTR,
	NONE,
	NONE
      }
    },
    {
      "timerfd_gettime",
      NULL, NULL,
      287, -1,
      {
	ARG_INT,
	ARG_S_ITIMERSPEC_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "accept4",
      NULL, NULL,
      288, -1,
      {
	ARG_INT,
	ARG_S_SOCKADDR_PTR,
	ARG_INT_PTR,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "signalfd4",
      NULL, NULL,
      289, -1,
      {
	ARG_INT,
	ARG_SIGSET_T_PTR,
	ARG_SIZE_T,
	ARG_INT,
	NONE,
	NONE
      }
    },
    {
      "eventfd2",
      NULL, NULL,
      290, -1,
      {
	ARG_UINT,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "epoll_create1",
      NULL, NULL,
      291, -1,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "dup3",
      NULL, NULL,
      292, -1,
      {
	ARG_UINT,
	ARG_UINT,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "pipe2",
      NULL, NULL,
      293, -1,
      {
	ARG_INT_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "inotify_init1",
      NULL, NULL,
      294, -1,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "preadv",
      NULL, NULL,
      295, -1,
      {
	ARG_ULONG,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE
      }
    },
    {
      "pwritev",
      NULL, NULL,
      296, -1,
      {
	ARG_ULONG,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	NONE
      }
    },
    {
      "rt_tgsigqueueinfo",
      NULL, NULL,
      297, -1,
      {
	ARG_PID_T,
	ARG_PID_T,
	ARG_INT,
	ARG_SIGINFO_T_PTR,
	NONE,
	NONE
      }
    },
    {
      "perf_event_open",
      NULL, NULL,
      298, -1,
      {
	ARG_S_PERF_EVENT_ATTR_PTR,
	ARG_PID_T,
	ARG_INT,
	ARG_INT,
	ARG_ULONG,
	NONE
      }
    },
    {
      "recvmmsg",
      NULL, NULL,
      299, -1,
      {
	ARG_INT,
	ARG_S_MSGHDR_PTR,
	ARG_UINT,
	ARG_UINT,
	ARG_S_TIMESPECT_PTR,
	NONE
      }
    },
    {
      "fanotify_init",
      NULL, NULL,
      300, -1,
      {
	ARG_UINT,
	ARG_UINT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fanotify_mark",
      NULL, NULL,
      301, -1,
      {
	ARG_LONG,
	ARG_LONG,
	ARG___U64D,
	ARG_LONG,
	ARG_LONG,
	NONE
      }
    },
    {
      "prlimit64",
      NULL, NULL,
      302, -1,
      {
	ARG_PID_T,
	ARG_UINT,
	ARG_S_RLIMIT64_PTR,
	ARG_S_RLIMIT64_PTR,
	NONE,
	NONE
      }
    },
    {
      "name_to_handle_at",
      NULL, NULL,
      303, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_S_FILE_HANDLE_PTR,
	ARG_INT_PTR,
	ARG_INT,
	NONE
      }
    },
    {
      "open_by_handle_at",
      NULL, NULL,
      304, -1,
      {
	ARG_INT,
	ARG_CHAR_PTR,
	ARG_S_FILE_HANDLE_PTR,
	ARG_INT_PTR,
	ARG_INT,
	NONE
      }
    },
    {
      "clock_adjtime",
      NULL, NULL,
      305, -1,
      {
	ARG_CLOCKID_T,
	ARG_S_TIMEX_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "syncfs",
      NULL, NULL,
      306, -1,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sendmmsg",
      NULL, NULL,
      307, -1,
      {
	ARG_INT,
	ARG_MMSGHDR_PTR,
	ARG_UINT,
	ARG_UINT,
	NONE,
	NONE
      }
    },
    {
      "setns",
      NULL, NULL,
      308, -1,
      {
	ARG_INT,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "getcpu",
      NULL, NULL,
      309, -1,
      {
	ARG_UNSIGNED,
	ARG_UNSIGNED,
	ARG_S_GETCPU_CACHE_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "process_vm_readv",
      NULL, NULL,
      310, -1,
      {
	ARG_PID_T,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	ARG_ULONG
      }
    },
    {
      "process_vm_writev",
      NULL, NULL,
      311, -1,
      {
	ARG_PID_T,
	ARG_S_IOVEC_PTR,
	ARG_ULONG,
	ARG_STRUCT_IOVCC_PTR,
	ARG_ULONG,
	ARG_ULONG
      }
    },
    {
      "waitpid",
      NULL, NULL,
      -1, 7,
      {
	ARG_PID_T,
	ARG_UINT_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "oldumount",
      NULL, NULL,
      -1, 22,
      {
	ARG_CHAR_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "stime",
      NULL, NULL,
      -1, 25,
      {
	ARG_INT_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "nice",
      NULL, NULL,
      -1, 34,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "signal",
      NULL, NULL,
      -1, 48,
      {
	ARG_INT,
	ARG_SIGHANDLER_T,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "umount",
      NULL, NULL,
      -1, 52,
      {
	ARG_CHAR_PTR,
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "olduname",
      NULL, NULL,
      -1, 59,
      {
	ARG_S_OLDOLD_UTSNAME_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sigaction",
      NULL, NULL,
      -1, 67,
      {
	ARG_INT,
	S_OLD_SIGACTION_PTR,
	S_OLD_SIGACTION_PTR,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sgetmask",
      NULL, NULL,
      -1, 68,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ssetmask",
      NULL, NULL,
      -1, 69,
      {
	ARG_INT,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sigsuspend",
      NULL, NULL,
      -1, 72,
      {
	ARG_INT,
	ARG_INT,
	ARG_OLD_SIGSET_T,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sigpending",
      NULL, NULL,
      -1, 73,
      {
	ARG_OLD_SIGSET_T_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "select",
      NULL, NULL,
      -1, 82,
      {
	ARG_INT,
	ARG_FD_SET_PTR,
	ARG_FD_SET_PTR,
	ARG_FD_SET_PTR,
	ARG_S_TIMEVAL_PTR,
	NONE
      }
    },
    {
      "readdir",
      NULL, NULL,
      -1, 89,
      {
	ARG_UINT,
	ARG_VOID_PTR,
	ARG_UINT,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "mmap",
      NULL, NULL,
      -1, 90,
      {
	ARG_S_MMAP_ARG_STRUCT_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "socketcall",
      NULL, NULL,
      -1, 102,
      {
	ARG_INT,
	ARG_ULONG_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "newstat",
      NULL, NULL,
      -1, 106,
      {
	ARG_CHAR_PTR,
	ARG_S_STAT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "newlstat",
      NULL, NULL,
      -1, 107,
      {
	ARG_CHAR_PTR,
	ARG_S_STAT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "newfstat",
      NULL, NULL,
      -1, 108,
      {
	ARG_UINT,
	ARG_S_STAT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "idle",
      NULL, NULL,
      -1, 112,
      {
	NONE,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "vm86old",
      NULL, NULL,
      -1, 113,
      {
	ARG_ULONG,
	ARG_S_VM86PLUS_STRUCT_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "ipc",
      NULL, NULL,
      -1, 117,
      {
	ARG_UINT,
	ARG_INT,
	ARG_INT,
	ARG_INT,
	ARG_VOID_PTR,
	NONE
      }
    },
    {
      "sigreturn",
      NULL, NULL,
      -1, 119,
      {
	ARG_ULONG,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "newuname",
      NULL, NULL,
      -1, 122,
      {
	ARG_S_NEW_UTSNAME_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "sigprocmask",
      NULL, NULL,
      -1, 126,
      {
	ARG_INT,
	ARG_OLD_SIGSET_T_PTR,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "bdflush",
      NULL, NULL,
      -1, 134,
      {
	ARG_INT,
	ARG_LONG,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "llseek",
      NULL, NULL,
      -1, 140,
      {
	ARG_UINT,
	ARG_ULONG,
	ARG_ULONG,
	ARG_LOFF_T_PTR,
	ARG_UINT,
	NONE
      }
    },
    {
      "sysctl",
      NULL, NULL,
      -1, 149,
      {
	ARG_S___SYSCTL_ARGS_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "vm86",
      NULL, NULL,
      -1, 166,
      {
	ARG_S_VM86_STRUCT_PTR,
	NONE,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "pread",
      NULL, NULL,
      -1, 180,
      {
	ARG_UINT,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	ARG_LOFF_T,
	NONE,
	NONE
      }
    },
    {
      "pwrite",
      NULL, NULL,
      -1, 181,
      {
	ARG_UINT,
	ARG_CHAR_PTR,
	ARG_SIZE_T,
	ARG_LOFF_T,
	NONE,
	NONE
      }
    },
    {
      "mmap2",
      NULL, NULL,
      -1, 192,
      {
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG,
	ARG_ULONG
      }
    },
    {
      "stat64",
      NULL, NULL,
      -1, 195,
      {
	ARG_CHAR_PTR,
	ARG_S_STAT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    },
    {
      "fstat64",
      NULL, NULL,
      -1, 197,
      {
	ARG_UINT,
	ARG_S_STAT,
	NONE,
	NONE,
	NONE,
	NONE
      }
    }
  };
