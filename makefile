CFLAGS = -std=c++11 -Wall -Ofast -Wsign-compare
FNAME = fractal
GPP = g++

file:
	$(GPP) $(CFLAGS) -o $(FNAME) *.cpp 

run:
	./$(FNAME)
	
clean:
	rm fractal
