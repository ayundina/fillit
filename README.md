# Fillit
Fillit takes as a parameter a file wich contains a list from 1 to 26 pieces of tetriminos and displays, on the standard output, all of them assembled together in the smallest possible square, assigning a capital letter to each tetrimino, starting with ’A’.</br></br>
# Usage
To download, build and launch:
```
$ git clone https://github.com/ayundina/fillit.git
$ cd fillit
$ make
$ ./fillit ./tetrimino_sets/trms_4_valid_exmpl_pdf
```
**Input example**
```
....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....
```
**Output example**
```
DDAA
CDDA
CCCA
BBBB
```
