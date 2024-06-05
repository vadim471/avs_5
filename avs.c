//
// Created by Vadim on 31.05.2024.
//

#include <printf.h>

int main() {
    long long number = 5;
    __asm__(

            "push %0 \n\t"
            "call func1 \n\t"
            "jmp exit \n\t"

            "func1:\n\t"
            "pop %%rbx\n\t" //адрес вызова функции
            "pop %%rax\n\t"
            "push %%rbx\n\t"
            "push %%rax\n\t"
            "cmp $1, %%rax \n\t"
            "je end_sub \n\t"
            "sub $1, %%rax\n\t"
            "push %%rax\n\t"
            "call func1 \n\t"
            "end_sub:\n\t"

            "pop %%rax\n\t" //значение функции
            "cmp $1, %%rax \n\t"
            "je jp_mul1 \n\t"

            "imul %%rcx, %%rax \n\t"

            "jp_mul1: \n\t"
            "mov %%rax, %%rcx \n\t"
            "ret \n\t"

            "exit: \n\t"
            "mov %%rcx, %0 \n\t"

            :"+r"(number)
            :
            :"%rbx", "%rax", "%rcx"
            );
    printf("%d", number);
    return 0;
}
