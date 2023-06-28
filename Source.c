#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"

#include <locale.h> // язык русский в консоли
//#include "List.c"
#pragma warning(disable : 4996)	//scanf () отключил предупреждение С4996 для всего main после 3-й строки

int main() {
	list* expression = db_create();
	
	char ch_in[100];

	setlocale(LC_ALL, "Rus");
	printf("ВВЕДИ свое выражение :");
	fgets(ch_in, sizeof(ch_in), stdin);
	char* token = strtok(ch_in, " "); // Разделитель разделяем полученную строку считая что между всеми компонентами есть пробел '	' 
	while (token != NULL) {
		if (isdigit(token[0])) {
			db_insert(expression, -1, token); // Добавляем операнд в конец списка
		}
		else {
			db_insert(expression, -1, token); // Добавляем оператор в конец списка
		}
		token = strtok(NULL, " ");
	}
	list_item* current = expression->head;

	while (current != NULL) {
		if (isdigit(((char*)current->data)[0])) {
			// Это операнд, выполните соответствующие действия
			// ...
			
		}
		else {
			// Это оператор, выполните соответствующие действия
			// ...
		}
		current = current->next;
	}

	
}