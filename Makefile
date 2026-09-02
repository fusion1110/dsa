# Usage:
#   make a                        -> builds a.cpp -> ./a  (debug: warnings + sanitizers + STL bounds checking)
#   make a MODE=release           -> builds a.cpp -> ./a  (optimized, closer to judge timing)
#   make run TARGET=a             -> builds (respects MODE) then runs, reading stdin normally
#   make run TARGET=a IN=in1.txt  -> same, but feeds in1.txt as stdin
#   make gdb TARGET=a             -> builds in debug mode, drops you into gdb
#   make clean                    -> removes compiled binaries for every *.cpp in this dir

CXX  := g++
STD  := -std=gnu++20
WARN := -Wall -Wextra -Wshadow

# Debug: -Og keeps it fast to compile/step through while still optimizing enough
# that ASan/UBSan traces stay sane. -D_GLIBCXX_DEBUG turns on STL bounds/iterator
# checking (catches out-of-range .at()-less accesses, invalidated iterators, etc.)
DEBUG_FLAGS   := -g3 -Og -fsanitize=address,undefined -fno-sanitize-recover=all \
                 -fno-omit-frame-pointer -D_GLIBCXX_DEBUG -DLOCAL

# Release: no sanitizers, no debug info bloat - use this to sanity-check that your
# solution is still fast enough once you've fixed correctness.
RELEASE_FLAGS := -O2 -DNDEBUG -DLOCAL

ifeq ($(MODE),release)
    CXXFLAGS := $(STD) $(WARN) $(RELEASE_FLAGS)
else
    CXXFLAGS := $(STD) $(WARN) $(DEBUG_FLAGS)
endif

# Pattern rule: any X.cpp can be built as `make X`
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run:
	@$(MAKE) $(TARGET) MODE=$(MODE)
	@./$(TARGET) $(if $(IN),< $(IN))

gdb:
	@$(MAKE) $(TARGET) MODE=$(MODE)
	gdb -q ./$(TARGET)

clean:
	@for f in *.cpp; do b="$${f%.cpp}"; [ -x "$$b" ] && [ ! -d "$$b" ] && rm -f "$$b"; done

.PHONY: run gdb clean
