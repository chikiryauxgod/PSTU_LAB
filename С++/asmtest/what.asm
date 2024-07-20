.686
.MODEL FLAT, C

.DATA
helloWorld db 'Hello World!', 0

.CODE

what PROC
    mov eax, OFFSET helloWorld ; ѕомещаем адрес строки в регистр EAX
    ret                        ; ¬озвращаемс€, EAX будет содержать адрес строки
what ENDP

END
