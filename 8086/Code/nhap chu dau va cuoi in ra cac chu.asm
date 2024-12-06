
org 100h
mov dx,offset tb1
mov ah,9 
int 21h
mov ah,1
int 21h
mov x,al  
mov dx,offset tb2
mov ah,9 
int 21h
mov ah,1
int 21h
mov y,al  
mov cl,y
sub cl,x
inc cl
mov ch,0 
mov dx,offset tb3
mov ah,9 
int 21h

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
x db ? 
y db ?    
tb1 db "Nhap chu cai dau: $"
tb2 db 10,13,"Nhap chu cai hai: $"
tb3 db 10,13,"Ket qua: $"




