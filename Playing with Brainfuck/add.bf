,                           read the first number in cell #1
>                           goto cell #2
,                           read the second number in cell #2
[                           begin the loop
    < +                     goto cell #1 & add 1
    > -                     goto cell #2 & subtract 1
]                           exit the loop when cell #2 is empty
+++++ + [ < ----- --- > - ] subtract 48 from cell #1 (ASCII code of '0')
< .                         print cell #1
