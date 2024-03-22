#lang racket
(require data/heap)
(provide sim? wire?
         (contract-out
          [make-sim        (-> sim?)]
          [sim-wait!       (-> sim? positive? void?)]
          [sim-time        (-> sim? real?)]
          [sim-add-action! (-> sim? positive? (-> any/c) void?)]

          [make-wire       (-> sim? wire?)]
          [wire-on-change! (-> wire? (-> any/c) void?)]
          [wire-value      (-> wire? boolean?)]
          [wire-set!       (-> wire? boolean? void?)]

          [bus-value (-> (listof wire?) natural?)]
          [bus-set!  (-> (listof wire?) natural? void?)]

          [gate-not  (-> wire? wire? void?)]
          [gate-and  (-> wire? wire? wire? void?)]
          [gate-nand (-> wire? wire? wire? void?)]
          [gate-or   (-> wire? wire? wire? void?)]
          [gate-nor  (-> wire? wire? wire? void?)]
          [gate-xor  (-> wire? wire? wire? void?)]

          [wire-not  (-> wire? wire?)]
          [wire-and  (-> wire? wire? wire?)]
          [wire-nand (-> wire? wire? wire?)]
          [wire-or   (-> wire? wire? wire?)]
          [wire-nor  (-> wire? wire? wire?)]
          [wire-xor  (-> wire? wire? wire?)]

          [flip-flop (-> wire? wire? wire? void?)]))

(define (bus-set! wires value)
  (match wires
    ['() (void)]
    [(cons w wires)
     (begin
       (wire-set! w (= (modulo value 2) 1))
       (bus-set! wires (quotient value 2)))]))

(define (bus-value ws)
  (foldr (lambda (w value) (+ (if (wire-value w) 1 0) (* 2 value)))
         0
         ws))

(define (flip-flop out clk data)
  (define sim (wire-sim data))
  (define w1  (make-wire sim))
  (define w2  (make-wire sim))
  (define w3  (wire-nand (wire-and w1 clk) w2))
  (gate-nand w1 clk (wire-nand w2 w1))
  (gate-nand w2 w3 data)
  (gate-nand out w1 (wire-nand out w3)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;WIRE
; Wire stucktures and functions
(struct wire ([sim #:mutable] [value #:mutable] [actions #:mutable]) #:transparent)

(define (make-wire sim)
  (wire sim #f '()))

(define (add-actions! wire)
  (let* ([sim (wire-sim wire)] [time (sim-time sim)])
    (for-each
     (lambda (action-record)
       (sim-add-action! sim (+ time (car action-record)) (cdr action-record)))
     (wire-actions wire))))

(define (wire-set! wire value)
  (set-wire-value! wire value)
  (add-actions! wire))

; Function that add action to wire
(define (wire-on-change! w action)
  (set-wire-actions! w (cons action (wire-actions w))))


;; SIMULATION
; Simulation struckture and functions
(struct sim ([time #:mutable] [events #:mutable]) #:transparent)

(define (make-sim)
  (sim 0 (make-heap (lambda (pair1 pair2) (< (car pair1) (car pair2))))))

(define (sim-wait! sim time)
  (define end-time (+ (sim-time sim) time))
  (define (do-next-action)
    (when (not (= (heap-count (sim-events sim)) 0))
      (let ([action-record (heap-min (sim-events sim))])
        (when (<= (car action-record) end-time)
          (heap-remove-min! (sim-events sim))
          (set-sim-time! sim (car action-record))
          (execute-action! (cdr action-record))
          (do-next-action)))))
  (do-next-action)
  (set-sim-time! sim end-time))
    
; Function that checks if records are the same
(define (eq-action-record? record1 record2)
  (and (= (car record1) (car record2))
       (eq-action? (cdr record1) (cdr record2))))

; Function that checks if an action is alreay added to queue
(define (action-in-events? new-action-record sim)
  (define (all list)
    (if (null? list) #f
        (or (eq-action-record? new-action-record (first list)) (all (rest list)))))
  (all (vector->list (heap->vector (sim-events sim)))))
    
(define (sim-add-action! sim time action)
  (when (not (action-in-events? (cons time action) sim)) (heap-add! (sim-events sim) (cons time action))))


;;ACTION
; Action struckture
(struct action (out in1 in2 proc) #:transparent)

; Function that calls action
(define (execute-action! action)
  (if (null? (action-in2 action))
      (wire-set!
       (action-out action)
       ((action-proc action) (wire-value (action-in1 action))))
  (wire-set!
   (action-out action)
   ((action-proc action) (wire-value (action-in1 action)) (wire-value (action-in2 action))))))

; Function thst checks if actions are the same
(define (eq-action? action1 action2)
  (and (eq? (action-out action1) (action-out action2))
       (eq? (action-in1 action1) (action-in1 action2))
       (eq? (action-in2 action1) (action-in2 action2))
       (eq? (action-proc action1) (action-proc action2))))


; NOT gate
(define (gate-not out in)
  (wire-on-change! in (cons 1 (action out in null (lambda (p) (not p))))))

; OR gate
(define (gate-or out in1 in2)
  (wire-on-change! in1 (cons 1 (action out in1 in2 (lambda (p q) (or p q)))))
  (when (not (null? in2))
    (wire-on-change! in2 (cons 1 (action out in1 in2 (lambda (p q) (or p q)))))))

; AND gate
(define (gate-and out in1 in2)
  (wire-on-change! in1 (cons 1 (action out in1 in2 (lambda (p q) (and p q)))))
  (when (not (null? in2))
    (wire-on-change! in2 (cons 1 (action out in1 in2 (lambda (p q) (and p q)))))))

; NOR gate
(define (gate-nor out in1 in2)
  (wire-on-change! in1 (cons 1 (action out in1 in2 (lambda (p q) (not (or p q))))))
  (when (not (null? in2))
    (wire-on-change! in2 (cons 1 (action out in1 in2 (lambda (p q) (not (or p q))))))))

; NAND gate
(define (gate-nand out in1 in2)
  (wire-on-change! in1 (cons 1 (action out in1 in2 (lambda (p q) (not (and p q))))))
  (when (not (null? in2))
    (wire-on-change! in2 (cons 1 (action out in1 in2 (lambda (p q) (not (and p q))))))))

; XOR gate
(define (gate-xor out in1 in2)
  (wire-on-change! in1 (cons 1 (action out in1 in2 (lambda (p q) (not (equal? p q))))))
  (when (not (null? in2))
    (wire-on-change! in2 (cons 1 (action out in1 in2 (lambda (p q) (not (equal? p q))))))))

(define (wire-not in)
  (define new-wire (make-wire (wire-sim in)))
  (gate-not new-wire in)
  new-wire)

(define (wire-and in1 in2)
  (define new-wire (make-wire (wire-sim in1)))
  (gate-and new-wire in1 in2)
  new-wire)

(define (wire-or in1 in2)
  (define new-wire (make-wire (wire-sim in1)))
  (gate-or new-wire in1 in2)
  new-wire)

(define (wire-nor in1 in2)
  (define new-wire (make-wire (wire-sim in1)))
  (gate-nor new-wire in1 in2)
  new-wire)

(define (wire-nand in1 in2)
  (define new-wire (make-wire (wire-sim in1)))
  (gate-nand new-wire in1 in2)
  new-wire)

(define (wire-xor in1 in2)
  (define new-wire (make-wire (wire-sim in1)))
  (gate-xor new-wire in1 in2)
  new-wire)