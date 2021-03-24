#include <stdio.h>
#include <assert.h> // assert
#include "roman_num.h"

int main (void) {
	
	/* test:
	   1. Signos/símbolos fuera del sistema, XIIHKE
	   2. Los nros base 5 no pueden restarse, VL
       3. Los nros base 5 no se pueden repetir, CLLIII
       4. Los nros base 10 no pueden repetirse más de 3 veces, XVIIII
       5. Los nros base 10 que esten restando no pueden repetirse, DXXCIV 
	   6+. Validos */
	char * test[] = { "XIIHKE",  
					  "VL", 
					  "CLLIII",
					  "XVIIII",
					  "DXXCIV", 
					  "I",
					  "III",
					  "IV",
					  "VIII",
					  "IX",
					  "XXXIV",
					  "XL",
					  "LXXX",
					  "XCVII",
					  "CDL",
					  "DCXXII",
					  "DCCCXCIX",
					  "CMXCIV",
					  "MCMLXXX" };
	const int test_result[] = { -1,
								-1,
								-1,
								-1,
								-1,
								1,
								3,
								4,
								8,
								9,
								24,
								40,
								80,
								97,
								450,
								622,
								899,
								994,
								1980 };
	const unsigned int TEST_TOTAL = 19;

	int i;

	for (i = 0; i < TEST_TOTAL; i++) {
		
		printf ("\n%s = %d", test[i], get_decimal (test[i]));
		//assert (get_decimal (test[i]) == test_result[i]);
		
	}
	
	return 0;

}
