.model big
.stack 100h
.data
tb0 db 10,13,"CHUONG TRINH TINH N!(DAY THUA)$"
tb1 db 10,13,"Enter N (<8): $"
tb2 db 10,13,"Invalid N. Try again$"
tb3 db 10,13,"N = $"
tb4 db 10,13,"You have to enter a number less than 8. Try again.$"
tb5 db 10,13,"N! = $"
tb6 db 10,13,"Do you want to recalculate, don't you?(y/n) : $" 
x dw ?
y dw 1
.code
main proc
start:
    mov ax,@data
    mov ds,ax
    ;title
    mov ah,9
    lea dx,tb0
    int 21h
    ;Enter N
    mov ah,9
    lea dx,tb1
    int 21h
    call Enter
    ;factorial
    call fact
    ;Display
    mov ah,9
    lea dx,tb5
    int 21h
    call displayNumber
    ;restart
    mov ah,9
    lea dx,tb6
    int 21h
    mov ah,1
    int 21h
    cmp al,79h
    je start
    cmp al,6eh
    je end
end:;End
    mov ah,4ch
    int 21h

    
    
    
main endp

Enter proc
    mov x,0 
nhap:
    mov ah,1
    int 21h
    cmp al,38h
    jae reEnter
    sub al,30h
    xor ah,ah
    mov x,ax
    ret
reEnter: 
    mov ah,9
    lea dx,tb2
    int 21h
    mov ah,9
    lea dx,tb3
    int 21h
    jmp nhap
    ret


Enter endp
    



;Process
fact proc
    mov ax,y
    mul x
    mov y,ax
    dec x
    cmp x,0
    je quit
    call fact
quit:
    ret
fact endp



;Display
displayNumber proc
    mov bx,10
    mov ax,y  
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
;Restart
reStart proc
      
reStart endp


end main