.model small
.stack 100h
.data
.code
main proc
    mov ax,0
    mov bx,0
    mov cx,255
tinh:
    inc ax
    add bx,ax
    loop tinh 


main endp
end main



