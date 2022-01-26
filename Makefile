#
#   Makefile
#
#   Description
#       Make tool build for MaPWaR
#
#   Author
#       Kyle Yu
#

build:
	gcc -Wall -std=c99 ./src/*.c -lSDL2 -o MaPWaR -I ./include

run:
	./MaPWaR

clean:
	rm MaPWaR

