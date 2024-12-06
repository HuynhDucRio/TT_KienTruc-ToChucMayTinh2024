
org 100h
mov ah,9
mov dx,offset tb1 
int 21h
mov ah,1
int 21h
mov x,al
sub x,30h

     
mov ah,9
mov dx,offset tb2 
int 21h
mov ah,1
int 21h
mov y,al
sub y,30h
         
         
mov bl,x
add bl,y
add bl,30h
mov z,bl
         
         
mov ah,9
mov dx,offset tb3 
int 21h
         
         
mov ah,2
mov dl,z
int 21h


mov ah,0
int 16h
ret   
tb1 db "Nhap so 1: $"
tb2 db 10,13,"Nhap so 2: $"
tb3 db 10,13,"Ket qua la: $"
x db ?
y db ?
z db ?



