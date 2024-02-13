CXX = gcc
SRC_DIRS := ./
SRC := $(shell find $(SRC_DIRS) -name '*.cc')

OS :=$(shell uname -s)
SRCSH := $(shell find $(SRC_DIRS) -name '*.h')
BLUE:=\033[96m
A :=  $(shell find $(SRC_DIRS) -name 'a.out')

EXECS = $(basename $(SRC))

ifeq ($(OS), Darwin)
	CFLAGS =-lstdc++ -std=c++17 -Wall -Wextra -Werror 
else
	CFLAGS =-lstdc++ -std=c++17 -Wall -Wextra -Werror -lrt -lm -lpthread
endif

all: clean $(EXECS)



%: %.cc
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"
	@$(CXX)  -o $@ $< -lgtest $(CFLAGS)
	@./$@
	@echo  "$(BLUE)------------------------------------------------------------------------$(END)"


test: clean $(EXECS) clean

clean:
	@rm -rf $(OBJS) $(EXECS) RESULT.log $(A) */*.g*

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(SRC)
	clang-format -n $(SRCSH)
	rm -rf .clang-format

format_style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i $(SRC)
	clang-format -i $(SRCSH)
	rm -rf .clang-format


valgrind: $(EXECS)
	@CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT.log  ./$(EXECS)  >/dev/null;
	cat RESULT.log

leaks:
	CK_FORK=no leaks -atExit -- ./$(EXECS) >/dev/null;


push: clean
	git add .
	git commit -m '$m'
	git push origin $o
