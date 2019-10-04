# Hashing

## Algorithm Idea

To use high precision fractional digits gotten from each symbol to mutate to whole current hash.

## Implementation

The string is read in and converted to ASCII number codes, with non-ASCII chwracters igonred.

A number is raised to the power of 1/619.

Then from groups of 3 digits. from the fractional digits looped back to less than 64( 2^6 ) by modulo, bit shifted with looping to the right and finally used to add to the current int of the character and modulo to less than 64 again.

When the string ends the numbers are converted to a string representation by referencing a good char array of size 64.

## Commandline Options

### -t testing mode

![testavimo duomenys](https://i.imgur.com/NGBRGFp.png "testavimo duomenys")

### -s (String to be hashed)

hashing.exe -s test

lPWWtidGyAO0L/R1ogJouaDN


### -f (file path) // whole file hashed at once

#### 1 length string hash comparison

hashing.exe -f ../f1.txt (contents "a")


hashing.exe -f ../f1.txt (contents "b")

#### 2 1000 length strings hash comparison

hashing.exe -f ../randomString1.txt

Bw+6x9+mE1d3aCp/DnlDjF+4

hashing.exe -f ../randomString2.txt

cOfSowZHDw47dNblzW3nP09h

#### 1000 length string and 1 char changed hash comparison

hashing.exe -f ../randomString1.txt

Bw+6x9+mE1d3aCp/DnlDjF+4

hashing.exe -f ../randomString1Changed.txt

qw3Me7PbR1zJqWiY6CTB+llT

#### empty file output
hashing.exe -f ../empty.txt

(returns newline)


### -l (file path) // file hashed line by line (lowercase L)

Konstitucija.txt uztrunka 0.280061 s
