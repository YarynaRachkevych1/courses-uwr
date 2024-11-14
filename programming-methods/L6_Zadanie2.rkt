#lang plait

(define (append xs ys)
   (if (empty? xs )
        ys
        (cons (first xs ) (append (rest xs ) ys))))

;Lemma: for any list xs, ys there exists a list zs such that (append xs ys) ≡ zs

Induction on the list xs:
P := (append xs ys) ≡ zs


(i)
(append empty ys) ≡ ys


(ii)
;Induction hypothesis: (append xs ys) ≡ zs
;To show: For any element x. (append (cons x xs) ys) ≡ zs

      Let's take some element x
      (append (cons x xs) ys) ≡
      (cons x (append xs ys)) ≡
      (cons x zs) 

For any lists xs and ys, there exists a list zs such that (append xs ys) ≡ zs


