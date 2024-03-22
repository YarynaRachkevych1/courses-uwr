#lang plait

(define-type (Tree 'a)
  (leaf)
  (two-node [l : (Tree 'a)] [elem : 'a] [r : (Tree 'a)])
  (three-node [l : (Tree 'a)] [elem-l : 'a] [m : (Tree 'a)] [elem-r : 'a] [r : (Tree 'a)]))


(define (height tree)
  (type-case (Tree 'a) tree
    ((leaf) 0)
    ((two-node left value right)
     (+ 1 (height left)))
    ((three-node left value1 middle value2 right)
     (+ 1 (height left)))))


(define (same-height? tree)
  (type-case (Tree 'a) tree
    [(leaf) #t]
    [(two-node left value right)
     (and (same-height? left)
          (same-height? right)
          (= (height left) (height right)))]
    [(three-node left value1 middle value2 right)
     (and (same-height? left)
          (same-height? middle)
          (same-height? right)
          (= (height left) (height middle))
          (= (height middle) (height right)))]))


(define (bst-helper tree min-val max-val)
  (type-case (Tree 'a) tree
    [(leaf) #t]
    [(two-node left value right)
     (if (and (>= value min-val)
              (<= value max-val))
         (and (bst-helper left min-val value)
              (bst-helper right value max-val))
          #f)]
    [(three-node left value1 middle value2 right)
     (if (and (>= value1 min-val)
              (<= value2 max-val)
              (> value2 value1))
         (and (bst-helper left min-val value1)
              (bst-helper middle value1 value2)
              (bst-helper right value2 max-val))
         #f)]))


(define (bst? t)
  (bst-helper t -inf.0 +inf.0))

(define (is-2-3-tree? tree)
  (and (same-height? tree) (bst? tree)))

(define good-tree
  (two-node
   (three-node (two-node (leaf) -1 (leaf))
               0
               (two-node (leaf) 1 (leaf))
               2
               (two-node (leaf) 3 (leaf)))
   5
   (two-node (two-node (leaf) 6 (leaf))
             7
             (two-node (leaf) 8 (leaf)))))

(define bad-height
  (two-node
   (three-node (two-node (leaf) -1 (leaf))
               0
               (two-node (leaf) 1 (leaf))
               2
               (two-node (leaf) 3 (leaf)))
   5
   (leaf)))

(define not-bst
  (two-node
   (three-node (two-node (leaf) 1 (leaf))
               4
               (two-node (leaf) 0 (leaf))
               2
               (two-node (leaf) 3 (leaf)))
   5
   (two-node (two-node (leaf) 6 (leaf))
             7
             (two-node (leaf) 8 (leaf)))))

(define t1
  (three-node
   (leaf)
   2
   (two-node (two-node (leaf) 1 (leaf)) 3 (leaf))
   8
   (leaf)))

(define t2
  (three-node
   (two-node (leaf) 4 (leaf))
   8
   (two-node (leaf) 9 (leaf))
   10
   (two-node (leaf) 19 (leaf))))

(is-2-3-tree? good-tree)
(is-2-3-tree? bad-height)
(is-2-3-tree? not-bst)
