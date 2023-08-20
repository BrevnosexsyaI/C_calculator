#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "List.h"
#include "Lecksema.h"
#include "function.h"

#include <locale.h> // ���� ������� � �������
#include <ctype.h>
#include <stdbool.h>
//#include <clocale>


//#include "List.c"
#pragma warning(disable : 4996)	//scanf () �������� �������������� �4996 ��� ����� main ����� 
#define BUFFER_SIZE 100
#define TYPE_NUMBER 1
#define TYPE_OPERATOR 0
#define BUFFER_NUM_SIZE 16
#define LC_ALL 0


int main() {
	setlocale(LC_ALL, "Rus");
	int i = 0;


	list* expression = db_create();


	char buffer[BUFFER_SIZE];// buffer 


	printf("����� ���� ��������� :");

	
	Leksema Num; // ��������� ������� 

	fgets(buffer, sizeof(buffer), stdin);
	while (buffer[i] != NULL) {
		if (buffer[i] == " ") {
			i++;
			continue;
		}
		else if (buffer[i] == '+' || buffer[i] == '-') {
			// ����� ������ ���� ������� 
			
			Leksema* Opera = {0};
			Opera = (Leksema*)malloc(sizeof(Leksema));
			if (Opera == NULL) {
				fprintf(stderr, "Error: �������� ������ ��� ��������� Leksema �� ������� .\n"); //����������� ��� ������ ��������� �� ������ �� ����������� ����� ������
				i++;
				continue;
			}
			Opera->operation = buffer[i]; // ���� �������������� �������� �� ���������� ������� ��������� �6011 
			Opera->type = TYPE_OPERATOR;
			push_back(expression, Opera);
			i++;

			continue;
		}
		else if (buffer[i] == '*' || buffer[i] == '/') {
			
			Leksema* Opera = {0};
			Opera = (Leksema*)malloc(sizeof(Leksema));
			if (Opera == NULL) {
				fprintf(stderr, "Error: �������� ������ ��� ��������� Leksema �� ������� .\n"); //����������� ��� ������ ��������� �� ������ �� ����������� ����� ������
				i++;
				continue;
			}
			Opera->operation = buffer[i];
			Opera->type = TYPE_OPERATOR;
			push_back(expression, Opera);
			i++;

			continue;
		}

		else if (isdigit(buffer[i])) {
			char* buffer_num = malloc(BUFFER_NUM_SIZE * sizeof(char));
			if (buffer_num == NULL) {
				fprintf(stderr, "������: �� ������� �������� ������ ��� ��������� ������.\n");
				// �������������� �������� �� ��������� ������
				return; // ��� �����-�� ������ ��������, � ����������� �� ���������
			}

			double return_num;
			int j = 0;

			buffer_num[j] = buffer[i];

			i++;
			j++;
			while ((isdigit(buffer[i])) || buffer[i] == '.') {
				buffer_num[j] = buffer[i];
				i++;
				j++;
			}

			buffer_num[j] = '\0'; // ��������� ������ �������� '\0'

			return_num = string_to_double(buffer_num);

			// ... ��������� ��� ...

			free(buffer_num); // ����������� ������ ����� �������������
		
			Leksema* Num = {0};
			Num = (Leksema*)malloc(sizeof(Leksema));
			if (Num == NULL) {
				fprintf(stderr, "Error: �������� ������ ��� ��������� Leksema �� ������� .\n"); //����������� ��� ������ ��������� �� ������ �� ����������� ����� ������
				i++;
				continue;
			}
			Num->numder = return_num;
			Num->type = TYPE_NUMBER;
			push_back(expression, Num);


			continue;
			// ������������� ����� 
			// ������� ��������� ���������� 
			// ����� �� sin \ cos
		}
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


}}*/
