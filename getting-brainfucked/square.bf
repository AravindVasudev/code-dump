,                               ; read x
> +++++ + [ < ----- --- > - ] < ; subtract 48 from temp
[ > + > + << - ]                ; copy x into y and temp
>> [ << + >> - ] <<             ; move temp to x
[                               ; loop x times
    > [ > + > + << - ]          ; copy y to temp & x2
    > [ < + > - ]               ; move temp to y
   << -                         ; decrement x
]                               ; exit when x = 0
>> +++++ + [ > +++++ +++ < - ]  ; add 48 to x2 (Num to ASCII)
> .                             ; print x2
