LEVEL = ../..
YACC = bison
LEX = flex
YFLAGS = -d
TOOLNAME = lvaluec
LINK_COMPONENTS := all engine jit interpreter nativecodegen
REQUIRES_RTTI := 1
USEDLIBS = lvaluel.a
USEDLIBS := lvaluel.a
ExtraSource := parse.cpp token.cpp
include $(LEVEL)/Makefile.common

token.cpp: parse.hpp
	$(LEX) -o token.cpp token.lpp 

parse.cpp parse.hpp: parse.ypp
	$(YACC) $(YFLAGS) parse.ypp -o parse.cpp
