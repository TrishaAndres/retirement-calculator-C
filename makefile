#compile code to executable file
compile:
	g++ calculate.cpp -o calculate.out

#run executable
run:
	./calculate.out

#clean executable
clean:
	rm *.out
