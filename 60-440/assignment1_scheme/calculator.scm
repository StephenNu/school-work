(define (calculator lst)
 (cond
  ((equal? (length lst) 1) (car lst))
  (else (calculator (cons (eval (cons (cadr lst) (cons (car lst) (cons (caddr lst) '())))) (cdddr lst))))
 )
)
