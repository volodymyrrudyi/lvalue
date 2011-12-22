LEVEL=../..
LEX = flex
YACC = bison
YFLAGS = -d
TOOLNAME = lvaluec
LINK_COMPONENTS := all engine jit interpreter nativecodegen
REQUIRES_RTTI := 1
CPPFLAGS  += -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS
ExtraSource = parser.cpp tokens.cpp

$(TOOLNAME): parser.cpp codegen.cpp main.cpp  tokens.cpp

tokens.cpp: parser.cpp   
	$(LEX)  -o tokens.cpp tokens.l

parser.cpp: parser.y
	$(YACC) $(YFLAGS) parser.y -o parser.cpp

include $(LEVEL)/Makefile.common
