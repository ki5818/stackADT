#ifndef STACKADT_H
#define STACKADT_H
#include <stdbool.h> /* C 99 only */ // bool Ÿ�� ����

typedef int Item; // ������ �����ϴ� stack
/*
float�� �����ϴ� �������� ����� �ʹٸ�
typedef flaot Item���θ� �������ָ� ��
-> �ڵ��� ����
*/
typedef struct stack_type *Stack;

Stack create(); // ������ ����
void destroy(); // ������ ����
void make_empty(Stack s);  // ������ ���븸 ���
bool is_empty(Stack s);
void push(Stack s, Item i);
//Item push(Stack s);
Item pop(Stack s);
Item peek(Stack s);

#endif // !STACKADT_H