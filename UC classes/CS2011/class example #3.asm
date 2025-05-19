                                .ORIG        x3000
                                TRAP         x10
                                HALT
                                .END
                                
                                
                                .ORIG        x0010
                                .FILL        x4000
                                .END
                              
                                
                                .ORIG        x4000
                                ADD          R6,R6,  #-1
                                STR          R0, R6, #0
                                ADD          R6,R6,  #-1
                                STR          R1,R6,  #0
                                
                                LEA          R0,STRING
                                PUTS
                                
                                LDR          R1,R6, #0
                                ADD          R6,R6, #1
                                LDR          R0,R6, #0
                                ADD          R6,R6, #1
                                RTI
                                .STRINGZ     "MESSAGE FROM TRAP x10"
                                .END