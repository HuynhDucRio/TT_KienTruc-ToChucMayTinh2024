
org 100h

       
mov cx,4  
mov bl,10
mov x1,0
mov y,0           

mov dx,offset tb1
mov ah,9
int 21h
nhap1:  
    mov ah,1 
    int 21h
    sub al,30h
    xor ah,ah
    mov y,ax
    mov ax,x1
    mul bl
    add ax,y
    mov x1,ax 
    loop nhap1   
mov x2,0
mov y,0
mov cx,4  
mov dx,offset tb2
mov ah,9
int 21h  
nhap2:  
    mov ah,1 
    int 21h
    sub al,30h
    xor ah,ah
    mov y,ax
    mov ax,x2
    mul bl
    add ax,y
    mov x2,ax 
    loop nhap2
    
    
    
mov ax,x1
sub ax,x2
mov hieu,ax
mov ax,x1
mul x2
mov tich,ax
mov dx,offset tb3
mov ah,9
int 21h
mov ah,0
int 16h
ret
tich dw ?
hieu dw ?     
y dw ?
x1 dw ?
x2 dw ?
tb1 db "Moi ban nhap so 1: $"  
tb2 db 10,13,"Moi ban nhap so 2: $"   
tb3 db 10,13,"Ket qua la: $"




