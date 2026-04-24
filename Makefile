CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -gdwarf-4 -Wall -Wextra -pedantic -fsanitize=address,null -Wno-error=unused $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./src/linked_up.cc ./includes/utilities.hpp ./includes/linked_up.hpp 
	$(CXX) $(CXXFLAGS) ./src/driver.cc ./src/linked_up.cc ./src/utilities.cc -o $@

bin/tests: obj/catch_main.o ./tests/tests.cc ./src/linked_up.cc ./includes/linked_up.hpp 
	$(CXX) $(CXXFLAGS) obj/catch_main.o ./tests/tests.cc ./src/linked_up.cc  -o $@

obj/catch_main.o: ./tests/catch.cc ./tests/catch.hpp
	$(CXX) $(CXX_FLAGS) -c ./tests/catch.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*