.686
.MODEL FLAT, C

.DATA
helloWorld db 'Hello World!', 0

.CODE

what PROC
    mov eax, OFFSET helloWorld ; �������� ����� ������ � ������� EAX
    ret                        ; ������������, EAX ����� ��������� ����� ������
what ENDP

END
