# Restricted grep (rgrep)

This program implements "rgrep", a simplified, restricted grep. rgrep is "restricted” in the sense that the patterns it matches only support a few regular operators: + . \ ?. The way rgrep is used is that a pattern is specified on the command line, and rgrep then reads lines from its standard input and prints them out on its standard output if and only if the pattern “matches” the line.

| Symbol           | Pattern       |
| ---------------- | ------------- |
| `.` (period)        | Matches any character | 
| `+` (plus sign)     | The preceding character may appear 1 or more times (the preceding character can be repeated several times in a row) |
| `?` (question mark) | The preceding character may appear between 0 and 1 times (the preceding character is optional) |
| `\` (backslash)     | “Escapes” the following character, nullifying any special meaning it has |

Usage: `./rgep 'pattern' < input` where 'pattern' is the pattern to be matched against and input is the standard input.

Should the input contain:

```
a.out
cs221.txt
cs221.pdf
usf.txt
nope.pdf
.txt
```

and the pattern is `.\.txt`, rgrep will print out

```
cs221.txt
usf.txt
```
