++++[>++++[>+++<-]<-]   writing 48 / 0x30 / '0' in cell(2)
,>,>                    reading two numbers in cell(0) and cell(1)
[<-<->>-]               decrementing cell(0) and cell(1) by 48 / 0x30 / '0'
<<                      go to cell(0)
[                       muliplication loop
    >                   go to cell(1)
    [>+>+<<-]           move cell(1) to cell(2) and cell(3)
    >>                  go to cell(3)
    [<<+>>-]            move cell(3) back to cell(1)
    <<<-                decrement cell(0)
]
>[-]<
++++[>++++[>+++<-]<-]   adding 48 / 0x30 / '0' to cell(2)
>>.                     print result
>[-]++++++++++.	
