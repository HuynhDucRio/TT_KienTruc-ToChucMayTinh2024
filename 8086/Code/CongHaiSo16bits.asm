.model small
.stack 100h  ;khai bao stack
.data  ;Chua du lieu can in ra man hinh   
tb1 db "Nhap so thap phan thu nhat: $"  
tb2 db 10,13,"So vua nhap la: $" 
tb3 db 10,13,"Nhap so thap phan thu hai: $"
tb4 db 10,13,"So vua nhap la: $"
tb5 db 10,13,"Tong hai so la: $" 
tb6 db 10,13,"Tich hai so la: $" 
tb7 db 10,13,"So thu nhat tru so thu hai bang: $"  
tb  db 10,13,"So thu nhat chia so thu hai: $"
tb8 db 10,13,"Nguyen: $"
tb9 db 10,13,"Du: "
x dw ? 
y dw ?
z dw ?
t dw ?
.code   
main proc    
    mov ax,@data
    mov ds,ax
    ;Nhap so dau tien
    mov ah,9
    lea dx,tb1
    int 21h
    call enterNumber
    mov ax,x
    mov t,ax
    ;Xuat so dau tien
    mov ah,9
    lea dx,tb2
    int 21h
    call displayNumber  
    ;Nhap so thu hai
    mov ax,0 
    mov ah,9
    lea dx,tb3
    int 21h
    call enterNumber
    mov ax,x
    mov z,ax 
    ;Xuat so thu hai
    mov ah,9
    lea dx,tb4
    int 21h
    call displayNumber
    ;Cong hai so
    mov ah,9
    lea dx,tb5
    int 21h
    call sum
    ;Tich hai so
    mov ah,9
    lea dx,tb6
    int 21h   
    call tich
    ;Hieu hai so
    mov ah,9
    lea dx,tb7
    int 21h   
    call hieu  
    ;Thuong hai so
    mov ah,9
    lea dx,tb
    int 21h
    mov ah,9
    lea dx,tb8
    int 21h
    call thuongNguyen
    
    
 
    ;Ket thuc
    mov ah,4ch
    int 21h
main endp 
    ;Input
enterNumber proc
    mov x,0
    mov y,0 
    mov bx,10
enter:
    mov ah,1
    int 21h
    cmp al,13
    je quit
    sub al,30h
    xor ah,ah
    mov y,ax    
    mov ax,x
    mul bx
    add ax,y
    mov x,ax
    jmp enter
quit:
    ret
enterNumber endp
    ;Output                 
displayNumber proc
    mov bx,10
    mov ax,x  
    mov cx,0
division:
    mov dx,0
    div bx
    inc cx
    push dx
    cmp al,0
    je display
    jmp division
display:
    pop dx
    add dl,30h
    mov ah,2
    int 21h
    dec cx
    cmp cx,0
    jne display
    ret
displayNumber endp
    ;Process
sum proc
    mov ax,t
    add ax,z
    mov x,ax
    call displayNumber
    ret
sum endp

tich proc
    mov ax,t
    mul z
    mov x,ax
    call displayNumber
    ret
tich endp

hieu proc
    mov ax,t
    sub ax,z
    mov x,ax
    call displayNumber
    ret
hieu endp  

thuongNguyen proc
    mov ax,t
    div z
    mov x,ax
    call displayNumber
    ret
thuongNguyen endp
endp main
