INCLUDE Irvine32.inc

.data

filename BYTE "BLOOD.txt",0
BUFFER_SIZE = 5000
buffer BYTE BUFFER_SIZE DUP(?)
filehandle DWORD ?
str1 BYTE BUFFER_SIZE DUP(?)
Sspace byte  ".........................................................",0h
space byte "			-------------------------------------------------------------------",0h
string byte "					|	Blood Management System  |		",0h
m1 byte "			1.Add new data ",0h
menu byte "			-------MENU-------",0h
m2 byte "			2.List of Donars",0h
m3 byte "			3.Search Donars",0h
choice byte "			Enter your choice	:	 ",0h
b byte ?
choi byte ?
 stringN byte "Enter Your name : ",0h
 stringB byte "ENter Blood Type : ",0h
 StringA byte "Enter Amount of blood you want to donate : ",0h 
ArrName dword dup(?)
len=($-ArrName)/4
.code

getLine PROTO, line:DWORD, inputStr:PTR BYTE, outputStr:PTR BYTE

main PROC
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
cmp choi ,2
jl L1
jg L2
Je L3

L1:
call crlf
mov edx,offset stringN
call writestring
 call crlf


	MOV edx,OFFSET filename
	CALL OpenInputFile
	MOV filehandle,eax

	INVOKE SetFilePointer,
		filehandle,
		0,
		0,
		FILE_BEGIN

	MOV eax,filehandle
	MOV edx,OFFSET buffer
	MOV ecx,BUFFER_SIZE
	CALL ReadFromFile

	INVOKE getLine, 1, ADDR buffer, ADDR str1

	MOV edx,OFFSET str1
	CALL WriteString
	
	CALL ReadInt
	INVOKE ExitProcess, 0
main ENDP

getLine PROC uses eax ebx esi, line:DWORD, inputStr:PTR BYTE, outputStr:PTR BYTE
.data
	lineCount DWORD 1
	currChar BYTE ?
.code
	MOV esi,outputStr
	MOV ebx,inputStr

	MOV al,[ebx]
	MOV currChar,al

	.WHILE currChar != 000h
		.WHILE currChar != '#'
		;check if the line is desired line then start copying characters until 00dh appears
			MOV eax,line
			.IF lineCount == eax
				MOV al,currChar
				MOV [esi],al
				INC esi
			.ENDIF
			INC ebx
			MOV al,[ebx]
			MOV currChar,al
		.ENDW

		;If the last loop was of desired line, then break main loop.
		MOV eax,line
		.IF	lineCount == eax
			.BREAK
		.ENDIF

		INC lineCount
		ADD ebx,2             ;adding two because to skip 00ah character
		MOV al,[ebx]
		MOV currChar,al
	.ENDW
	RET
getLine ENDP
End Main

