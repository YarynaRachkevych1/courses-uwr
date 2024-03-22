#lang racket
;Definition of tree structure
(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)


;1 subsection

;Checking if tree is a bst
(define (bst-helper node min-val max-val)
  (cond [(leaf? node) #t]
        [(and (>= (node-elem node) min-val)
              (<= (node-elem node) max-val))
         (and (bst-helper (node-l node) min-val (node-elem node)) ;changing max-val here to current node value
              (bst-helper (node-r node) (node-elem node) max-val))] ;changing min-val to current node value
        [else #f]))

(define (bst? t)
  (bst-helper t -inf.0 +inf.0)) ;Could also take min & max from 2 task

;Example tree to test
(define my-tree
  (node
   (node (leaf) 2 (leaf))
   5
   (node (node (leaf) 6 (leaf))
         8
         (node (leaf) 9 (leaf)))))

(define my-tree2
  (node (node (leaf) 7 (leaf))
          5
          (node (node (leaf) 19 (leaf))
                 13
                 (node (leaf) 22 (leaf)))))
;Testing
(bst? my-tree)
(bst? my-tree2)



;2 subsection

(define (add-path tree)
  (define (helper tree sum)
    (cond
      [(leaf? tree) (leaf)]
      [(node? tree) (let ([left-sum (+ sum (node-elem tree))])
         (node (helper (node-l tree) left-sum)
               left-sum
               (helper (node-r tree) left-sum)))]
      [else (error "Invalid tree")]))
  (helper tree 0))

;Testing
(add-path my-tree)

(node (node (leaf) 7 (leaf)) 5 (node (node (leaf) 19 (leaf)) 13 (node (leaf) 22 (leaf))))

        
