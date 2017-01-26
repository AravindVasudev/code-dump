,                                ; read x
[
     >  +                        ; increment y
     >  +                        ; increment temp
     << -                        ; decrement x
]
>>                               ; goto temp
[
     << +                        ; increment x
     >> -                        ; decrement temp
]
<< .                             ; print x
>> ++++ [ > +++++ +++ < - ] > .  ; print ' ' using temp & temp next
<<  .                            ; print y
