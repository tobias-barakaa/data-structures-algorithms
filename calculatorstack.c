#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

// Define a stack structure
struct Stack {
    double items[STACK_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Push an item onto the stack
void push(struct Stack* stack, double value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

// Pop an item from the stack
double pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

// Check if a character is an operator (+, -, *, /)
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Evaluate a mathematical expression
double evaluate_expression(const char* expression) {
    struct Stack value_stack;
    initialize(&value_stack);

    struct Stack operator_stack;
    initialize(&operator_stack);

    int i = 0;
    while (expression[i] != '\0') {
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || is_operator(expression[i - 1])))) {
            char* endptr;
            double number = strtod(&expression[i], &endptr);
            i = endptr - expression;
            push(&value_stack, number);
        } else if (is_operator(expression[i])) {
            while (operator_stack.top >= 0 && is_operator(expression[i]) &&
                   (expression[i] == '*' || expression[i] == '/') &&
                   (operator_stack.items[operator_stack.top] == '+' || operator_stack.items[operator_stack.top] == '-')) {
                double right = pop(&value_stack);
                double left = pop(&value_stack);
                char op = pop(&operator_stack);
                if (op == '+') {
                    push(&value_stack, left + right);
                } else if (op == '-') {
                    push(&value_stack, left - right);
                } else if (op == '*') {
                    push(&value_stack, left * right);
                } else if (op == '/') {
                    push(&value_stack, left / right);
                }
            }
            push(&operator_stack, expression[i]);
            i++;
        } else {
            printf("Invalid character in the expression: %c\n", expression[i]);
            exit(EXIT_FAILURE);
        }
    }

    while (operator_stack.top >= 0) {
        double right = pop(&value_stack);
        double left = pop(&value_stack);
        char op = pop(&operator_stack);
        if (op == '+') {
            push(&value_stack, left + right);
        } else if (op == '-') {
            push(&value_stack, left - right);
        } else if (op == '*') {
            push(&value_stack, left * right);
        } else if (op == '/') {
            push(&value_stack, left / right);
        }
    }

    if (value_stack.top == 0 && operator_stack.top == -1) {
        return value_stack.items[0];
    } else {
        printf("Invalid expression\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char expression[100];
    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character from input
    int len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    double result = evaluate_expression(expression);
    printf("Result: %.2lf\n", result);

    return 0;
}
