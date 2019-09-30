# keyboardcat
Keyboard cat is a simple CLI tool to generate ransom streams of ASCII characters to stdout. Speed and Charset can be adjusted and written to stdout or file. Can be as simle random string generator or display purpose. If there is any bug or feature request feel free to create an Issue or pull request.

# Usage
```
KCat v1.0
Keboard cat usage:
    -d    --delay      Delay between each char in microseconds
    -s    --slow       Print in slow mode
    -f    --fast       Print in fast mode
    -i    --insane     Print in insane mode
    -l    --lower-case Include lowercase characters
    -u    --upper-case Include uppercase characters
    -n    --num        Include numbers
    -x    --special    Include special chars
    -h    --help       Print this help and exit
```
# Install
```
./configure
make
sudo make instal
```
# Example
Print numbers only
```
kcat -n 
```

Print lowercase alphanum
```
kcat -ln 
```
Print special chars faster
```
kcat -x -d 10
```
