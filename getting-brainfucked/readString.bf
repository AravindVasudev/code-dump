> +                         ; make cell #2 1 (helps the read loop to begin)
[
    > ,                     ; read a character till null
]
<                           ; goto last character(helps the loop to begin)
[ < ]                       ; goto next 0 cell (cell #1)
>>                          ; goto first character
[ . > ]                     ; print character
