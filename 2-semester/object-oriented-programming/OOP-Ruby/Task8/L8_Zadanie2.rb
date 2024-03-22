# Yaryna Rachkevych
# PO, Lista8, Zadanie 2, Zamiana jednostek
# ruby L8_Zadanie2.rb

class Dlugosc2
  def initialize(dlugosc)
    @m = dlugosc
  end

  def m
    @m
  end

  def inm
    @m.to_f / 1852
  end

  def inm=(m)
    @inm = m * 1852
  end

  # Mila Wroclawska :)
  def mwr
    @m.to_f / 6700
  end

  def mwr=(m)
    @m = m * 6700
  end

  def mm
    @m * 1000
  end

  def mm=(m)
    @mm = m / 1000.0
  end

  def km
    @m / 1000.0
  end

  def km=(m)
    @km = m * 1000.0
  end
end

class Czas
  def initialize(czas)
    @s = czas
  end

  def s
    @s
  end

  def min
    @s / 60.0
  end

  def min=(s)
    @s = s * 60.0
  end

  def h
    @s.to_f / 3600.0
  end

  def h=(s)
    @s = s * 3600.0
  end
end

class Predkosc
  def initialize(dlugosc, czas)
    @m = dlugosc
    @s = czas
    @pr = dlugosc.m / czas.s.to_f
  end

  def pr
    @pr
  end

  def km_h
    @m.km / @s.h
  end

  def km_h=(pr)
    @km_h = pr * 3.6
  end

  def mwr_min
    @m.mwr / @s.min
  end

  def mwr_min=(pr)
    @mwr_min = pr * 60 / 6700
  end

  def km_s
    @m.km / @s.s
  end

  def mm_h
    @m.mm / @s.h
  end
end

class Przyspieszenie
  def initialize(ms1, ms2, czas)
    @pr1 = ms1
    @pr2 = ms2
    @s = czas
    @przyspieszenie = (ms2.pr - ms1.pr) / czas.s
  end
  def przyspieszenie
    @przyspieszenie
  end

  def km_s2
    (@pr2.km_s - @pr1.km_s) / @s.s
  end
  def km_s2=(przyspieszenie)
    @km_s2 = przyspieszenie * 0.001 * 3.6
  end

  def mm_h2
    (@pr2.mm_h - @pr1.mm_h) / @s.h
  end
  def mm_h2=(przyspieszenie)
    @mm_h2 = przyspieszenie * 1000 * 3600 / 1000 / 1000
  end
end

dl1 = Dlugosc2.new(65000)
dl2 = Dlugosc2.new(40000)
czas1 = Czas.new(1000)
czas2 = Czas.new(34000)
czas3 = Czas.new(10)
pr1 = Predkosc.new(dl1, czas1)
pr2 = Predkosc.new(dl2, czas2)
pr3 = Predkosc.new(dl1, czas2)
pr4 = Predkosc.new(dl2, czas1)
predkosci = [pr1, pr2, pr3, pr4]
puts "Predkosci: "
puts "+---------+----------+-------------+"
puts "| M/s     | Km/h     | Mili Wr/min |"
puts "+---------+----------+-------------+"

predkosci.each do |pr|
  puts sprintf("| %7.4f | %8.4f |  %2.4e |", pr.pr, pr.km_h, pr.mwr_min)
end
puts "+---------+----------+-------------+"


prz1 = Przyspieszenie.new(pr1, pr2, czas3)
prz2 = Przyspieszenie.new(pr1, pr2, czas1)
prz3 = Przyspieszenie.new(pr2, pr1, czas3)
prz4 = Przyspieszenie.new(pr2, pr1, czas1)
przyspieszenia = [prz1, prz2, prz3, prz4]
print"\n"
puts "Przyspieszenia: "
puts "+---------+----------+--------------+"
puts "| M/s^2   | Km/s^2   | Mm/h^2       |"
puts "+---------+----------+--------------+"

przyspieszenia.each do |prz|
  puts sprintf("| %7.4f | %8.4f |  %11.4e |", prz.przyspieszenie, prz.km_s2, prz.mm_h2)
end
puts "+---------+----------+--------------+"