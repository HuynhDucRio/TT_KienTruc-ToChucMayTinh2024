
org 100h
mov cx,26 

lap:
    mov ah,2   
    mov dl,x
    int 21h 
    mov ah,2
    mov dl,20h
    int 21h
    inc x
    loop lap 
ret 
x db 41h




