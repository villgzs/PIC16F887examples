
;-------------------------------------------------------------------------
; TÁBLÁZATOLVASÓ ELJÁRÁS (Feltételezzük, hogy az index a W regiszterben van)
; Ha az index > 255, akkor egy segédregiszter (pl. INDEX_HIGH) is kellene,
; de a PCLATH számítás elve 16 bites indexnél is ugyanez.
;-------------------------------------------------------------------------
Read_Big_Table:
    MOVWF   INDEX_LOW       ; Mentjük a kért indexet (0-255 közötti példa)
    CLRF    INDEX_HIGH      ; Ha 256-nál nagyobb az index, ide jön a felső bájt
    
    ; 1. Kiszámoljuk a táblázat abszolút kezdőcímét + az indexet
    MOVLW   LOW(Table_Start)  ; Táblázat alacsony címe
    ADDWF   INDEX_LOW, W      ; Hozzáadjuk az index alacsony bájtját
    MOVWF   TARGET_PCL        ; Elmentjük az új PCL értéket
    
    MOVLW   HIGH(Table_Start) ; Táblázat magas címe
    BTFSC   STATUS, C         ; Volt túlcsordulás az alsó bájtnál?
    ADDLW   1                 ; Ha igen, növeljük a magas címet
    ADDWF   INDEX_HIGH, W     ; Hozzáadjuk az index magas bájtját (ha van)
    
    ; 2. Beállítjuk a PCLATH-t és végrehajtjuk az ugrást
    MOVWF   PCLATH            ; A kiszámolt magas cím megy a PCLATH-ba
    MOVF    TARGET_PCL, W     ; Az alacsony cím megy a W-be
    MOVWF   PCL               ; A PCL betöltésével megtörténik a táblázatra ugrás

;-------------------------------------------------------------------------
; TÁBLÁZAT (A programban bárhol elhelyezkedhet, akár laphatáron is crossingolhat)
;-------------------------------------------------------------------------
Table_Start:
    ; ... Itt akár 300-400 darab RETLW is állhatna előtte ...
    ; 
    RETLW   0x10            ; Index 0
    RETLW   0x20            ; Index 1
    RETLW   0x30            ; Index 2
    RETLW   0x40            ; Index 3
    RETLW   0x50            ; Index 4
    RETLW   0x60            ; Index 5
    RETLW   0x70            ; Index 6
    RETLW   0x80            ; Index 7
    RETLW   0x90            ; Index 8
    RETLW   0xA0            ; Index 9

