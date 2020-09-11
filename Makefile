all: eq_solver.cpp
	g++ -Wall -o eq_solver eq_solver.cpp

clean: 
	rm -rf *.o all


