,                                    ; read x
> , <                                ; read y
>> +++++ + [ << ----- --- >> - ] <<  ; subtract 48 from x (ASCII to Number)
>> +++++ + [ < ----- --- > - ] <<    ; subtract 48 from y (ASCII to Number)
[                                    ; loop x times
    > [ > + > + << - ]               ; copy y to temp & xy
    > [ < + > - ]                    ; restore y from temp
    << -                             ; decrement x
]                                    ; exit when x = 0
>> +++++ + [ > +++++ +++ < - ]       ; add 48 to xy (Num to ASCII)
> .                                  ; print xy
