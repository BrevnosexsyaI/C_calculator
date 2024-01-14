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

	
	/*Leksema Num;*/ // ��������� ������� 

fgets(buffer, sizeof(buffer), stdin);
	while (buffer[i] != '\0' && buffer[i] != '\n') {
		if (buffer[i] == ' ') {
			i++;
			continue;
		}
		else if (buffer[i] == '+' ) // ���������� ����� � ������ ������� 
		{
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
		else if (buffer[i] == '-') 
		{

			Leksema* Opera = { 0 };
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
		/*else if (buffer[i] == '-') {
			if (i == 0) {

			}
			else if () {
			// ���� ������ �������, ����� �� ������ � ���� ����� ������� ������������� �����
			} // ������� � ���, ��� ������� ������� � ������ ��� ���� 

				// ������� � ���, ��� ������� ������� �����
				
		}*/
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
		

		
	}//0-2*4+6     
	//	0-2*4+6/6
	//0-2*4+60-20-2*4+60-20-2*4+60-20-2*4+60-20-2*4+60-20-2*4+60-2
	//	1*1+1*8/8

		printf("\n");	// ������ ��������� ����� � ��������� ����� �� 1 � ������� ���������
	for (int i = 0; i <= expression->count ; i++)
	{
		/*	multiply_My(expression, i);*/
		list_item* base = get_element(expression, i);
		if (base->data.type)
		{
			printf("%g", base->data.numder);
		}
		else
		{
			char buf = base->data.operation;
			printf("%c", base->data.operation);
			
		}
		base = (0);
	}
	


	// 9 / 9 * 6
	for (int i = 0; i < expression->count; i++)
	{
		/*	multiply_My(expression, i);*/
		list_item* base = get_element(expression, i);
		char buf = base->data.operation;
		if (buf == '*' )   //�������� ��������� 
		{
			expression = multiply_My(expression, i);	
			i--;
		}

		base = (0);
	}

	for (int i = 0; i < expression->count; i++)
	{
		list_item* base = get_element(expression, i);
		char buf = base->data.operation;
		 if (buf == '/') 
{
			expression =  Divide_My( expression, i);
			i--;
		}
		base = (0);
	}



	for (int i = 0; i < expression->count; i++)   ///////����� �������������� �����				 ������ ����� 
	{
		list_item* base = get_element(expression, i);
		char buf = base->data.operation;
		if (buf == '+')  //�������� ��������� 
		{
			expression = sum_My(expression, i);
			i--;
		}
		base = (0);
	}

	for (int i = 0; i < expression->count; i++)
	{
		list_item* base = get_element(expression, i);
		char buf = base->data.operation;
		if (buf == '-')   //�������� ��������� 
		{
			expression = subtract_My(expression, i);
			i--;
		}
		base = (0);
	}

	







		printf("\n");	// ������ ��������� ����� � ��������� ����� �� 1 � ������� ���������
	for (int i = 0; i < expression->count ; i++)
	{
		/*	multiply_My(expression, i);*/
		list_item* base = get_element(expression, i);
		if (base->data.type)
		{
			printf("%g", base->data.numder);
		}
		else
		{
			char buf = base->data.operation;
			printf("%c", base->data.operation);
			
		}
		base = (0);
	}
	




	return 0;

}


