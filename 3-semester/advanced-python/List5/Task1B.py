class VariableNotFound(Exception):
    def __init__(self, variable_name):
        self.variable_name = variable_name
        super().__init__(f"Nie znaleziono zmiennej '{variable_name}'")

class DivisionByZero(Exception):
    def __init__(self):
        super().__init__(f"Dzielenie przez zero!")

class Expression:
    left = None
    right = None

    def eval(self, vars):
        pass

    def __str__(self) -> str:
        pass

    def __add__(self, other):
        return Add(self, other)
    
    def __mul__(self, other):
        return Mult(self, other)

    def setLeft(self, exp):
        self.left = exp

    def setRight(self, exp):
        self.right = exp

    def simplifyConst(self, f, op):
        l = self.left
        r = self.right
        if isinstance(l, Const) and isinstance(r, Const): 
            return Const(f(l.eval({}), r.eval({}))).__str__()
        elif isinstance(l, Const):
            return "(" + l.__str__() + op + r.simplifyConst() + ")"
        elif isinstance(r, Const):
            return "(" + l.simplifyConst() + op + r.__str__() + ")"
        elif isinstance(self, Var):
            return self.__str__()
        elif isinstance(l, Var) and isinstance(r, Var):
            return "(" + l.__str__() + op + r.__str__() + ")"
        elif isinstance(l, Var):
            return "(" + l.__str__() + op + r.simplifyConst() + ")"
        elif isinstance(r, Var):
            return "(" + l.simplifyConst() + op + r.__str__() + ")"
        else:
            return "(" + l.simplifyConst() + op + r.simplifyConst() + ")"
        
    def simplifyVar(self):
        pass

class Const(Expression):
    def __init__(self, val_):
        self.isLeaf = True
        self.val = val_

    def eval(self, vars):
        return self.val

    def __str__(self) -> str:
        return str(self.val)
    
class Var(Expression):
    def __init__(self, name):
        self.isLeaf = True
        self.name = name

    def eval(self, vars):
        if self.name in vars:
            return vars[self.name]
        raise VariableNotFound(self.name)
    
    def __str__(self) -> str:
        return self.name
    
    def simplifyConst(self):
        return self.__str__() 

class Add(Expression):
    def __init__(self, left, right):
        self.setLeft(left)
        self.setRight(right)

    def eval(self, vars):
        return self.left.eval(vars) + self.right.eval(vars)

    def __str__(self) -> str:
        return "(" + self.left.__str__() + "+" + self.right.__str__() + ")"
    
    def simplifyConst(self):
        return super().simplifyConst(lambda x, y: x + y, "+")
    
    def simplifyVar(self):
        r = self.right
        l = self.left
        if isinstance(l, Var) and isinstance(r, Var) and l.__str__() == r.__str__():
            return Mult(Const(2), l).__str__()
        elif isinstance(l, Var) or isinstance(r, Var) or isinstance(l, Const) or isinstance(r, Const):
            return self.__str__()
        else:
            return "(" + l.simplifyVar() + "+" + r.simplifyVar() + ")"
                
class Sub(Expression):
    def __init__(self, left, right):
        self.setLeft(left)
        self.setRight(right)

    def eval(self, vars):
        return self.left.eval(vars) - self.right.eval(vars)

    def __str__(self) -> str:
        return "(" + self.left.__str__() + "-" + self.right.__str__() + ")"

    def simplifyConst(self):
        return super().simplifyConst(lambda x, y: x - y, "-")
    
    def simplifyVar(self):
        r = self.right
        l = self.left
        if isinstance(l, Var) and isinstance(r, Var) and l.__str__() == r.__str__():
            return Const(0).__str__()
        elif isinstance(l, Var) or isinstance(r, Var) or isinstance(l, Const) or isinstance(r, Const):
            return self.__str__()
        else:
            return "(" + l.simplifyVar() + "-" + r.simplifyVar() + ")"
    
class Mult(Expression):
    def __init__(self, left, right):
        self.setLeft(left)
        self.setRight(right)

    def eval(self, vars):
        return self.left.eval(vars) * self.right.eval(vars)

    def __str__(self) -> str:
        return self.left.__str__() + "*" + self.right.__str__()
    
    def simplifyConst(self):
        return super().simplifyConst(lambda x, y: x * y, "*")
    
    def simplifyVar(self):
        r = self.right
        l = self.left
        if isinstance(l, Var) or isinstance(r, Var) or isinstance(l, Const) or isinstance(r, Const):
            return self.__str__()
        else:
            return "(" + l.simplifyVar() + "*" + r.simplifyVar() + ")"
    
class Div(Expression):
    def __init__(self, left, right):
        self.setLeft(left)
        self.setRight(right)

    def eval(self, vars):
        if self.right.eval(vars) == 0:
            raise DivisionByZero()
        return self.left.eval(vars) / self.right.eval(vars)

    def __str__(self) -> str:
        return self.left.__str__() + "/" + self.right.__str__()
    
    def simplifyConst(self):
        return super().simplifyConst(lambda x, y: x / y, "/")
    
    def simplifyVar(self):
        r = self.right
        l = self.left
        if isinstance(l, Var) and isinstance(r, Var) and l.__str__() == r.__str__():
            return Const(1).__str__()
        elif isinstance(l, Var) or isinstance(r, Var) or isinstance(l, Const) or isinstance(r, Const):
            return self.__str__()
        else:
            return "(" + l.simplifyVar() + "/" + r.simplifyVar() + ")"