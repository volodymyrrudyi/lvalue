LEVEL = .
REQUIRES_RTTI = 1
DIRS = lib tools
EXTRA_DIST = include
#
# Include the Master Makefile that knows how to build all.
#
include $(LEVEL)/Makefile.common
