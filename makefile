CCX = g++
CXFLAGS = -g3
EXEC = smart_allocator
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
DEPS = $(wildcard src/*.h)

$(EXEC): $(OBJ)
	$(CCX) $(CXFLAGS) -o $@ $^

obj/%.o: src/%.cpp $(DEPS)
	mkdir -p obj
	$(CCX) $(CXFLAGS) -o $@ -c $<

clean:
	rm -f $(EXEC) 
	rm -rf obj

format:
	@for file in $(SRC) $(DEPS); do \
		clang-format -i $$file; \
	done \

run : 
	$(MAKE) clean
	$(MAKE)
	./$(EXEC)

.phony: clean format run
