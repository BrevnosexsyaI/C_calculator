#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "List.h"
#include "Lecksema.h"
#include "functions.h"

#include <locale.h> // ���� ������� � �������
#include <ctype.h>
#include <stdbool.h>


//#include "List.c"
#pragma warning(disable : 4996)	//scanf () �������� �������������� �4996 ��� ����� main ����� 3-� ������
#define BUFFER_SIZE 100
#define TYPE_NUMBER 1
#define TYPE_OPERATOR 0
#define BUFFER_NUM_SIZE 16


int main() {
	setlocale(LC_ALL, "Rus");
	int i = 0;


	list* expression = db_create();


	char buffer[BUFFER_SIZE];// buffer 


	printf("����� ���� ��������� :");

	

	fgets(buffer, sizeof(buffer), stdin);
	while(buffer[i] != NULL){
		if (buffer[i] == " ") {
			i++; 
			continue;
		}
		else if (buffer[i] == '+' || buffer[i] == '-') {
			// ����� ������ ���� ������� 
			Leksema* Opera;
			Opera->operation = buffer[i];
			Opera->type = TYPE_OPERATOR;
			push_back( expression, Opera);
			i++;
		
			continue;
		}
		else if (buffer[i] == '*' || buffer[i] == '/') {
			// ����� ������ ���� ������� 
			Leksema* Opera;
			Opera->operation = buffer[i];
			Opera->type = TYPE_OPERATOR;
			push_back(expression, Opera);
			i++;

			continue;
		}

		else if (isdigit(buffer[i])) {
			char* buffer_num;
			double return_num;
			buffer_num = malloc(sizeof(char) * BUFFER_NUM_SIZE);
			int j = 0;
			buffer_num[j] = buffer[i];
			
			i++;
			j++;
			while ((isdigit(buffer[i])) || buffer[i] = '.') {
				buffer_num[j] = buffer[i];
				i++;
				j++;
			}
			return_num = string_to_double(buffer_num);
			Leksema* Num;
			Num->numder = return_num;
			Num->type = TYPE_NUMBER;
			push_back(expression, Num);


			continue;
			// ������������� ����� 
			// ������� ��������� ���������� 
			// ����� �� sin \ cos
		}
	}


















	/*char* token = strtok(buffer, " "); // ����������� ��������� ���������� ������ ������ ��� ����� ����� ������������ ���� ������ '	'









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


}*/
}