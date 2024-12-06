
org 100h
mov dx, offset tb1
mov ah,9
int 21h   
mov cx,0
nhap:     
    mov ah,1
    int 21h 
    cmp al,13
    je thoat
    mov ah,0
    push ax
    inc cx
    jmp nhap         
      
display:
    cmp cx,0
    je  quit
    pop bx
    mov ah,2
    mov dl,bl
    int 21h
    dec cx
    jmp display


thoat:
    mov dx, offset tb2
    mov ah,9
    int 21h
    jmp display
quit:
    mov ah,4ch
    int 21h

ret
tb1 db "Nhap vao 5 ki tu: $"    
tb2 db 10,13,"Ket qua: $"




