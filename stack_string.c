#include "monty.h"

/**
 * print_char - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
    int char_code;

    if (stack == NULL || *stack == NULL)
        string_err(11, line_number);

    char_code = (*stack)->n;
    if (char_code < 0 || char_code > 127)
        string_err(10, line_number);
    printf("%c\n", char_code);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
    int char_code;
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    tmp = *stack;
    while (tmp != NULL)
    {
        char_code = tmp->n;
        if (char_code <= 0 || char_code > 127)
            break;
        printf("%c", char_code);
        tmp = tmp->next;
    }
    printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack)->prev = tmp;
    (*stack) = tmp;
}

