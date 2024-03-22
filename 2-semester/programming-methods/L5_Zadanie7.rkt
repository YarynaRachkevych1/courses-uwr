#lang plait
(define-type Prop
   (var [ v : String ])
   (conj [ l : Prop ] [ r : Prop ])
   (disj [ l : Prop ] [ r : Prop ])
   (neg [ f : Prop ]) )

(define (make-list p lst)
            (cond [(var? p)
                     (cons (var-v p) lst)]
                  [(conj? p)
                   (append (make-list (conj-l p) '())(append (make-list (conj-r p) '()) lst))]
                  [(disj? p)
                   (append (make-list (disj-l p) '())(append (make-list (disj-r p) '()) lst))]
                  [(neg? p)
                   (make-list (neg-f p) lst)]))

(define (lookup x lst)
  (cond [(empty? lst) #f]
        [(string=? x (first lst)) #t]
        [else (lookup x (rest lst))]))

  (define (helper seen lst)
    (cond [(empty? lst) '()]
          [(lookup (first lst) seen)
           (helper seen (rest lst))]
          [else
           (cons (first lst) (helper (cons (first lst) seen) (rest lst)))]))

(define (remove-rep lst)
  (helper '() lst))
         

(define (free-vars p)
   (remove-rep (make-list p '())))

(define s (neg (conj (disj (conj (var "p")(var "q"))(var "q"))(disj (var "p")(var "r")))))

(free-vars s)