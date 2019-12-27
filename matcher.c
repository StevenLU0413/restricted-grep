#include "matcher.h"

/**
 * The following functions check whether or not 
 * the characters are special characters
*/

int isDot(char* character){
	return *character == '.';
}

int isPlus(char* character){
	return *character == '+';
}

// if the next char is a question mark then the current char is the one that appears either once or not at all
int isQuestion(char* character){
	return *(character+1) == '?';
}

int isBackslash(char* character){
	return *character == '\\';
}

/**
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */

int matches_leading(char *partial_line, char *pattern) {
	if(*pattern == 0){
		// at the end of the pattern and 0 has not been returned yet
		return 1;
	}
	if(*partial_line == 0){
		// have not reached the end of the pattern
		return 0;
	}
	
	if(isBackslash(pattern)){
		// then the next char is not special
		pattern += 1; // moves past the \ to check if the next character matches as a non-special character
		if(*partial_line != *pattern){
			return 0;
		}
		return matches_leading(partial_line+1, pattern+1);
	} else if(isDot(pattern)){
		// so continue on like normal (any character matches)
		return matches_leading(partial_line+1, pattern+1);
	} else if(isPlus(pattern)){ 
		// already know that the char before matches in the pattern and the partial
		// while that character is repeating, then keep moving the pointer forward
		while(*partial_line == *(pattern-1)){
			partial_line += 1;
		}
		return matches_leading(partial_line, pattern+1);
		// at the end of the loop, the partial pointer should be at the next char after the string of continuous chars and the pattern is at +, then moves forward one
	} else if(isQuestion(pattern)){ // if the next char is a question mark then this char appears either once or not at all
		// if the character matches the pattern
		if(*partial_line == *pattern){
			// then move the partial_line pointer up one and the pattern pointer up 2 (to get past the char and the ?)
			return matches_leading(partial_line+1, pattern+2);
		} else { // if the character does not match the pattern, or the char? is not there
			// only move the pattern pointer past the char and ?
			return matches_leading(partial_line, pattern+2);
		}
	} else {
		// if the characters do not match then the line doesn't match the pattern
		if(*partial_line != *pattern){
			return 0;
		}
		return matches_leading(partial_line+1, pattern+1);			
	}

}


int rgrep_matches(char *line, char *pattern) {
	if(*line == 0){
		// base case returns false - the pointer has gotten to the end of the word and there was not a match
		return 0;
	}
	if(matches_leading(line, pattern)){
		// if the beginning of the string matches the pattern then return true
		return 1;
	} else {
		// moves pointer to the next character in the string and checks the beginning of the string from there
		return rgrep_matches(line+1, pattern);
	}
}
