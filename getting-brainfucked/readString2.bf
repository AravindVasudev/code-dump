> +                                ; make cell #2 1 (helps the read loop to begin)
[
    ,                              ; read a character till null
    [ > + > + << -]                ; copy character to i plus 1th & i plus 2th cell
    >> [ << + >> - ]               ; move i plus 2th cell back to current position
    +++++ + [ < ----- --- > - ] <  ; subtract 48(ASCII to Num) from i plus 1th character
]
< [ - ]                            ; delete last character(Terminator 0)
<                                  ; goto last character(helps the loop to begin)
[ < ]                              ; goto next 0 cell (cell #1)
>                                  ; goto first character
[ . > ]                            ; print character
