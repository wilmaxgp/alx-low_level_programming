section .data
    format db "Hello, Holberton", 0

section .text
    global main
    extern printf

main:
    ; Set up the stack frame
    push rbp
    mov rbp, rsp

    ; Call printf
    mov edi, format
    xor eax, eax
    call printf

    ; Clean up and return
    mov eax, 0
    mov rsp, rbp
    pop rbp
    ret

