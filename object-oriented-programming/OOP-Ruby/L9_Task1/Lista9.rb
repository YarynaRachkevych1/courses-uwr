# Yaryna Rachkevych
# PO, Lista 9, Zadanie 1 i Zadanie 3
# ruby Lista9.rb

class Function
  def initialize(&block)
    @function = block
  end

  def value(x)
    begin
      result = @function.call(x)
      return result
    rescue Math::DomainError
      return nil
    end
  end

  def zero(a, b, e)
    # metoda bisekcji
    while (b - a).abs > e
      s = (a + b) / 2.0
      if value(s).abs < e
        return s
      elsif value(s) * value(a) < 0
        b = s
      else
        a = s
      end
    end
    nil
  end

  def field(a, b)
    # metoda trapezow
    dx = 0.0001
    area = 0
    (a..(b-dx)).step(dx) do |x|
      area_tr = (value(x) + value(x+dx)) * 0.5 * dx
      area += area_tr
    end
    area
  end

  def deriv(x)
    dx = 0.0001
    (value(x+dx) - value(x)) / dx
  end

  def plot
    y_range = (-5..5).step(0.5).to_a
    x_range = (-5..10).step(0.5).to_a
    y_range.reverse_each do |y|
      row = ""
      x_range.each do |x|
        if ! value(x).nil? and (y-0.5..y+0.5).cover?(value(x)*2)
            row += "●"
        elsif y == 0 && x == 0
          row += "┼"
        elsif y == 0
          row += "─"
        elsif x == 0
          row += "│"
        else
          row += " "
        end
      end
      puts row
    end
  end
end


f1 = Function.new { |x| Math.sin(x)}
f2 = Function.new { |x| x**2 - 2 }
f3 = Function.new { |x| x ** x }
f4 = Function.new { |x| Math.sqrt(x) }
fn = [
  ["sin(x)", f1],
  ["x^2-2", f2],
  ["x^x", f3],
  ["x^1/2", f4]
]

puts "│        Funkcja        │ f(5)  │ f(x) = 0 │ Pole [0 - 5]    │ f'(5)   │"
puts "────────────────────────+───────+──────────+─────────────────+──────────"

fn.each do |name, f|
  val = f.value(5).round(2).to_s
  zero = f.zero(-20, 20, 0.01)
  if zero.nil?
    zero_st = "-"
  else
    zero_st = zero.round(3).to_s
  end
  field = f.field(0, 5).round(10).to_s
  deriv = f.deriv(5).round(2).to_s
  puts "│ %21s │ %5s │ %8s │ %15s │ %7s │" % [name, val, zero_st, field, deriv]
end

puts "────────────────────────+───────+──────────+─────────────────+──────────"

fn.each do |name, f|
  puts name + ":"
  f.plot
  print "\n"
end