sudoku:Producer.o Solver.o File.o User.o sudoku.o
	g++ -o sudoku Producer.o Solver.o File.o User.o sudoku.o

Producer.o:Producer.cpp Producer.h Solver.h
	g++ -c Producer.cpp

Solver.o:Solver.cpp Solver.h Data.h
	g++ -c Solver.cpp

File.o:File.cpp File.h
	g++ -c File.cpp

User.o:User.cpp User.h Producer.h
	g++ -c User.cpp

sudoku.o:sudoku.cpp Solver.h User.h
	g++ -c sudoku.cpp
