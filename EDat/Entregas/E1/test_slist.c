#include "slist.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 64

/* OUTPUT ESPERADO PARA UNA IMPLEMENTACIÓN CORRECTA, SI SE LLAMA SIN ARGUMENTOS
 */
/* $ ./test_slist
hola1 hola2
hola1 hola2 hola3 hola4 hola5 adios
Removing last:
Removed adios
List now:
hola1 hola2 hola3 hola4 hola5
*/

int main() {
	SList *lst = NULL;
	char new_string[STR_LEN], *removed_string = NULL;
	int cmd = 0;

	/* crete a new SList */
	lst = sl_new();
	if (!lst)
		exit(EXIT_FAILURE);

	while (cmd != 4){
		/* chose a task */
		printf("Chose a task (1-Append, 2-Remove, 3-Show, 4-Exit): ");
		scanf("%d", &cmd);

		/* append a new string to the SList */
		if (cmd == 1){
			printf("Enter the new string: ");
			scanf("%s", new_string);
			if (sl_append(lst, new_string) == ERROR){
				printf("Could not append the string\n");
				exit(EXIT_FAILURE);
			}
			else{
				printf("The string '%s' was appended to the SList\n", new_string);
				cmd = 3;
			}
		}

		/* remove the last string from the SLits */
		if (cmd == 2){
			if (sl_removeLast(lst, &removed_string) == ERROR){
				printf("Could not remove the last string\n");
				exit(EXIT_FAILURE);
			}
			else{
				printf("The string '%s' was removed from the SList\n", removed_string);
				cmd = 3;
			}
		}
		/* show the SList */
		if (cmd == 3){
			printf("Actual SList:\n");
			sl_print(lst);
			printf("\n");
		}

		/* exit */
		if (cmd == 4){
			exit(EXIT_SUCCESS);
		}
	}
}
