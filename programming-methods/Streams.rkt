 #lang racket

;; processing data sequences with lists --------------------

(define (second-prime-in-interval a b)
  (car (cdr (filter prime?
                    (enumerate-interval a b)))))

; (second-prime-in-interval 10000 5000000)

(define (enumerate-interval a b)
  (if (> a b)
      '()
      (cons a (enumerate-interval (+ a 1) b))))

(define (square x)
  (* x x))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

;; streams aka lazy lists ---------------------------------

;; delay and force

(define-syntax-rule
  (stream-cons v s)
  (cons v (delay s)))

(define stream-car car)

(define (stream-cdr s)
  (force (cdr s)))

(define stream-null null)
(define stream-null? null?)

;; operations on streams

(define (stream-len s)
  (if (stream-null? s)
      0
      (+ 1 (stream-len (stream-cdr s)))))

(define (stream-ref s n)
  (if (= n 0)
      (stream-car s)
      (stream-ref (stream-cdr s) (- n 1))))

(define (stream-filter p s)
  (if (stream-null? s)
      stream-null
      (if (p (stream-car s))
          (stream-cons (stream-car s)
                       (stream-filter p (stream-cdr s)))
          (stream-filter p (stream-cdr s)))))

(define (stream-enumerate-interval a b)
  (if (> a b)
      stream-null
      (stream-cons a (stream-enumerate-interval (+ a 1) b))))

(define (stream-second-prime-in-interval a b)
  (stream-car
   (stream-cdr
    (stream-filter prime?
                   (stream-enumerate-interval a b)))))

;; infinite streams

(define ones (stream-cons 1 ones))

(define (integers-from n)
  (stream-cons n (integers-from (+ n 1))))

(define nats (integers-from 0))

(define (sieve s)
  (stream-cons
   (stream-car s)
   (sieve
    (stream-filter
     (λ (x) (not (divides? (stream-car s) x)))
     (stream-cdr s)))))

(define primes (sieve (integers-from 2)))


; Zadanie 2 (próba)
(define primes-stream
  (stream-cons 2
               (stream-filter
                (λ (x) (not (divides? (stream-car primes-stream) x)))
                (cdr nats))))

 ;; combining (infinite) streams 

(define (map2 f xs ys)
  (stream-cons
   (f (stream-car xs)
      (stream-car ys))
   (map2 f (stream-cdr xs) (stream-cdr ys))))

(define nats2 (stream-cons 0 (map2 + nats2 ones)))

#|
nats2    0 1 2 ...
ones     1 1 1 ...
---------------------------------------
nats2  0 1 2 3 ...
|#

(define fibs
  (stream-cons 0 (stream-cons 1 (map2 + fibs (stream-cdr fibs)))))

; Zadanie 3
(define fact
  (stream-cons 1 (map2 * fact (stream-cdr nats))))

; Zadanie 4
(define (partial-sums s)
  (stream-cons (stream-car s) (map2 + (partial-sums s) (stream-cdr s))))


; Zadanie 5
(define (merge s1 s2)
  (cond ((stream-null? s1) s2)
        ((stream-null? s2) s1)
        ((< (stream-car s1) (stream-car s2))
         (stream-cons (stream-car s1)
                      (merge (stream-cdr s1) s2)))
        ((> (stream-car s1) (stream-car s2))
         (stream-cons (stream-car s2)
                      (merge s1 (stream-cdr s2))))
        (else
         (stream-cons (stream-car s1)
                      (merge (stream-cdr s1) (stream-cdr s2))))))


(define stream1
  (stream-cons 1 (stream-cons 3 (stream-cons 5 stream-null))))

(define stream2
  (stream-cons 2 (stream-cons 3 (stream-cons 6 stream-null))))

(define stream-res
  (merge stream1 stream2))


(define (scale s n)
  (stream-cons (* (stream-car s) n)
               (scale (stream-cdr s) n)))

(define hamming
  (merge (scale (stream-cdr nats) 5)
                (merge (scale (stream-cdr nats) 3)
                       (scale (stream-cdr nats) 2))))

(define weird-st
  (stream-cons 1
               (stream-cons 2
                              (stream-cons 3
                                           (stream-cons 4 (map2 + weird-st (stream-cdr (stream-cdr weird-st))))))))