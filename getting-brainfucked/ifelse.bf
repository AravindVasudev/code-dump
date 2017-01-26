,                                              ; read a character
> +++++ + [ < ----- --- > - ] <                ; subtract 48 (ASCII to Number)
> + <                                          ; set temp to 1
[                                              ; IF Block
  >>                                           ; goto temp plus 1th cell
  +++++ ++++ [ > +++++ +++ < -] > . +  . [-]   ; print 'HI'
  <<<                                          ; goto back
  > -                                          ; make temp 0(break out & stop else block)
] >                                            ; end IF
[                                              ; ELSE Block
  >                                            ; goto temp plus 1th cell
  +++++ +++++ [                                ; loop to print 'bye'
    > +++++ +++++
    > +++++ +++++ ++
    > +++++ +++++
  <<< -
  ]
  > -- . [-]                                   ; print 'b'
  >  + . [-]                                   ; print 'y'
  >  + . [-]                                   ; print 'e'
  <<<< -                                       ; make temp 0(break out)
]
<                                              ; goto x
