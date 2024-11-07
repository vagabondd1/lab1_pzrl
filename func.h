#ifndef FUNC_H
#define FUNC_H

void print_results_expr(int *ptr, int argc);
void print_result_string(int *ptr, int argc, int flag_value);
int convert_expression(const char *ptr1, const char *ptr2, const char *ptr3, const int n1, const int n2, const int n3, int *ptr_err);
#endif