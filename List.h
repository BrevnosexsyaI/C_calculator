#include <stdio.h> // ����������� ���������� ��
#include <string.h> // ��� ������ �� ��������
#include <stdlib.h> // ��� ������ � �������

// ��������� �������� ������
typedef struct list_item {
    void* data; // �� ����� ��������� �� ������ �����-�� ������
    struct list_item* next; // ��� � ��� ������ �� ��������� ���������
    struct list_item* prev; // ��� � ��� ������ �� ���������� ���������
} list_item;

// ����� ��������� ������
typedef struct list {
    int count; // ���������� � ������� ������
    list_item* head; // ��� ������ �� �������� �������
    list_item* tail; // ��� � ��� ������ �� ��������� ������� (����� ������)
} list;

list* db_create();

void db_insert(list* lst, int index, char* data);

char* db_read(list* lst, int index);

int db_search(list* lst, char* data);

void db_delete(list* lst, int index);

void db_print(list* lst);

list_item* get_element(list* lst, int index); // ��� ������ ������������ �������� ? ��� ��������� ?