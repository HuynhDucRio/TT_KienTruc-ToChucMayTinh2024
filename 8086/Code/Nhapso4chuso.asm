
org 100h
mov dx,offset tb1
mov ah,9
int 21h
       
mov cx,4  
mov bl,10
nhap:  
    mov ah,1 
    int 21h
    sub al,30h
    xor ah,ah
    mov y,ax
    mov ax,x
    mul bl
    add ax,y
    mov x,ax 
    loop nhap
mov ah,0
int 16h
ret     
x dw ?
y dw ?
tb1 db "Moi ban nhap so: $"



