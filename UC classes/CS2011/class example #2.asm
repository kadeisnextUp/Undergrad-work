                           .ORIG           x3000
                            LEA             R0, S1
                            TRAP            x20
                            LD              R0,NEWLINE
                            OUT
                            LEA             R0, S2
                            PUTS
                            LD              R0, NEWLINE
                            OUT
                            HALT
S1                          .STRINGZ "STRING ONE"
S2                          .STRINGZ "STRING TWO"
NEWLINE                     .FILL    #13
                            .END
                    
                    