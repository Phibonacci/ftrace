##
## Makefile for  in ./
##
## Made by Jean Fauquenot
## Login   <fauque_j@epitech.net>
##
## Started on  Sat Jul  5 19:14:34 2014 Jean Fauquenot
## Last update Sun Jul  6 20:12:47 2014 paul-maxime leduc
##

# All the default variables used in this Makefile are commented with their
# definition and their default value.
# Read the Make manual at gnu.org for more informations.
# https://www.gnu.org/software/make/manual/

# VARIABLES

NAME		=	ftrace
#  CC
#  Program for compiling C programs; default ‘cc’.
CC		=	gcc
INCLUDE		=	-I ./src/include

DEBUG		=	0
BUILD		=	build

SRC		=	\
			main.c
#  VPATH
#  https://www.gnu.org/software/make/manual/make.html#Directory-Search
VPATH		=	src
INCLUDE		+=	-I ./src/

SRC		+=	\
			merror.c \
			syscalls.c
VPATH		+=	src/utils/
INCLUDE		+=	-I ./src/utils/

SRC		+=	\
			stack_empty.c \
			stack_new.c \
			stack_init.c \
			stack_delete.c \
			stack_destroy.c \
			stack_pop.c \
			stack_push.c \
			stack_size.c \
			stack_top.c \
			stack_clear.c
VPATH		+=	src/utils/t_stack/

SRC		+=	\
			list_new.c \
			list_init.c \
			list_delete.c \
			list_destroy.c \
			list_assign.c \
			list_back.c \
			list_begin.c \
			list_clear.c \
			list_empty.c \
			list_end.c \
			list_front.c \
			list_insert.c \
			list_pop_back.c \
			list_pop_front.c \
			list_push_back.c \
			list_push_front.c \
			list_remove.c \
			list_size.c
VPATH		+=	src/utils/t_list/

SRC		+=	\
			ftrace_new.c \
			ftrace_init.c \
			ftrace_delete.c \
			ftrace_destroy.c \
			ftrace_parser.c \
			ftrace_start.c \
			ftrace_trace.c \
			ftrace_signal.c \
			ftrace_break_signal.c \
			ftrace_break.c \
			ftrace_syscall.c \
			ftrace_attach.c \
			ftrace_call.c \
			ftrace_call_inlist.c \
			ftrace_call_exist.c \
			ftrace_ktree_link.c \
			ftrace_getlib_name.c
VPATH		+=	src/t_ftrace/

SRC		+=	\
			call_finder_init.c \
			call_finder_destroy.c \
			call_finder_step.c
VPATH		+=	src/t_call_finder/

SRC		+=	\
			memory_map_init.c \
			memory_map_destroy.c \
			memory_map_addressat.c
VPATH		+=	src/t_memory_map/

SRC		+=	\
			symbol_finder_init.c \
			symbol_finder_initgotsymbols.c \
			symbol_finder_findsymbol.c \
			symbol_finder_cache_init.c
VPATH		+=	src/t_symbol_finder/

SRC		+=	\
			ktree_new.c \
			ktree_init.c \
			ktree_delete.c \
			ktree_destroy.c \
			ktree_clean.c \
			ktree_add.c \
			ktree_elem_new.c \
			ktree_elem_init.c
VPATH		+=	src/t_ktree/

SRC		+=	\
			trace.c \
			function_definer.c \
			graph.c \
			dump_graph.c
VPATH		+=	src/t_graph/

SRC		+=	\
			unmangle.c \
			unmangle_handleprefix.c
VPATH		+=	src/t_mangling/


#  CFLAGS
#  Extra flags to give to the C compiler.
CFLAGS		+=	-Wall -Wextra
#CFLAGS		+=	-ansi -pedantic
#  IFEQ
#  https://www.gnu.org/software/make/manual/make.html#index-ifeq_002c-expansion-110
#  FILTER
#  https://www.gnu.org/software/make/manual/make.html#index-filter-587
ifeq ($(DEBUG), $(filter $(DEBUG), 1 yes YES))
 CFLAGS		+=	-ggdb3 -D DEBUG
endif
CFLAGS		+=	$(INCLUDE)
#  CPPFLAGS
#  Extra flags to give to the C preprocessor and programs that use it (the C and
#  Fortran compilers).
CPPFLAGS	=
#  LDFLAGS
#  Extra flags to give to compilers when they are supposed to invoke the linker,
#  ‘ld’, such as -L.
#  Libraries (-lfoo) should be added to the LDLIBS variable instead.
#  e.g.: -L /usr/lib
LDFLAGS		=
#  LDLIBS
#  Library flags or names given to compilers when they are supposed to invoke
#  the linker, ‘ld’. LOADLIBES is a deprecated (but still supported) alternative
#  to LDLIBS. Non-library linker flags, such as -L, should go in the LDFLAGS
#  variable.
#  e.g.: -lphtread
LDLIBS		= -lelf

OBJ		=	$(patsubst %.c, $(BUILD)/%.o, $(SRC))

MKDIR		=	mkdir -p
RMDIR		=	-rmdir
#  RM
#  Command to remove a file; default ‘rm -f’.
RM		=	rm -f

# RULES

all		:	$(BUILD) $(NAME)

$(BUILD)	:
		$(MKDIR) $(BUILD)

#  See:
#  Automatic Variables:
#  https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
#  Implicit Rules
#  https://www.gnu.org/software/make/manual/make.html#Using-Implicit
.SUFFIXES	:	.c .o
$(BUILD)/%.o	:	%.c
		$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(NAME)		:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

clean		:
		$(RM) $(OBJ)
ifeq ($(wildcard $(BUILD)), $(BUILD))
		$(RMDIR) $(BUILD)
endif

fclean		:	clean
		$(RM) $(NAME)

mrproper	:	fclean

re		:	fclean all

.PHONY		:	all clean fclean mrproper re
