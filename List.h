#pragma once

#include <stdio.h> // ����������� ���������� ��
#include <string.h> // ��� ������ �� ��������
#include <stdlib.h> // ��� ������ � �������
#include "Lecksema.h"

// ��������� �������� ������
typedef struct list_item {
    Leksema* data; // �� ����� ��������� �� ������ �����-�� ������
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

Leksema* db_read(list* lst, int index);

void db_print(list* lst);

void push_front(list* lst, Leksema lex);

void push_back(list* lst, Leksema* lex);

Leksema* pop_front(list* lst);

Leksema* pop_back(list* lst);

list_item* get_element(list* lst, int index); // ��� ������ ������������ �������� ? ��� ��������� ?