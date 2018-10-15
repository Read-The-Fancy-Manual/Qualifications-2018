Dans un premier temps il faut convertir cette chaine en decimal, on obitent donc: 
```
515 505 503 515 501 503 518 523 476 465 483 484 469 471 465 467 469 483 484 480 465 483 483 473 470 465 467 473 476 469 525
```
On remarque une similitude flagrante pour chaque caractère il faut enlever 400, et on obtient: 
```
115 105 103 115 101 103 118 123 76 65 83 84 69 71 65 67 69 83 84 80 65 83 83 73 70 65 67 73 76 69 125
```
On reconvertit en text et le flag apparait: 
```
sigsegv{LASTEGACESTPASSIFACILE}
```
