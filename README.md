# SimpleTailUtility

This code was created to run in linux OS.

How to compile and run it:
	gcc tail_utility.c -o tail_utility

	./tail_utility < my_file.txt
	(OR)
	./tail_utility -n 2 < my_file.txt




Syntax:
	tail [OPTION]... < [FILE]

Description:
	Print the last 3 lines of FILE to standard output.

	-> Optional argument:
		-n <numberOfLines> : output the last n lines

Examples:
	tail_utility > my_file.txt 
		It will print 3 last lines my_file.txt by default. Empty lines at the end of the file are not counted.

	tail_utility -n 8 > my_file.txt
		It will print last 8 lines of my_file.txt. Empty lines at the end of the file are not counted.

