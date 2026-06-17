; =============================================
; PIC16F887 + KS0108 GLCD (128x64)
; Belső 8MHz oszcillátor
; Bitmap megjelenítés
; =============================================
;	${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.crs

        LIST    P=16F887
        #include <p16f887.inc>
	

        __CONFIG _CONFIG1, _INTOSCIO & _WDT_OFF & _PWRTE_ON & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_OFF & _IESO_OFF & _FCMEN_OFF
        __CONFIG _CONFIG2, _BOR40V & _WRT_OFF & _DEBUG_OFF

; ============================================================
; PIN DEFINÍCIÓK
; ============================================================

#define GLCD_CS1 PORTBx,0
#define GLCD_CS2 PORTBx,1
#define GLCD_RS  PORTBx,2
#define GLCD_RW  PORTBx,3
#define GLCD_EN  PORTBx,4
#define GLCD_RST PORTBx,5

; ============================================================
; RAM
; ============================================================

        CBLOCK 0x20
            Temp
            Temp2
            GLCDPage
            Column
            DelayCnt1
            DelayCnt2
            BitmapIndex
	    PORTBx
	    TEMPVAL
	    LineX           ; Aktuális X koordináta (0-127)
	    LineY           ; Aktuális Y koordináta (0-63)
	    ErrReg          ; Bresenham hiba-regiszter
	    WaitingTime
	    NextPCL
	    NextPCLATH
	    RotationNum
	    RotationCounter
	    RotationTemp
	    STTATUSvalue
	    Sevenseg
	    SkipValue
        ENDC
	
SETPORTEBIT MACRO
 
	    banksel	TRISE
	    clrf	TRISE

	    banksel PORTE
	    movlw	0x01
	    movwf	PORTE
	    
	    PAGESEL $
	    GOTO $
	
	    ENDM
	    
FLIP_STATUS macro value
 
    movlw   b'00000000'
    btfsc   STTATUSvalue,value	; Ha bit=0, akkor w=0
    movlw   b'00000001'
    
    addlw   b'11111111'
    btfsc   STATUS,Z		; Ha Z, akkor w=1 volt Ã©s
    bcf	    STTATUSvalue,value	; kimarad
    
    btfss   STATUS,Z		; Ha NZ, akkor w=0 volt és
    bsf	    STTATUSvalue,value    ; kimarad
    
    movf    STTATUSvalue,w
    banksel PORTE
    movwf   PORTE
    banksel STTATUSvalue
    
    endm	    
	    
#define CSn 0        
#define	CS1 1
#define CS2 2
#define CSx 3	

CHIPSELECTION MACRO VALUE
 
	    IF VALUE == CSn
		BCF     GLCD_CS1
		BCF     GLCD_CS2
		movf	PORTBx,W
		movwf	PORTB
	    ENDIF
 
	    IF VALUE == CS1
		BSF     GLCD_CS1
		BCF     GLCD_CS2
		movf	PORTBx,W
		movwf	PORTB
	    ENDIF
	    IF VALUE == CS2
		BCF     GLCD_CS1
		BSF     GLCD_CS2
		movf	PORTBx,W
		movwf	PORTB
	    ENDIF
	    IF VALUE == CSx
		BSF     GLCD_CS1
		BSF     GLCD_CS2
		movf	PORTBx,W
		movwf	PORTB
	    ENDIF
	
	    ENDM	   

; ============================================================
; RESET
; ============================================================

        ORG 0x0000
	
	PAGESEL	MainEntry
        GOTO	MainEntry
	
	ORG 0x0010

; ============================================================
; DELAY
; ============================================================

Delay_ms
        BANKSEL DelayCnt2       ; Biztonságosan átváltunk a RAM bankra
        MOVLW   0x02            ; Külső számláló indítása (2-szer fut le a belső kör)
        MOVWF   DelayCnt2

DLoop2
        MOVLW   0xDD            ; Belső számláló indítása (D'221')
        MOVWF   DelayCnt1

DLoop1
        DECFSZ  DelayCnt1, F    ; 1 ciklus (ha nem ugrik), 2 ciklus (ha ugrik)
        GOTO    DLoop1          ; 2 ciklus

        DECFSZ  DelayCnt2, F    ; Külső kör csökkentése
        GOTO    DLoop2

        BANKSEL PORTB           ; Visszaállítjuk a portok bankját a főprogramnak
        RETURN                  ; 2 ciklus

; ============================================================
; GLCD COMMAND
; ============================================================

GLCD_Write_Cmd

	banksel	TEMPVAL
	movwf	TEMPVAL
	
        BCF     GLCD_RS
        BCF     GLCD_RW
	movf	PORTBx,W
	movwf	PORTB

	banksel PORTD
	MOVF	TEMPVAL,W
        MOVWF   PORTD
	
        NOP
        NOP

        BSF     GLCD_EN
	movf	PORTBx,W
	movwf	PORTB
	
        NOP
        NOP
        NOP
        NOP

        BCF     GLCD_EN
	movf	PORTBx,W
	movwf	PORTB
	

        RETURN

; ============================================================
; GLCD DATA
; ============================================================

GLCD_Write_Data
	
	banksel	TEMPVAL
	movwf	TEMPVAL

        BSF     GLCD_RS
        BCF     GLCD_RW
	movf	PORTBx,W
	movwf	PORTB

	banksel PORTD
	MOVF	TEMPVAL,W
        MOVWF   PORTD

        NOP
        NOP

        BSF     GLCD_EN
	movf	PORTBx,W
	movwf	PORTB

        NOP
        NOP
        NOP
        NOP

        BCF     GLCD_EN
	movf	PORTBx,W
	movwf	PORTB

        RETURN

; ============================================================
; CHIP SELECT
; ============================================================

Select_Chip
        BTFSC   Column,6
        GOTO    Select_Left

Select_Right

	BCF     GLCD_CS1
        BSF     GLCD_CS2        
	movf	PORTBx,W
	movwf	PORTB
;        MOVLW   0x40            ; Jobb chip Y=0 címre állítása
;        GOTO    GLCD_Write_Cmd  ; Visszatér a GLCD_Write_Cmd RETURN-jével

Select_Left

        BSF     GLCD_CS1
        BCF     GLCD_CS2
	movf	PORTBx,W
	movwf	PORTB
;        MOVLW   0x40            ; Bal chip Y=0 címre állítása
;        GOTO    GLCD_Write_Cmd

; ============================================================
; INIT
; ============================================================

GLCD_Init
        ; Analóg funkciók kikapcsolása (Bank 3)
        BANKSEL ANSEL
        CLRF    ANSEL
        CLRF    ANSELH

        ; Portok alaphelyzetbe állítása (Bank 0)
        BANKSEL PORTB
        CLRF    PORTB
        CLRF    PORTD

        ; Irányregiszterek beállítása kimenetre (Bank 1)
        BANKSEL TRISB
        CLRF    TRISB
        CLRF    TRISD
	
        ; VISSZATÉRÉS BANK 0-RA A HARDVER KEZELÉSHEZ
        BANKSEL PORTBx	
	clrf	PORTBx

        ; Hardveres Reset a kijelzőnek
        BCF     GLCD_RST
	movf	PORTBx,W
	movwf	PORTB
	
	PAGESEL Delay_ms
        CALL    Delay_ms        ; Biztonságos késleltetés
	
        BSF     GLCD_RST
	movf	PORTBx,W
	movwf	PORTB
	
	PAGESEL Delay_ms
        CALL    Delay_ms

        ; Mindkét chip kijelölése az inicializáláshoz
        BSF     GLCD_CS1
        BSF     GLCD_CS2
	movf	PORTBx,W
	movwf	PORTB
	
        ; Parancsok kiküldése (Mindig ellenőrizve, hogy Bank 0-ban vagyunk)
	PAGESEL GLCD_Write_Cmd
        MOVLW   0x3F            ; Display ON
        CALL    GLCD_Write_Cmd
	
	PAGESEL GLCD_Write_Cmd
        MOVLW   0xC0            ; Start Line = 0
        CALL    GLCD_Write_Cmd

	PAGESEL GLCD_Write_Cmd
        MOVLW   0x40            ; Set Y Address = 0
        CALL    GLCD_Write_Cmd

	PAGESEL GLCD_Write_Cmd
        MOVLW   0xB8            ; Set X Address (Page) = 0
        CALL    GLCD_Write_Cmd

        RETURN                  

; ============================================================
; CLEAR DISPLAY
; ============================================================

GLCD_Clear

        CLRF    GLCDPage
		
PageLoop_Clear
	
	CLRF	Column
	
	BSF     GLCD_CS1
        BSF     GLCD_CS2
	movf	PORTBx,W
	movwf	PORTB

        MOVF    GLCDPage,W
        ADDLW   0xB8
        CALL    GLCD_Write_Cmd
	
; ----- BAL CHIP -----

        BCF     GLCD_CS1
        BSF     GLCD_CS2
	movf	PORTBx,W
	movwf	PORTB

        MOVLW   0x40
        CALL    GLCD_Write_Cmd

        MOVLW   D'64'
        MOVWF   Temp

Left_Clear

	CLRW
        movlw	0x01
	movf	Column,W
        CALL    GLCD_Write_Data
	
	incf	Column,F

        DECFSZ  Temp,F
        GOTO    Left_Clear

; ----- JOBB CHIP -----

	BSF     GLCD_CS1
        BCF     GLCD_CS2
        
	movf	PORTBx,W
	movwf	PORTB

        MOVLW   0x40
        CALL    GLCD_Write_Cmd

        MOVLW   D'64'
        MOVWF   Temp

Right_Clear

        CLRW
	movlw	0x80
	movf	GLCDPage,W
	movf	Column,W
        CALL    GLCD_Write_Data
	
	incf	Column,F

        DECFSZ  Temp,F
        GOTO    Right_Clear	
		
	INCF    GLCDPage,F

        MOVLW   8
        SUBWF   GLCDPage,W

        BTFSS   STATUS,Z
        GOTO    PageLoop_Clear

        RETURN
	
; ============================================================
; BITMAP PAGE OLVASÓ
; ============================================================

Read_Memory

	PAGESEL Page0_Read
        MOVF    GLCDPage,W
        XORLW   0
        BTFSC   STATUS,Z
        GOTO    Page0_Read		
	
	PAGESEL Page1_Read
        MOVF    GLCDPage,W
        XORLW   1
        BTFSC   STATUS,Z
        GOTO    Page1_Read

	PAGESEL Page2_Read
        MOVF    GLCDPage,W
        XORLW   2
        BTFSC   STATUS,Z
        GOTO    Page2_Read

	PAGESEL Page3_Read
        MOVF    GLCDPage,W
        XORLW   3
        BTFSC   STATUS,Z
        GOTO    Page3_Read

	PAGESEL Page4_Read
        MOVF    GLCDPage,W
        XORLW   4
        BTFSC   STATUS,Z
        GOTO    Page4_Read

	PAGESEL Page5_Read
        MOVF    GLCDPage,W
        XORLW   5
        BTFSC   STATUS,Z
        GOTO    Page5_Read

	PAGESEL Page6_Read
        MOVF    GLCDPage,W
        XORLW   6
        BTFSC   STATUS,Z
        GOTO    Page6_Read	

	PAGESEL Page7_Read
        GOTO    Page7_Read
	
; A W-ben kapott Byte forgatása a forgatási szám alapján
	
ByteRotation
	
	movwf	RotationTemp
	
	movf	RotationNum,W
	movwf	RotationCounter
	
RepeatRotation
	
	movf	RotationCounter,W
	btfsc	STATUS,Z
	goto	EndOfRotation
	
	decf	RotationCounter,F
	
;	rrf	RotationTemp,F
;	
;	bsf	RotationTemp,7
;	btfss	STATUS,C
;	bcf	RotationTemp,7
	
	rlf	RotationTemp,F
	
	bsf	RotationTemp,0
	btfss	STATUS,C
	bcf	RotationTemp,0
	
	goto	RepeatRotation
	
EndOfRotation
	
	movf	RotationTemp,W
	
	return

; ============================================================
; BITMAP KIRAJZOLÁS
; ============================================================

Show_Logo
	
	banksel GLCDPage
        CLRF    GLCDPage
	
	clrf	PORTA

Page_Draw
	
;	Mindkét oldalnak ugyanazon lapja és kezdősora
	
	CHIPSELECTION CSx

        MOVF    GLCDPage,W
        ADDLW   0xB8
        CALL    GLCD_Write_Cmd
	
	MOVLW   0x40
	CALL    GLCD_Write_Cmd
	
	; ----- BAL CHIP -----

	CHIPSELECTION CS1

	MOVLW   0x40
	CALL    GLCD_Write_Cmd
	
	CLRF	BitmapIndex

	MOVLW   D'64'
	MOVWF   Temp	

ColumnsDraw

	CLRW
	movlw	0x01
	movf	Column,W
	
	PAGESEL Read_Memory
        CALL    Read_Memory
	
	PAGESEL ByteRotation
	CALL	ByteRotation
		
	PAGESEL GLCD_Write_Data
	CALL    GLCD_Write_Data

	incf	BitmapIndex,F

	PAGESEL ColumnsDraw
	DECFSZ  Temp,F
	GOTO    ColumnsDraw
	
	; ----- JOBB CHIP -----

	CHIPSELECTION CS2

	MOVLW   0x40
	CALL    GLCD_Write_Cmd
	
	MOVLW   D'64'
	MOVWF   Temp
	
ColumnsDraw1

	CLRW
	movlw	0x01
	movf	Column,W
	
	PAGESEL Read_Memory
        CALL    Read_Memory
	
	PAGESEL ByteRotation
	CALL	ByteRotation
	
	PAGESEL GLCD_Write_Data
	CALL    GLCD_Write_Data

	incf	BitmapIndex,F

	PAGESEL ColumnsDraw1
	DECFSZ  Temp,F
	GOTO    ColumnsDraw1
	
	
;	MOVLW	0x40
;	CALL	GLCD_Write_Cmd
;	
;
;	CLRF	Column	
;	CLRF	BitmapIndex
;
;Column_Draw
;        CALL    Select_Chip
;	 
;	PAGESEL Read_Memory
;        CALL    Read_Memory	
;	
;	PAGESEL GLCD_Write_Data        
;        CALL    GLCD_Write_Data
;
;        INCF    BitmapIndex,F
;        INCF    Column,F	
;
;	PAGESEL	Column_Draw
;        MOVLW   .128
;        SUBWF   Column,W	
;        BTFSS   STATUS,Z
;        GOTO    Column_Draw
;	
        INCF    GLCDPage,F

        MOVLW   .8
        SUBWF   GLCDPage,W	

	pagesel	Page_Draw
        BTFSS   STATUS,Z
        GOTO    Page_Draw
	
	CHIPSELECTION CSn
	
	movlw	.1
	addwf	RotationNum,F
	
	movlw	.7
	andwf	RotationNum,F
		
        RETURN
	
; ============================================================
; FERDE VONAL RAJZOLÁSA (0,0 -> 127,63)
; ============================================================
Draw_Diagonal_Line
        BANKSEL LineX
        CLRF    LineX           ; X = 0 (Bal szél)
        CLRF    LineY           ; Y = 0 (Teteje)
        
        ; Bresenham kezdő hibaérték fixen a (0,0)->(127,63) meredekséghez:
        ; Error = dx / 2 = 128 / 2 = 64
        MOVLW   D'64'
        MOVWF   ErrReg

Line_Loop
        ; --- 1. LÉPÉS: PIXEL KIRAJZOLÁSA (LineX, LineY) HELYRE ---
        CALL    Plot_Pixel

        ; --- 2. LÉPÉS: BRESENHAM LÉPTETÉS ---
        INCF    LineX, F        ; X mindig lép előre egyet

        ; ErrReg = ErrReg - dy (ahol dy = 64 a kijelző magassága miatt)
        MOVLW   D'64'
        SUBWF   ErrReg, F

        ; Ha az ErrReg negatívvá válik (Carry = 0), akkor Y-nak is lépnie kell!
        BTFSC   STATUS, C
        GOTO    Check_X_End     ; Ha nem lett negatív, ugrás a végellenőrzésre

        ; Ha negatív lett: Y lép lefelé, és ErrReg = ErrReg + dx (dx = 128)
        INCF    LineY, F
        MOVLW   D'128'
        ADDWF   ErrReg, F

Check_X_End
        ; Elértük az X = 128-at? (Vége a vonalnak)
        MOVLW   .128
        SUBWF   LineX, W
        BTFSS   STATUS, Z
        GOTO    Line_Loop       ; Ha még nem, folytatjuk a következő ponttal

        RETURN
	
Plot_Pixel
        ; --- OLDAL (PAGE) KISZÁMÍTÁSA ---
        ; Page = Y / 8. Mivel 8-cal osztunk, ez megegyezik 3 jobbra tolásal.
        MOVF    LineY, W
        MOVWF   Temp
        RRF     Temp, F
        RRF     Temp, F
        RRF     Temp, F
        MOVLW   b'00011111'     ; Csak az alsó bitek kellenek
        ANDWF   Temp, F         ; Temp-ben van a keresett GLCDPage (0-7)

        ; --- CS chip választás és Y cím (Page) beállítás ---
        MOVF    LineX, W
        MOVWF   Column          ; Select_Chip-nek kell a Column változó
        CALL    Select_Chip     ; Kiválasztja a megfelelő chipet (bal/jobb)

        ; Kiküldjük az oldal parancsot (0xB8 + Page)
        MOVF    Temp, W
        ADDLW   0xB8
        CALL    GLCD_Write_Cmd

        ; Kiküldjük az oszlop parancsot (X koordináta alsó 6 bitje: 0x40 + (X AND 63))
        MOVLW   0x3F
        ANDWF   LineX, W
        ADDLW   0x40
        CALL    GLCD_Write_Cmd

        ; --- PIXEL POZÍCIÓ KISZÁMÍTÁSA A BÁJTON BELÜL ---
        ; A bájt melyik bitje lesz az? Bit = Y AND 7
        MOVLW   0x07
        ANDWF   LineY, W
        MOVWF   Temp            ; Temp = hányszor kell eltolni a bitet

        MOVLW   0x01            ; Kezdő bitmaszk: b'00000001'
        MOVWF   Temp2

Shift_Loop
        MOVF    Temp, F
        BTFSC   STATUS, Z
        GOTO    Write_Pixel     ; Ha a számláló 0, kész az eltolás
        BCF     STATUS, C
        RLF     Temp2, F        ; Bit eltolása balra
        DECF    Temp, F
        GOTO    Shift_Loop

Write_Pixel
        ; Kiküldjük a kész pixelbájtot a kijelzőre
        MOVF    Temp2, W
        PAGESEL GLCD_Write_Data
        CALL    GLCD_Write_Data
        
        PAGESEL Draw_Diagonal_Line ; PCLATH helyreállítás!
        RETURN	


; ============================================================
; MAIN
; ============================================================

MainEntry

        BANKSEL OSCCON
        MOVLW   b'01110000'
        MOVWF   OSCCON
	
	banksel	TRISC
	clrf	TRISA
;	clrf	TRISC
	
	banksel STTATUSvalue
	
	clrf	STTATUSvalue
	clrf	Sevenseg
	incf	Sevenseg,F

	PAGESEL GLCD_Init
        CALL    GLCD_Init

        CALL    GLCD_Clear

	PAGESEL Draw_Diagonal_Line ; PCLATH helyreállítás!
	call	Draw_Diagonal_Line	
	
Forever		
	
	decf	SkipValue,W
	
	btfsc	STATUS,Z
	movlw	.99
	
	movwf	SkipValue
	
		
	movf	Sevenseg,W
;	movwf	PORTC
	movwf	PORTA	
	
	rlf	Sevenseg,F
	
	bsf     Sevenseg,0
	btfss	Sevenseg,4
	bcf	Sevenseg,0

	PAGESEL Show_Logo
	decf	SkipValue,W
	BTFSC	STATUS,Z
        CALL    Show_Logo
		
	movlw	.2
	movwf	WaitingTime
	
	movlw	LOW($)
	movwf	NextPCL
	
	movlw	HIGH($)
	movwf	NextPCLATH
	
	PAGESEL	Delay_ms
	CALL	Delay_ms
	
	movf	NextPCLATH,W
	movwf	PCLATH
	
	movf	NextPCL,W
	
	decfsz  WaitingTime,F
	movwf	PCL
		

	FLIP_STATUS 0
	
        GOTO    Forever
	
	#include "bitmap.inc"	

        END
