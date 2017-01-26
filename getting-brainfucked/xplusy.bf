[ x = x + y without modifying y ]

,                                    ; read x
>                                    ; goto y
,                                    ; read y
[
     < +                             ; increment x
    >> +                             ; increment temp
     < -                             ; decrement y
]
>                                    ; goto temp
[
     < +                             ; increment y
     > -                             ; decrement temp
]
+++++ +[ << ----- --- >> -]          ; subtract 48 from x (ASCII code of '0')
<< .                                 ; print x
>> ++++ [ > +++++ +++ < - ] > . <<<  ; print ' ' using temp & temp next and go back to x
> .                                  ; print y
