#include "function.h"


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

    return sign * val / power;
}