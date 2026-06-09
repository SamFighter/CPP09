NAME			:=	PmergeMe

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

SRC				:=	main.cpp \
					PmergeMe.cpp

SRC_OBJS		:=	$(SRC:%.cpp=.build/%.o)
DEPS			:=	$(SRC_OBJS:%.o=%.d)

CC				:=	c++
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98
CPPFLAGS		:=	-MP -MMD
LDFLAGS			:=

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) $(LDFLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo "	  ____ ____  ____    __  __           _       _         ___   ___	"
	@echo "	 / ___|  _ \|  _ \  |  \/  | ___   __| |_   _| | ___   / _ \ / _ \	"
	@echo "	| |   | |_) | |_) | | |\/| |/ _ \ / _  | | | | |/ _ \ | | | | | | |	"
	@echo "	| |___|  __/|  __/  | |  | | (_) | (_| | |_| | |  __/ | |_| | |_| |	"
	@echo "	 \____|_|   |_|     |_|  |_|\___/ \____|\____|_|\___|  \___/ \___/	"
	@echo "				    by salabbe											"
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
