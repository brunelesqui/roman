/* roman_num.h
   Archivo de cabecera para la librería. */

#ifndef ROMAN_NUM_H
#define ROMAN_NUM_H

typedef enum {
	ERROR = 0,
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100,
	D = 500,
	M = 1000,
} Sign;


unsigned int get_decimal (const char * );
unsigned int get_sign_value (const char * );
unsigned int is_base_5 (unsigned int );
unsigned int is_roman_number (const char * );
unsigned int validate_sign (const char * );

#endif
