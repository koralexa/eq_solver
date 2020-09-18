all: eq_solver.cpp test_defines.h functions.h functions.cpp
	g++ -Wall -Wextra -Wfloat-equal -o eq_solver eq_solver.cpp functions.cpp

debug: eq_solver.cpp test_defines.h functions.h functions.cpp
	g++ -Wall -Wextra -Wfloat-equal -DDEBUG -o eq_solver_debug eq_solver.cpp functions.cpp

clean: 
	rm -rf *.o all


