DEPS = sort

compile: main.cpp sorting.h
	g++ main.cpp -o $(DEPS)

run: $(DEPS)
	./$(DEPS) $(var)

clean:
	rm -f $(DEPS)