#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define INIT_CAPACITY 100

struct stack_type
{
	Item* contents; // 배열
	int top;
	int size; // 배열의 크기
};

static void terminate(const char* message) {
	printf("%s\n", message);
	exit(1);
}

Stack create() {
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL)
		terminate("Error in create: stack could not be created");
	s->contents = (Item*)malloc(INIT_CAPACITY * sizeof(Item));
	if (s->contents == NULL) {
		free(s);
		terminate("Error in create: stack could not be created");
	}
	s->top = -1;
	s->size = INIT_CAPACITY;
	return s;
}

void destroy(Stack s) {
	free(s->contents);
	free(s);
}

void make_empty(Stack s) {
	s->top = -1;
}

bool is_empty(Stack s)
{
	return s->top == -1;
}

void push(Stack s, Item i) {
	if (is_full(s))
		reallocate(s);
	s->top++;
	s->contents[s->top] = i;
}

Item pop(Stack s) {
	if (is_empty(s))
		terminate("Error in pop: stack is empty");
	s->top--;
	return s->contents[s->top + 1];
}

Item peek(Stack s) {
	if (is_empty(s))
		terminate("Error in peek: stack is empty");
	return s->contents[s->top];
}

void reallocate(Stack s) { // 스택이 꽉찼을 때 재 할당
	Item* tmp = (Item*)malloc(2 * s->size * sizeof(Item));
	if (tmp == NULL) {
		terminate("Error in create: stack colud not be created");
	}
	for (int i = 0; i < s->size; i++) {
		tmp[i] = s->contents[i];
	}
	free(s->contents);
	s->contents = tmp;
	s->size *= 2;
}