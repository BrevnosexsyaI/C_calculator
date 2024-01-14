#include "function.h"
#include <ctype.h>
#include "List.h"
#include "Lecksema.h"
double string_to_double(char* s)
{
    double val, power;
    int i, sign, int_val;
    for (i = 0; isspace(s[i]); i++)
        ; /* ignore separator characters */

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++){
        int_val = (int)(s[i] - '0');
        val = 10.0 * val + int_val;
    }
    
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        int_val = (int)(s[i] - '0');
        val = 10.0 * val + int_val;
        power *= 10.0;
    }

    double answer = sign * val / power;
   // printf("### String_to_double -> answer: %lf\n", answer);

    return answer;
}

list* operation_My(list* expression, int index, char oper) {


    list_item* bufff = get_element(expression, index); //я должен взглянуть на программу и понять
    double val = 0;
    double a = bufff->next->data.numder;
    double b = bufff->prev->data.numder;
    switch (oper) {
    case '*':
        val = a * b;
    case '/':
        val = a / b;
    case '+':
        val = a + b;
    case '-':
        val = a - b;
    default:
        fprintf(stderr, "Error: не правильный знак операции .\n");
    }
   
    db_delete(expression, index);
    db_delete(expression, index);
    //db_delete(expression, index - 1);
    list_item* bufff1 = get_element(expression, index - 1);
    bufff1->data.numder = val;
    return expression;
}
