#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "List.h"

#include <locale.h> // ���� ������� � �������
//#include "List.c"
#pragma warning(disable : 4996)	//scanf () �������� �������������� �4996 ��� ����� main ����� 3-� ������

int main() {
	list* expression = db_create();
	
	char ch_in[100];

	setlocale(LC_ALL, "Rus");
	printf("����� ���� ��������� :");
	fgets(ch_in, sizeof(ch_in), stdin);
	char* token = strtok(ch_in, " "); // ����������� ��������� ���������� ������ ������ ��� ����� ����� ������������ ���� ������ '	' 
	while (token != NULL) {
		if (isdigit(token[0])) {
			db_insert(expression, -1, token); // ��������� ������� � ����� ������
		}
		else {
			db_insert(expression, -1, token); // ��������� �������� � ����� ������
		}
		token = strtok(NULL, " ");
	}
	list_item* current = expression->head;

	while (current != NULL) {
		if (isdigit(((char*)current->data)[0])) {
			// ��� �������, ��������� ��������������� ��������
			// ...
			
		}
		else {
			// ��� ��������, ��������� ��������������� ��������
			// ...
		}
		current = current->next;
	}

	
}