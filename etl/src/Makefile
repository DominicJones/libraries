cpp_compiler:=g++-7
# cpp_compiler:=clang
# cpp_compiler:=$(GCC_CXX14_HOME)/bin/g++ -static-libstdc++ -fno-use-linker-plugin
cpp_flags:=-std=c++14
cpp_flags+=-O3
# cpp_flags+=-g

# cpp_flags+=-p

# cpp_flags+=-mavx
# cpp_flags+=-DNDEBUG

# cpp_flags+=--param large-unit-insns=100000000
# cpp_flags+=--param large-function-insns=100000000

# cpp_flags+=--param inline-unit-growth=100000000
# cpp_flags+=--param max-inline-insns-single=100000000
# cpp_flags+=--param large-function-growth=100000000
# cpp_flags+=--param inline-unit-growth=100000000

# largefunc: i2, l37, n82, s12
# cpp_flags+=-ftemplate-depth=175

# harmonic: i5, l25, n331, s103
cpp_flags+=-ftemplate-depth=1200


# cpp_flags+=-Wall
# cpp_flags+=-Wshadow
# cpp_flags+=-Woverloaded-virtual
# cpp_flags+=-ansi

cpp_flags+=-I..
cpp_flags+=-I../src
cpp_flags+=-I../include
cpp_flags+=-I../brigand/include/standalone

# cpp_flags+=-D"SMALLFUNC_UNIQ"
# cpp_flags+=-D"LARGEFUNC_UNIQ"
cpp_flags+=-D"HARMONIC_UNIQ"

# ld_flags:=-lstdc++ -lm

target_path:=../bin/
target:=main.exe

# sources:=$(wildcard *.cpp)
sources:=main.cpp
# sources+=test/smallfunc.cpp
# sources+=test/largefunc.cpp
sources+=test/harmonic.cpp
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
