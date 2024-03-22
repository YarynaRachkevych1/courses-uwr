#lang plait

(define (map f l)
  (if (empty? l) '()
      (cons (f (first l)) (map f (rest l)))))

(map (lambda (x) (+ x 1)) '(1 2 3 4 5))

Lemma: (map f (map g xs)) ≡ (map (lambda (x) (f (g x))) xs)

Induction on the list xs:
P(xs) := (map f (map g xs)) ≡ (map (lambda (x) (f (g x))) xs)


(i) Base case
;(map f (map g empty)) ≡ (map (lambda (x) (f (g x))) empty)

Let's simplify the Left side
(map f (map g empty)) ≡ (map (if empty? empty) (...)) ≡  (map f empty)  ≡  
≡   (if empty? empty) ≡ emty 

Let’s simplify the Right side 
(map (lambda (x) (f (g x))) empty)   ≡   (empty? empty (...))   ≡   empty 

empty   ≡   empty


(ii) Induction step 
;Induction hypothesis:  (map f  (map g xs))   ≡   (map  (lambda (x)  (f (g x)))  xs) 
;To show: For any x. (map f  (map g  (cons x xs)))   ≡   (map  (lambda  (x)  (f (g x)))  (cons x xs)) 

Let's simplify the Left side 
(map f  (map g  (cons x xs)))
 ≡ (map f  (cons (g x)  (map g xs)))
 ≡ (cons (f (g x))  (map f  (map g xs))) 
 ≡ using induction hypothesis   ≡   (cons (f (g x)) (map (lambda (x) (f (g x))) xs))
; ≡  using definition  ≡  (map (lambda (x) (f (g x))) (cons x xs))

Let’s simplify the Right side
(map  (lambda  (x)  (f (g x)))  (cons x xs))
= (cons ((lambda  (x)  (f (g x))) x) (map (lambda  (x)  (f (g x))) xs)) =
= (cons (f (g x)) (map f (map g xs)))

L ≡ P
Since both the base case and the induction step have been proved as true,
by mathematical induction the statement P(xs) holds
for every list xs type of (Listof τ) for some τ. 








