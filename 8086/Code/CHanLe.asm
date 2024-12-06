
org 100h
mov dx,offset tb1
mov ah,9
int 21h
       
mov cx,2  
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


mov cx,2
mov bx,10
mov ax,x
chiacal:
    mov dx,0
    div bx
    push dx
    loop chiacal
mov cx,2    
cal:
    pop dx
    add tong,dx
    loop cal
    mov ax,tong
    mov dx,0
    mov bx,2
    div bx
    cmp dx,0
    je chan
    jmp le
chan:
    mov dx,offset tb2
    mov ah,9
    int 21h
    mov bx,10
    mov ax,tong
    mov cx,0
chiachan:
    mov dx,0
    div bx
    inc cx
    push dx
    cmp al,0
    je hienthichan
    jmp chiachan
hienthichan:
    pop dx
    add dl,30h
    mov ah,2
    int 21h
    dec cx
    cmp cx,0
    jne hienthichan
    jmp stop    
    
le: 
    mov dx,offset tb3
    mov ah,9
    int 21h
    mov bx,10
    mov ax,tong
    mov cx,0
chiale:
    mov dx,0
    div bx
    inc cx
    push dx
    cmp al,0
    je hienthile
    jmp chiale
hienthile:
    pop dx
    add dl,30h
    mov ah,2
    int 21h
    dec cx
    cmp cx,0
    jne hienthile
    jmp stop   
    
    
stop:    
mov ah,0
int 16h
ret     
x dw ?
y dw ?
tong dw ?
tb1 db "Moi ban nhap so: $"   
tb2 db 10,13,"Tong la chan: $"  
tb3 db 10,13,"Tong la le: $"




