# Yaryna Rachkevych
# PO, Lista8, Zadanie 1, Zamiana jednostek
# ruby L8_Zadanie1.rb

class Masa
  def initialize(kg)
    @kg = kg
  end

  def kg
    @kg
  end
  def kg=(warotsc)
    @kg = warotsc
  end

  def lbs
    @kg * 2.20462
  end
  def lbs=(kg)
    @lbs = kg * 2.20462
  end
end


class Dlugosc
  def initialize(m)
    @m = m
  end

  def m
    @m
  end

  def yd
    @m * 1.09361
  end
  def yd=(m)
    @yd = m * 1.09361
  end
end

class Powierzchnia < Dlugosc
  def initialize(m2)
    @m2 = m2
  end

  def m2
    @m2
  end

  def ha
    @m2 * 0.01
  end
  def ha=(m2)
    @ha = m2 * 0.01
  end

  def in2
    m2 * 6.45 * 0.0000000001
  end
  def in=(m2)
    @in = m2 * 6.45 * 0.0000000001
  end
end

class Cisnienie
  def initialize(masa, pow)
    @masa = masa
    @pow = pow
    g = 9.81
    @pa = (masa.kg * g) / pow.m2
  end

  def pa
    @pa
  end

  def bar
    pa * 0.00001
  end
  def bar=(pa)
    @bar = pa * 0.00001
  end

  def psi
    g = 386.088
    (@masa.lbs * g) / @pow.in2
  end
  def psi=(pa)
    @psi = pa / 6895
  end
end



powierzchnia1 = Powierzchnia.new(10)
powierzchnia2 = Powierzchnia.new(28)
powierzchnia3 = Powierzchnia.new(420)
powierzchnia4 = Powierzchnia.new(500)
powierzchnie = [powierzchnia1, powierzchnia2, powierzchnia3, powierzchnia4]
puts "Powierzchnia:"
puts "+-------+-------+--------------+"
puts "| Km^2  | Ha    | In^2         |"
puts "+-------+-------+--------------+"

powierzchnie.each do |p|
  puts sprintf("| %5.1f | %5.2f | %12.3e |", p.m2, p.ha, p.in2)
end
puts "+-------+-------+--------------+"

masa1 = Masa.new(20)
masa2 = Masa.new(420)
pow1 = Powierzchnia.new(5)
pow2 = Powierzchnia.new(1)
cisnienie1 = Cisnienie.new(masa1, pow1)
cisnienie2 = Cisnienie.new(masa2, pow2)
cisnienie3 = Cisnienie.new(masa1, pow2)
cisnienie4 = Cisnienie.new(masa2, pow1)
cisnienia = [cisnienie1, cisnienie2, cisnienie3, cisnienie4]
print"\n"
puts "Cisnienie: "
puts "+----------+------------+------------+"
puts "| Pa       | Bar        | Psi        |"
puts "+----------+------------+------------+"
cisnienia.each do |c|
  puts sprintf("| %8.2f | %6.8f | %10.3e |", c.pa, c.bar, c.psi)
end
puts "+----------+------------+------------+"
