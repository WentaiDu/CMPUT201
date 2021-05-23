1.Show the contents of your is_com.txt
	cat ls_com.txt
2.generate the ls_out.txt file
	cat ls_com.txt > ls_out.txt
3.compole hello.c into an executable called hello
	this code is missing a curly brace'}' and two semicolons ';'.
	Every function should end with a curly brace. And every complete line of code should also
	end with a semicolon. The C program is based on the semiolon to break sentences.
 
	gcc -Wall -std=c99 hello.c -o hello
gcc -Wall -std=c99 l7q
4.run hello
	./hello
5.create a .tar file containing ls_com.txt,Ls_out.txt,hello.c and this file readme.txt
	tar -cvf submit.tar l8q1.c l8q2.c l8q3.c readme.txt things.txt
tar -cvf submit.tar l7q1.c l7q2.c l7q3.c readme.txt
6.create a temporary temp/directory
	mkdir temp
7.copy the .tar file to temp/ directory
	cp submit.tar /temp
8.untar file
	tar -xvf submit.tar

reference :https://www.fprintf.net/imCheatSheet.html
tar -cvf submit.tar a2.c a2.o a2 Makefile run.sh stat.txt run.sh readme.txt