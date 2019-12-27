# Your program must compile with 'make'
# You must not change this file.

CC = gcc
FLAGS = -std=c99 -O0 -Wall -Werror -g -pedantic

default:
	$(CC) $(FLAGS) rgrep.c matcher.c -o rgrep

clean:
	rm -f rgrep
	rm -rf *.dSYM

check: clean default
	test "`echo "a\nb\nc" | ./rgrep 'a'`" = "a"
	test "`echo "a\n" | ./rgrep 'a'`" = "a"
	test "`echo "a" | ./rgrep '...'`" = ""
	test "`echo "abc" | ./rgrep '.b.'`" = "abc"
	test "`echo "h\naaaaah" | ./rgrep 'a+h'`" = "aaaaah"
	test "`echo "h\naaaaahhhhh" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "h\naaaaahhhhh\n" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "woot\nwot\nwat\n" | ./rgrep 'wo?t'`" = "wot"
	test "`echo "CCCCCCC\nC+\nC++" | ./rgrep '.\+\+'`" = "C++"
	test "`echo "GG" | ./rgrep 'G+'`" = "GG"
	test "`echo "USF_CS221.jpg" | ./rgrep 'U.F_CL?S2+1\.jpg'`" = "USF_CS221.jpg"
	test "`echo "ABBCCC" | ./rgrep 'A+B+C+'`" = "ABBCCC"
	test "`echo "RED\nREED" | ./rgrep 'RE?D'`" = "RED"
	test "`echo "testcase.tiff.mkv.exe" | ./rgrep 'testcase\.tiff\.mkv\.exe'`" = "testcase.tiff.mkv.exe"
	test "`echo "abcde" | ./rgrep 'abcde?c?'`" = "abcde"
	test "`echo "a?bcde" | ./rgrep 'a\?bc'`" = "a?bcde"
	test "`echo "aaab?cde" | ./rgrep 'a+\b\?c'`" = "aaab?cde"
	test "`echo "abcde" | ./rgrep 'a?b?c?d?e?f?g?'`" = "abcde"
	@echo "Passed sanity check."

