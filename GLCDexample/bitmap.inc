; ============================================================
; BITMAP TÁBLÁK
; ============================================================

        ORG     0x0400

Page0_Read
	movlw	HIGH(Page0_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
	
	ORG     0x0500

Page1_Read
	movlw	HIGH(Page1_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81	

	ORG     0x0600

Page2_Read
	movlw	HIGH(Page2_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

	ORG     0x0700

Page3_Read
	movlw	HIGH(Page3_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

	ORG     0x0800

Page4_Read
	movlw	HIGH(Page4_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

	ORG     0x0900

Page5_Read
	movlw	HIGH(Page5_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81


	ORG     0x0A00

Page6_Read
	movlw	HIGH(Page6_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81


	ORG     0x0B00

Page7_Read
	movlw	HIGH(Page7_Read)
	movwf	PCLATH
        MOVF    BitmapIndex,W
	ANDLW	0x7F
        ADDWF   PCL,F

        RETLW   0xFF
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81

        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0xFF
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0xFF

        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x81
        RETLW   0xBD
        RETLW   0xA5
        RETLW   0xA5
        RETLW   0xBD
        RETLW   0x81
        RETLW   0xFF

        RETLW   0x00
        RETLW   0x18
        RETLW   0x3C
        RETLW   0x7E
        RETLW   0xFF
        RETLW   0x7E
        RETLW   0x3C
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0x80
        RETLW   0xFF

        RETLW   0xFF
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0x01
        RETLW   0xFF

        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55
        RETLW   0xAA
        RETLW   0x55

        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88
        RETLW   0x11
        RETLW   0x22
        RETLW   0x44
        RETLW   0x88

        RETLW   0xFF
        RETLW   0xFE
        RETLW   0xFC
        RETLW   0xF8
        RETLW   0xF0
        RETLW   0xE0
        RETLW   0xC0
        RETLW   0x80

        RETLW   0x80
        RETLW   0xC0
        RETLW   0xE0
        RETLW   0xF0
        RETLW   0xF8
        RETLW   0xFC
        RETLW   0xFE
        RETLW   0xFF

        RETLW   0x81
        RETLW   0x42
        RETLW   0x24
        RETLW   0x18
        RETLW   0x18
        RETLW   0x24
        RETLW   0x42
        RETLW   0x81

        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18
        RETLW   0x18

        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00
        RETLW   0x00
        RETLW   0xFF
        RETLW   0x00

        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81
        RETLW   0x81



