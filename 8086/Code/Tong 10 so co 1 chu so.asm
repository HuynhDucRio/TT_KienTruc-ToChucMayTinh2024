
org 100h
mov dx,offset tb
mov ah,9 
int 21h 
mov cx,10 
mov dx,offset tb1
mov ah,9 
int 21h
lap:   
    mov ah,1
    int 21h
    sub al,30h
    xor ah,ah
    add y,ax
    mov ah,2
    mov dl,20h
    int 21h
    loop lap   
    
mov dx,offset tb3
mov ah,9 
int 21h
       
mov bx,10
mov ax,y
mov cx,0 
chia:
    mov dx,0
    div bx
    inc cx
    push dx
    cmp al,0
    je hienthi
    jmp chia
hienthi:
    pop dx
    add dl,30h
    mov ah,2
    int 21h
    dec cx
    cmp cx,0
    jne hienthi
ret 
x db 31h 
y dw ? 
tb db "Tong cac chu so co 1 chu so$"   
tb1 db 10,13,"Nhap 10 so: $"

tb3 db 10,13,"Ket qua: $"




