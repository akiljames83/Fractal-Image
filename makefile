CFLAGS = -std=c++11 -Wall
FNAME = fractal
GPP = g++

file:
	$(GPP) $(CFLAGS) -o $(FNAME) *.cpp 

run:
	./$(FNAME)
	
clean:
	rm fractal
