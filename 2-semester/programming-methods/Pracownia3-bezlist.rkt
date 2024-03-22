#lang plait

(define-type-alias Value Number)

(define (run [s : S-Exp]) : Value
  (valI-val (eval (parse s) mt-env)))

;; Abstract syntax -------------------------------

(define-type Op
  (add) (sub) (mul) (leq))

(define-type Exp
  (numE [n : Number])
  (opE [op : Op] [l : Exp] [r : Exp])
  (ifE [b : Exp] [l : Exp] [r : Exp])
  (varE [x : Symbol])
  (letE [x : Symbol] [e1 : Exp] [e2 : Exp])
  (appE [name : Symbol] [s : (Listof Exp)])
  (funE [s : (Listof Symbol)] [e : Exp])
  (definE [s : (Listof (Symbol * Exp))] [e : Exp]))

;; Parse function --------------------------------------

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `{define {(fun SYMBOL (SYMBOL ...) = ANY) ...} for ANY} s)
     (definE (map parse-f (s-exp->list (second (s-exp->list s))))
       (parse-exp (fourth (s-exp->list s))))]
    [else (error 'parse "invalid input")]))
    
(define (parse-exp [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `{ANY SYMBOL ANY} s)
     (opE (parse-op (s-exp->symbol (second (s-exp->list s))))
          (parse-exp (first (s-exp->list s)))
          (parse-exp (third (s-exp->list s))))]
    [(s-exp-match? `{ifz ANY then ANY else ANY} s)
     (ifE (parse-exp (second (s-exp->list s)))
          (parse-exp (fourth (s-exp->list s)))
          (parse-exp (fourth (rest (rest (s-exp->list s))))))]
    [(s-exp-match? `{let SYMBOL be ANY in ANY} s)
     (letE (s-exp->symbol (second (s-exp->list s)))
           (parse-exp (fourth (s-exp->list s)))
           (parse-exp (fourth (rest (rest (s-exp->list s))))))]
    [(s-exp-match? `{SYMBOL (ANY ...)} s)
     (appE (s-exp->symbol (first (s-exp->list s)))
           (map parse-exp (s-exp->list (second (s-exp->list s)))))]
    [(s-exp-match? `SYMBOL s)
     (varE (s-exp->symbol s))]))

(define (parse-f [s : S-Exp]) : (Symbol * Exp)
  (let ((func-exp (funE
    (map s-exp->symbol (s-exp->list (third (s-exp->list s))))
    (parse-exp (fourth (rest (s-exp->list s)))))))
    (pair (s-exp->symbol (second (s-exp->list s))) func-exp)))

(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '<=) (leq)]
    [else (error 'parse "unknown operator")]))

;; Environment -------------------------------------------------

(define-type Info
  (valI [val : Value])
  (funI [xs : (Listof Symbol)] [e : Exp]))

(define-type Binding
  (bind [name : Symbol]
        [info : Info]))

(define-type-alias Env (Listof Binding))

(define mt-env empty)

(define (extend-env [env : Env] [x : Symbol] [i : Info]) : Env
  (cons (bind x i) env))
  
(define (lookup-env [n : Symbol] [env : Env]) : Info
  (type-case (Listof Binding) env
    [empty (error 'lookup "unbound variable")]
    [(cons b rst-env) (cond
                        [(eq? n (bind-name b)) (bind-info b)]
                        [else (lookup-env n rst-env)])]))

;; Eval function ---------------------------------------------------

(define (eval [e : Exp] [env : Env]) : Info
  (type-case Exp e
    [(numE n)
     (valI n)]
    [(opE op l r)
     (valI (eval-op op (valI-val (eval l env)) (valI-val (eval r env))))]
    [(ifE b l r)
     (if (= (valI-val (eval b env)) 0)
         (eval l env)
         (eval r env))]
    [(varE x) (lookup-env x env)]
    [(letE x e1 e2)
     (eval e2 (extend-env env x (eval e1 env)))]
    [(funE xs b) (funI xs b)]
    [(appE name in) (apply-single (lookup-env name env) (first in) env)]
    [(definE fs e)
       (define-list fs e env)]))

(define (apply-single [f : Info] [e : Exp] [env : Env]) : Info
  (let ([i (eval e env)])
    (eval (funI-e f) (extend-env env (first (funI-xs f)) i))))

(define (define-list [ls : (Listof (Symbol * Exp))] [e : Exp] [env : Env]) : Info
  (let ([s (map (lambda (p) (pair (fst p) (eval (snd p) env))) ls)])
    (eval e (extend-env-list env s))))

(define (extend-env-list [env : Env] [xs : (Listof (Symbol * Info))]) : Env
  (if (empty? xs) env
      (let ([p (first xs)])
        (extend-env-list (extend-env env (fst p) (snd p)) (rest xs))))) 
  
(define (eval-op [op : Op] [l : Value] [r : Value]) : Value
  (type-case Op op
    [(add) (+ l r)]
    [(sub) (- l r)]
    [(mul) (* l r)]
    [(leq) (if (<= l r) 0 1)]))