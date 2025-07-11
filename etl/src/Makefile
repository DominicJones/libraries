# cpp_compiler:=g++17
# cpp_compiler:=clang
cpp_compiler:=$(GCC_HOME)/bin/g++ -static-libstdc++ -fno-use-linker-plugin
cpp_flags:=-std=c++20
cpp_flags+=-O3


cpp_flags+=-I..
cpp_flags+=-I../src
cpp_flags+=-I../include
cpp_flags+=-I../brigand/include/standalone

ld_flags:=-lstdc++ -lm

target_path:=../bin/
target:=main.exe

# sources:=$(wildcard *.cpp)
sources:=main.cpp
objects:=$(sources:.cpp=.o)
obj_dep_rules:=$(sources:.cpp=.mk)

objects:=$(addprefix $(target_path), $(objects))
obj_dep_rules:=$(addprefix $(target_path), $(obj_dep_rules))
target:=$(addprefix $(target_path), $(target))

make_target_path:=mkdir -p $(target_path)
make_target_path_test:=mkdir -p $(target_path)/test

.PHONY: clean default

default: $(target)

$(target): $(objects)
	@$(make_target_path)
	@$(make_target_path_test)
	$(cpp_compiler) $(cpp_flags) $(ld_flags) $^ -o $@

$(target_path)%.o: $(target_path)%.mk
	@$(make_target_path)
	@$(make_target_path_test)
	@t0=$$(date +%s%3N); \
	$(cpp_compiler) $(cpp_flags) -c $(basename $*).cpp -o $@; \
	t1=$$(date +%s%3N); \
	echo "$(basename $*): build time = $$((t1-t0)) ms"

$(target_path)%.mk: %.cpp
	@$(make_target_path)
	@$(make_target_path_test)
	$(cpp_compiler) $(cpp_flags) -MM $< >> $@

clean:
	@rm -rf $(target_path)

ifneq ($(MAKECMDGOALS), clean)
-include $(obj_dep_rules)
endif
