TITLE creating a file
Include Irvine32.inc 
Buffer_size=501
.data
Sspace byte  ".........................................................",0h
space byte "			-------------------------------------------------------------------",0h
string byte "					|	Blood Management System  |		",0h
m1 byte "			1.Add new data ",0h
menu byte "			-------MENU-------",0h
m2 byte "			2.List of Donars",0h
m3 byte "			3.Search Donars",0h
choice byte "			Enter your choice	:	 ",0h
filename byte "BLOOD.txt",0
filehandle Dword ?
b byte ?
buffer byte buffer_size dup(?)
choi byte ?
bloodfile byte ?
msg1 byte 20 dup(0)
bytesRead dword 1 dup(0)
.code 
main proc 

mov edx,offset space
call writestring
call crlf
mov edx,offset string
call writestring
call crlf
mov edx,offset space 
call writestring
call  crlf
call crlf
;mov edx,offset Sspace
;call writestring 
call crlf
mov edx,offset menu 
call writestring 
call crlf
call crlf
mov edx,offset m1
call writestring
call crlf
mov edx,offset m2
call writestring
call crlf
mov edx,offset m3
call writestring
call crlf
call crlf
call crlf
mov edx,offset choice 
call writestring  
mov choi,al
call readint
mov edx,offset filename
call createOutputfile
;mov eax,filehandle
;mov edx,offset buffer
;mov ecx,buffer_size
;call writeToFile
;mov   ,   blood
;call openinputfile
;mov filehandle ,eax
;mov edx,offset b
;mov ecx,300
;call READFROMFILE
;call writeint
INVOKE CreateFile,
ADDR filename,
GENERIC_READ, 
DO_NOT_SHARE,
NULL,
OPEN_ALWAYS,
FILE_ATTRIBUTE_NORMAL,
0
mov filehandle, eax
invoke ReadFile, 
filehandle,
addr msg1,
40,
addr bytesRead,
0
invoke CloseHandle,
filehandle 
mov edx, offset msg1
call WriteString
exit
main endp 
end main
