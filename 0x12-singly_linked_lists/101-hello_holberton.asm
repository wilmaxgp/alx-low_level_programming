section .data
    format db "Hello, Holberton", 0
    newline db 10, 0

section .text
    global main
    extern printf

main:
    ; Set up the stack frame
    push rbp
    mov rbp, rsp

    ; Call printf to print the message
    mov edi, format
    xor eax, eax
    call printf

    ; Call printf to print a new line
    mov edi, newline
    xor eax, eax
    call printf

    ; Clean up and return
    mov eax, 0
    mov rsp, rbp
    pop rbp
    ret

