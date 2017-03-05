/*
** syscalls.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Jun 29 19:19:34 2014 Jean Fauquenot
** Last update Sun Jun 29 20:50:10 2014 Jean Fauquenot
*/

/**
** @file strace_syscall.h
** @brief Informations relatives to the syscall and errno arrays.
*/

#ifndef SYSCALLS_H_
# define SYSCALLS_H_

# include <sys/types.h>

/**
** @brief Enum for all the differents x86_64 syscall params
*/
enum e_arg
  {
    NONE = 0,
    ARG_UINT_PTR,
    ARG_SIGHANDLER_T,
    ARG_OLD_SIGSET_T,
    ARG_S_STAT,
    ARG_KEY_SERIAL_T,
    ARG_KEY_T,
    ARG_UNION_SEMUN,
    ARG_TIMER_T,
    ARG_LONG_TIMEOUT_MSECS,
    ARG_OFF_T,
    ARG_LOFF_T,
    ARG_RT_SIGACTION,
    ARG_SIGSET_T,
    ARG_CAP_USER_HEADER_T,
    ARG_CAP_USER_DATA_T,
    ARG_CLOCKID_T,
    ARG_MODE_T,
    ARG_GIT_T,
    ARG_GID_T,
    ARG_QID_T,
    ARG_UID_T,
    ARG_SIZE_T,
    ARG_PID_T,
    ARG_MQD_T,
    ARG_AIO_CONTEXT_T,
    ARG___S32D,
    ARG_U32D,
    ARG_U64_PTR,
    ARG_U64D,
    ARG___U64D,
    ARG_UINT,
    ARG_ULONG,
    ARG_INT,
    ARG_LONG,
    ARG_UNSIGNED,
    ARG_S_USTAT_PTR,
    ARG_S_POLL_FD_PTR,
    ARG_S_SIGACTION_PTR,
    ARG_SIGSET_T_PTR,
    ARG_RT_SIGACTION_PTR,
    ARG_S_IOVEC_PTR,
    ARG_FD_SET_PTR,
    ARG_UCHAR_PTR,
    ARG_S_STATFS_PTR,
    ARG_S_SHMID_DS_PTR,
    ARG_S_SYSINFO_PTR,
    ARG_S_RLIMIT_PTR,
    ARG_S_TIMEZONE_PTR,
    ARG_S_TIMEVAL_PTR,
    ARG_S_TIMESPECT_PTR,
    ARG_S_TIMESPEC_PTR,
    ARG_S_ITIMERVAL_PTR,
    ARG_S_SOCKADDR_PTR,
    ARG_S_MSGHDR_PTR,
    ARG_S_OLD_UTSNAME_PTR,
    ARG_S_SEMBUF_PTR,
    ARG_S_MSGBUF_PTR,
    ARG_RUSAGE_PTR,
    ARG_S_LINUX_DIRENT64_PTR,
    ARG_S_LINUX_DIRENT_PTR,
    ARG_S_MSQID_DS_PTR,
    ARG_SIGINFO_T_PTR,
    ARG_S_SIGEVENT_PTR,
    ARG_S_ITIMERSPEC_PTR,
    ARG_TIME_T_PTR,
    ARG_S_EPOLL_EVENT_PTR,
    ARG_S_GETCPU_CACHE_PTR,
    ARG_MMSGHDR_PTR,
    ARG_S_IOCB_PTR,
    ARG_STRUCT_IOVCC_PTR,
    ARG_S_IO_EVENT_PTR,
    ARG_STACK_T_PTR,
    ARG_S_UTIMBUF_PTR,
    ARG_S_SCHED_PARAM_PTR,
    ARG_S___SYSCTL_ARGS_PTR,
    ARG_S_TASK_STRUCT_PTR,
    ARG_S_TIMEX_PTR,
    ARG_S_PT_REGS_PTR,
    ARG_S_KEXEC_SEGMENT_PTR,
    ARG_S_SIGINFO_PTR,
    ARG_S_MQ_ATTR_PTR,
    ARG_S_ROBUST_LIST_HEAD_PTR,
    ARG_S_PERF_EVENT_ATTR_PTR,
    ARG_INT_PTR,
    ARG_S_RLIMIT64_PTR,
    ARG_S_FILE_HANDLE_PTR,
    ARG_U32_PTR,
    ARG_CHAR_PTR,
    ARG_CHAR_PTR_A,
    ARG_VOID_PTR,
    ARG_S_OLDOLD_UTSNAME_PTR,
    S_OLD_SIGACTION_PTR,
    ARG_OLD_SIGSET_T_PTR,
    ARG_S_MMAP_ARG_STRUCT_PTR,
    ARG_ULONG_PTR,
    ARG_S_STAT_PTR,
    ARG_S_VM86PLUS_STRUCT_PTR,
    ARG_S_NEW_UTSNAME_PTR,
    ARG_LOFF_T_PTR,
    ARG_S_VM86_STRUCT_PTR,
    ARG_S_IOCB_PTR_PTR
  };

/**
** @brief Every enum e_arg superior or equal is a pointer
*/
# define PTR_ARG_START	ARG_S_USTAT_PTR


/**
** @brief Structure used for the syscalls array index
*/
typedef struct	s_syscall
{
  char		*name;
  ssize_t	id_x86_64;
  ssize_t	id_x86;
}		t_syscall;

/**
** @brief Array index of syscalls
*/
extern t_syscall const	g_syscall[346];

#endif /* !SYSCALLS_H_ */
