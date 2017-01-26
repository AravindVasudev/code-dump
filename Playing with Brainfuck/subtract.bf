,                           read num #1 into cell #1
>                           goto cell #2
,                           read num #2 into cell #2
[                           start the loop
    < -                     decrement cell #1
    > -                     decrement cell #2'
]                           exit the loop when cell #2 becomes 0
+++++ + [ < +++++ +++ > - ] add 48(ASCII for '0') to cell #1
< .                         print cell #1

