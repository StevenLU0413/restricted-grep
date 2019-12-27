# Restricted grep (rgrep)

This program implements "rgrep", a simplified, restricted grep. rgrep is "restricted” in the sense that the patterns it matches only support a few regular operators: + . \ ?. The way rgrep is used is that a pattern is specified on the command line, and rgrep then reads lines from its standard input and prints them out on its standard output if and only if the pattern “matches” the line.

| :--------------: | ------------- |
| .(period)        | Matches any character | 
| +(plus sign)     | The preceding character may appear 1 or more times (in other words, the preceding character can be repeated several times in a row)      |
| ?(question mark) | The preceding character may appear between 0 and 1 times (in other words, the preceding character is optional)      |
| \(backslash)     | “Escapes” the following character, nullifying any special meaning it has      |

Usage: `./rgep '.\.txt' < input` where input is the input, and contains

```
a.out
cs221.txt
cs221.pdf
usf.txt
nope.pdf
.txt
```

will print out

```
cs221.txt
usf.txt
```
