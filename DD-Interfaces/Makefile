all: tablasConversion tests

conversion.o: conversion.c
	gcc -c conversion.c

tablasConversion: conversion.o
	gcc TablasDeConversion.c conversion.o -o tablasConversion

conversionTest: conversion.o
	gcc conversionTest.c conversion.o -o conversionTest

tests: conversionTest
	./conversionTest