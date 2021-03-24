#include <string.h> // toupper
#include "roman_num.h"


/* Retorna el decimal del romano number. 
   return -1, si no es un nro. romano propio */
unsigned int get_decimal (const char * roman_num) {

	if (!is_roman_number (roman_num))
		return -1;

	unsigned int decimal = 0;

	while (*roman_num != '\0') {
		
		if (*(roman_num + 1) == '\0') {
			decimal += get_sign_value (roman_num);
		}
		else {
			if (get_sign_value (roman_num) >= get_sign_value (roman_num + 1)) {
				decimal += get_sign_value (roman_num);
			}
			else {
				decimal -= get_sign_value (roman_num);
			}
		}

		roman_num++;
	}

	return decimal;

}


/* Retorna el valor de un signo.
   return 0, si no es válido */
unsigned int get_sign_value (const char * sign) {
	
	Sign value = ERROR;

	switch (toupper (*sign)) {
		case 'I': value = I; break;
		case 'V': value = V; break;
		case 'X': value = X; break;
		case 'L': value = L; break;
		case 'C': value = C; break;
		case 'D': value = D; break;
		case 'M': value = M; break;
	}
	
	return value;	
	
}


/* return 1, number es base 5 */
unsigned int is_base_5 (unsigned int number) {
	
	const unsigned int BASE_5 = 5;

	switch ((number / BASE_5)) {
		case 1: return 1;
		case 10: return 1;
		case 100: return 1;
	}

	return 0;
}


/* Verifica si number cumple con las condiciones
   para ser romano.
   return 1, es romano */
unsigned int is_roman_number (const char * number) {

	char prev_sign = 'z';
	unsigned int same_sign = 0;
	const unsigned int SIGN_REPETITION_LIMIT = 3;
	
	while (*number != '\0') {

		if (!validate_sign (number))
			return 0;

		if (get_sign_value (number) > get_sign_value (&prev_sign)) {
			// Los base 5 no pueden utilizarse para restar
			if (is_base_5 (get_sign_value (&prev_sign)))
				return 0;
		}

		if (*number == prev_sign) {
			// Las v, l y d (nros. con base 5) no pueden repetirse
			if (is_base_5 (get_sign_value (number)))
				return 0;

			// Los x, c y m (base 10) y el i pueden repetirse hasta 3 veces
			same_sign++;
			if (same_sign == SIGN_REPETITION_LIMIT)
				return 0;	
		}
		else {
			// En caso de estar restando los valore no pueden repetirse
			if (same_sign > 0) {
				if (get_sign_value (number) > get_sign_value (&prev_sign))
					return 0;
			}

			same_sign = 0;
		}

		prev_sign = *number;
		number++;
	}

	return 1;

}


/* Verifica que el signo/símbolo sea válido.
   return 1, es válido */
unsigned int validate_sign (const char * sign) {

	if (get_sign_value (sign))
		return 1;

	return 0;

}
