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
      0, 3,
    },
    {
      "write",
      1, 4,
    },
    {
      "open",
      2, 5,
    },
    {
      "close",
      3, 6,
    },
    {
      "stat",
      4, 18,
    },
    {
      "fstat",
      5, 28,
    },
    {
      "lstat",
      6, 84,
    },
    {
      "poll",
      7, 168,
    },
    {
      "lseek",
      8, 19,
    },
    {
      "mmap",
      9, -1,
    },
    {
      "mprotect",
      10, 125,
    },
    {
      "munmap",
      11, 91,
    },
    {
      "brk",
      12, 45,
    },
    {
      "rt_sigaction",
      13, 174,
    },
    {
      "rt_sigprocmask",
      14, 175,
    },
    {
      "rt_sigreturn",
      15, 173,
    },
    {
      "ioctl",
      16, 54,
    },
    {
      "pread64",
      17, -1,
    },
    {
      "pwrite64",
      18, -1,
    },
    {
      "readv",
      19, 145,
    },
    {
      "writev",
      20, 146,
    },
    {
      "access",
      21, 33,
    },
    {
      "pipe",
      22, 42,
    },
    {
      "select",
      23, 142,
    },
    {
      "sched_yield",
      24, 158,
    },
    {
      "mremap",
      25, 163,
    },
    {
      "msync",
      26, 144,
    },
    {
      "mincore",
      27, -1,
    },
    {
      "madvise",
      28, -1,
    },
    {
      "shmget",
      29, -1,
    },
    {
      "shmat",
      30, -1,
    },
    {
      "shmctl",
      31, -1,
    },
    {
      "dup",
      32, 41,
    },
    {
      "dup2",
      33, 63,
    },
    {
      "pause",
      34, 29,
    },
    {
      "nanosleep",
      35, 162,
    },
    {
      "getitimer",
      36, 105,
    },
    {
      "alarm",
      37, 27,
    },
    {
      "setitimer",
      38, 104,
    },
    {
      "getpid",
      39, 20,
    },
    {
      "sendfile",
      40, 187,
    },
    {
      "socket",
      41, -1,
    },
    {
      "connect",
      42, -1,
    },
    {
      "accept",
      43, -1,
    },
    {
      "sendto",
      44, -1,
    },
    {
      "recvfrom",
      45, -1,
    },
    {
      "sendmsg",
      46, -1,
    },
    {
      "recvmsg",
      47, -1,
    },
    {
      "shutdown",
      48, -1,
    },
    {
      "bind",
      49, -1,
    },
    {
      "listen",
      50, -1,
    },
    {
      "getsockname",
      51, -1,
    },
    {
      "getpeername",
      52, -1,
    },
    {
      "socketpair",
      53, -1,
    },
    {
      "setsockopt",
      54, -1,
    },
    {
      "getsockopt",
      55, -1,
    },
    {
      "clone",
      56, 120,
    },
    {
      "fork",
      57, 2,
    },
    {
      "vfork",
      58, 190,
    },
    {
      "execve",
      59, 11,
    },
    {
      "exit",
      60, 1,
    },
    {
      "wait4",
      61, 114,
    },
    {
      "kill",
      62, 37,
    },
    {
      "uname",
      63, 109,
    },
    {
      "semget",
      64, -1,
    },
    {
      "semop",
      65, -1,
    },
    {
      "semctl",
      66, -1,
    },
    {
      "shmdt",
      67, -1,
    },
    {
      "msgget",
      68, -1,
    },
    {
      "msgsnd",
      69, -1,
    },
    {
      "msgrcv",
      70, -1,
    },
    {
      "msgctl",
      71, -1,
    },
    {
      "fcntl",
      72, 55,
    },
    {
      "flock",
      73, 143,
    },
    {
      "fsync",
      74, 118,
    },
    {
      "fdatasync",
      75, 148,
    },
    {
      "truncate",
      76, 92,
    },
    {
      "ftruncate",
      77, 93,
    },
    {
      "getdents",
      78, 141,
    },
    {
      "getcwd",
      79, 183,
    },
    {
      "chdir",
      80, 12,
    },
    {
      "fchdir",
      81, 133,
    },
    {
      "rename",
      82, 38,
    },
    {
      "mkdir",
      83, 39,
    },
    {
      "rmdir",
      84, 40,
    },
    {
      "creat",
      85, 8,
    },
    {
      "link",
      86, 9,
    },
    {
      "unlink",
      87, 10,
    },
    {
      "symlink",
      88, 83,
    },
    {
      "readlink",
      89, 85,
    },
    {
      "chmod",
      90, 15,
    },
    {
      "fchmod",
      91, 94,
    },
    {
      "chown",
      92, 182,
    },
    {
      "fchown",
      93, 95,
    },
    {
      "lchown",
      94, 16,
    },
    {
      "umask",
      95, 60,
    },
    {
      "gettimeofday",
      96, 78,
    },
    {
      "getrlimit",
      97, 76,
    },
    {
      "getrusage",
      98, 77,
    },
    {
      "sysinfo",
      99, 116,
    },
    {
      "times",
      100, 43,
    },
    {
      "ptrace",
      101, 26,
    },
    {
      "getuid",
      102, 24,
    },
    {
      "syslog",
      103, 103,
    },
    {
      "getgid",
      104, 47,
    },
    {
      "setuid",
      105, 23,
    },
    {
      "setgid",
      106, 46,
    },
    {
      "geteuid",
      107, 49,
    },
    {
      "getegid",
      108, 50,
    },
    {
      "setpgid",
      109, 57,
    },
    {
      "getppid",
      110, 64,
    },
    {
      "getpgrp",
      111, 65,
    },
    {
      "setsid",
      112, 66,
    },
    {
      "setreuid",
      113, 70,
    },
    {
      "setregid",
      114, 71,
    },
    {
      "getgroups",
      115, 80,
    },
    {
      "setgroups",
      116, 81,
    },
    {
      "setresuid",
      117, 164,
    },
    {
      "getresuid",
      118, 165,
    },
    {
      "setresgid",
      119, 170,
    },
    {
      "getresgid",
      120, 171,
    },
    {
      "getpgid",
      121, 132,
    },
    {
      "setfsuid",
      122, 138,
    },
    {
      "setfsgid",
      123, 139,
    },
    {
      "getsid",
      124, 147,
    },
    {
      "capget",
      125, 184,
    },
    {
      "capset",
      126, 185,
    },
    {
      "rt_sigpending",
      127, 176,
    },
    {
      "rt_sigtimedwait",
      128, 177,
    },
    {
      "rt_sigqueueinfo",
      129, 178,
    },
    {
      "rt_sigsuspend",
      130, 179,
    },
    {
      "sigaltstack",
      131, 186,
    },
    {
      "utime",
      132, 30,
    },
    {
      "mknod",
      133, 14,
    },
    {
      "uselib",
      134, 86,
    },
    {
      "personality",
      135, 136,
    },
    {
      "ustat",
      136, 62,
    },
    {
      "statfs",
      137, 99,
    },
    {
      "fstatfs",
      138, 100,
    },
    {
      "sysfs",
      139, 135,
    },
    {
      "getpriority",
      140, 96,
    },
    {
      "setpriority",
      141, 97,
    },
    {
      "sched_setparam",
      142, 154,
    },
    {
      "sched_getparam",
      143, 155,
    },
    {
      "sched_setscheduler",
      144, 156,
    },
    {
      "sched_getscheduler",
      145, 157,
    },
    {
      "sched_get_priority_max",
      146, 159,
    },
    {
      "sched_get_priority_min",
      147, 160,
    },
    {
      "sched_rr_get_interval",
      148, 161,
    },
    {
      "mlock",
      149, 150,
    },
    {
      "munlock",
      150, 151,
    },
    {
      "mlockall",
      151, 152,
    },
    {
      "munlockall",
      152, 153,
    },
    {
      "vhangup",
      153, 111,
    },
    {
      "modify_ldt",
      154, 123,
    },
    {
      "pivot_root",
      155, -1,
    },
    {
      "_sysctl",
      156, -1,
    },
    {
      "prctl",
      157, 172,
    },
    {
      "arch_prctl",
      158, -1,
    },
    {
      "adjtimex",
      159, 124,
    },
    {
      "setrlimit",
      160, 75,
    },
    {
      "chroot",
      161, 61,
    },
    {
      "sync",
      162, 36,
    },
    {
      "acct",
      163, 51,
    },
    {
      "settimeofday",
      164, 79,
    },
    {
      "mount",
      165, 21,
    },
    {
      "umount2",
      166, -1,
    },
    {
      "swapon",
      167, 87,
    },
    {
      "swapoff",
      168, 115,
    },
    {
      "reboot",
      169, 88,
    },
    {
      "sethostname",
      170, 74,
    },
    {
      "setdomainname",
      171, 121,
    },
    {
      "iopl",
      172, 110,
    },
    {
      "ioperm",
      173, 101,
    },
    {
      "create_module",
      174, 127,
    },
    {
      "init_module",
      175, 128,
    },
    {
      "delete_module",
      176, 129,
    },
    {
      "get_kernel_syms",
      177, 130,
    },
    {
      "query_module",
      178, 167,
    },
    {
      "quotactl",
      179, 131,
    },
    {
      "nfsservctl",
      180, 169,
    },
    {
      "getpmsg",
      181, -1,
    },
    {
      "putpmsg",
      182, -1,
    },
    {
      "afs_syscall",
      183, -1,
    },
    {
      "tuxcall",
      184, -1,
    },
    {
      "security",
      185, -1,
    },
    {
      "gettid",
      186, -1,
    },
    {
      "readahead",
      187, -1,
    },
    {
      "setxattr",
      188, -1,
    },
    {
      "lsetxattr",
      189, -1,
    },
    {
      "fsetxattr",
      190, -1,
    },
    {
      "getxattr",
      191, -1,
    },
    {
      "lgetxattr",
      192, -1,
    },
    {
      "fgetxattr",
      193, -1,
    },
    {
      "listxattr",
      194, -1,
    },
    {
      "llistxattr",
      195, -1,
    },
    {
      "flistxattr",
      196, -1,
    },
    {
      "removexattr",
      197, -1,
    },
    {
      "lremovexattr",
      198, -1,
    },
    {
      "fremovexattr",
      199, -1,
    },
    {
      "tkill",
      200, -1,
    },
    {
      "time",
      201, 13,
    },
    {
      "futex",
      202, -1,
    },
    {
      "sched_setaffinity",
      203, -1,
    },
    {
      "sched_getaffinity",
      204, -1,
    },
    {
      "set_thread_area",
      205, 243,
    },
    {
      "io_setup",
      206, -1,
    },
    {
      "io_destroy",
      207, -1,
    },
    {
      "io_getevents",
      208, -1,
    },
    {
      "io_submit",
      209, -1,
    },
    {
      "io_cancel",
      210, -1,
    },
    {
      "get_thread_area",
      211, -1,
    },
    {
      "lookup_dcookie",
      212, -1,
    },
    {
      "epoll_create",
      213, -1,
    },
    {
      "epoll_ctl_old",
      214, -1,
    },
    {
      "epoll_wait_old",
      215, -1,
    },
    {
      "remap_file_pages",
      216, -1,
    },
    {
      "getdents64",
      217, -1,
    },
    {
      "set_tid_address",
      218, -1,
    },
    {
      "restart_syscall",
      219, -1,
    },
    {
      "semtimedop",
      220, -1,
    },
    {
      "fadvise64",
      221, -1,
    },
    {
      "timer_create",
      222, -1,
    },
    {
      "timer_settime",
      223, -1,
    },
    {
      "timer_gettime",
      224, -1,
    },
    {
      "timer_getoverrun",
      225, -1,
    },
    {
      "timer_delete",
      226, -1,
    },
    {
      "clock_settime",
      227, -1,
    },
    {
      "clock_gettime",
      228, -1,
    },
    {
      "clock_getres",
      229, -1,
    },
    {
      "clock_nanosleep",
      230, -1,
    },
    {
      "exit_group",
      231, 252,
    },
    {
      "epoll_wait",
      232, -1,
    },
    {
      "epoll_ctl",
      233, -1,
    },
    {
      "tgkill",
      234, -1,
    },
    {
      "utimes",
      235, -1,
    },
    {
      "vserver",
      236, -1,
    },
    {
      "mbind",
      237, -1,
    },
    {
      "set_mempolicy",
      238, -1,
    },
    {
      "get_mempolicy",
      239, -1,
    },
    {
      "mq_open",
      240, -1,
    },
    {
      "mq_unlink",
      241, -1,
    },
    {
      "mq_timedsend",
      242, -1,
    },
    {
      "mq_timedreceive",
      243, -1,
    },
    {
      "mq_notify",
      244, -1,
    },
    {
      "mq_getsetattr",
      245, -1,
    },
    {
      "kexec_load",
      246, -1,
    },
    {
      "waitid",
      247, -1,
    },
    {
      "add_key",
      248, -1,
    },
    {
      "request_key",
      249, -1,
    },
    {
      "keyctl",
      250, -1,
    },
    {
      "ioprio_set",
      251, -1,
    },
    {
      "ioprio_get",
      252, -1,
    },
    {
      "inotify_init",
      253, -1,
    },
    {
      "inotify_add_watch",
      254, -1,
    },
    {
      "inotify_rm_watch",
      255, -1,
    },
    {
      "migrate_pages",
      256, -1,
    },
    {
      "openat",
      257, -1,
    },
    {
      "mkdirat",
      258, -1,
    },
    {
      "mknodat",
      259, -1,
    },
    {
      "fchownat",
      260, -1,
    },
    {
      "futimesat",
      261, -1,
    },
    {
      "newfstatat",
      262, -1,
    },
    {
      "unlinkat",
      263, -1,
    },
    {
      "renameat",
      264, -1,
    },
    {
      "linkat",
      265, -1,
    },
    {
      "symlinkat",
      266, -1,
    },
    {
      "readlinkat",
      267, -1,
    },
    {
      "fchmodat",
      268, -1,
    },
    {
      "faccessat",
      269, -1,
    },
    {
      "pselect6",
      270, -1,
    },
    {
      "ppoll",
      271, -1,
    },
    {
      "unshare",
      272, -1,
    },
    {
      "set_robust_list",
      273, -1,
    },
    {
      "get_robust_list",
      274, -1,
    },
    {
      "splice",
      275, -1,
    },
    {
      "tee",
      276, -1,
    },
    {
      "sync_file_range",
      277, -1,
    },
    {
      "vmsplice",
      278, -1,
    },
    {
      "move_pages",
      279, -1,
    },
    {
      "utimensat",
      280, -1,
    },
    {
      "epoll_pwait",
      281, -1,
    },
    {
      "signalfd",
      282, -1,
    },
    {
      "timerfd_create",
      283, -1,
    },
    {
      "eventfd",
      284, -1,
    },
    {
      "fallocate",
      285, -1,
    },
    {
      "timerfd_settime",
      286, -1,
    },
    {
      "timerfd_gettime",
      287, -1,
    },
    {
      "accept4",
      288, -1,
    },
    {
      "signalfd4",
      289, -1,
    },
    {
      "eventfd2",
      290, -1,
    },
    {
      "epoll_create1",
      291, -1,
    },
    {
      "dup3",
      292, -1,
    },
    {
      "pipe2",
      293, -1,
    },
    {
      "inotify_init1",
      294, -1,
    },
    {
      "preadv",
      295, -1,
    },
    {
      "pwritev",
      296, -1,
    },
    {
      "rt_tgsigqueueinfo",
      297, -1,
    },
    {
      "perf_event_open",
      298, -1,
    },
    {
      "recvmmsg",
      299, -1,
    },
    {
      "fanotify_init",
      300, -1,
    },
    {
      "fanotify_mark",
      301, -1,
    },
    {
      "prlimit64",
      302, -1,
    },
    {
      "name_to_handle_at",
      303, -1,
    },
    {
      "open_by_handle_at",
      304, -1,
    },
    {
      "clock_adjtime",
      305, -1,
    },
    {
      "syncfs",
      306, -1,
    },
    {
      "sendmmsg",
      307, -1,
    },
    {
      "setns",
      308, -1,
    },
    {
      "getcpu",
      309, -1,
    },
    {
      "process_vm_readv",
      310, -1,
    },
    {
      "process_vm_writev",
      311, -1,
    },
    {
      "waitpid",
      -1, 7,
    },
    {
      "oldumount",
      -1, 22,
    },
    {
      "stime",
      -1, 25,
    },
    {
      "nice",
      -1, 34,
    },
    {
      "signal",
      -1, 48,
    },
    {
      "umount",
      -1, 52,
    },
    {
      "olduname",
      -1, 59,
    },
    {
      "sigaction",
      -1, 67,
    },
    {
      "sgetmask",
      -1, 68,
    },
    {
      "ssetmask",
      -1, 69,
    },
    {
      "sigsuspend",
      -1, 72,
    },
    {
      "sigpending",
      -1, 73,
    },
    {
      "select",
      -1, 82,
    },
    {
      "readdir",
      -1, 89,
    },
    {
      "mmap",
      -1, 90,
    },
    {
      "socketcall",
      -1, 102,
    },
    {
      "newstat",
      -1, 106,
    },
    {
      "newlstat",
      -1, 107,
    },
    {
      "newfstat",
      -1, 108,
    },
    {
      "idle",
      -1, 112,
    },
    {
      "vm86old",
      -1, 113,
    },
    {
      "ipc",
      -1, 117,
    },
    {
      "sigreturn",
      -1, 119,
    },
    {
      "newuname",
      -1, 122,
    },
    {
      "sigprocmask",
      -1, 126,
    },
    {
      "bdflush",
      -1, 134,
    },
    {
      "llseek",
      -1, 140,
    },
    {
      "sysctl",
      -1, 149,
    },
    {
      "vm86",
      -1, 166,
    },
    {
      "pread",
      -1, 180,
    },
    {
      "pwrite",
      -1, 181,
    },
    {
      "mmap2",
      -1, 192,
    },
    {
      "stat64",
      -1, 195,
    },
    {
      "fstat64",
      -1, 197,
    }
  };
