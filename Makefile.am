bin_PROGRAMS = lvalue
lvalue_YFLAGS = -d
#lvalue_LFLAGS =
lvalue_CPPFLAGS =  -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS `llvm-config --cppflags`
lvalue_LDFLAGS = `llvm-config --ldflags core jit ` `llvm-config --libs core jit`
AM_CPPFLAGS=`llvm-config --cppflags`
lvalue_SOURCES = src/lvalue/main.cpp \
	src/lvalue/parser.ypp \
	src/lvalue/tokens.lpp \
	src/lvalue/node.h \
	src/lvalue/codegen.h \
	src/lvalue/codegen.cpp
