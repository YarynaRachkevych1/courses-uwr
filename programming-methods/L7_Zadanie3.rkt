#lang racket

(define/contract (suffixes lst)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (if (null? lst)
      '(())
      (cons lst (suffixes (cdr lst)))))

(define (suffixes2 lst)
  (if (null? lst)
      '(())
      (cons lst (suffixes (cdr lst)))))

(define long-list (range 3000))


(time (set! long-list (suffixes long-list)))
(time (set! long-list (suffixes2 long-list)))