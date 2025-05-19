

                            .ORIG   x3000
                            AND     R0, R0, #0
                            ADD     R0, R0, #10
                            JSR     SUB1
                            ADD     R0,R0,R0
                            HALT
SUB1                        LD      R0, STRING
                            PUTS
                            RET
STRING                      .STRINGZ    "A message for you..."
                            .END
                            