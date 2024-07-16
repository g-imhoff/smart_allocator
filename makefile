CCX = g++
CXFLAGS = -g3
EXEC = smart_allocator
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
DEPS = $(wildcard src/*.h)

$(EXEC): $(OBJ)
	$(CCX) -shared -o $@.so $^
	$(CCX) $(CXFLAGS) -o $@ $^

obj/%.o: src/%.c $(DEPS)
	mkdir -p obj
	$(CCX) $(CXFLAGS) -o $@ -c $<

clean:
	rm -f $(EXEC) $(EXEC).so
	rm -rf obj

format:
	@for file in $(SRC) $(DEPS); do \
		clang-format -i $$file; \
	done \

.phony: clean format
