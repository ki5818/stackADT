#ifndef STACKADT_H
#define STACKADT_H
#include <stdbool.h> /* C 99 only */ // bool 타입 지원

typedef int Item; // 정수를 저장하는 stack
/*
float을 저장하는 스택으로 만들고 싶다면
typedef flaot Item으로만 수정해주면 됨
-> 코드의 재사용
*/
typedef struct stack_type *Stack;

Stack create(); // 스택을 만듦
void destroy(); // 스택을 없앰
void make_empty(Stack s);  // 스택의 내용만 비움
bool is_empty(Stack s);
void push(Stack s, Item i);
//Item push(Stack s);
Item pop(Stack s);
Item peek(Stack s);

#endif // !STACKADT_H